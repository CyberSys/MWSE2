-- This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
-- More information: https://github.com/MWSE/MWSE/tree/master/docs

--- @meta
--- Provides support for interacting with json data through an extended dkjson module.
--- @class jsonlib
--- @field null number You can use this value for setting explicit null values.
--- @field version string Current version of dkjson.
json = {}

--- Decode string into a table.
--- 
--- !!! warning
--- 	If the table encoded as json had both string and integer indices, this process converted all the integer indices to strings. For example, `[1]` was converted to `["1"]`. So, when loading mixed tables from json, this needs to be considered.
--- 
--- @param s string No description yet available.
--- @param position number? *Default*: `1`. No description yet available.
--- @param nullValue string|nil *Default*: `nil`. No description yet available.
--- @return table result No description yet available.
function json.decode(s, position, nullValue) end

--- Create a string representing the object. Object can be a table, a string, a number, a boolean, nil, json.null or any object with a function __tojson in its metatable. A table can only use strings and numbers as keys and its values have to be valid objects as well. It raises an error for any invalid data types or reference cycles.
--- 
--- !!! warning
--- 	If the table you are encoding as json has both string and integer indices, this action will convert all the integer indices to strings. For example, `[1]` is converted to `["1"]`. So, when loading mixed tables from json, this needs to be considered.
--- 
--- @param object table No description yet available.
--- @param state table? No description yet available.
--- @return string result No description yet available.
function json.encode(object, state) end

--- Loads the contents of a file through json.decode. Files loaded from Data Files\\MWSE\\{fileName}.json.
--- 
--- !!! warning
--- 	If the table encoded as json had both string and integer indices, this process converted all the integer indices to strings. For example, `[1]` was converted to `["1"]`. So, when loading mixed tables from json, this needs to be considered. If you need to save and load your mod's configuration file, consider using [`mwse.loadConfig()`](https://mwse.github.io/MWSE/apis/mwse/#mwseloadconfig) as that function will do this for you.
--- 
--- @param fileName string No description yet available.
--- @return table result No description yet available.
function json.loadfile(fileName) end

--- Quote a UTF-8 string and escape critical characters using JSON escape sequences. This function is only necessary when you build your own __tojson functions.
--- @param s string No description yet available.
--- @return string result No description yet available.
function json.quotestring(s) end

--- Saves a serializable table to Data Files\\MWSE\\{fileName}.json, using json.encode.
--- @param fileName string No description yet available.
--- @param object table No description yet available.
--- @param config table? *Optional*. No description yet available.
function json.savefile(fileName, object, config) end

