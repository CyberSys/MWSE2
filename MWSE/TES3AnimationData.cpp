#include "TES3ActorAnimationController.h"
#include "TES3AnimationData.h"
#include "TES3DataHandler.h"

#include "NINode.h"
#include "NIKeyframeManager.h"

#include "LuaManager.h"
#include "MemoryUtil.h"

#include "LuaPlayAnimationGroupEvent.h"

namespace TES3 {
	constexpr int VanillaLayerCount = 3;
	constexpr int BaseAnimLayerIndex = 2;
	constexpr int BodySectionCount = 3;
	constexpr float fixedPointSpeedScale = 256.0f;

	//
	// TES3::AnimationDataVanilla
	//

	const auto TES3_AnimationData_ctor = reinterpret_cast<void(__thiscall*)(AnimationDataVanilla*)>(0x46B7A0);
	AnimationDataVanilla* AnimationDataVanilla::ctor() {
		// Call original function.
		TES3_AnimationData_ctor(this);

		// Initialize custom data.
		patchedCastSpeed = (unsigned short)(1 * fixedPointSpeedScale);

		return this;
	}

	const auto TES3_AnimationData_calcAnimRootMovement = reinterpret_cast<void(__thiscall*)(AnimationDataVanilla*, unsigned char)>(0x46FD80);
	void AnimationDataVanilla::calcAnimRootMovement(unsigned char animGroup) {
		TES3_AnimationData_calcAnimRootMovement(this, animGroup);
	}

	const auto TES3_AnimationData_playAnimationGroupForIndex = reinterpret_cast<void(__thiscall*)(AnimationDataVanilla*, int, int, int, int)>(0x470AE0);
	void AnimationDataVanilla::playAnimationGroupForIndex(int animationGroup, int bodySection, int startFlag, int loopCount) {
		if (mwse::lua::event::PlayAnimationGroupEvent::getEventEnabled()) {
			auto stateHandle = mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle();
			sol::object response = stateHandle.triggerEvent(new mwse::lua::event::PlayAnimationGroupEvent(reinterpret_cast<AnimationData*>(this), animationGroup, bodySection, startFlag, loopCount));
			if (response.get_type() == sol::type::table) {
				sol::table eventData = response;

				// Allow event blocking.
				if (eventData.get_or("block", false)) {
					return;
				}

				// Allow overrides.
				animationGroup = eventData.get_or("group", animationGroup);
				startFlag = eventData.get_or("flags", startFlag);
				loopCount = eventData.get_or("loopCount", loopCount);
			}
		}

		TES3_AnimationData_playAnimationGroupForIndex(this, animationGroup, bodySection, startFlag, loopCount);
	}

	const auto TES3_AnimationData_mergeAnimGroups = reinterpret_cast<void(__thiscall*)(AnimationDataVanilla*, AnimationGroup*, int)>(0x4708D0);
	void AnimationDataVanilla::mergeAnimGroups(AnimationGroup* firstGroup, int layerIndex) {
		TES3_AnimationData_mergeAnimGroups(this, firstGroup, layerIndex);
	}

	const auto TES3_AnimationData_setHeadNode = reinterpret_cast<void(__thiscall*)(AnimationDataVanilla*, NI::Node*)>(0x4704B0);
	void AnimationDataVanilla::setHeadNode(NI::Node* head) {
		TES3_AnimationData_setHeadNode(this, head);
	}

	const auto TES3_AnimationData_setLayerKeyframes = reinterpret_cast<bool(__thiscall*)(AnimationDataVanilla*, KeyframeDefinition*, int, bool)>(0x46BA30);
	bool AnimationDataVanilla::setLayerKeyframes(KeyframeDefinition* kfData, int layerIndex, bool isBiped) {
		return TES3_AnimationData_setLayerKeyframes(this, kfData, layerIndex, isBiped);
	}

	const auto TES3_AnimationData_updateMovementDelta = reinterpret_cast<bool(__thiscall*)(AnimationDataVanilla*, float, Vector3*, bool)>(0x470320);
	void AnimationDataVanilla::updateMovementDelta(float timing, Vector3 *inout_startingPosition, bool dontUpdatePositionDelta) {
		TES3_AnimationData_updateMovementDelta(this, timing, inout_startingPosition, dontUpdatePositionDelta);
	}

	Reference* AnimationDataVanilla::getReference() const {
		if (actorNode) {
			return actorNode->getTes3Reference(false);
		}
		return nullptr;
	}

