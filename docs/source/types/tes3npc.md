# tes3npc

An NPC object that has not been cloned. Typically represents the raw information edited in the construction set.

This type inherits the following: [tes3actor](../../types/tes3actor), [tes3physicalObject](../../types/tes3physicalObject), [tes3object](../../types/tes3object), [tes3baseObject](../../types/tes3baseObject)
## Properties

### `actorFlags`

*Read-only*. A number representing the actor flags. Truly a bit field.

**Returns**:

* `result` (number)

***

### `aiConfig`

*Read-only*. A substructure off of actors that contains information on the current AI configuration.

**Returns**:

* `result` (tes3aiConfig)

***

### `attributes`

A table of eight numbers, representing the base values for the actor's attributes.

**Returns**:

* `result` (table)

***

### `autoCalc`

Direct access to the actor autocalc flag.

**Returns**:

* `result` (boolean)

***

### `barterGold`

Friendly access to actor's barter gold amount.

**Returns**:

* `result` (number)

***

### `baseDisposition`

The actor's base disposition.

**Returns**:

* `result` (number)

***

### `blocked`

The blocked state of the object.

**Returns**:

* `result` (boolean)

***

### `blood`

Friendly access to actor's blood type.

**Returns**:

* `result` (number)

***

### `boundingBox`

The bounding box for the object.

**Returns**:

* `result` ([tes3boundingBox](../../types/tes3boundingBox))

***

### `class`

*Read-only*. The class that the NPC uses.

**Returns**:

* `result` ([tes3class](../../types/tes3class))

***

### `cloneCount`

*Read-only*. The number of clones that exist of this actor.

**Returns**:

* `result` (number)

***

### `deleted`

*Read-only*. The deleted state of the object.

**Returns**:

* `result` (boolean)

***

### `disabled`

*Read-only*. The disabled state of the object.

**Returns**:

* `result` (boolean)

***

### `equipment`

*Read-only*. The items currently equipped to the actor.

**Returns**:

* `result` ([tes3iterator](../../types/tes3iterator))

***

### `faction`

*Read-only*. The class that the NPC is joined to.

**Returns**:

* `result` ([tes3faction](../../types/tes3faction))

***

### `factionIndex`

No description yet available.

**Returns**:

* `result` (number)

***

### `factionRank`

The NPC's rank in their faction.

**Returns**:

* `result` (number)

***

### `fatigue`

The actor's max fatigue.

**Returns**:

* `result` (number)

***

### `female`

Direct access to the actor female flag.

**Returns**:

* `result` (boolean)

***

### `hair`

The hair body part that the NPC will use.

**Returns**:

* `result` ([tes3bodyPart](../../types/tes3bodyPart))

***

### `head`

The head body part that the NPC will use.

**Returns**:

* `result` ([tes3bodyPart](../../types/tes3bodyPart))

***

### `health`

The actor's max health.

**Returns**:

* `result` (number)

***

### `id`

*Read-only*. The unique identifier for the object.

**Returns**:

* `result` (string)

***

### `inventory`

*Read-only*. The items currently carried by the actor.

**Returns**:

* `result` ([tes3inventory](../../types/tes3inventory))

***

### `isAttacked`

*Read-only*. If true, the actor's attacked flag is set.

**Returns**:

* `result` (boolean)

***

### `isEssential`

*Read-only*. If true, the actor's essential flag is set.

**Returns**:

* `result` (boolean)

***

### `isInstance`

Always returns false.

**Returns**:

* `result` (boolean)

***

### `isLocationMarker`

True if this object is an editor marker for a gameplay location. These include travel, intervention, prison, door, and interior north markers. Markers are invisible in-game.

**Returns**:

* `result` (boolean)

***

### `isRespawn`

*Read-only*. If true, the actor's respawn flag is set.

**Returns**:

* `result` (boolean)

***

### `level`

The actor's level.

**Returns**:

* `result` (number)

***

### `magicka`

The actor's max magicka.

**Returns**:

* `result` (number)

***

### `mesh`

The path to the object's mesh.

**Returns**:

* `result` (string)

***

### `modified`

The modification state of the object since the last save.

**Returns**:

* `result` (boolean)

***

### `name`

The player-facing name for the object.

**Returns**:

* `result` (string)

***

### `nextInCollection`

The next object in parent collection's list.

**Returns**:

* `result` ([tes3object](../../types/tes3object))

***

### `objectFlags`

*Read-only*. The raw flags of the object.

**Returns**:

* `result` (number)

***

### `objectType`

*Read-only*. The type of object. Maps to values in tes3.objectType.

**Returns**:

* `result` (number)

***

### `owningCollection`

The collection responsible for holding this object.

**Returns**:

* `result` ([tes3referenceList](../../types/tes3referenceList))

***

### `persistent`

The persistent flag of the object.

**Returns**:

* `result` (boolean)

***

### `previousInCollection`

The previous object in parent collection's list.

**Returns**:

* `result` ([tes3object](../../types/tes3object))

***

### `race`

*Read-only*. The race that the NPC uses.

**Returns**:

* `result` ([tes3race](../../types/tes3race))

***

### `reputation`

The actor's base reputation.

**Returns**:

* `result` (number)

***

### `scale`

The object's scale.

**Returns**:

* `result` (number)

***

### `sceneCollisionRoot`

The scene graph node for this object's physics collision, if its mesh has a root collision node.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `sceneNode`

The scene graph node for this object.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `sceneReference`

The scene graph reference node for this object.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `script`

The script that runs on the object.

**Returns**:

* `result` (tes3script)

***

### `skills`

A table of twenty seven numbers, representing the base values for the NPC's skills.

**Returns**:

* `result` (table)

***

### `sourceless`

The soruceless flag of the object.

**Returns**:

* `result` (boolean)

***

### `sourceMod`

*Read-only*. The filename of the mod that owns this object.

**Returns**:

* `result` (string)

***

### `spells`

*Read-only*. A list of spells that the actor has access to. It is a tes3spellList, which is a list wrapper with helper functions. The actual list is accessed with .iterator. e.g. for _, spell in pairs(npc.spells.iterator) do print(spell.name) end

**Returns**:

* `result` ([tes3spellList](../../types/tes3spellList))

***

### `stolenList`

A list of actors that the object has been stolen from.

**Returns**:

* `result` ([tes3iterator](../../types/tes3iterator))

***

### `supportsLuaData`

If true, references of this object can store temporary or persistent lua data.

**Returns**:

* `result` (boolean)

***

## Methods

### `__tojson`

Serializes the object to json.

```lua
local string = tes3baseObject:__tojson()
```

**Returns**:

* `string` (string)

***

### `offersService`

Checks if the actor will offer a service in dialogue. This an offer and may still be refused by dialogue checks. To also get the result of dialogue checks, use tes3.checkMerchantOffersService.

```lua
local result = tes3actor:offersService(service)
```

**Parameters**:

* `service` (number): Use one of the tes3.merchantService.* constants.

**Returns**:

* `result` (boolean)

***

### `onInventoryClose`

A callback function invoked when an inventory is closed. Typically not used outside of specific purposes. You may find tes3.reference's onCloseInventory() to be more convenient to use.

```lua
tes3actor:onInventoryClose(reference)
```

**Parameters**:

* `reference` ([tes3reference](../../types/tes3reference))

***

### `tradesItemType`

Checks if the actor will buy and sell items of a given object type. e.g. actor:tradesItemType(tes3.objectType.repairItem)

```lua
local result = tes3actor:tradesItemType(objectType)
```

**Parameters**:

* `objectType` (tes3objectType): tes3.objectType.* constants can be passed here.

**Returns**:

* `result` (boolean)

***
