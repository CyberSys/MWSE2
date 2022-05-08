#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

namespace mwse {
	class xArcTan : InstructionInterface_t {
	public:
		xArcTan();
		virtual float execute(VMExecuteInterface& virtualMachine);
	};

	static xArcTan xArcTanInstance;

	xArcTan::xArcTan() : mwse::InstructionInterface_t(OpCode::xArcTan) {}

	float xArcTan::execute(mwse::VMExecuteInterface& virtualMachine) {
		mwse::Stack::getInstance().pushFloat(std::atan(mwse::Stack::getInstance().popFloat()));
		return 0.0f;
	}
}
