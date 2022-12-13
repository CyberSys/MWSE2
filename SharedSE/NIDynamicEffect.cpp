#include "NIDynamicEffect.h"

#include "ExceptionUtil.h"

namespace NI {
	DynamicEffect::DynamicEffect() {
#if defined(SE_NI_DYNAMICEFFECT_FNADDR_CTOR) && SE_NI_DYNAMICEFFECT_FNADDR_CTOR > 0
		const auto NI_DynamicEffect_ctor = reinterpret_cast<void(__thiscall*)(DynamicEffect*)>(SE_NI_DYNAMICEFFECT_FNADDR_CTOR);
		NI_DynamicEffect_ctor(this);
#else
		throw not_implemented_exception();
#endif
	}

	DynamicEffect::~DynamicEffect() {
		// Call dtor without deletion.
		vTable.asObject->destructor(this, 0);
	}

	int DynamicEffect::getType() {
		return vTable.asDynamicEffect->getType(this);
	}

	void DynamicEffect::attachAffectedNode(Node* node) {
#if defined(SE_NI_DYNAMICEFFECT_FNADDR_ATTACHAFFECTEDNODE) && SE_NI_DYNAMICEFFECT_FNADDR_ATTACHAFFECTEDNODE > 0
		const auto NI_DynamicEffect_attachAffectedNode = reinterpret_cast<void(__thiscall*)(DynamicEffect*, Node*)>(SE_NI_DYNAMICEFFECT_FNADDR_ATTACHAFFECTEDNODE);
		NI_DynamicEffect_attachAffectedNode(this, node);
#else
		throw not_implemented_exception();
#endif
	}

	void DynamicEffect::detachAffectedNode(Node* node) {
#if defined(SE_NI_DYNAMICEFFECT_FNADDR_DETACHAFFECTEDNODE) && SE_NI_DYNAMICEFFECT_FNADDR_DETACHAFFECTEDNODE > 0
		const auto NI_DynamicEffect_detachAffectedNode = reinterpret_cast<void(__thiscall*)(DynamicEffect*, Node*)>(SE_NI_DYNAMICEFFECT_FNADDR_DETACHAFFECTEDNODE);
		NI_DynamicEffect_detachAffectedNode(this, node);
#else
		throw not_implemented_exception();
#endif
	}
}

#if defined(SE_USE_LUA) && SE_USE_LUA == 1
MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::DynamicEffect)
#endif
