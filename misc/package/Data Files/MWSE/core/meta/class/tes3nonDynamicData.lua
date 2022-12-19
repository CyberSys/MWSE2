-- This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
-- More information: https://github.com/MWSE/MWSE/tree/master/docs

--- @meta
--- @diagnostic disable:undefined-doc-name

--- A child container from [`tes3dataHandler`](https://mwse.github.io/MWSE/types/tes3dataHandler/), where game data is stored.
--- @class tes3nonDynamicData
--- @field activeMods tes3gameFile[] *Read-only*. A collection of all actively loaded mods.
--- @field birthsigns tes3birthsign[] *Read-only*. A collection of all birthsign objects.
--- @field cells tes3cell[] *Read-only*. A collection of all cell objects.
--- @field classes tes3class[] *Read-only*. A collection of all class objects.
--- @field dialogues tes3dialogue[] *Read-only*. A collection of all dialogue objects.
--- @field factions tes3faction[] *Read-only*. A collection of all faction objects.
--- @field globals tes3iterator *Read-only*. A collection of all global variable objects.
--- @field isSavingOrLoading boolean *Read-only*. True when in the process of saving or loading the game.
--- @field lastLoadedFile tes3gameFile *Read-only*. The last loaded savegame file.
--- @field magicEffects table<integer, tes3magicEffect> *Read-only*. A table of references to all magic effects. This is a dictionary, as the effect list may have gaps.
--- @field mapTexture niSourceTexture Access to the World map texture.
--- @field objects tes3activator[]|tes3alchemy[]|tes3apparatus[]|tes3armor[]|tes3bodyPart[]|tes3book[]|tes3clothing[]|tes3container[]|tes3containerInstance[]|tes3creature[]|tes3creatureInstance[]|tes3door[]|tes3enchantment[]|tes3ingredient[]|tes3leveledCreature[]|tes3leveledItem[]|tes3light[]|tes3lockpick[]|tes3misc[]|tes3npc[]|tes3npcInstance[]|tes3probe[]|tes3reference[]|tes3repairTool[]|tes3spell[]|tes3static[]|tes3weapon[] *Read-only*. A collection of all other game objects.
--- @field races tes3race[] *Read-only*. A collection of all race objects.
--- @field regions tes3region[] *Read-only*. A collection of all region objects.
--- @field scripts tes3script[] *Read-only*. A collection of all script objects.
--- @field skills tes3skill[] *Read-only*. A table of references to all 27 skills.
--- @field soundGenerators tes3soundGenerator[] *Read-only*. A collection of all sound generator objects.
--- @field sounds tes3sound[] *Read-only*. A collection of all sound objects.
--- @field spells tes3spell[] *Read-only*. A collection of all spell objects.
--- @field startScripts tes3startScript[] *Read-only*. A collection of all start script objects.
tes3nonDynamicData = {}

--- Inserts a newly created object into the proper collections.
--- @param object tes3activator|tes3alchemy|tes3apparatus|tes3armor|tes3birthsign|tes3bodyPart|tes3book|tes3cell|tes3class|tes3clothing|tes3container|tes3containerInstance|tes3creature|tes3creatureInstance|tes3dialogue|tes3dialogueInfo|tes3door|tes3enchantment|tes3faction|tes3gameSetting|tes3globalVariable|tes3ingredient|tes3leveledCreature|tes3leveledItem|tes3light|tes3lockpick|tes3magicSourceInstance|tes3misc|tes3npc|tes3npcInstance|tes3probe|tes3quest|tes3race|tes3reference|tes3region|tes3repairTool|tes3script|tes3skill|tes3sound|tes3soundGenerator|tes3spell|tes3startScript|tes3static|tes3weapon No description yet available.
--- @return boolean result No description yet available.
function tes3nonDynamicData:addNewObject(object) end

--- Removes an object from the proper collections.
--- @param object tes3activator|tes3alchemy|tes3apparatus|tes3armor|tes3birthsign|tes3bodyPart|tes3book|tes3cell|tes3class|tes3clothing|tes3container|tes3containerInstance|tes3creature|tes3creatureInstance|tes3dialogue|tes3dialogueInfo|tes3door|tes3enchantment|tes3faction|tes3gameSetting|tes3globalVariable|tes3ingredient|tes3leveledCreature|tes3leveledItem|tes3light|tes3lockpick|tes3magicSourceInstance|tes3misc|tes3npc|tes3npcInstance|tes3probe|tes3quest|tes3race|tes3reference|tes3region|tes3repairTool|tes3script|tes3skill|tes3sound|tes3soundGenerator|tes3spell|tes3startScript|tes3static|tes3weapon No description yet available.
function tes3nonDynamicData:deleteObject(object) end

--- Draws a map marker box for an exterior cell onto the world map.
--- @param cell tes3cell No description yet available.
function tes3nonDynamicData:drawCellMapMarker(cell) end

--- **Deprecated. An alias for `tes3nonDynamicData.findDialogue`.** Locates a dialogue for a given ID.
--- @deprecated
--- @param id string No description yet available.
--- @return tes3dialogue result No description yet available.
function tes3nonDynamicData:findDialogInfo(id) end

--- Locates a dialogue for a given ID.
--- @param id string No description yet available.
--- @return tes3dialogue result No description yet available.
function tes3nonDynamicData:findDialogue(id) end

--- Locates the first reference for a given object ID.
--- @param id string No description yet available.
--- @return tes3reference result No description yet available.
function tes3nonDynamicData:findFirstCloneOfActor(id) end

--- Locates a global variable for a given ID.
--- @param id string No description yet available.
--- @return tes3globalVariable result No description yet available.
function tes3nonDynamicData:findGlobalVariable(id) end

--- Locates a script for a given ID.
--- @param id string No description yet available.
--- @return tes3script result No description yet available.
function tes3nonDynamicData:findScript(id) end

--- Locates a sound for a given ID.
--- @param id string No description yet available.
--- @return tes3sound result No description yet available.
function tes3nonDynamicData:findSound(id) end

--- Locates a general object for a given ID.
--- @param id string No description yet available.
--- @return tes3activator|tes3alchemy|tes3apparatus|tes3armor|tes3birthsign|tes3bodyPart|tes3book|tes3cell|tes3class|tes3clothing|tes3container|tes3containerInstance|tes3creature|tes3creatureInstance|tes3dialogue|tes3dialogueInfo|tes3door|tes3enchantment|tes3faction|tes3gameSetting|tes3globalVariable|tes3ingredient|tes3leveledCreature|tes3leveledItem|tes3light|tes3lockpick|tes3magicSourceInstance|tes3misc|tes3npc|tes3npcInstance|tes3probe|tes3quest|tes3race|tes3reference|tes3region|tes3repairTool|tes3script|tes3skill|tes3sound|tes3soundGenerator|tes3spell|tes3startScript|tes3static|tes3weapon result No description yet available.
function tes3nonDynamicData:resolveObject(id) end

--- Draws map marker boxes onto the world map for all cells with names starting with the prefix. e.g. `showLocationOnMap("Vivec")` draws boxes for all cells in Vivec, because the cell names "Vivec, Arena", "Vivec, Temple", etc. matches.
--- @param cellNamePrefix string No description yet available.
function tes3nonDynamicData:showLocationOnMap(cellNamePrefix) end