	void AnimationDataVanilla::playAnimationGroup(int animationGroup, int startFlag, int loopCount) {
		playAnimationGroupForIndex(animationGroup, 0, startFlag, loopCount);
		playAnimationGroupForIndex(animationGroup, 1, startFlag, loopCount);
		playAnimationGroupForIndex(animationGroup, 2, startFlag, loopCount);
	}

	bool AnimationDataVanilla::setOverrideLayerKeyframes(KeyframeDefinition* kfData) {
		constexpr int specialLayerIndex = 0;
		bool success = setLayerKeyframes(kfData, specialLayerIndex, true);
		if (success) {
			mergeAnimGroups(kfData->animationGroup, specialLayerIndex);
		}
		return success;
	}

	bool AnimationDataVanilla::hasOverrideAnimations() const {
		return keyframeLayers[0].lower != nullptr;
	}

	void AnimationDataVanilla::swapAnimationGroups(int animationGroup1, int animationGroup2) {
		// Swap all animation group specific data.
		std::swap(animationGroups[animationGroup1], animationGroups[animationGroup2]);
		std::swap(animGroupLayerIndices[animationGroup1], animGroupLayerIndices[animationGroup2]);
		std::swap(animGroupSoundGens[animationGroup1], animGroupSoundGens[animationGroup2]);
		std::swap(animGroupSoundGenCounts[animationGroup1], animGroupSoundGenCounts[animationGroup2]);
		std::swap(approxRootTravelDistances[animationGroup1], approxRootTravelDistances[animationGroup2]);

		// Fix up timing and sequence activation if the swap affects the currently playing animation.
		for (int i = 0; i < 3; ++i) {
			auto group = currentAnimGroup[i];
			auto sequenceGroup = &this->keyframeLayers[i].lower;

			if (group == animationGroup1 || group == animationGroup2) {
				// Reset timing to the start of the current action.
				timing[i] = animationGroups[group]->actionTimings[currentActionIndices[i]];

				if (currentAnimGroupLayer[i] != animGroupLayerIndices[group]) {
					manager->deactivateSequence(sequenceGroup[currentAnimGroupLayer[i]]);
					manager->activateSequence(sequenceGroup[animGroupLayerIndices[group]]);
					currentAnimGroupLayer[i] = animGroupLayerIndices[group];
				}
			}
		}

		// Fix up movement root if the swap affects the currently playing animation.
		auto lowerGroup = currentAnimGroup[0];
		if (lowerGroup == animationGroup1 || lowerGroup == animationGroup2) {
			Vector3 unused;
			updateMovementDelta(timing[0], &unused, true);
		}
	}

	float AnimationDataVanilla::getCastSpeed() const {
		return patchedCastSpeed / fixedPointSpeedScale;
	}

	void AnimationDataVanilla::setCastSpeed(float speed) {
		speed = std::max(0.0f, std::min(255.0f, speed));
		patchedCastSpeed = (unsigned short)(speed * fixedPointSpeedScale);

		// Update current animation speed if currently casting.
		constexpr unsigned char spellCastAnimID = 0x80;
		if (currentAnimGroup[1] == spellCastAnimID) {
			// Ensure non-zero weaponSpeed to bypass the actor controller resetting the value on zero.
			weaponSpeed = speed + FLT_MIN;
		}
	}

	std::reference_wrapper<decltype(AnimationDataVanilla::currentAnimGroup)> AnimationDataVanilla::getCurrentAnimGroups() {
		return std::ref(currentAnimGroup);
	}

	std::reference_wrapper<decltype(AnimationDataVanilla::currentActionIndices)> AnimationDataVanilla::getCurrentActionIndices() {
		return std::ref(currentActionIndices);
	}

	std::reference_wrapper<decltype(AnimationDataVanilla::loopCounts)> AnimationDataVanilla::getLoopCounts() {
		return std::ref(loopCounts);
	}

	std::reference_wrapper<decltype(AnimationDataVanilla::timing)> AnimationDataVanilla::getTimings() {
		return std::ref(timing);
	}

	std::reference_wrapper<decltype(AnimationDataVanilla::animationGroups)> AnimationDataVanilla::getAnimationGroups() {
		return std::ref(animationGroups);
	}

	std::reference_wrapper<decltype(AnimationDataVanilla::keyframeLayers)> AnimationDataVanilla::getKeyframeLayers() {
		return std::ref(keyframeLayers);
	}

