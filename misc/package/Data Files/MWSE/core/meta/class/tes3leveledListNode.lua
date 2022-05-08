--- @meta
--- @diagnostic disable:undefined-doc-name

--- A simple collection that maps an object in a leveled list to a level required for that object to spawn.
--- @class tes3leveledListNode
--- @field levelRequired number The minimum level the player must meet before the node can be used.
--- @field object tes3activator|tes3alchemy|tes3apparatus|tes3armor|tes3bodyPart|tes3book|tes3clothing|tes3container|tes3containerInstance|tes3creature|tes3creatureInstance|tes3door|tes3ingredient|tes3leveledCreature|tes3leveledItem|tes3light|tes3lockpick|tes3misc|tes3npc|tes3npcInstance|tes3probe|tes3repairTool|tes3static|tes3weapon The item or creature that can be resolved.
tes3leveledListNode = {}

