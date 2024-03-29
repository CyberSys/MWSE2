# calcSpellmakingPrice
<div class="search_terms" style="display: none">calcspellmakingprice</div>

<!---
	This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
	More information: https://github.com/MWSE/MWSE/tree/master/docs
-->

This event is called when determining the cost of making a spell. The price can be modified.

```lua
--- @param e calcSpellmakingPriceEventData
local function calcSpellmakingPriceCallback(e)
end
event.register(tes3.event.calcSpellmakingPrice, calcSpellmakingPriceCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `mobile` ([tes3mobileActor](../types/tes3mobileActor.md)): *Read-only*. The mobile actor of the spellmaking service npc the player is interacting with.
* `price` (number): The price of the spell.
* `reference` ([tes3reference](../types/tes3reference.md)): *Read-only*. Mobile's related reference.


## Related events

[calcBarterPrice](./calcBarterPrice.md){ .md-button }[calcEnchantmentPrice](./calcEnchantmentPrice.md){ .md-button }[calcRepairPrice](./calcRepairPrice.md){ .md-button }[calcSpellmakingPrice](./calcSpellmakingPrice.md){ .md-button }[calcSpellPrice](./calcSpellPrice.md){ .md-button }[calcTrainingPrice](./calcTrainingPrice.md){ .md-button }[calcTravelPrice](./calcTravelPrice.md){ .md-button }

