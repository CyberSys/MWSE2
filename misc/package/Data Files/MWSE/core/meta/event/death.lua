--- @meta
--- @diagnostic disable:undefined-doc-name

--- This event triggers when an actor dies.
--- @class deathEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer *Read-only*. The mobile actor that has died.
--- @field reference tes3reference *Read-only*. mobile’s associated reference.
