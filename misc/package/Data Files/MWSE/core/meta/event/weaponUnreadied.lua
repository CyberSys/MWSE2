--- @meta
--- @diagnostic disable:undefined-doc-name

--- This event is called when a weapon is no longer readied, and pairs with the weaponReadied event. It can be used to reliably tell if a specific weapon is readied for attack. This does not necessarily mean that the animation state has changed for the first time. If an actor equips a weapon while having their hands up to attack with, the event will fire for the new weapon.
--- @class weaponUnreadiedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field reference tes3reference *Read-only*. The reference associated with the change in readied weapon.
