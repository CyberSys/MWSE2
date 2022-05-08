#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"

#include "TES3DataHandler.h"
#include "TES3MagicEffect.h"

namespace mwse {
	class xSetBaseEffectInfo : InstructionInterface_t {
	public:
		xSetBaseEffectInfo();
		virtual float execute(VMExecuteInterface& virtualMachine);
	};

	static xSetBaseEffectInfo xSetBaseEffectInfoInstance;

	xSetBaseEffectInfo::xSetBaseEffectInfo() : mwse::InstructionInterface_t(OpCode::xSetBaseEffectInfo) {}

	float xSetBaseEffectInfo::execute(mwse::VMExecuteInterface& virtualMachine) {
		// Get parameters.
		long id = Stack::getInstance().popLong();
		long school = Stack::getInstance().popLong();
		float baseMagickaCost = Stack::getInstance().popFloat();
		long flags = Stack::getInstance().popLong();

		// Validate id.
		if (id < TES3::EffectID::FirstEffect || id > TES3::EffectID::LastEffect) {
			if constexpr (DEBUG_MWSCRIPT_FUNCTIONS) {
				log::getLog() << "xSetBaseEffectInfo: Effect ID out of range." << std::endl;
			}
			Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Validate school.
		if (school < TES3::MagicSchool::FirstMagicSchool || school > TES3::MagicSchool::LastMagicSchool) {
			if constexpr (DEBUG_MWSCRIPT_FUNCTIONS) {
				log::getLog() << "xSetBaseEffectInfo: School ID out of range." << std::endl;
			}
			Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		TES3::MagicEffect* effect = TES3::DataHandler::get()->nonDynamicData->getMagicEffect(id);
		effect->school = school;
		effect->baseMagickaCost = baseMagickaCost;

		// Flags are a unique case. We added extra information in xGetBaseEffectInfo. We
		// need to strip that back out here, and make sure only the right bits are set.
		// TODO: Programmatically allow setting/getting these normally hard-coded values.
		effect->flags = (flags & (TES3::EffectFlag::AllowSpellmaking | TES3::EffectFlag::AllowEnchanting | TES3::EffectFlag::NegativeLighting));

		Stack::getInstance().pushLong(true);

		return 0.0f;
	}
}
