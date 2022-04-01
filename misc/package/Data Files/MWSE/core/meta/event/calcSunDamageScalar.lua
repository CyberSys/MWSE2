--- @meta
--- @diagnostic disable:undefined-doc-name

--- calcSunDamageScalar is used when calculating the amount of damage to apply for the Sun Damage magic effect.
--- @class calcSunDamageScalarEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field damage number The previously calculated sun damage.