	std::reference_wrapper<decltype(AnimationDataVanilla::currentAnimGroupLayer)> AnimationDataVanilla::getCurrentAnimGroupLayers() {
		return std::ref(currentAnimGroupLayer);
	}

	std::reference_wrapper<decltype(AnimationDataVanilla::animGroupLayerIndices)> AnimationDataVanilla::getAnimGroupLayerIndices() {
		return std::ref(animGroupLayerIndices);
	}

	std::reference_wrapper<decltype(AnimationDataVanilla::approxRootTravelDistances)> AnimationDataVanilla::getApproxRootTravelDistances() {
		return std::ref(approxRootTravelDistances);
	}

	std::reference_wrapper<decltype(AnimationDataVanilla::currentSoundGenIndices)> AnimationDataVanilla::getCurrentSoundGenIndices() {
		return std::ref(currentSoundGenIndices);
	}

	std::reference_wrapper<decltype(AnimationDataVanilla::animGroupSoundGenCounts)> AnimationDataVanilla::getAnimGroupSoundGenCounts() {
		return std::ref(animGroupSoundGenCounts);
	}

	std::reference_wrapper<decltype(AnimationDataVanilla::animGroupSoundGens)> AnimationDataVanilla::getAnimGroupSoundGens() {
		return std::ref(animGroupSoundGens);
	}

	//
	// TES3::AnimationData
	//

	AnimationData* AnimationData::ctor() {
		// Call base class ctor.
		AnimationDataVanilla::ctor();

		// Finish construction of new members.
		::new (&customLayers) decltype(customLayers);
		::new (&customAnims) decltype(customAnims);

		// Ensure there are 3 initial layers to match vanilla.
		// customLayers elements are zeroed by the SequenceGroup ctor.
		customLayers.resize(VanillaLayerCount);
		customAnims.resize(VanillaLayerCount);
		std::fill(customAnims.begin(), customAnims.end(), nullptr);

		// Set vanilla sequence pointers to some obvious junk data to catch accesses.
		memset(keyframeLayers, 0xCD, sizeof(keyframeLayers));

		return this;
	}

	const auto TES3_AnimationData_dtor = reinterpret_cast<void(__thiscall*)(AnimationData*)>(0x46B830);
	void AnimationData::dtor() {
		const auto NI_Sequence_deleting_dtor = reinterpret_cast<void(__thiscall*)(NI::Sequence*, char)>(0x4F05E0);

		// Clean up all sequences.
		if (manager) {
			manager->deactivateAll();
			manager->removeAll();
		}
		for (auto& layer : customLayers) {
			if (layer.lower) {
				NI_Sequence_deleting_dtor(layer.lower, 1);
			}
			if (layer.upper) {
				NI_Sequence_deleting_dtor(layer.upper, 1);
			}
			if (layer.leftArm) {
				NI_Sequence_deleting_dtor(layer.lower, 1);
			}
		}

		// Release loaded animations.
		auto modelLoader = DataHandler::get()->nonDynamicData->meshData;
		for (int i = VanillaLayerCount; i < customAnims.size(); ++i) {
			if (customAnims[i]) {
				modelLoader->releaseKeyframes(customAnims[i]);
			}
		}
		
		// Destruction of new members.
		customAnims.~vector();
		customLayers.~vector();

		// Set vanilla sequence pointers to zero before dtor.
		memset(keyframeLayers, 0, sizeof(keyframeLayers));

		// Call base dtor.
		TES3_AnimationData_dtor(this);
	}

	bool AnimationData::setLayerKeyframes(KeyframeDefinition* kfData, int layerIndex, bool isBiped) {
		if (layerIndex >= customAnims.size()) {
			// Allocate space for the new layer. The engine will write to the sequence group for the layer.
			customAnims.resize(layerIndex + 1);
			customLayers.resize(layerIndex + 1);
		}

		// Store anim source. This is read by extension code inside setLayerKeyframes.
		customAnims[layerIndex] = kfData;

		return TES3_AnimationData_setLayerKeyframes(this, kfData, layerIndex, isBiped);
	}

