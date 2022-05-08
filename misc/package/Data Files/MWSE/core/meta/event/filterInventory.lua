--- @meta
--- @diagnostic disable:undefined-doc-name

--- This event fires when an item in the inventory is filtered.
--- @class filterInventoryEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field item tes3alchemy|tes3apparatus|tes3armor|tes3book|tes3clothing|tes3ingredient|tes3light|tes3lockpick|tes3misc|tes3probe|tes3repairTool|tes3weapon *Read-only*. The item being filtered.
--- @field itemData tes3itemData *Read-only*. The item data for the item being filtered.
--- @field tile tes3inventoryTile *Read-only*. The inventory tile being filtered.
