// This file contains code from fps optimizer
// Memory layout originally worked out by Alexander Stasenko

#include "MGEMWBridge.h"
#include "assert.h"

#include "TES3AudioController.h"
#include "TES3Cell.h"
#include "TES3DataHandler.h"
#include "TES3Game.h"
#include "TES3GameSetting.h"
#include "TES3GlobalVariable.h"
#include "TES3InputController.h"
#include "TES3MobController.h"
#include "TES3MobilePlayer.h"
#include "TES3Moon.h"
#include "TES3NPC.h"
#include "TES3PlayerAnimationController.h"
#include "TES3UIManager.h"
#include "TES3WaterController.h"
#include "TES3Weapon.h"
#include "TES3Weather.h"
#include "TES3WeatherController.h"
#include "TES3WorldController.h"

#include "NICamera.h"
#include "NIColor.h"
#include "NIGeometryData.h"
#include "NITriShape.h"

#include "MemoryUtil.h"
#include "TES3Util.h"

namespace mge {
	static MWBridge m_instance;

	//-----------------------------------------------------------------------------

	MWBridge::MWBridge() {
		memset(this, 0, sizeof(*this));
		m_loaded = false;
		m_version = 0;
	}

	//-----------------------------------------------------------------------------

	MWBridge::~MWBridge() {
	}

	//-----------------------------------------------------------------------------

	MWBridge* MWBridge::get() {
		return &m_instance;
	}

	//-----------------------------------------------------------------------------

	void MWBridge::Load() {
		m_loaded = true;
	}

	//-----------------------------------------------------------------------------

	bool MWBridge::CanLoad() {
		// reads static address, so game doesn't need to be loaded
		return TES3::DataHandler::get() != nullptr;
	}

	//-----------------------------------------------------------------------------

	void MWBridge::SetCrosshairEnabled(bool enabled) {
		// This is just appculling WorldController::nodeCursor
		auto worldController = TES3::WorldController::get();
		worldController->nodeCursor->setAppCulled(!enabled);
		worldController->cursorOff = !enabled;
	}

	//-----------------------------------------------------------------------------

	void MWBridge::ToggleCrosshair() {
		auto worldController = TES3::WorldController::get();
		auto disabled = !worldController->cursorOff;
		worldController->cursorOff = disabled;
		worldController->nodeCursor->setAppCulled(disabled);
	}

	//-----------------------------------------------------------------------------

	bool MWBridge::IsExterior() {
		return TES3::DataHandler::get()->currentInteriorCell == nullptr;
	}

	//-----------------------------------------------------------------------------

	bool MWBridge::IsMenu() {
		return TES3::WorldController::get()->flagMenuMode;
	}

	//-----------------------------------------------------------------------------

	bool MWBridge::IsLoadScreen() {
		return *reinterpret_cast<bool*>(0x7C85B8);
	}

	//-----------------------------------------------------------------------------

	void MWBridge::SkipToNextTrack() {
		TES3::WorldController::get()->audioController->unknown_0x8 &= ~0x2;
	}

	//-----------------------------------------------------------------------------

	void MWBridge::DisableMusic() {
		auto audioController = TES3::WorldController::get()->audioController;
		audioController->setMusicVolume(0.01f);
		audioController->volumeNextTrack = 0.01f;
	}

	//-----------------------------------------------------------------------------

	DWORD MWBridge::GetCurrentWeather() {
		auto currentWeather = TES3::WorldController::get()->weatherController->currentWeather;
		if (currentWeather == nullptr) {
			return 0;
		}
		return currentWeather->index;
	}

	//-----------------------------------------------------------------------------

	DWORD MWBridge::GetNextWeather() {
		auto weatherController = TES3::WorldController::get()->weatherController;
		if (weatherController->nextWeather) {
			return weatherController->nextWeather->index;
		}
		else if (weatherController->currentWeather) {
			return weatherController->currentWeather->index;
		}
		return 0;
	}

	//-----------------------------------------------------------------------------

	float MWBridge::GetWeatherRatio() {
		return TES3::WorldController::get()->weatherController->transitionScalar;
	}

