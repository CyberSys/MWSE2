# shieldBlocked
<div class="search_terms" style="display: none">shieldblocked</div>

<!---
	This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
	More information: https://github.com/MWSE/MWSE/tree/master/docs
-->

This event is fired when a melee strike is blocked, and the equipped shield is about to take damage from the strike. It allows modification of the damage applied to the shield.

```lua
--- @param e shieldBlockedEventData
local function shieldBlockedCallback(e)
end
event.register(tes3.event.shieldBlocked, shieldBlockedCallback)
```

!!! tip
	This event can be filtered based on the **`reference`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `attacker` ([tes3mobileActor](../types/tes3mobileActor.md)): *Read-only*. The mobile actor dealing the damage.
* `conditionDamage` (number): The shield's condition will be reduced by this amount. It is initially equal to the pre-armor-mitigation damage value of the strike.
* `mobile` ([tes3mobileActor](../types/tes3mobileActor.md)): *Read-only*. The mobile actor which is blocking the strike.
* `reference` ([tes3reference](../types/tes3reference.md)): *Read-only*. A shortcut to the mobile's reference.

