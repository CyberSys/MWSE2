-- This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
-- More information: https://github.com/MWSE/MWSE/tree/master/docs

--- @meta
--- An Info field that shows mouseover information for settings.
--- @class mwseMCMMouseOverInfo : mwseMCMInfo, mwseMCMSetting, mwseMCMComponent
--- @field triggerOff "MCM:MouseLeave" The event ID on which a function calling `self:updateInfo` is registered.
--- @field triggerOn "MCM:MouseOver" The event ID on which a function calling `self:updateInfo` is registered.
mwseMCMMouseOverInfo = {}

--- This method creates the info (a label) UI element of the mwseMCMMouseOverInfo and stores it in `self.elements.info` and `self.mouseOvers`. Also, registers event handlers on `triggerOn` and `triggerOff` events that call `self:updateInfo`.
--- @param parentBlock tes3uiElement No description yet available.
function mwseMCMMouseOverInfo:makeComponent(parentBlock) end

--- Creates a new MouseOverInfo.
--- @param data mwseMCMMouseOverInfo.new.data? This table accepts the following values:
--- 
--- `label`: string? — *Optional*. The MouseOverInfo's label.
--- 
--- `text`: string? — *Optional*. The MouseOverInfo's text.
--- 
--- `description`: string? — *Optional*. If in a [Sidebar Page](../types/mwseMCMSideBarPage.md), the description will be shown on mouseover.
--- 
--- `variable`: mwseMCMConfigVariable|mwseMCMCustomVariable|mwseMCMGlobal|mwseMCMGlobalBoolean|mwseMCMPlayerData|mwseMCMTableVariable|mwseMCMVariable|mwseMCMSettingNewVariable|nil — *Optional*. A variable for this setting.
--- 
--- `defaultSetting`: unknown? — *Optional*. If `defaultSetting` wasn't passed in the `variable` table, can be passed here. The new variable will be initialized to this value.
--- 
--- `inGameOnly`: boolean? — *Default*: `false`. No description yet available.
--- 
--- `indent`: integer? — *Default*: `12`. The left padding size in pixels. Only used if the `childIndent` isn't set on the parent component.
--- 
--- `childIndent`: integer? — *Optional*. The left padding size in pixels. Used on all the child components.
--- 
--- `paddingBottom`: integer? — *Default*: `4`. The bottom border size in pixels. Only used if the `childSpacing` is unset on the parent component.
--- 
--- `childSpacing`: integer? — *Optional*. The bottom border size in pixels. Used on all the child components.
--- 
--- `postCreate`: nil|fun(self: mwseMCMMouseOverInfo) — *Optional*. Can define a custom formatting function to make adjustments to any element saved in `self.elements`.
--- 
--- `class`: string? — *Optional*. No description yet available.
--- 
--- `componentType`: string? — *Optional*. No description yet available.
--- 
--- `parentComponent`: mwseMCMActiveInfo|mwseMCMButton|mwseMCMCategory|mwseMCMComponent|mwseMCMDecimalSlider|mwseMCMDropdown|mwseMCMExclusionsPage|mwseMCMFilterPage|mwseMCMHyperlink|mwseMCMInfo|mwseMCMKeyBinder|mwseMCMMouseOverInfo|mwseMCMMouseOverPage|mwseMCMOnOffButton|mwseMCMPage|mwseMCMParagraphField|mwseMCMSetting|mwseMCMSideBarPage|mwseMCMSideBySideBlock|mwseMCMSlider|mwseMCMTemplate|mwseMCMTextField|mwseMCMYesNoButton|nil — *Optional*. No description yet available.
--- @return mwseMCMActiveInfo|mwseMCMMouseOverInfo info No description yet available.
function mwseMCMMouseOverInfo:new(data) end

---Table parameter definitions for `mwseMCMMouseOverInfo.new`.
--- @class mwseMCMMouseOverInfo.new.data
--- @field label string? *Optional*. The MouseOverInfo's label.
--- @field text string? *Optional*. The MouseOverInfo's text.
--- @field description string? *Optional*. If in a [Sidebar Page](../types/mwseMCMSideBarPage.md), the description will be shown on mouseover.
--- @field variable mwseMCMConfigVariable|mwseMCMCustomVariable|mwseMCMGlobal|mwseMCMGlobalBoolean|mwseMCMPlayerData|mwseMCMTableVariable|mwseMCMVariable|mwseMCMSettingNewVariable|nil *Optional*. A variable for this setting.
--- @field defaultSetting unknown? *Optional*. If `defaultSetting` wasn't passed in the `variable` table, can be passed here. The new variable will be initialized to this value.
--- @field inGameOnly boolean? *Default*: `false`. No description yet available.
--- @field indent integer? *Default*: `12`. The left padding size in pixels. Only used if the `childIndent` isn't set on the parent component.
--- @field childIndent integer? *Optional*. The left padding size in pixels. Used on all the child components.
--- @field paddingBottom integer? *Default*: `4`. The bottom border size in pixels. Only used if the `childSpacing` is unset on the parent component.
--- @field childSpacing integer? *Optional*. The bottom border size in pixels. Used on all the child components.
--- @field postCreate nil|fun(self: mwseMCMMouseOverInfo) *Optional*. Can define a custom formatting function to make adjustments to any element saved in `self.elements`.
--- @field class string? *Optional*. No description yet available.
--- @field componentType string? *Optional*. No description yet available.
--- @field parentComponent mwseMCMActiveInfo|mwseMCMButton|mwseMCMCategory|mwseMCMComponent|mwseMCMDecimalSlider|mwseMCMDropdown|mwseMCMExclusionsPage|mwseMCMFilterPage|mwseMCMHyperlink|mwseMCMInfo|mwseMCMKeyBinder|mwseMCMMouseOverInfo|mwseMCMMouseOverPage|mwseMCMOnOffButton|mwseMCMPage|mwseMCMParagraphField|mwseMCMSetting|mwseMCMSideBarPage|mwseMCMSideBySideBlock|mwseMCMSlider|mwseMCMTemplate|mwseMCMTextField|mwseMCMYesNoButton|nil *Optional*. No description yet available.

--- Sets the Info's text to the `component.description` if there is one. Sets the Info's displayed text to `self.text` otherwise.
--- @param component mwseMCMActiveInfo|mwseMCMButton|mwseMCMCategory|mwseMCMComponent|mwseMCMDecimalSlider|mwseMCMDropdown|mwseMCMExclusionsPage|mwseMCMFilterPage|mwseMCMHyperlink|mwseMCMInfo|mwseMCMKeyBinder|mwseMCMMouseOverInfo|mwseMCMMouseOverPage|mwseMCMOnOffButton|mwseMCMPage|mwseMCMParagraphField|mwseMCMSetting|mwseMCMSideBarPage|mwseMCMSideBySideBlock|mwseMCMSlider|mwseMCMTemplate|mwseMCMTextField|mwseMCMYesNoButton|nil *Optional*. No description yet available.
function mwseMCMMouseOverInfo:updateInfo(component) end

