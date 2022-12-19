-- This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
-- More information: https://github.com/MWSE/MWSE/tree/master/docs

--- @meta
--- @diagnostic disable:undefined-doc-name

--- uiEvent is triggered through various UI events. This includes scrolling through panes, clicking buttons, selecting icons, or a host of other UI-related activities.
--- @class uiEventEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field block tes3uiElement *Read-only*. *Deprecated, please use `source` instead*. The UI element that is firing this event.
--- @field parent tes3uiElement *Read-only*. The calling element's parent.
--- @field property number *Read-only*. The property identifier that is being triggered.
--- @field source tes3uiElement *Read-only*. The UI element that is firing this event.
--- @field var1 number *Read-only*. One of two undefined variables related to the event.
--- @field var2 number *Read-only*. One of two undefined variables related to the event.
