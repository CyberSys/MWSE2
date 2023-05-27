# dialogueFiltered
<div class="search_terms" style="display: none">dialoguefiltered</div>

<!---
	This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
	More information: https://github.com/MWSE/MWSE/tree/master/docs
-->

This event fires whenever a tes3dialogueInfo has been selected for a given tes3dialogue. This includes but is not limited to showing greetings, finding voice overs, and calculating service requirements.

```lua
--- @param e dialogueFilteredEventData
local function dialogueFilteredCallback(e)
end
event.register(tes3.event.dialogueFiltered, dialogueFilteredCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `actor` ([tes3actor](../../types/tes3actor)): *Read-only*. Any associated actor for the query.
* `context` (number): *Read-only*. What caused the dialogue filtering. Maps to values in the [`tes3.dialogueFilterContext`](https://mwse.github.io/MWSE/references/dialogue-filter-context/) table.
* `dialogue` ([tes3dialogue](../../types/tes3dialogue)): *Read-only*. The dialogue that was filtered.
* `info` ([tes3dialogueInfo](../../types/tes3dialogueInfo)): *Read-only*. The result that the filter returned.
* `reference` ([tes3actor](../../types/tes3actor)): *Read-only*. Any associated reference for the query.