	//-----------------------------------------------------------------------------

	const RGBVECTOR* MWBridge::getCurrentWeatherSkyCol() {
		return reinterpret_cast<RGBVECTOR*>(&TES3::WorldController::get()->weatherController->currentSkyColor);
	}

	//-----------------------------------------------------------------------------

	const RGBVECTOR* MWBridge::getCurrentWeatherFogCol() {
		return reinterpret_cast<RGBVECTOR*>(&TES3::WorldController::get()->weatherController->currentFogColor);
	}

	//-----------------------------------------------------------------------------

	DWORD MWBridge::getScenegraphFogCol() {
		// TODO: Handle packed colors better.
		return *reinterpret_cast<DWORD*>(&TES3::DataHandler::get()->sgFogProperty->color[0]);
	}

	//-----------------------------------------------------------------------------

	void MWBridge::setScenegraphFogCol(DWORD c) {
		// TODO: Handle packed colors better.
		*reinterpret_cast<DWORD*>(&TES3::DataHandler::get()->sgFogProperty->color[0]) = c;
	}

	//-----------------------------------------------------------------------------

	float MWBridge::getScenegraphFogDensity() {
		return TES3::DataHandler::get()->sgFogProperty->density;
	}

	//-----------------------------------------------------------------------------

	bool MWBridge::CellHasWeather() {
		auto dataHandler = TES3::DataHandler::get();
		if (dataHandler == nullptr) {
			return true;
		}

		if (dataHandler->currentInteriorCell) {
			return dataHandler->currentInteriorCell->getRegion() != nullptr;
		}

		return true;
	}

	//-----------------------------------------------------------------------------

	float* MWBridge::GetWindVector() {
		return &TES3::WorldController::get()->weatherController->windVelocityCurrWeather.x;
	}

	//-----------------------------------------------------------------------------

	DWORD MWBridge::GetWthrStruct(int wthr) {
		if (wthr >= 0 && wthr <= 9) {
			return DWORD(TES3::WorldController::get()->weatherController->arrayWeathers[wthr]);
		}
		return 0;
	}

	//-----------------------------------------------------------------------------

	bool MWBridge::CellHasWater() {
		auto currentInteriorCell = TES3::DataHandler::get()->currentInteriorCell;
		if (currentInteriorCell) {
			return currentInteriorCell->getHasWater();
		}
		return true;
	}

	//-----------------------------------------------------------------------------

	bool MWBridge::IsUnderwater(float eyeZ) {
		auto level = TES3::DataHandler::get()->currentCell->getWaterLevel();
		if (!level) {
			return false;
		}

		return eyeZ < level.value() - 1.0f;
	}

	//-----------------------------------------------------------------------------

	// simulationTime - Total real time elapsed this session, does not advance in menus
	float MWBridge::simulationTime() {
		return mwse::tes3::getSimulationTimestamp();
	}

	//-----------------------------------------------------------------------------

	// frameTime - Duration of last frame in seconds
	float MWBridge::frameTime() {
		return TES3::WorldController::get()->deltaTime;
	}

	//-----------------------------------------------------------------------------

	// getMouseSensitivityYX() - Returns address of mouse sensitivity struct
	// data is float[2], Y sensitivity component is first
	float* MWBridge::getMouseSensitivityYX() {
		return &TES3::WorldController::get()->mouseSensitivity;
	}

	//-----------------------------------------------------------------------------

	float MWBridge::GetViewDistance() {
		return TES3::WorldController::get()->worldCamera.cameraData.farPlaneDistance;
	}

	//-----------------------------------------------------------------------------

	void MWBridge::SetViewDistance(float dist) {
		auto worldController = TES3::WorldController::get();
		worldController->shadowCamera.cameraData.camera->viewFrustum.far = dist;
		worldController->shadowCamera.cameraData.farPlaneDistance = dist;
		worldController->worldCamera.cameraData.camera->viewFrustum.far = dist;
		worldController->worldCamera.cameraData.farPlaneDistance = dist;

		TES3::Game::get()->renderDistance = dist;

	}

	//-----------------------------------------------------------------------------

