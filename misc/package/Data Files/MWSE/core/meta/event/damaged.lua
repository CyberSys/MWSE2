--- @meta
--- @diagnostic disable:undefined-doc-name

--- The damaged event triggers after an actor has been damaged.
---
--- [Examples available in online documentation](https://mwse.github.io/MWSE/events/damaged).
--- @class damagedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field activeMagicEffect tes3magicEffect *Read-only*. Magic effect which caused damage. Can be `nil`.
--- @field attacker tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer *Read-only*. The mobile actor dealing the damage. Can be `nil`.
--- @field attackerReference tes3reference *Read-only*. The attacker mobile's associated reference. Can be `nil`.
--- @field damage number *Read-only*. The amount of damage done.
--- @field killingBlow boolean *Read-only*. If true, the damage killed the target.
--- @field magicEffectInstance tes3magicEffectInstance An instance of the magic effect in the spell that caused damage. Can be `nil`.
--- @field magicSourceInstance tes3magicSourceInstance A `tes3magicSourceInstance` object of a spell that caused damage. Can be `nil`.
--- @field mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer *Read-only*. The mobile actor that took damage.
--- @field projectile tes3mobileProjectile|tes3mobileSpellProjectile *Read-only*. Projectile that dealt the damage. Can be `nil`.
--- @field reference tes3reference *Read-only*. The mobile’s associated reference.
--- @field source string *Read-only*. The origin of damage. These damage sources are present as [`tes3.damageSource`](https://mwse.github.io/MWSE/references/damage-sources/) constants. See the example. Damage with `tes3.damageSource.shield` source comes from magic shields. Other sources are self-explanatory.