	bool AnimationData::addCustomAnim(KeyframeDefinition* kfData) {
		if (std::find(customAnims.cbegin(), customAnims.cend(), kfData) != customAnims.cend()) {
			return false;
		}

		int layer = customAnims.size();
		bool isBiped = customLayers[BaseAnimLayerIndex].upper != nullptr;

		// Call layer setup function that will add to customAnims and customLayers.
		kfData->refCount++;
		setLayerKeyframes(kfData, layer, isBiped);
		return true;
	}

	bool AnimationData::applyCustomAnim(const char* name) {
		auto iter = std::find_if(customAnims.begin(), customAnims.end(),
			[name](TES3::KeyframeDefinition* anim) { return anim && std::strcmp(anim->filename, name) == 0; }
		);
		if (iter == customAnims.end()) {
			return false;
		}
		int layer = iter - customAnims.begin();
		auto kfData = *iter;

		// Disable sequences from current active layers.
		for (int i = 0; i < BodySectionCount; ++i) {
			auto l = currentAnimGroupLayer[i];
			if (l != -1) {
				auto seqGrp = &customLayers[l].lower;
				manager->deactivateSequence(seqGrp[i]);
			}
		}

		// Merge in groups from this anim.
		mergeAnimGroups(kfData->animationGroup, layer);

		// Reset timing for any currently running anims using new data.
		for (int i = 0; i < BodySectionCount; ++i) {
			auto group = currentAnimGroup[i];
			if (animGroupLayerIndices[group] == layer && currentAnimGroupLayer[i] != layer) {
				currentAnimGroupLayer[i] = layer;
				timing[i] = animationGroups[group]->actionTimings[currentActionIndices[i]];
			}
		}

		// Enable sequences for new active layers.
		for (int i = 0; i < BodySectionCount; ++i) {
			auto l = currentAnimGroupLayer[i];
			if (l != -1) {
				auto seqGrp = &customLayers[l].lower;
				manager->activateSequence(seqGrp[i]);
			}
		}

		// Fix up movement root after modification by TES3_AnimationData_mergeAnimGroups.
		TES3::Vector3 unused;
		updateMovementDelta(timing[0], &unused, true);

		return true;
	}

	bool AnimationData::removeCustomAnim(const char* name) {
		// TODO: Implement.
		return false;
	}

	void AnimationData::resetCustomAnims() {
		// Disable sequences from current active layers.
		for (int i = 0; i < BodySectionCount; ++i) {
			auto l = currentAnimGroupLayer[i];
			if (l != -1) {
				auto seqGrp = &customLayers[l].lower;
				manager->deactivateSequence(seqGrp[i]);
			}
		}

		// Merge in vanilla animations in order.
		for (int layer = BaseAnimLayerIndex; layer >= 0; --layer) {
			if (customAnims[layer]) {
				mergeAnimGroups(customAnims[layer]->animationGroup, layer);
			}
		}

		// Reset timing for any currently running anims using new data.
		for (int i = 0; i < BodySectionCount; ++i) {
			auto group = currentAnimGroup[i];
			if (currentAnimGroupLayer[i] != animGroupLayerIndices[group]) {
				currentAnimGroupLayer[i] = animGroupLayerIndices[group];
				timing[i] = animationGroups[group]->actionTimings[currentActionIndices[i]];
			}
		}

		// Enable sequences for new active layers.
		for (int i = 0; i < BodySectionCount; ++i) {
			auto l = currentAnimGroupLayer[i];
			if (l != -1) {
				auto seqGrp = &customLayers[l].lower;
				manager->activateSequence(seqGrp[i]);
			}
		}

		// Fix up movement root after modification by TES3_AnimationData_mergeAnimGroups.
		TES3::Vector3 unused;
		updateMovementDelta(timing[0], &unused, true);
	}

	std::reference_wrapper<decltype(AnimationData::customLayers)> AnimationData::getKeyframeLayers() {
		return std::ref(customLayers);
	}

	std::reference_wrapper<decltype(AnimationData::customAnims)> AnimationData::getAnimations() {
		return std::ref(customAnims);
	}

	//
	// Patch: Extended animation system.
	//

	__declspec(naked) NI::Sequence* addData_getLowerGroup() {
		__asm {
			mov edx, [esi + 0x7E4]	// edx = esi->customLayers.begin
			lea eax, [edi + edi*2]
			mov eax, [edx + eax*4]	// eax = (edx + edi * sizeof(SequenceGroup))->lower
			ret
		}
	}
	__declspec(naked) void patchAddData() {
		__asm {
			test eax, eax
		}
	}
	const size_t patchAddData_size = 0x2;

