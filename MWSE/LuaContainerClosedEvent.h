#pragma once

#include "LuaObjectFilteredEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse::lua::event {
	class ContainerClosedEvent : public ObjectFilteredEvent, public DisableableEvent<ContainerClosedEvent> {
	public:
		ContainerClosedEvent(TES3::Reference* reference);
		sol::table createEventTable();

	protected:
		TES3::Reference* m_Reference;
	};
}