	void MWBridge::SetFOV(float screenFOV) {
		// Recalculate FOV values
		float fovtan = std::tan(screenFOV * D3DX_PI / 360.0f);

		auto* frustrum = &TES3::WorldController::get()->worldCamera.cameraData.camera->viewFrustum;
		if (std::fabs(frustrum->left + fovtan) > 0.001f) {
			float aspect = frustrum->right / frustrum->top;
			float fovtanaspect = fovtan / aspect;

			frustrum->left = -fovtan;
			frustrum->right = fovtan;
			frustrum->top = fovtanaspect;
			frustrum->bottom = -fovtanaspect;

			frustrum = &TES3::WorldController::get()->armCamera.cameraData.camera->viewFrustum;
			frustrum->left = -fovtan;
			frustrum->right = fovtan;
			frustrum->top = fovtanaspect;
			frustrum->bottom = -fovtanaspect;

			auto shadowManager = TES3::WorldController::get()->shadowManager;
			if (shadowManager) {
				auto camera = shadowManager->camera;
				if (camera) {
					frustrum = &camera->viewFrustum;
					frustrum->left = -fovtan;
					frustrum->right = fovtan;
					frustrum->top = fovtanaspect;
					frustrum->bottom = -fovtanaspect;
				}
			}
		}

	}

	//-----------------------------------------------------------------------------

	void MWBridge::GetSunDir(float& x, float& y, float& z) {
		// Note: Previous method caused significant jitter with moving view
		// This now returns the exact offset which was in the same scenegraph node
		auto& translate = TES3::WorldController::get()->weatherController->sgSunVis->localTranslate;
		x = translate.x;
		y = translate.y;
		z = translate.z;
	}

	//-----------------------------------------------------------------------------

	BYTE MWBridge::GetSunVis() {
		// TODO: This is totally wrong, need to look at fixing it without breaking visuals.
		auto color = reinterpret_cast<BYTE*>(TES3::WorldController::get()->weatherController->shTriSunBase->modelData->color);
		return color[3];
	}

	//-----------------------------------------------------------------------------

	DWORD MWBridge::IntCurCellAddr() {
		auto dataHandler = TES3::DataHandler::get();
		if (dataHandler) {
			return DWORD(dataHandler->currentInteriorCell);
		}

		return 0;
	}

	//-----------------------------------------------------------------------------

	const char* MWBridge::getInteriorName() {
		auto dataHandler = TES3::DataHandler::get();
		if (dataHandler && dataHandler->currentInteriorCell) {
			return dataHandler->currentInteriorCell->name;
		}

		return nullptr;
	}

	//-----------------------------------------------------------------------------

	bool MWBridge::IntLikeExterior() {
		auto dataHandler = TES3::DataHandler::get();
		if (dataHandler && dataHandler->currentInteriorCell) {
			return dataHandler->currentInteriorCell->getBehavesAsExterior();
		}

		return false;
	}

	//-----------------------------------------------------------------------------

	float MWBridge::WaterLevel() {
		return TES3::DataHandler::get()->currentCell->getWaterLevel().value_or(0.0f);
	}

	//-----------------------------------------------------------------------------

	void MWBridge::HaggleMore(DWORD num) {
		int& haggleAmount = TES3::UI::getHaggleAmount();

		if (haggleAmount != 0) {
			if (haggleAmount <= 0) {
				haggleAmount -= num;
			}
			else {
				haggleAmount += num;
			}
		}

		TES3::UI::updateHaggleLabels();
	}

	//-----------------------------------------------------------------------------

	void MWBridge::HaggleLess(DWORD num) {
		int& haggleAmount = TES3::UI::getHaggleAmount();

		if (haggleAmount != 0) {
			if (haggleAmount <= 0) {
				haggleAmount += num;
			}
			else {
				haggleAmount -= num;
			}
		}

		TES3::UI::updateHaggleLabels();
	}

	//-----------------------------------------------------------------------------

	const BYTE* MWBridge::getInteriorSun() {
		auto interior = TES3::DataHandler::get()->currentInteriorCell;
		if (interior) {
			return reinterpret_cast<const BYTE*>(&interior->variantData.interior.sunColor);

		}

		return nullptr;
	}

