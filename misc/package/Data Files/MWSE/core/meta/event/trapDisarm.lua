--- @meta
--- @diagnostic disable:undefined-doc-name

--- This event fires when a trap is being disarmed.
--- @class trapDisarmEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field chance number *Read-only*. The chance the trap disarm will be successful.
--- @field disarmer tes3mobileNPC|tes3mobilePlayer *Read-only*. The Mobile NPC doing the disarming.
--- @field lockData tes3lockNode *Read-only*. The lock data of the reference.
--- @field reference tes3reference *Read-only*. The reference that triggered the event (container, door, etc.).
--- @field tool tes3alchemy|tes3apparatus|tes3armor|tes3book|tes3clothing|tes3ingredient|tes3light|tes3lockpick|tes3misc|tes3probe|tes3repairTool|tes3weapon *Read-only*. The item the disarmer is using to disarm the trap.
--- @field toolItemData tes3itemData *Read-only*. The item data for the tool.
--- @field trapPresent boolean *Read-only*. Indicates if a trap is present on the reference.
