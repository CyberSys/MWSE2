--- @meta
--- @diagnostic disable:undefined-doc-name

--- This event is triggered just before a spell cast is resolved, at the end of the casting animation. It can control the success chance of the spell cast.
--- @class spellCastEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field castChance number The percentage chance of the caster successfully casting the spell. May be modified. Setting it to 0 will cause the cast to fail.
--- @field caster tes3reference *Read-only*. The caster of the spell.
--- @field source tes3spell *Read-only*. The magic source.
--- @field weakestSchool number *Read-only*. Of all the magic effects in the spell, there is a magic school which the caster has the lowest skill at casting. This school determines which skill will gain experience on a successful cast.
