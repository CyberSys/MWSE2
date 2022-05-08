--- @meta
--- @diagnostic disable:undefined-doc-name

--- uiPreEvent is triggered through various UI events. This includes scrolling through panes, clicking buttons, selecting icons, or a host of other UI-related activities. This event fires before uiEvent, and has the additional advantage of being able to be blocked.
--- @class uiPreEventEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field parent tes3uiElement *Read-only*. The calling element's parent.
--- @field property number *Read-only*. The property identifier that is being triggered.
--- @field source tes3uiElement *Read-only*. The UI element that is firing this event.
--- @field var1 number *Read-only*. One of two undefined variables related to the event.
--- @field var2 number *Read-only*. One of two undefined variables related to the event.