	//-----------------------------------------------------------------------------

	float MWBridge::getInteriorFogDens() {
		auto interior = TES3::DataHandler::get()->currentInteriorCell;
		if (interior) {
			return interior->variantData.interior.fogDensity;
		}

		return 0.0f;
	}

	//-----------------------------------------------------------------------------

	DWORD MWBridge::PlayerPositionPointer() {
		// Note: This used to point to the AudioController listenerPosition.
		return DWORD(&TES3::WorldController::get()->getMobilePlayer()->positionAtLastLightUpdate);
	}

	//-----------------------------------------------------------------------------

	float MWBridge::PlayerHeight() { // player eyes height, in CS
		// Is this accurate? This is the player rotation matrix...
		auto height = reinterpret_cast<TES3::Matrix33*>(0x7D39D0)->m2.z;
		return (height == 0 ? 1.0f : height);
	}

	//-----------------------------------------------------------------------------

	// getPlayerMACP - Gets main game object holding the player state
	DWORD MWBridge::getPlayerMACP() {
		return DWORD(TES3::WorldController::get()->getMobilePlayer());
	}

	//-----------------------------------------------------------------------------

	D3DXVECTOR3* MWBridge::PCam3Offset() {
		// Pointer resolve will fail during load screens
		if (IsLoadScreen()) {
			return nullptr;
		}

		auto macp = TES3::WorldController::get()->getMobilePlayer();
		if (macp == nullptr) {
			return nullptr;
		}

		return reinterpret_cast<D3DXVECTOR3*>(&macp->animationController.asPlayer->cameraOffset);
	}

	//-----------------------------------------------------------------------------

	bool MWBridge::is3rdPerson() {
		if (IsLoadScreen()) {
			return false;
		}

		auto macp = TES3::WorldController::get()->getMobilePlayer();
		if (macp == nullptr) {
			return false;
		}

		return macp->animationController.asPlayer->is3rdPerson;
	}

	//-----------------------------------------------------------------------------

	DWORD MWBridge::getPlayerTarget() {
		constexpr auto x = offsetof(TES3::MobileActor, currentEnchantedItem) == 0x380;
		return DWORD(TES3::Game::get()->playerTarget);
	}

	//-----------------------------------------------------------------------------

	// getPlayerWeapon - Gets player weapon type
	int MWBridge::getPlayerWeapon() {
		auto macp = TES3::WorldController::get()->getMobilePlayer();
		if (macp == nullptr) {
			return 0;
		}

		// Check active weapon
		auto readiedWeapon = macp->readiedWeapon;
		if (readiedWeapon == nullptr) {
			return -1;
		}

		return static_cast<TES3::Weapon*>(readiedWeapon->object)->weaponType;
	}

	//-----------------------------------------------------------------------------

	// isPlayerCasting - Tests is the player is currently casting
	bool MWBridge::isPlayerCasting() {
		auto macp = TES3::WorldController::get()->getMobilePlayer();
		if (macp == nullptr) {
			return false;
		}
		return macp->actionData.animStateAttack == TES3::AttackAnimationState::Casting;
	}

	//-----------------------------------------------------------------------------

	// isPlayerAimingWeapon - Tests if the player is in the drawing stage of attacking with a ranged weapon
	bool MWBridge::isPlayerAimingWeapon() {
		auto macp = TES3::WorldController::get()->getMobilePlayer();
		if (macp == nullptr) {
			return false;
		}

		// Check animation state machine for weapon pullback
		auto anim = macp->actionData.animStateAttack;
		if (anim != TES3::AttackAnimationState::SwingUp) {
			return false;
		}

		// Check weapon type (bow, crossbow, thrown)
		auto readiedWeapon = macp->readiedWeapon;
		if (readiedWeapon == nullptr) {
			return false;
		}

		return static_cast<TES3::Weapon*>(readiedWeapon->object)->isRanged();
	}

	//-----------------------------------------------------------------------------

