#pragma once

#include "NIAVObject.h"

namespace NI {
	struct DynamicEffect : AVObject {
		bool enabled; // 0x90
		int index; // 0x94
		int unknown_0x98;
		int unknown_0x9C;
		int unknown_0xA0;
		int unknown_0xA4;
	};
	static_assert(sizeof(DynamicEffect) == 0xA8, "NI::DynamicEffect failed size validation");
}
