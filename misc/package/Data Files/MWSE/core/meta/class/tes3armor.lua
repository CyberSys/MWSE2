--- @meta
--- @diagnostic disable:undefined-doc-name

--- An armor game object.
--- @class tes3armor : tes3item, tes3physicalObject, tes3object, tes3baseObject
--- @field armorRating number The armor's defensive rating.
--- @field armorScalar number *Read-only*. This is the maximal contribution to actor's total Armor Rating for this piece of armor. For vanilla armors, this is slot based. Cuirasses have `armorScalar = 0.3`, helmets, pauldrons, greaves, boots and shields have `0.1`, while gauntlets and bracers have `armorScalar = 0.05`.
--- @field enchantCapacity number The object's enchantment capacity.
--- @field enchantment tes3enchantment The enchantment used by the object.
--- @field icon string The path to the object's icon.
--- @field isLeftPart boolean Determines if the armor is the left part of a pair.
--- @field maxCondition number The object's maximum condition.
--- @field mesh string The path to the object's mesh.
--- @field name string The player-facing name for the object.
--- @field parts tes3wearablePart[] *Read-only*. An array-style table of the [`tes3wearablePart`](https://mwse.github.io/MWSE/types/tes3wearablePart/) data on the object.
--- @field script tes3script The script that runs on the object.
--- @field slot number The slot used by the armor. Maps to [`tes3.armorSlot`](https://mwse.github.io/MWSE/references/armor-slots/) namespace.
--- @field slotName string *Read-only*. The name of the slot used by the armor.
--- @field value number The value of the object.
--- @field weight number The weight of the object.
--- @field weightClass number *Read-only*. The weight class of the armor. This value maps to [`tes3.armorWeightClass`](https://mwse.github.io/MWSE/references/armor-weight-classes/) constants.
tes3armor = {}

--- Calculates what armor rating is provided for a given mobile actor.
--- @param mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer No description yet available.
function tes3armor:calculateArmorRating(mobile) end

