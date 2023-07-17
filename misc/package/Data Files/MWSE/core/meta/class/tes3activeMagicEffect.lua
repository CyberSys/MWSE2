-- This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
-- More information: https://github.com/MWSE/MWSE/tree/master/docs

--- @meta
--- Data about a magic effect currently active on a particular mobile actor. It is accessed from `tes3mobileActor.activeMagicEffectList`. The data is a subset of the full data from a `tes3magicEffectInstance`, but does not require extra lookups to access, making it faster to scan through an actor's magic effects.
--- @class tes3activeMagicEffect
--- @field attributeId integer *Read-only*. The attribute ID (note that this may be the skill ID if the effect affects skills, since `attributeId` and `skillId` properties are set to the same value by the engine). Maps to values from [`tes3.attribute`](https://mwse.github.io/MWSE/references/attributes/) table.
--- @field duration number *Read-only*. The total duration of this specific effect.
--- @field effectId integer *Read-only*. The magic effect ID. Maps to values from [`tes3.effect`](https://mwse.github.io/MWSE/references/magic-effects/) table.
--- @field effectIndex integer *Read-only*. The index of the effect inside the magic source instance.
--- @field effectInstance tes3magicEffectInstance *Read-only*. The magic effect instance for this effect.
--- @field harmful boolean *Read-only*. This flag that determines if this effect is counted as a hostile action.
--- @field instance tes3magicSourceInstance *Read-only*. The magic source instance for this effect.
--- @field isBoundItem boolean *Read-only*. If this effect has summoned a bound item.
--- @field isIllegalSummon boolean *Read-only*. If this effect has summoned a creature that has been declared illegal to summon. This is an otherwise unused flag in the game that is set for daedra and undead summon magic effects, but not for any other summon creature magic effects.
--- @field isSummon boolean *Read-only*. If this effect has summoned a creature.
--- @field magnitude integer *Read-only*. The unresisted magnitude of the magic effect, that is the magnitude before resistance attributes are applied. To find the actual effective magnitude after resistances are applied, you must check the magic effect instance.
--- @field magnitudeMin number *Read-only*. Deprecated.
--- @field mobile tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer|tes3mobilePlayer *Read-only*. The mobile affected by the magic effect.
--- @field next tes3activeMagicEffect *Read-only*. Deprecated.
--- @field previous tes3activeMagicEffect *Read-only*. Deprecated.
--- @field serial integer *Read-only*. The magic source instance serial number. See the `instance` and `effectInstance` properties to easily access the magic and effect instances.
--- @field skillId integer *Read-only*. The skill ID (note that this may be the attribute ID if the effect affects attributes, since `attributeId` and `skillId` properties are set to the same value by the engine). Maps to values in [`tes3.skill`](https://mwse.github.io/MWSE/references/skills/) table.
