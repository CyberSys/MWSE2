-- This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
-- More information: https://github.com/MWSE/MWSE/tree/master/docs

--- @meta
--- An AI package game object.
--- @class tes3aiPackage
--- @field destinationCell tes3cell The destination cell for escort and follow AI packages. For wander package, this is the cell the actor wanders in.
--- @field distance number Determines the size of the area the actor with this wander AI package will walk around. Measured in the in-game units.
--- @field duration number This property represents the duration of the AI package. It is present for wander, escort and follow AI packages. Measured in the in-game hours.
--- @field hourOfDay number 
--- @field isDone boolean 
--- @field isFinalized boolean 
--- @field isMoving boolean This property is `true` if the parent actor is moving.
--- @field isReset boolean 
--- @field isStarted boolean 
--- @field mobile tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer Access to the actor to whom this AI package belongs.
--- @field startGameHour number The in-game hour at which this AI package started.
--- @field targetActor tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer The target actor for activate, follow and escort AI packages.
--- @field targetPosition tes3vector3 The final position to be reached by the escort, follow, and travel AI packages.
--- @field type number *Read-only*. Maps to values in [`tes3.aiPackage`](https://mwse.github.io/MWSE/references/ai-packages/) namespace.
