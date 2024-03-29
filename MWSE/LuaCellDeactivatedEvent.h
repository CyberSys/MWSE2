#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class CellDeactivatedEvent : public ObjectFilteredEvent, public DisableableEvent<CellDeactivatedEvent> {
	public:
		CellDeactivatedEvent(TES3::Cell* cell);
		sol::table createEventTable();

	protected:
		TES3::Cell* m_Cell;
	};
}