	// toggleRipples - Turns off ripple generation from all sources
	void MWBridge::toggleRipples(BOOL enabled) {
		// TODO: Clean this up to ideally not require code injection. Maybe just set maxRipples to 0?
		auto code = *reinterpret_cast<DWORD*>(0x51C2D4);
		if (enabled && code == 0x33504D8B || !enabled && code == 0x3390C931) {
			return;
		}

		auto newCode = code = enabled ? 0x33504D8B : 0x3390C931;
		mwse::writeDoubleWordEnforced(0x51C2D4, code, newCode);
	}

	//-----------------------------------------------------------------------------

	// markWaterNode
	// Edits the water material to set (normally unused) specular power to a recognizable value
	void MWBridge::markWaterNode(float k) {
		auto waterMaterialProperty = static_cast<NI::MaterialProperty*>(TES3::DataHandler::get()->waterController->waterNode->getProperty(NI::PropertyType::Material).get());
		if (waterMaterialProperty) {
			waterMaterialProperty->shininess = k;
		}
	}

	//-----------------------------------------------------------------------------

	// markMoonNodes
	// Edits the material for both moons to set (normally unused) specular power to a recognizable value
	void MWBridge::markMoonNodes(float k) {
		auto weatherController = TES3::WorldController::get()->weatherController;

		auto materialProperty = static_cast<NI::MaterialProperty*>(weatherController->moonMasser->sgTriMoonShadow->getProperty(NI::PropertyType::Material).get());
		if (materialProperty) {
			materialProperty->shininess = k;
		}

		materialProperty = static_cast<NI::MaterialProperty*>(weatherController->moonSecunda->sgTriMoonShadow->getProperty(NI::PropertyType::Material).get());
		if (materialProperty) {
			materialProperty->shininess = k;
		}
	}

	//-----------------------------------------------------------------------------

	// disableScreenshotFunc
	// Stops Morrowind from taking its own screenshots, or displaying an error message, when PrtScr is pressed
	void MWBridge::disableScreenshotFunc() {
		// TODO: More code injection changes.
		// Replace jz short with jmp (74 -> eb)
		mwse::writeByteUnprotected(0x41B08A, 0xEB);
	}

	//-----------------------------------------------------------------------------

	// disableSunglare - Turns off the sunglare billboard and fullscreen glare that appears when looking at the sun
	void MWBridge::disableSunglare() {
		// TODO: More code injection changes.
		mwse::genNOPUnprotected(0x4404FB, 2);
	}

	//-----------------------------------------------------------------------------

	// disableIntroMovies - Skips playing both intro movies
	void MWBridge::disableIntroMovies() {
		// TODO: More code injection changes.
		BYTE patch[] = { 0xeb, 0x16 };

		mwse::writeBytesUnprotected(0x418EF0, patch, sizeof(patch));
		mwse::writeBytesUnprotected(0x5FC8F7, patch, sizeof(patch));
	}

	//-----------------------------------------------------------------------------

	// isIntroDone - Tests if both intro movies are finished, and main menu is about to display
	bool MWBridge::isIntroDone() {
		return *reinterpret_cast<bool*>(0x7D5005);
	}

	//-----------------------------------------------------------------------------

	// isLoadingSplash - Tests if a splash screen is shown (as a proxy for post-main menu loading)
	bool MWBridge::isLoadingSplash() {
		return *reinterpret_cast<bool*>(0x7D4294);
	}

	//-----------------------------------------------------------------------------

	// redirectMenuBackground - Redirects splash screen scenegraph draw call to another function
	void MWBridge::redirectMenuBackground(void(_stdcall* func)(int)) {
		// Replace jump address
		DWORD newCall = func ? (DWORD)func : 0x6CC7B0;
		mwse::writeDoubleWordUnprotected(0x04589FB, newCall);
	}

	//-----------------------------------------------------------------------------

	const auto TES3_WorldController_configScaling = reinterpret_cast<void(__thiscall*)(TES3::WorldController*, int)>(0x40F2A0);
	const auto TES3_MouseController_setMouseBounds = reinterpret_cast<void(__thiscall*)(TES3::MouseController*, int, int, int, int)>(0x408740);

