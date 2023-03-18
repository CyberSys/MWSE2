-- This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
-- More information: https://github.com/MWSE/MWSE/tree/master/docs

--- @meta
--- This event is called when an actor’s movement speed is calculated. The event allows modification of this value, to dehardcode actor movement speeds. Invoked after all other movement speed events are finished.
--- 
--- The movement event flow is described below:
--- 
--- - Walking: [calcWalkSpeed](https://mwse.github.io/MWSE/events/calcWalkSpeed) -> **calcMoveSpeed**
--- - Running: [calcWalkSpeed](https://mwse.github.io/MWSE/events/calcWalkSpeed) -> [calcRunSpeed](https://mwse.github.io/MWSE/events/calcRunSpeed) -> **calcMoveSpeed**
--- - Swimming: [calcWalkSpeed](https://mwse.github.io/MWSE/events/calcWalkSpeed) -> [calcSwimSpeed](https://mwse.github.io/MWSE/events/calcSwimSpeed) -> **calcMoveSpeed**
--- - Swimming (while running): [calcWalkSpeed](https://mwse.github.io/MWSE/events/calcWalkSpeed) -> [calcSwimSpeed](https://mwse.github.io/MWSE/events/calcSwimSpeed) -> [calcSwimRunSpeed](https://mwse.github.io/MWSE/events/calcSwimRunSpeed) -> **calcMoveSpeed**
--- - Flying: [calcFlySpeed](https://mwse.github.io/MWSE/events/calcFlySpeed) -> **calcMoveSpeed**
---
--- [Examples available in online documentation](https://mwse.github.io/MWSE/events/calcMoveSpeed).
--- @class calcMoveSpeedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field mobile tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer *Read-only*. The mobile actor whose speed is being calculated.
--- @field reference tes3reference *Read-only*. mobile’s related reference.
--- @field speed number The previous speed calculated, starting with the base engine values.
--- @field type number *Read-only*. The type of movement that was calculated. This is always 0 for this event.
