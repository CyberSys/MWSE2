local mcm = {}
mcm.noParent = true
mcm.version = 1.5

function mcm:new()
	local t = {}
	setmetatable(t, self)
	t.__index = mcm.__index
	return t
end

--- @param template mwseMCMTemplate
function mcm.register(template)
	local modConfig = {}

	--- @param container tes3uiElement
	modConfig.onCreate = function(container)
		template:create(container)
		modConfig.onClose = template.onClose
	end
	mwse.log("%s mod config registered", template.name)
	mwse.registerModConfig(template.name, modConfig)
end

--- @param keybind mwseKeyCombo
--- @return boolean pressed
function mcm.testKeyBind(keybind)
	local inputController = tes3.worldController.inputController
	return inputController:isKeyDown(keybind.keyCode) and keybind.isShiftDown == inputController:isShiftDown() and
	       keybind.isAltDown == inputController:isAltDown() and keybind.isControlDown == inputController:isControlDown()
end

--- @param keyCode integer|nil
--- @return string|nil letter
function mcm.getKeyCodeName(keyCode)
	local letter = table.find(tes3.scanCode, keyCode)
	local returnString = tes3.scanCodeToNumber[keyCode] or letter
	if returnString then
		return string.upper(returnString)
	end
end

local mouseWheelDirectionName = {
	[1] = "Mouse wheel up",
	[-1] = "Mouse wheel down",
}

--- @param wheel integer|nil
--- @return string|nil result
function mcm.getMouseWheelName(wheel)
	local name = mouseWheelDirectionName[wheel]
	if name then
		return mwse.mcm.i18n(name)
	end
end

local mouseButtonName = {
	[0] = "Left mouse button",
	[1] = "Right mouse button",
	[2] = "Middle mouse button",
}

--- @param buttonIndex number|nil
--- @return string|nil result
function mcm.getMouseButtonName(buttonIndex)
	-- Only work with button indices supporte by the inputController
	if not buttonIndex or buttonIndex > 7 or buttonIndex < 0 then
		return
	end
	local name = mouseButtonName[buttonIndex]
	if name then
		return mwse.mcm.i18n(name)
	end

	return string.format(mwse.mcm.i18n("Mouse %s"), buttonIndex)
end

--- @param keyCombo mwseKeyMouseCombo
--- @return string|nil result
function mcm.getKeyComboName(keyCombo)
	-- Returns "SHIFT-X" if shift is held down but the active key is not Shift,
	-- otherwise just "X" (X being the key being pressed)
	-- And so on for Alt and Ctrl

	local keyCode = keyCombo.keyCode
	local comboText = mwse.mcm.getKeyCodeName(keyCode) or
	                  mwse.mcm.getMouseWheelName(keyCombo.mouseWheel) or
	                  mwse.mcm.getMouseButtonName(keyCombo.mouseButton)

	-- No valid name yet, nothing to do.
	if not comboText then
		return
	end

	local hasAlt = keyCombo.isAltDown and keyCode ~= tes3.scanCode.lAlt and keyCode ~= tes3.scanCode.rAlt
	local hasShift = keyCombo.isShiftDown and keyCode ~= tes3.scanCode.lShift and keyCode ~= tes3.scanCode.rShift
	local hasCtrl = keyCombo.isControlDown and keyCode ~= tes3.scanCode.lCtrl and keyCode ~= tes3.scanCode.rCtrl
	local prefix = (hasAlt and "Alt - " or hasShift and "Shift - " or hasCtrl and "Ctrl - " or "")

	return (prefix .. comboText)
end

-- Depreciated
function mcm.registerModData(mcmData)
	-- object returned to be used in modConfigMenu
	local modConfig = {}

	---CREATE MCM---
	--- @param container tes3uiElement
	function modConfig.onCreate(container)
		local templateClass = mcmData.template or "Template"
		local templatePath = ("mcm.components.templates." .. templateClass)
		local template = require(templatePath):new(mcmData) --[[@as mwseMCMTemplate]]
		template:create(container)
		modConfig.onClose = template.onClose
	end

	mwse.log("%s mod config registered", mcmData.name)

	return modConfig
end

-- Depreciated
function mcm.registerMCM(mcmData)
	local newMCM = mcm.registerModData(mcmData)
	mwse.registerModConfig(mcmData.name, newMCM)
end

--[[
	Check if key being accessed is in the form "create{class}" where
	{class} is a component or variable class.

	If only component data was sent as a parameter, create the new
	component instance. If a parentBlock was also passed, then also
	create the element on the parent.

]]--

local strLengthCreate = string.len("create")

function mcm.__index(tbl, key)

	local meta = getmetatable(tbl)
	if string.sub(key, 1, strLengthCreate) == "create" then

		local class = string.sub(key, strLengthCreate + 1)
		local component

		local classPaths = require("mcm.classPaths")
		for _, path in pairs(classPaths.all) do

			local classPath = path .. class
			local fullPath = lfs.currentdir() .. classPaths.basePath .. classPath .. ".lua"
			local fileExists = lfs.fileexists(fullPath)
			if fileExists then
				component = require(classPath)
			end

			if component then
				--- @cast component mwseMCMComponent
				return function(param1, param2)
					local parent = nil
					local data = nil
					if param2 then
						parent = param1
						data = param2
					else
						data = param1
					end
					if not data then
						data = "---"
					end
					if type(data) == "string" then
						if component.componentType == "Template" then
							data = { name = data }
						else
							data = { label = data }
						end
					end
					data.class = class

					component = component:new(data)
					-- Add check for mcm field to deal with using `:` instead of `.`
					if parent and parent.noParent ~= true then
						component:create(parent)
					end
					return component
				end
			end
		end
	end

	return meta[key]
end

return mcm:new()
