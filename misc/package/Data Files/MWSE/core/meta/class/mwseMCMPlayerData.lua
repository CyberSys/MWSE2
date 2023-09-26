-- This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
-- More information: https://github.com/MWSE/MWSE/tree/master/docs

--- @meta
--- Stores the variable on the Player reference.data table. This results in the value of the variable being local to the loaded save file. If users may want different values set for different games, this is a good Variable to use.
--- 
--- Settings using mwseMCMPlayerData are in-game only by default, as the Player reference can only be accessed while a game is loaded.
--- @class mwseMCMPlayerData : mwseMCMVariable
--- @field defaultSetting unknown If `id` does not exist in the `tes3.player.data` field, it will be initialized to this value. It's best to initialize this yourself though, as this will not create the value until you've entered the MCM.
--- @field id string Key of entry used on the `tes3.player.data` table.
--- @field inGameOnly true *Read-only*. Always `true` for this variable type, since `tes3.player.data` can only be changed while the game is loaded.
--- @field path string Path to `id` relative to `tes3.player.data`. The subtable keys need to be split by dots.
mwseMCMPlayerData = {}

--- Creates a new variable of this type.
--- @param variable mwseMCMPlayerData.new.variable This table accepts the following values:
--- 
--- `id`: string — Key of entry used on the `tes3.player.data` table.
--- 
--- `path`: string — Path to `id` relative to `tes3.player.data`. The subtable keys need to be split by dots. It's best to at least store all your mwseMCMPlayerData fields in a table named after your mod to avoid conflicts.
--- 
--- `defaultSetting`: unknown? — *Optional*. If `id` does not exist in the `tes3.player.data` field, it will be initialized to this value. It's best to initialize this yourself though, as this will not create the value until you've entered the MCM.
--- 
--- `restartRequired`: boolean? — *Default*: `false`. If true, updating the setting containing this variable will notify the player to restart the game.
--- 
--- `restartRequiredMessage`: string? — *Optional*.  The default text is a localized version of: "The game must be restarted before this change will come into effect.".
--- 
--- `converter`: nil|fun(newValue): unknown — *Optional*. This function is called when the value of the variable is changed. The function can modify the new value before it is saved.
--- @return mwseMCMPlayerData variable No description yet available.
function mwseMCMPlayerData:new(variable) end

---Table parameter definitions for `mwseMCMPlayerData.new`.
--- @class mwseMCMPlayerData.new.variable
--- @field id string Key of entry used on the `tes3.player.data` table.
--- @field path string Path to `id` relative to `tes3.player.data`. The subtable keys need to be split by dots. It's best to at least store all your mwseMCMPlayerData fields in a table named after your mod to avoid conflicts.
--- @field defaultSetting unknown? *Optional*. If `id` does not exist in the `tes3.player.data` field, it will be initialized to this value. It's best to initialize this yourself though, as this will not create the value until you've entered the MCM.
--- @field restartRequired boolean? *Default*: `false`. If true, updating the setting containing this variable will notify the player to restart the game.
--- @field restartRequiredMessage string? *Optional*.  The default text is a localized version of: "The game must be restarted before this change will come into effect.".
--- @field converter nil|fun(newValue): unknown *Optional*. This function is called when the value of the variable is changed. The function can modify the new value before it is saved.