	// setUIScale - Configures the scaling of Morrowind's UI system, must be called early before main menu
	//              MWBridge is not required to be loaded for this function.
	void MWBridge::setUIScale(float scale) {
		auto worldController = TES3::WorldController::get();

		// Change view scales.
		worldController->viewWidth /= scale;
		worldController->viewHeight /= scale;

		// Update main scaling.
		TES3_WorldController_configScaling(worldController, worldController->viewWidth);

		// Update mouse bounds.
		int halfW = (worldController->viewWidth + 1) / 2;
		int halfH = (worldController->viewHeight + 1) / 2;
		TES3_MouseController_setMouseBounds(worldController->mouseController, -halfW, -halfH, halfW, halfH);

		// Patch raycast system to use UI viewport size instead of D3D viewport size
		const BYTE patch[] = {
			0xa1, 0xdc, 0x67, 0x7c, 0x00,       // mov eax, eMaster
			0x8b, 0x78, 0x78,                   // mov edi, [eax+0x78]
			0x8b, 0x40, 0x7c,                   // mov eax, [eax+0x7c]
			0x90, 0x90, 0x90                    // nops
		};
		mwse::writeBytesUnprotected(0x6F5157, patch, sizeof(patch));
	}

	//-----------------------------------------------------------------------------

	// patchUIConfigure - Patches the normal call to ui_configureUIScale to redirect to a new function.
	//                    MWBridge is not required to be loaded for this function.
	void MWBridge::patchUIConfigure(void(_stdcall* newfunc)()) {
		BYTE patch[] = {
			0xb8, 0xff, 0xff, 0xff, 0xff,       // mov eax, newfunc
			0xff, 0xd0,                         // call eax
			0xeb, 0x06                          // jmp past rest of block
		};
		mwse::writeBytesUnprotected(0x40E554, patch, sizeof(patch));
	}

	//-----------------------------------------------------------------------------

	static int(__cdecl* patchFrameTimerTarget)();

	// patchFrameTimer - Patches certain calls to timeGetTime to redirect to a new function.
	void MWBridge::patchFrameTimer(int(__cdecl* newfunc)()) {
		DWORD patchPoints[] = { 0x403b52, 0x4535fd, 0x453615, 0x453638 };

		patchFrameTimerTarget = newfunc;

		for (size_t i = 0; i < sizeof(patchPoints) / sizeof(DWORD); i++) {
			mwse::writeDoubleWordUnprotected(patchPoints[i], DWORD(&patchFrameTimerTarget));
		}
	}

	//-----------------------------------------------------------------------------

	// getGMSTPointer - Gets a pointer directly to the data of a GMST (of any type)
	void* MWBridge::getGMSTPointer(DWORD id) {
		return &TES3::DataHandler::get()->nonDynamicData->GMSTs[id]->value;
	}

	//-----------------------------------------------------------------------------

	// getKeybindCode - Gets the scancode that an action is bound to
	// action -> the keybind order in the Morrowind controls menu
	DWORD MWBridge::getKeybindCode(DWORD action) {
		return TES3::WorldController::get()->inputController->inputMaps[action].keyCode;
	}

	//-----------------------------------------------------------------------------

	// getPlayerName - Returns the player's name, or null if not loaded
	const char* MWBridge::getPlayerName() {
		auto macp = TES3::WorldController::get()->getMobilePlayer();
		if (macp == nullptr) {
			return nullptr;
		}

		// Get name from base NPC
		return macp->npcInstance->baseNPC->name;
	}

	//-----------------------------------------------------------------------------

	// getGameHour - Returns the value of the script global GameHour
	float MWBridge::getGameHour() {
		return TES3::WorldController::get()->gvarGameHour->value;
	}

	//-----------------------------------------------------------------------------

	// getDaysPassed - Returns the value of the script global DaysPassed
	int MWBridge::getDaysPassed() {
		return int(TES3::WorldController::get()->gvarDaysPassed->value);
	}

	//-----------------------------------------------------------------------------

	// getFrameBeginMillis - Returns timer millis measured at start of frame
	int MWBridge::getFrameBeginMillis() {
		return TES3::WorldController::get()->systemTimeMillis;
	}
}
