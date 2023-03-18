-- This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
-- More information: https://github.com/MWSE/MWSE/tree/master/docs

--- @meta
--- This event is fired when an enchanted item has been created by the player.
--- @class enchantedItemCreatedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field baseObject tes3alchemy|tes3apparatus|tes3armor|tes3book|tes3clothing|tes3ingredient|tes3light|tes3lockpick|tes3misc|tes3probe|tes3repairTool|tes3weapon *Read-only*. The item originally enchanted.
--- @field enchanter tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer The mobile actor responsible for creating the enchantment.
--- @field enchanterReference tes3reference The reference responsible for creating the enchantment.
--- @field object tes3alchemy|tes3apparatus|tes3armor|tes3book|tes3clothing|tes3ingredient|tes3light|tes3lockpick|tes3misc|tes3probe|tes3repairTool|tes3weapon *Read-only*. The newly created and enchanted item.
--- @field soul tes3container|tes3containerInstance|tes3creature|tes3creatureInstance|tes3npc|tes3npcInstance The actor used to enchant the item.
--- @field soulGem tes3misc The soul gem used for the creation of the item.
