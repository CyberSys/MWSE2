-- This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
-- More information: https://github.com/MWSE/MWSE/tree/master/docs

--- @meta
--- @diagnostic disable:undefined-doc-name

--- niParticlesData objects contain the geometry data necessary to render a niParticles object. When a niParticles-based object is created, the actual geometry data is stored in an attached niParticlesData object.
--- @class niParticlesData : niTriBasedGeometryData, niGeometryData, niObject
--- @field activeCount number *Read-only*. The number of active particles.
--- @field radius number *Read-only*. The radius of the particles.
--- @field sizes number[] *Read-only*. The particle sizes. The length of the array is equal to `vertexCount`.
niParticlesData = {}

