--- @meta
--- @diagnostic disable:undefined-doc-name

--- This event is called when an actor tries to jump. The velocity can be modified.
--- @class jumpEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer *Read-only*. The mobile actor that is trying to jump.
--- @field reference tes3reference *Read-only*. Mobile's related reference.
--- @field velocity tes3vector3 The velocity of the jump.
