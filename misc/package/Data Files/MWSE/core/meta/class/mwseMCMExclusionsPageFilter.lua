-- This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
-- More information: https://github.com/MWSE/MWSE/tree/master/docs

--- @meta
--- The filters used in the Exclusions Page.
--- @class mwseMCMExclusionsPageFilter
--- @field callback nil|fun(): string[] A custom filter function. The callback function needs to return a string array of items that should appear in the list. To use callback, don't pass the `type` field, just `label` and `callback`.
--- @field label string The text shown on a button used to activate this filter on the Exclusions Page.
--- @field noScripted boolean|nil If set to true, no objects with a script will be added to the list.
--- @field objectFilters table<string, unknown>|nil If using "Object" filter, you can pass a dictionary-style table of fields and values that the objects need to satisfy to appear in the list.
--- @field objectType integer|integer[]|nil If using "Object" filter, pass the object types from [`tes3.objectType`](https://mwse.github.io/MWSE/references/object-types/) enumeration here.
--- @field type string|nil The filter type. Available options are:
--- 
--- - "Plugin" - The list will contain the currently loaded plugin list.
--- - "Object" - This filter will list objects.
--- 
--- Another option is to pass no `type`. Then, you can define custom `callback` function.
