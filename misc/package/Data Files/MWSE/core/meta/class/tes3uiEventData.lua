-- This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
-- More information: https://github.com/MWSE/MWSE/tree/master/docs

--- @meta
--- Contains information from a standard UI callback. This is the parameter passed to callbacks when using `:register`, `:registerBefore`, or `:registerAfter`.
--- @class tes3uiEventData
--- @field data0 number *Read-only*. Event-specific raw data values. For mouse events, these are the screen X and Y coordinates of the pointer. For keyboard events, data0 is the scan code.
--- @field data1 number *Read-only*. Event-specific raw data values. For mouse events, these are the screen X and Y coordinates of the pointer.
--- @field forwardSource tes3uiElement *Read-only*. No description yet available.
--- @field id number *Read-only*. The ID of the event that is being triggered.
--- @field relativeX number|nil *Read-only*. For mouse-related events, this is the relative horizontal position for the current element.
--- @field relativeY number|nil *Read-only*. For mouse-related events, this is the relative vertical position for the current element.
--- @field source tes3uiElement *Read-only*. The element that owns the event.
--- @field widget tes3uiElement *Read-only*. The widget element that the source belongs to, if the element is a sub-part of a widget. May not be accurate if the element is not a sub-part.
