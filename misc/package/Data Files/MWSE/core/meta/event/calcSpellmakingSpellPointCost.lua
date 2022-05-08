--- @meta
--- @diagnostic disable:undefined-doc-name

--- This event is called when determining the spell point cost of making a spell. The spell point cost can be modified.
--- @class calcSpellmakingSpellPointCostEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer *Read-only*. The mobile actor of the spellmaking service npc the player is interacting with.
--- @field reference tes3reference *Read-only*. Mobile's related reference.
--- @field spellPointCost number The spell point cost of the spell.
