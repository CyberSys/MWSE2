#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"
#include "TES3MobileNPC.h"
#include "TES3Reference.h"

namespace mwse {
	class xGetBasePer : InstructionInterface_t {
	public:
		xGetBasePer();
		virtual float execute(VMExecuteInterface& virtualMachine);
	private:
		const float INVALID_VALUE = -1.0f;
	};

	static xGetBasePer xGetBasePerInstance;

	xGetBasePer::xGetBasePer() : mwse::InstructionInterface_t(OpCode::xGetBasePer) {}

	float xGetBasePer::execute(mwse::VMExecuteInterface& virtualMachine) {
		// Get the associated MACP record.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == nullptr) {
			if constexpr (DEBUG_MWSCRIPT_FUNCTIONS) {
				mwse::log::getLog() << "xGetBasePer: No reference provided." << std::endl;
			}
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		auto mobileObject = reference->getAttachedMobileActor();
		if (mobileObject == NULL) {
			if constexpr (DEBUG_MWSCRIPT_FUNCTIONS) {
				mwse::log::getLog() << "xGetBasePer: Could not find MACP record for reference." << std::endl;
			}
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		// Push the current value of that attribute.
		mwse::Stack::getInstance().pushFloat(mobileObject->attributes[TES3::Attribute::Personality].base);

		return 0.0f;
	}
}
