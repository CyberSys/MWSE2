# tes3animationGroup
<div class="search_terms" style="display: none">tes3animationgroup, animationgroup</div>

<!---
	This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
	More information: https://github.com/MWSE/MWSE/tree/master/docs
-->

A game object that astores animation group data from loaded keyframe data.

## Properties

### `actionCount`
<div class="search_terms" style="display: none">actioncount</div>

*Read-only*. The number of action note keys.

**Returns**:

* `result` (number)

***

### `actionFrames`
<div class="search_terms" style="display: none">actionframes</div>

*Read-only*. The action frame numbers array. The available action indexes depend on the purpose of the animation group.

**Returns**:

* `result` (number[])

***

### `actionTimings`
<div class="search_terms" style="display: none">actiontimings</div>

*Read-only*. The action frame timings array. The available action indexes depend on the purpose of the animation group.

**Returns**:

* `result` (number[])

***

### `groupId`
<div class="search_terms" style="display: none">groupid</div>

*Read-only*. The animation group ID. Useful when iterating through groups using nextGroup.

**Returns**:

* `result` (number)

***

### `nextGroup`
<div class="search_terms" style="display: none">nextgroup</div>

*Read-only*. The next animation group in this keyframe data.

**Returns**:

* `result` ([tes3animationGroup](../types/tes3animationGroup.md))

***

### `soundGenCount`
<div class="search_terms" style="display: none">soundgencount</div>

*Read-only*. The number of soundgen note keys.

**Returns**:

* `result` (number)

***

### `soundGenKeys`
<div class="search_terms" style="display: none">soundgenkeys</div>

*Read-only*. An array containing the soundgens.

**Returns**:

* `result` ([tes3animationGroupSoundGenKey](../types/tes3animationGroupSoundGenKey.md)[])
