# mwse.string
<div class="search_terms" style="display: none">mwse.string</div>

<!---
	This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
	More information: https://github.com/MWSE/MWSE/tree/master/docs
-->

The mwse string library provides functions for interacting with mwscript string storage.

## Functions

### `mwse.string.create`
<div class="search_terms" style="display: none">create</div>

Creates a string in storage, and returns the numerical key for it.

If the string is already in storage, the previous key will be returned.

```lua
local result = mwse.string.create(value)
```

**Parameters**:

* `value` (string)

**Returns**:

* `result` (number)

***

### `mwse.string.get`
<div class="search_terms" style="display: none">get</div>

Returns the numerical key for a given string in storage, or nil if the string isn't in storage.

```lua
local unnamed1 = mwse.string.get(id)
```

**Parameters**:

* `id` (number): *Optional*.

**Returns**:

* `unnamed` (string)

