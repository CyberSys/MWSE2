-- This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
-- More information: https://github.com/MWSE/MWSE/tree/master/docs

--- @meta
--- A Sidebar Page is a special page type that includes an additional container used to display mouseover information for components.
--- 
--- Children in the *components* list can have a *description* text field, which will display in the sidebar when that component is moused over. When no component is moused over, the sidebar will display the text in the *description* field of the page and any component added to the `myPage.sidebar`.
--- @class mwseMCMSideBarPage : mwseMCMPage, mwseMCMCategory, mwseMCMComponent
--- @field description string|nil Default sidebar text shown when the mouse isn't hovering over a component inside this Sidebar Page.
--- @field elements mwseMCMFilterPageElements|mwseMCMSideBarPageElements This dictionary-style table holds all the UI elements of the Sidebar Page, for easy access.
--- @field sidebar mwseMCMMouseOverPage The object that holds components in the sidebar. Components can be added to that page like any other page..
--- @field triggerOff "MCM:MouseLeave" The event ID on which a function, that shows the default text for the Sidebar Page in the right column, is registered.
--- @field triggerOn "MCM:MouseOver" The event ID on which a function, that shows the description of the component the mouse is currently hovering over in the right column of the Sidebar Page, is registered.
mwseMCMSideBarPage = {}

--- Creates a standard mwseMCMPage as the left column of the Sidebar Page.
--- @param parentBlock tes3uiElement No description yet available.
function mwseMCMSideBarPage:createLeftColumn(parentBlock) end

--- Creates a mwseMCMMouseOverPage as the right column of the Sidebar Page.
--- @param parentBlock tes3uiElement No description yet available.
function mwseMCMSideBarPage:createRightColumn(parentBlock) end

--- Creates the sideToSideBlock UI element, and stores it in the `self.elements.sideToSideBlock`. The sideToSideBlock is the parent UI element for the left and right columns of the Sidebar Page.
--- @param parentBlock tes3uiElement No description yet available.
function mwseMCMSideBarPage:createSidetoSideBlock(parentBlock) end

--- Creates a new Sidebar Page.
--- @param data mwseMCMSideBarPage.new.data? This table accepts the following values:
--- 
--- `showHeader`: boolean? — *Default*: `false`. The page's label will only be created if set to true.
--- 
--- `label`: string? — *Optional*. The label field is displayed in the tab for that page at the top of the menu. Defaults to: "Page {number}".
--- 
--- `noScroll`: boolean? — *Default*: `false`. When set to true, the page will not have a scrollbar. Particularly useful if you want to use a [ParagraphField](./mwseMCMParagraphField.md), which is not compatible with scroll panes.
--- 
--- `description`: string? — *Optional*. Default sidebar text shown when the mouse isn't hovering over a component inside this Sidebar Page. It will be added to right column as a mwseMCMInfo.
--- 
--- `components`: mwseMCMComponent.getComponent.componentData[]? — *Optional*. Use this if you want to directly create all the nested components in this Page. This table is described at [getComponent](./mwseMCMSideBarPage.md#getcomponent).
--- 
--- `indent`: integer? — *Default*: `6`. The left padding size in pixels. Only used if the `childIndent` isn't set on the parent component.
--- 
--- `childIndent`: integer? — *Optional*. The left padding size in pixels. Used on all the child components.
--- 
--- `paddingBottom`: integer? — *Default*: `4`. The bottom border size in pixels. Only used if the `childSpacing` is unset on the parent component.
--- 
--- `childSpacing`: integer? — *Optional*. The bottom border size in pixels. Used on all the child components.
--- 
--- `inGameOnly`: boolean? — *Default*: `false`. No description yet available.
--- 
--- `postCreate`: nil|fun(self: mwseMCMSideBarPage) — *Optional*. Can define a custom formatting function to make adjustments to any element saved in `self.elements`.
--- 
--- `class`: string? — *Optional*. No description yet available.
--- 
--- `componentType`: string? — *Optional*. No description yet available.
--- 
--- `parentComponent`: mwseMCMActiveInfo|mwseMCMButton|mwseMCMCategory|mwseMCMComponent|mwseMCMDecimalSlider|mwseMCMDropdown|mwseMCMExclusionsPage|mwseMCMFilterPage|mwseMCMHyperlink|mwseMCMInfo|mwseMCMKeyBinder|mwseMCMMouseOverInfo|mwseMCMMouseOverPage|mwseMCMOnOffButton|mwseMCMPage|mwseMCMParagraphField|mwseMCMSetting|mwseMCMSideBarPage|mwseMCMSideBySideBlock|mwseMCMSlider|mwseMCMTemplate|mwseMCMTextField|mwseMCMYesNoButton|nil — *Optional*. No description yet available.
--- @return mwseMCMFilterPage|mwseMCMSideBarPage page No description yet available.
function mwseMCMSideBarPage:new(data) end

---Table parameter definitions for `mwseMCMSideBarPage.new`.
--- @class mwseMCMSideBarPage.new.data
--- @field showHeader boolean? *Default*: `false`. The page's label will only be created if set to true.
--- @field label string? *Optional*. The label field is displayed in the tab for that page at the top of the menu. Defaults to: "Page {number}".
--- @field noScroll boolean? *Default*: `false`. When set to true, the page will not have a scrollbar. Particularly useful if you want to use a [ParagraphField](./mwseMCMParagraphField.md), which is not compatible with scroll panes.
--- @field description string? *Optional*. Default sidebar text shown when the mouse isn't hovering over a component inside this Sidebar Page. It will be added to right column as a mwseMCMInfo.
--- @field components mwseMCMComponent.getComponent.componentData[]? *Optional*. Use this if you want to directly create all the nested components in this Page. This table is described at [getComponent](./mwseMCMSideBarPage.md#getcomponent).
--- @field indent integer? *Default*: `6`. The left padding size in pixels. Only used if the `childIndent` isn't set on the parent component.
--- @field childIndent integer? *Optional*. The left padding size in pixels. Used on all the child components.
--- @field paddingBottom integer? *Default*: `4`. The bottom border size in pixels. Only used if the `childSpacing` is unset on the parent component.
--- @field childSpacing integer? *Optional*. The bottom border size in pixels. Used on all the child components.
--- @field inGameOnly boolean? *Default*: `false`. No description yet available.
--- @field postCreate nil|fun(self: mwseMCMSideBarPage) *Optional*. Can define a custom formatting function to make adjustments to any element saved in `self.elements`.
--- @field class string? *Optional*. No description yet available.
--- @field componentType string? *Optional*. No description yet available.
--- @field parentComponent mwseMCMActiveInfo|mwseMCMButton|mwseMCMCategory|mwseMCMComponent|mwseMCMDecimalSlider|mwseMCMDropdown|mwseMCMExclusionsPage|mwseMCMFilterPage|mwseMCMHyperlink|mwseMCMInfo|mwseMCMKeyBinder|mwseMCMMouseOverInfo|mwseMCMMouseOverPage|mwseMCMOnOffButton|mwseMCMPage|mwseMCMParagraphField|mwseMCMSetting|mwseMCMSideBarPage|mwseMCMSideBySideBlock|mwseMCMSlider|mwseMCMTemplate|mwseMCMTextField|mwseMCMYesNoButton|nil *Optional*. No description yet available.

