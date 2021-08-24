--- @meta

--- This event is called when determining the cost of purchasing a spell. The price can be modified.
--- @class calcSpellPriceEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field basePrice number *Read-only*. The price before adjustment.
--- @field mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer *Read-only*. The mobile actor of the merchant the player is interacting with.
--- @field price number The adjusted price of spell.
--- @field reference tes3reference *Read-only*. mobile’s related reference.
--- @field spell tes3spell *Read-only*. The spell currently being purchased.