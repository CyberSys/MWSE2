#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"
#include "TES3MobileNPC.h"
#include "TES3Skill.h"
#include "TES3Reference.h"

namespace mwse {
	class xGetBaseBlock : InstructionInterface_t {
	public:
		xGetBaseBlock();
		virtual float execute(VMExecuteInterface& virtualMachine);
	private:
		const float INVALID_VALUE = -1.0f;
	};

	static xGetBaseBlock xGetBaseBlockInstance;

	xGetBaseBlock::xGetBaseBlock() : mwse::InstructionInterface_t(OpCode::xGetBaseBlock) {}

	float xGetBaseBlock::execute(mwse::VMExecuteInterface& virtualMachine) {
		// Get the associated MACP record.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == nullptr) {
			if constexpr (DEBUG_MWSCRIPT_FUNCTIONS) {
				mwse::log::getLog() << "xGetBaseBlock: No reference provided." << std::endl;
			}
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		auto mobileObject = reference->getAttachedMobileNPC();
		if (mobileObject == NULL) {
			if constexpr (DEBUG_MWSCRIPT_FUNCTIONS) {
				mwse::log::getLog() << "xGetBaseBlock: Could not find MACP record for reference." << std::endl;
			}
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		// Push the base value of that skill.
		mwse::Stack::getInstance().pushFloat(mobileObject->skills[TES3::SkillID::Block].base);

		return 0.0f;
	}
}
