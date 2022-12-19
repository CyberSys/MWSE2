-- This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
-- More information: https://github.com/MWSE/MWSE/tree/master/docs

--- @meta
--- @diagnostic disable:undefined-doc-name

--- A rendering property that manages alpha blending, enabling and disabling it, and setting blending functions. The property also affects alpha testing, which can provide a performance boost.
--- @class niAlphaProperty : niProperty, niObjectNET, niObject
--- @field alphaTestRef integer The reference value used for alpha testing. In range [0, 255].
niAlphaProperty = {}

--- Creates a new, niAlphaProperty, with the `alphaTestRef` set to 0.
--- @return niAlphaProperty property No description yet available.
function niAlphaProperty.new() end

