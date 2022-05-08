--- @meta
--- @diagnostic disable:undefined-doc-name

--- A core game object used for storing both active and non-dynamic gameplay data.
--- @class tes3dataHandler
--- @field backgroundThread number *Read-only*. A Windows handle to the background processing thread.
--- @field backgroundThreadId number *Read-only*. The thread ID for the background processing thread.
--- @field backgroundThreadRunning boolean *Read-only*. Access to the running state for the background processing thread.
--- @field cellChanged boolean *Read-only*. A flag set for the frame that the player has changed cells.
--- @field centralGridX boolean *Read-only*. The position of the origin horizontal grid coordinate.
--- @field centralGridY boolean *Read-only*. The position of the origin longitudinal grid coordinate.
--- @field currentAmbientWaterSound tes3sound Access to the current ambient water sound.
--- @field currentCell tes3cell *Read-only*. Access to the cell that the player is currently in.
--- @field currentInteriorCell tes3cell *Read-only*. Access to the current interior cell, if the player is in an interior.
--- @field dontThreadLoad boolean Access to dontThreadLoad setting.
--- @field exteriorCells tes3dataHandlerExteriorCellData[] *Read-only*. A table of nine [`tes3cellExteriorData`](https://mwse.github.io/MWSE/types/tes3cellExteriorData/) objects for all loaded exterior cells.
--- @field lastExteriorCell tes3cell *Read-only*. Access to the last visited exterior cell.
--- @field mainThread number *Read-only*. A Windows handle to the main execution thread.
--- @field mainThreadId number *Read-only*. The thread ID for the main execution thread.
--- @field nonDynamicData tes3nonDynamicData *Read-only*. A child structure where core game objects are held.
--- @field suppressThreadLoad boolean Access to suppressThreadLoad setting.
--- @field threadSleepTime number *Read-only*. No description yet available.
--- @field useCellTransitionFader boolean An engine flag that controls if there is a fade in/out between cells.
--- @field worldLandscapeRoot niBillboardNode|niCollisionSwitch|niNode|niSwitchNode *Read-only*. One of the core parent scene graph nodes.
--- @field worldObjectRoot niBillboardNode|niCollisionSwitch|niNode|niSwitchNode *Read-only*. One of the core parent scene graph nodes.
--- @field worldPickObjectRoot niBillboardNode|niCollisionSwitch|niNode|niSwitchNode *Read-only*. One of the core parent scene graph nodes.
tes3dataHandler = {}

--- No description yet available.
--- @param params tes3dataHandler.updateCollisionGroupsForActiveCells.params This table accepts the following values:
--- 
--- `force`: boolean? — *Default*: `true`. No description yet available.
--- 
--- `isResettingData`: boolean? — *Default*: `false`. No description yet available.
--- 
--- `resetCollisionGroups`: boolean? — *Default*: `true`. No description yet available.
function tes3dataHandler:updateCollisionGroupsForActiveCells(params) end

---Table parameter definitions for `tes3dataHandler.updateCollisionGroupsForActiveCells`.
--- @class tes3dataHandler.updateCollisionGroupsForActiveCells.params
--- @field force boolean? *Default*: `true`. No description yet available.
--- @field isResettingData boolean? *Default*: `false`. No description yet available.
--- @field resetCollisionGroups boolean? *Default*: `true`. No description yet available.

