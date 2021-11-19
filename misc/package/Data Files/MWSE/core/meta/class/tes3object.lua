--- @meta

--- Almost anything that can be represented in the Construction Set is based on this structure.
--- @class tes3object : tes3baseObject
--- @field isLocationMarker boolean True if this object is an editor marker for a gameplay location. These include travel, intervention, prison, door, and interior north markers. Markers are invisible in-game.
--- @field nextInCollection tes3activator|tes3alchemy|tes3apparatus|tes3armor|tes3bodyPart|tes3book|tes3clothing|tes3container|tes3containerInstance|tes3creature|tes3creatureInstance|tes3door|tes3enchantment|tes3ingredient|tes3leveledCreature|tes3leveledItem|tes3light|tes3lockpick|tes3misc|tes3npc|tes3npcInstance|tes3probe|tes3reference|tes3repairTool|tes3spell|tes3static|tes3weapon The next object in parent collection's list.
--- @field owningCollection tes3referenceList The collection responsible for holding this object.
--- @field previousInCollection tes3activator|tes3alchemy|tes3apparatus|tes3armor|tes3bodyPart|tes3book|tes3clothing|tes3container|tes3containerInstance|tes3creature|tes3creatureInstance|tes3door|tes3enchantment|tes3ingredient|tes3leveledCreature|tes3leveledItem|tes3light|tes3lockpick|tes3misc|tes3npc|tes3npcInstance|tes3probe|tes3reference|tes3repairTool|tes3spell|tes3static|tes3weapon The previous object in parent collection's list.
--- @field scale number The object's scale.
--- @field sceneCollisionRoot niBillboardNode|niCollisionSwitch|niNode|niSwitchNode The scene graph node for this object's physics collision, if its mesh has a root collision node.
--- @field sceneNode niBillboardNode|niCollisionSwitch|niNode|niSwitchNode The scene graph node for this object.
--- @field sceneReference niBillboardNode|niCollisionSwitch|niNode|niSwitchNode The scene graph reference node for this object.
tes3object = {}