	__declspec(naked) AnimationDataVanilla::SequenceGroup* setLayerKeyFrames_getSequenceGroup() {
		__asm {
			mov ebp, [esi + 0x7E4]	// ebp = esi->customLayers.begin
			lea eax, [edi + edi*2]
			lea ebp, [ebp + eax*4]	// ebp = ebp + edi * sizeof(SequenceGroup)
			ret
		}
	}
	__declspec(naked) void patchSetLayerKeyFrames1() {
		__asm {
			mov eax, [ebp + 4]		// eax = sequenceGroup.upper
		}
	}
	const size_t patchSetLayerKeyFrames1_size = 0x3;
	__declspec(naked) void patchSetLayerKeyFrames2() {
		__asm {
			nop
			nop
			nop
			mov ecx, [ebp + 8]		// ecx = sequenceGroup.leftArm
		}
	}
	const size_t patchSetLayerKeyFrames2_size = 0x6;

	const BYTE patchLinkAnimSequences1[] = {
		0x74, 0x0B		// jmp short
	};
	const size_t patchLinkAnimSequences1_size = 0x2;
	__declspec(naked) void patchLinkAnimSequences2() {
		__asm {
			add esp, 8
			mov edx, [esp + 0x40]		// mov edx, [esp+layerIndex]
			lea ecx, [edx + edx*2]
			add ecx, edi				// ecx += sectionIndex
			mov edx, [esp + 0x24]		// mov edx, [esp+this]
			mov edx, [edx + 0x7E4]		// edx = edx->customLayers.begin
			mov [edx + ecx*4], eax		// *sequence = eax
			jmp $ + 0x16				// jump to end of loop
		}
	}
	const size_t patchLinkAnimSequences2_size = 0x1E;

	__declspec(naked) NI::Sequence* update_getUpperSequence() {
		__asm {
			mov ecx, [ebp + 0x7E4]	// ecx = ebp->customLayers.begin
			lea edx, [eax + eax*2 + 1]
			mov eax, [ecx + edx*4]	// eax = (ecx + eax * sizeof(SequenceGroup))->upper
			ret
		}
	}
	__declspec(naked) NI::Sequence* update_getLeftArmSequence() {
		__asm {
			mov ecx, [ebp + 0x7E4]	// ecx = ebp->customLayers.begin
			lea edx, [eax + eax*2 + 2]
			mov eax, [ecx + edx*4]	// eax = (ecx + eax * sizeof(SequenceGroup))->leftArm
			ret
		}
	}

	__declspec(naked) NI::Sequence* checkAnimGroupMovementConstraints_getLowerSequence() {
		__asm {
			mov ecx, [esi + 0x7E4]	// ecx = esi->customLayers.begin
			lea eax, [eax + eax*2]
			mov ecx, [ecx + eax*4]	// ecx = (ecx + eax * sizeof(SequenceGroup))->lower
			ret
		}
	}
	__declspec(naked) void patchCheckAnimGroupMovementConstraints() {
		__asm {
			test ecx, ecx
		}
	}
	const size_t patchCheckAnimGroupMovementConstraints_size = 0x2;

	__declspec(naked) NI::Sequence* setSequencePlayback_getSequence() {
		__asm {
			mov ecx, [esi + 0x7E4]	// ecx = esi->customLayers.begin
			lea eax, [eax + eax*2]
			add eax, edi
			mov eax, [ecx + eax*4]	// eax = *(ecx + eax * sizeof(SequenceGroup) + edi * sizeof(NI::Sequence*))
			ret
		}
	}
	__declspec(naked) NI::Sequence* patchSetSequencePlayback_getSequence() {
		__asm {
			mov eax, ebp			// eax = layerIndex
		}
	}
	const size_t patchSetSequencePlayback_getSequence_size = 2;
	__declspec(naked) NI::Sequence* setSequencePlayback_getUpperSequence() {
		__asm {
			mov ecx, [esi + 0x7E4]	// ecx = esi->customLayers.begin
			lea edx, [eax + eax*2 + 1]
			mov eax, [ecx + edx*4]	// eax = (ecx + eax * sizeof(SequenceGroup))->upper
			ret
		}
	}
	__declspec(naked) NI::Sequence* setSequencePlayback_getLeftArmSequence() {
		__asm {
			mov ecx, [esi + 0x7E4]	// ecx = esi->customLayers.begin
			lea edx, [eax + eax*2 + 2]
			mov eax, [ecx + edx*4]	// eax = (ecx + eax * sizeof(SequenceGroup))->leftArm
			ret
		}
	}

