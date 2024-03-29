# magicCasted
<div class="search_terms" style="display: none">magiccasted</div>

<!---
	This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
	More information: https://github.com/MWSE/MWSE/tree/master/docs
-->

This event is triggered when any spell or enchant is cast successfully, or when any alchemy item is used. This includes spells cast via scripts. For spells, this occurs at the end of the casting animation. For spells and enchants, it is just after the magic projectile has been constructed.

```lua
--- @param e magicCastedEventData
local function magicCastedCallback(e)
end
event.register(tes3.event.magicCasted, magicCastedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `caster` ([tes3reference](../types/tes3reference.md)): *Read-only*. The caster of the spell.
* `source` ([tes3alchemy](../types/tes3alchemy.md), [tes3enchantment](../types/tes3enchantment.md), [tes3spell](../types/tes3spell.md)): *Read-only*. The magic source.
* `sourceInstance` ([tes3magicSourceInstance](../types/tes3magicSourceInstance.md)): *Read-only*. The unique instance of the magic source.
* `target` ([tes3reference](../types/tes3reference.md)): *Read-only*. The target of the spell. For self-targeted spells, this matches the caster. Touch spells can also have `target` parameter. On target spells don't have `target` parameter during this event, since it can't have a target until it hits it. Which isn't known when the spell is casted.

