<!---
	This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
	More information: https://github.com/MWSE/MWSE/tree/master/docs
-->

# niSkinPartitionPartition

Skinning data for a submesh, optimized for hardware skinning.

## Properties

### `bones`

*Read-only*. The list of bone indices (that influence this partition) from the bones array in the parent `niSkinInstance` node.

**Returns**:

* `result` (integer[])

***

### `bonesPerVertex`



**Returns**:

* `result` (integer)

***

### `stripLengths`

*Read-only*. 

**Returns**:

* `result` (integer[])

***

### `triangles`

*Read-only*. The triangles that form this submesh.

**Returns**:

* `result` ([niTriangle](../../types/niTriangle)[])

***

### `vertices`

*Read-only*. Maps the weight/influence list in this submesh to the vertices in the shape being skinned.

**Returns**:

* `result` (integer[])

***
