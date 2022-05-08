#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

namespace mwse {
	class xGetRef : InstructionInterface_t
	{
	public:
		xGetRef();
		virtual float execute(VMExecuteInterface& virtualMachine);
	};

	static xGetRef xGetRefInstance;

	xGetRef::xGetRef() : InstructionInterface_t(OpCode::xGetRef) {}

	float xGetRef::execute(mwse::VMExecuteInterface& virtualMachine) {
		// Get the parameter.
		mwseString& id = virtualMachine.getString(Stack::getInstance().popLong());

		// Get its reference.
		TES3::Reference* ref = virtualMachine.getReference(id.c_str());

		// Push back as long.
		Stack::getInstance().pushLong((long)ref);

		return 0.0f;
	}
}
