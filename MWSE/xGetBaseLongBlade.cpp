/************************************************************************
	
	xGetBaseLongBlade.cpp - Copyright (c) 2008 The MWSE Project
	https://github.com/MWSE/MWSE/

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 2
	of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

**************************************************************************/

#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"
#include "TES3MACP.h"

using namespace mwse;

namespace mwse
{
	class xGetBaseLongBlade : mwse::InstructionInterface_t
	{
	public:
		xGetBaseLongBlade();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	private:
		const mwFloat INVALID_VALUE = -1.0f;
	};

	static xGetBaseLongBlade xGetBaseLongBladeInstance;

	xGetBaseLongBlade::xGetBaseLongBlade() : mwse::InstructionInterface_t(OpCode::xGetBaseLongBlade) {}

	void xGetBaseLongBlade::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetBaseLongBlade::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get the associated MACP record.
		TES3::Reference* reference = virtualMachine.getReference();
		TES3::MACP* macp = tes3::getAttachedMACPRecord(reference);
		if (macp == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetBaseLongBlade: Could not find MACP record for reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		// Push the base value of that skill.
		mwse::Stack::getInstance().pushFloat(macp->skills[TES3::SkillLongBlade].base);

		return 0.0f;
	}
}