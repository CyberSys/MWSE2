-- This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
-- More information: https://github.com/MWSE/MWSE/tree/master/docs

--- @meta
--- @diagnostic disable:undefined-doc-name

--- This modifer applies force, constant over time, to particles in the parent niParticleSystemController.
--- @class niGravity : niParticleModifier, niObject
--- @field decay number This value impacts how fast gravitational force attenuates with the distance from the source. A value of `0` causes no decay.
--- @field direction tes3vector3 The direction of action for planar gravity.
--- @field force number The magnitude of the gravitational force in [units/second](https://mwse.github.io/MWSE/references/other/game-units/).
--- @field forceType integer The type of the modifier. Planar force will attract the particles parallel to the `.direction` vector. Spherical force will act so that the point defined by `.position` property is the source of the spherical gravitational force.
--- 
--- Maps to values in [`ni.gravityForceType`](https://mwse.github.io/MWSE/references/ni/gravity-force-types/) table.
--- @field position tes3vector3 The position of the center used when applying spherical gravity.
niGravity = {}
