-- This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
-- More information: https://github.com/MWSE/MWSE/tree/master/docs

--- @meta
--- A logging class. Needs to be required before use. See [this guide](https://mwse.github.io/MWSE/guides/logging/).
--- @class mwseLogger
--- @field logToConsole boolean If `true`, all the logged messages will also be logged to console.
--- @field name string Name of the mod, also counts as unique id of the logger.
mwseLogger = {}

--- Assert a condition and log an error if it fails.
--- @param condition boolean No description yet available.
--- @param message string No description yet available.
--- @param ... any? *Optional*. Formatting and additional parameters matching string.format's usage.
function mwseLogger:assert(condition, message, ...) end

--- Log debug message.
--- @param message string No description yet available.
--- @param ... any? *Optional*. Formatting and additional parameters matching string.format's usage.
function mwseLogger:debug(message, ...) end

--- Returns true if the messages of the given log level will be logged.
--- @param logLevel mwseLoggerLogLevel Options are: "TRACE", "DEBUG", "INFO", "WARN", "ERROR" and "NONE".
--- @return boolean doLog No description yet available.
function mwseLogger:doLog(logLevel) end

--- Log error message.
--- @param message string No description yet available.
--- @param ... any? *Optional*. Formatting and additional parameters matching string.format's usage.
function mwseLogger:error(message, ...) end

--- Log info message.
--- @param message string No description yet available.
--- @param ... any? *Optional*. Formatting and additional parameters matching string.format's usage.
function mwseLogger:info(message, ...) end

--- Set the log level. Options are: "TRACE", "DEBUG", "INFO", "WARN", "ERROR" and "NONE".
--- @param newLogLevel mwseLoggerLogLevel No description yet available.
function mwseLogger:setLogLevel(newLogLevel) end

--- Set the output file. If set, logs will be sent to a file of this name.
--- @param outputFile string No description yet available.
function mwseLogger:setOutputFile(outputFile) end

--- Log trace message.
--- @param message string No description yet available.
--- @param ... any? *Optional*. Formatting and additional parameters matching string.format's usage.
function mwseLogger:trace(message, ...) end

--- Log warn message.
--- @param message string No description yet available.
--- @param ... any? *Optional*. Formatting and additional parameters matching string.format's usage.
function mwseLogger:warn(message, ...) end
