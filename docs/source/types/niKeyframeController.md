<!---
	This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
	More information: https://github.com/MWSE/MWSE/tree/master/docs
-->

# niKeyframeController

The controller responsible for animating transforms, using position, rotation, and scale keys.

This type inherits the following: [niTimeController](../../types/niTimeController), [niObject](../../types/niObject)
## Properties

### `active`

If the controller is active. When inactive, the target does not get updated and animation timing does not advance.

**Returns**:

* `result` (boolean)

***

### `animTimingType`

How the time parameter passed to the update function is treated. Type 0 is the default, which treats the update time as a delta time. Type 1 treats the update time an offset from the start of the animation.

**Returns**:

* `result` (number)

***

### `cycleType`

The animation cycle type. Type 0 is looping, type 2 is reverse, type 4 is clamped.

**Returns**:

* `result` (number)

***

### `data`

*Read-only*. The keyframe data used by the controller.

**Returns**:

* `result` ([niKeyframeData](../../types/niKeyframeData))

***

### `frequency`

The animation controller's frequency value.

**Returns**:

* `result` (number)

***

### `highKeyFrame`

No description.

**Returns**:

* `result` (number)

***

### `lastScaledTime`

No description.

**Returns**:

* `result` (number)

***

### `lastTime`

No description.

**Returns**:

* `result` (number)

***

### `lastUsedPositionIndex`

The last position index that the game engine used.

**Returns**:

* `result` (number)

***

### `lastUsedRotationIndex`

The last rotation index that the game engine used.

**Returns**:

* `result` (number)

***

### `lastUsedScaleIndex`

The last scale index that the game engine used.

**Returns**:

* `result` (number)

***

### `lowKeyFrame`

No description.

**Returns**:

* `result` (number)

***

### `nextController`

The next NiTimeController in the list of controllers containing the calling controller.

**Returns**:

* `result` ([niTimeController](../../types/niTimeController))

***

### `phase`

The phase value.

**Returns**:

* `result` (number)

***

### `refCount`

*Read-only*. The number of references that exist for this object. When this value reaches zero, the object will be deleted.

**Returns**:

* `result` (number)

***

### `references`

*Read-only*. The number of references that exist for the given object. When this value hits zero, the object's memory is freed.

**Returns**:

* `result` (string)

***

### `RTTI`

*Read-only*. The runtime type information for this object. This is an alias for the `.runTimeTypeInformation` property.

**Returns**:

* `result` ([niRTTI](../../types/niRTTI))

***

### `runTimeTypeInformation`

*Read-only*. The runtime type information for this object.

**Returns**:

* `result` ([niRTTI](../../types/niRTTI))

***

### `startTime`

No description.

**Returns**:

* `result` (number)

***

### `target`

The scene graph object that this animation controller is to animate.

**Returns**:

* `result` ([niObjectNET](../../types/niObjectNET))

***

## Methods

### `clone`

Creates a copy of this object.

```lua
local result = myObject:clone()
```

**Returns**:

* `result` ([niObject](../../types/niObject))

***

### `isInstanceOfType`

Determines if the object is of a given type, or of a type derived from the given type. Types can be found in the [`tes3.niType`](https://mwse.github.io/MWSE/references/niTypes/) table.

```lua
local result = myObject:isInstanceOfType(type)
```

**Parameters**:

* `type` (number): Use values in the [`tes3.niType`](https://mwse.github.io/MWSE/references/niTypes/) table.

**Returns**:

* `result` (boolean)

***

### `isOfType`

Determines if the object is of a given type. Types can be found in the [`tes3.niType`](https://mwse.github.io/MWSE/references/niTypes/) table.

```lua
local result = myObject:isOfType(type)
```

**Parameters**:

* `type` (number): Use values in the [`tes3.niType`](https://mwse.github.io/MWSE/references/niTypes/) table.

**Returns**:

* `result` (boolean)

***

### `saveBinary`

Serializes the object, and writes it to the given file.

```lua
local success = myObject:saveBinary(path)
```

**Parameters**:

* `path` (string): The path to write the file at, relative to the Morrowind installation folder.

**Returns**:

* `success` (boolean): If true the object was successfully serialized.

***

### `start`

Starts the controller at the specified time.

```lua
myObject:start(time)
```

**Parameters**:

* `time` (number)

***

### `stop`

Stops the controller. If you only want to pause the controller, use the `update` property.

```lua
myObject:stop()
```

***