	__declspec(naked) NI::Sequence* setAnimationStateDirect_getSequence() {
		__asm {
			mov ecx, [esi + 0x7E4]	// ecx = esi->customLayers.begin
			lea eax, [eax + eax*2]
			add eax, edi
			mov eax, [ecx + eax*4]	// eax = *(ecx + eax * sizeof(SequenceGroup) + edi * sizeof(NI::Sequence*))
			ret
		}
	}
	__declspec(naked) NI::Sequence* patchSetAnimationStateDirect() {
		__asm {
			mov eax, ebx			// eax = layerIndex
			nop
		}
	}
	const size_t patchSetAnimationStateDirect_size = 3;

	const auto NI_Sequence_ctor = reinterpret_cast<NI::Sequence* (__thiscall*)(NI::Sequence*, const char*, unsigned int, unsigned int)>(0x70F470);
	const auto TES3_animationSequenceNames = reinterpret_cast<const char**>(0x7889CC);
	NI::Sequence* __fastcall splitBodySectionSequences_newSequence(AnimationData* _this, DWORD _EDX_, NI::Sequence* seq, int bodySection, int layerIndex) {
		// Sequences require unique names, or their controllers will silently fail to activate.
		if (layerIndex < VanillaLayerCount) {
			// Vanilla naming.
			auto name = TES3_animationSequenceNames[layerIndex * BodySectionCount + bodySection];
			return NI_Sequence_ctor(seq, name, 1, 1);
		}
		else {
			// Custom naming.
			auto kfData = _this->customAnims.at(layerIndex);
			auto sectionName = TES3_animationSequenceNames[bodySection] + 0xD;
			char buffer[240];
			std::snprintf(buffer, sizeof(buffer), "%s (%s)", kfData->filename, sectionName);
			return NI_Sequence_ctor(seq, buffer, 1, 1);
		}
	}
	__declspec(naked) NI::Sequence* patchSplitBodySectionSequences() {
		__asm {
			push ecx				// push layerIndex
			push edx				// push bodySection
			push eax				// push new sequence
			mov ecx, [esp + 0x30]	// set up thiscall
			jmp $ + 0xC				// jmp to call
		}
	}
	const size_t patchSplitBodySectionSequences_size = 0xC;

	//
	// Patch: Allow changing cast animation speed. Custom speed is read and applied on initial cast.
	//

#pragma warning(push)
#pragma warning(disable: 4102)
	__declspec(naked) bool patchApplyAnimationSpeed() {
		__asm {
			fld [ebp + 0x64]		// ebp->AnimationData.deltaTime

		isMovementAnim:
			cmp cl, 0x2B			// AnimGroup_SwimWalkForward
			jb isWeaponAnim
			cmp cl, 0x7F			// AnimGroup_Jump2w
			ja isWeaponAnim
		movement:
			fmul [ebp + 0x4D8]		// * ebp->AnimationData.movementSpeed
			jmp done

		isWeaponAnim:
			cmp cl, 0x80			// AnimGroup_SpellCast (added test)
			je weapon
			cmp cl, 0x83			// AnimGroup_Attack1 (added creature and h2h attacks)
			jb done
			cmp cl, 0x8F			// AnimGroup_WeaponTwoWide
			ja done
		weapon:
			fmul [ebp + 0x4DC]		// * ebp->AnimationData.weaponSpeed
			nop
			nop
			nop
		done:
		}
	}
	const size_t patchApplyAnimationSpeed_size = 0x2D;
#pragma warning(pop)

	void __fastcall SetAnimSpeedOnCast(TES3::AnimationData* animData) {
		// Ensure non-zero weaponSpeed to bypass the actor controller resetting the value on zero.
		animData->weaponSpeed = animData->getCastSpeed() + FLT_MIN;
	}


