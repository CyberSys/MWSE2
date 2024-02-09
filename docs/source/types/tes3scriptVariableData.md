# tes3scriptVariableData
<div class="search_terms" style="display: none">tes3scriptvariabledata, scriptvariabledata</div>

<!---
	This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
	More information: https://github.com/MWSE/MWSE/tree/master/docs
-->

Table returned by the `tes3script:getVariableData` and `tes3scriptContext:getVariableData` methods.

## Properties

### `index`
<div class="search_terms" style="display: none">index</div>

*Read-only*. The order of occurrence of the variable in the script, starting from `0`.

**Returns**:

* `result` (integer)

***

### `type`
<div class="search_terms" style="display: none">type</div>

*Read-only*. The mwscript variable type.

Type | Description
---- | -----------
`s`  | The variable is of `short` type.
`f`  | The variable is of `float` type.
`l`  | The variable is of `long` type.


**Returns**:

* `result` (string)

***

### `value`
<div class="search_terms" style="display: none">value</div>

The current value of the variable.

**Returns**:

* `result` (number, nil)
