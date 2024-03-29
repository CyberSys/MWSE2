# absorbedMagic
<div class="search_terms" style="display: none">absorbedmagic</div>

<!---
	This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
	More information: https://github.com/MWSE/MWSE/tree/master/docs
-->

This event is triggered after magic absorption absorbs and cancels a magic effect, and just before magic absorption gives magicka to the target. It can control the amount of magicka restored.

This event occurs once per effect restored, so a multi-effect spell may trigger this multiple times. The default amount restored is equal to the casting cost of the entire spell, which is the vanilla behaviour.

```lua
--- @param e absorbedMagicEventData
local function absorbedMagicCallback(e)
end
event.register(tes3.event.absorbedMagic, absorbedMagicCallback)
```

!!! tip
	This event can be filtered based on the **`target`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `absorb` (number): The amount of magicka to restore to the actor.
* `mobile` ([tes3mobileActor](../types/tes3mobileActor.md)): *Read-only*. The mobile actor that absorbed the spell.
* `source` ([tes3alchemy](../types/tes3alchemy.md), [tes3enchantment](../types/tes3enchantment.md), [tes3spell](../types/tes3spell.md)): *Read-only*. The magic source.
* `sourceInstance` ([tes3magicSourceInstance](../types/tes3magicSourceInstance.md)): *Read-only*. The unique instance of the magic source.
* `target` ([tes3reference](../types/tes3reference.md)): *Read-only*. The actor that absorbed the spell.


## Related events

[spellResist](./spellResist.md){ .md-button }[spellResisted](./spellResisted.md){ .md-button }

