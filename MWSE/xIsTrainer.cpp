#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"
#include "TES3NPC.h"
#include "TES3Reference.h"
#include "TES3Class.h"


namespace mwse {
	class xIsTrainer : InstructionInterface_t {
	public:
		xIsTrainer();
		virtual float execute(VMExecuteInterface& virtualMachine);
	};

	static xIsTrainer xIsTrainerInstance;

	xIsTrainer::xIsTrainer() : mwse::InstructionInterface_t(OpCode::xIsTrainer) {}

	float xIsTrainer::execute(mwse::VMExecuteInterface& virtualMachine) {
		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
			if constexpr (DEBUG_MWSCRIPT_FUNCTIONS) {
				mwse::log::getLog() << "xIsTrader: Called on invalid reference." << std::endl;
			}
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		long npcServiceFlags = 0;
		long classServiceFlags = 0;

		// Get the gold based on the base record type.
		TES3::AIConfig* aiConfig = reference->baseObject->vTable.object->getAIConfig(reference->baseObject);
		if (aiConfig) {
			npcServiceFlags = aiConfig->merchantFlags & 0x00004000;

			// Get the class flags.
			TES3::Class* npcClass = reference->baseObject->vTable.object->getClass(reference->baseObject);
			if (npcClass) {
				npcServiceFlags = npcClass->services & 0x00004000;
			}
		}
		else {
			if constexpr (DEBUG_MWSCRIPT_FUNCTIONS) {
				mwse::log::getLog() << "xIsTrainer: Failed to get AI configuration for target." << std::endl;
			}
		}

		mwse::Stack::getInstance().pushLong(npcServiceFlags | classServiceFlags);

		return 0.0f;
	}
}
