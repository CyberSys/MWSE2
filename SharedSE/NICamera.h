#pragma once

#include "NINode.h"
#include "NIRenderer.h"
#include "NIPlane.h"

namespace NI {
	struct Frustum {
		float left; // 0x0
		float right; // 0x4
		float top; // 0x8
		float bottom; // 0xC
		float near; // 0x10
		float far; // 0x14

		bool setFOV(float fovDegrees, float aspect);
	};
	static_assert(sizeof(Frustum) == 0x18, "NI::Frustum failed size validation");

	struct Camera : AVObject {
		float worldToCamera[4][4]; // 0x90
		float viewDistance; // 0xD0
		float twoDivRmL; // 0xD4
		float twoDivTmB; // 0xD8
		Vector3 worldDirection; // 0xDC
		Vector3 worldUp; // 0xE8
		Vector3 worldRight; // 0xF4
		Frustum viewFrustum; // 0x100
		Rect<float> port; // 0x118
		Pointer<Node> scene; // 0x128
		TArray<void*> unknown_0x12C; // Screen related?
		Pointer<Renderer> renderer; // 0x144
		TArray<void*> unknown_0x148; // Multiple cameras?
		int unknown_0x160;
		Plane cullingPlanes[6]; // 0x164
		float unknown_0x1C4;
		float unknown_0x1C8;
		float unknown_0x1CC;
		float unknown_0x1D0;
		void* unknown_0x1D4;
		int unknown_0x1D8;
		float LODAdjust; // 0x1DC

		Camera();
		~Camera();

		//
		// Other related this-call functions.
		//

		void clear(Renderer::ClearFlags flags = Renderer::ClearFlags::ALL);

		void click(bool something = false);
#if defined(SE_USE_LUA) && SE_USE_LUA == 1
		void click_lua(sol::optional<bool> something = false);
#endif

#if defined(SE_USE_LUA) && SE_USE_LUA == 1
		std::reference_wrapper<TES3::Vector4[6]> getCullingPlanes_lua();
#endif

		// Note: screen coordinates are real from the viewport, and not 
		bool windowPointToRay(int screenX, int screenY, Vector3& out_origin, Vector3& out_direction);
		bool worldPointToScreenPoint(const Vector3* point, float& out_screenX, float& out_screenY);

#if defined(SE_USE_LUA) && SE_USE_LUA == 1
		// Unlike above, we need to convert the ouput from [width/-2, width/2] to [0, width] and flip the height.
		sol::optional<std::tuple<TES3::Vector3, TES3::Vector3>> windowPointToRay_lua(sol::stack_object);

		// Unlike above, we need to convert the ouput from [0,1] to [width/-2, width/2].
		sol::optional<TES3::Vector2> worldPointToScreenPoint_lua(sol::stack_object);
#endif
	};
	static_assert(sizeof(Camera) == 0x1E0, "NI::Camera failed size validation");
}

#if defined(SE_USE_LUA) && SE_USE_LUA == 1
MWSE_SOL_CUSTOMIZED_PUSHER_DECLARE_NI(NI::Camera)
#endif