	void AnimationData::patch() {
		using mwse::genCallEnforced;
		using mwse::genCallUnprotected;
		using mwse::genNOPUnprotected;
		using mwse::writeDoubleWordUnprotected;
		using mwse::writePatchCodeUnprotected;

		// Override AnimationData creation with MWSE extended struct.
		auto AnimationDataExtended_ctor = &AnimationData::ctor;
		writeDoubleWordUnprotected(0x4E6386 + 1, sizeof(AnimationData));
		genCallEnforced(0x4E63A5, 0x46B7A0, *reinterpret_cast<DWORD*>(&AnimationDataExtended_ctor));
		writeDoubleWordUnprotected(0x4E64C7 + 1, sizeof(AnimationData));
		genCallEnforced(0x4E64E6, 0x46B7A0, *reinterpret_cast<DWORD*>(&AnimationDataExtended_ctor));
		writeDoubleWordUnprotected(0x4E6747 + 1, sizeof(AnimationData));
		genCallEnforced(0x4E6766, 0x46B7A0, *reinterpret_cast<DWORD*>(&AnimationDataExtended_ctor));
		writeDoubleWordUnprotected(0x4E69CD + 1, sizeof(AnimationData));
		genCallEnforced(0x4E69EC, 0x46B7A0, *reinterpret_cast<DWORD*>(&AnimationDataExtended_ctor));
		writeDoubleWordUnprotected(0x4E6C42 + 1, sizeof(AnimationData));
		genCallEnforced(0x4E6C5F, 0x46B7A0, *reinterpret_cast<DWORD*>(&AnimationDataExtended_ctor));

		auto AnimationDataExtended_dtor = &AnimationData::dtor;
		genCallEnforced(0x4E46E7, 0x46B830, *reinterpret_cast<DWORD*>(&AnimationDataExtended_dtor));
		genCallEnforced(0x4E4C88, 0x46B830, *reinterpret_cast<DWORD*>(&AnimationDataExtended_dtor));
		genCallEnforced(0x4E6852, 0x46B830, *reinterpret_cast<DWORD*>(&AnimationDataExtended_dtor));
		genCallEnforced(0x4E6E03, 0x46B830, *reinterpret_cast<DWORD*>(&AnimationDataExtended_dtor));
		genCallEnforced(0x4E893D, 0x46B830, *reinterpret_cast<DWORD*>(&AnimationDataExtended_dtor));

		// Patch: Allow changing cast animation speed. Custom speed is read and applied on initial cast.
		mwse::writePatchCodeUnprotected(0x46CAC0, (BYTE*)&patchApplyAnimationSpeed, patchApplyAnimationSpeed_size);
		genCallUnprotected(0x541B81, reinterpret_cast<DWORD>(&SetAnimSpeedOnCast), 0xA);

		// Patch every setLayerKeyframes call.
		auto AnimationDataExtended_setLayerKeyframes = &AnimationData::setLayerKeyframes;
		genCallEnforced(0x46B9FA, 0x46BA30, *reinterpret_cast<DWORD*>(&AnimationDataExtended_setLayerKeyframes));
		genCallEnforced(0x4E644C, 0x46BA30, *reinterpret_cast<DWORD*>(&AnimationDataExtended_setLayerKeyframes));
		genCallEnforced(0x4E6808, 0x46BA30, *reinterpret_cast<DWORD*>(&AnimationDataExtended_setLayerKeyframes));
		genCallEnforced(0x4E68F7, 0x46BA30, *reinterpret_cast<DWORD*>(&AnimationDataExtended_setLayerKeyframes));
		genCallEnforced(0x4E699D, 0x46BA30, *reinterpret_cast<DWORD*>(&AnimationDataExtended_setLayerKeyframes));
		genCallEnforced(0x4E6AA7, 0x46BA30, *reinterpret_cast<DWORD*>(&AnimationDataExtended_setLayerKeyframes));
		genCallEnforced(0x4E6B05, 0x46BA30, *reinterpret_cast<DWORD*>(&AnimationDataExtended_setLayerKeyframes));
		genCallEnforced(0x4E6B4B, 0x46BA30, *reinterpret_cast<DWORD*>(&AnimationDataExtended_setLayerKeyframes));
		genCallEnforced(0x4E6BA0, 0x46BA30, *reinterpret_cast<DWORD*>(&AnimationDataExtended_setLayerKeyframes));

		// Patch every keyframeLayers access.
		genCallUnprotected(0x46B979, reinterpret_cast<DWORD>(addData_getLowerGroup), 0x9);
		writePatchCodeUnprotected(0x46B982, reinterpret_cast<BYTE*>(patchAddData), patchAddData_size);

		genCallUnprotected(0x46BA50, reinterpret_cast<DWORD>(setLayerKeyFrames_getSequenceGroup), 0xA);
		genNOPUnprotected(0x46BAAE, 0xA);
		writePatchCodeUnprotected(0x46BAB8, reinterpret_cast<BYTE*>(patchSetLayerKeyFrames1), patchSetLayerKeyFrames1_size);
		writePatchCodeUnprotected(0x46BAC1, reinterpret_cast<BYTE*>(patchSetLayerKeyFrames2), patchSetLayerKeyFrames2_size);

		writePatchCodeUnprotected(0x46BCF2, patchLinkAnimSequences1, patchLinkAnimSequences1_size);
		writePatchCodeUnprotected(0x46BCFC, reinterpret_cast<BYTE*>(patchLinkAnimSequences2), patchLinkAnimSequences2_size);

		genCallUnprotected(0x46CA17, reinterpret_cast<DWORD>(update_getUpperSequence), 0xA);
		genCallUnprotected(0x46CA33, reinterpret_cast<DWORD>(update_getLeftArmSequence), 0xA);
		genCallUnprotected(0x46E68A, reinterpret_cast<DWORD>(update_getUpperSequence), 0xA);
		genCallUnprotected(0x46E6B2, reinterpret_cast<DWORD>(update_getLeftArmSequence), 0xA);

		genCallUnprotected(0x46FDCB, reinterpret_cast<DWORD>(checkAnimGroupMovementConstraints_getLowerSequence), 0xA);
		writePatchCodeUnprotected(0x46FDD3, reinterpret_cast<BYTE*>(patchCheckAnimGroupMovementConstraints), patchCheckAnimGroupMovementConstraints_size);
		genCallUnprotected(0x46FEAE, reinterpret_cast<DWORD>(checkAnimGroupMovementConstraints_getLowerSequence), 0x9);
		genCallUnprotected(0x4700C0, reinterpret_cast<DWORD>(checkAnimGroupMovementConstraints_getLowerSequence), 0x9);
		genNOPUnprotected(0x470105, 0x3);
		genCallUnprotected(0x47010B, reinterpret_cast<DWORD>(checkAnimGroupMovementConstraints_getLowerSequence), 0x6);

		genCallUnprotected(0x470E22, reinterpret_cast<DWORD>(setSequencePlayback_getSequence), 0xB);
		genCallUnprotected(0x470E61, reinterpret_cast<DWORD>(setSequencePlayback_getSequence), 0xB);
		writePatchCodeUnprotected(0x470E7C, reinterpret_cast<BYTE*>(patchSetSequencePlayback_getSequence), patchSetSequencePlayback_getSequence_size);
		genCallUnprotected(0x470E7E, reinterpret_cast<DWORD>(setSequencePlayback_getSequence), 0x9);
		genCallUnprotected(0x4718F1, reinterpret_cast<DWORD>(setSequencePlayback_getUpperSequence), 0xA);
		writePatchCodeUnprotected(0x47190B, reinterpret_cast<BYTE*>(patchSetSequencePlayback_getSequence), patchSetSequencePlayback_getSequence_size);
		genCallUnprotected(0x47190D, reinterpret_cast<DWORD>(setSequencePlayback_getUpperSequence), 0x9);
		genCallUnprotected(0x471970, reinterpret_cast<DWORD>(setSequencePlayback_getLeftArmSequence), 0xA);
		writePatchCodeUnprotected(0x47198A, reinterpret_cast<BYTE*>(patchSetSequencePlayback_getSequence), patchSetSequencePlayback_getSequence_size);
		genCallUnprotected(0x47198C, reinterpret_cast<DWORD>(setSequencePlayback_getLeftArmSequence), 0x9);

		genCallUnprotected(0x471A84, reinterpret_cast<DWORD>(setAnimationStateDirect_getSequence), 0xB);
		writePatchCodeUnprotected(0x471A9F, reinterpret_cast<BYTE*>(patchSetAnimationStateDirect), patchSetAnimationStateDirect_size);
		genCallUnprotected(0x471AA2, reinterpret_cast<DWORD>(setAnimationStateDirect_getSequence), 0x8);

		// Patch sequence cloning to avoid out of bounds read + SequenceManager requires unique sequence names.
		writePatchCodeUnprotected(0x46BBC6, reinterpret_cast<BYTE*>(patchSplitBodySectionSequences), patchSplitBodySectionSequences_size);
		genCallUnprotected(0x46BBD9, reinterpret_cast<DWORD>(splitBodySectionSequences_newSequence));
	}

}
