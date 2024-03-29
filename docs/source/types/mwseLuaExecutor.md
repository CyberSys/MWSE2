# mwseLuaExecutor
<div class="search_terms" style="display: none">mwseluaexecutor</div>

<!---
	This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
	More information: https://github.com/MWSE/MWSE/tree/master/docs
-->

A handle to a command excuted using `os.execute` configured to run asynchronously.

## Properties

### `command`
<div class="search_terms" style="display: none">command</div>

The command originally passed to `os.execute`.

**Returns**:

* `result` (string)

***

### `errorCode`
<div class="search_terms" style="display: none">errorcode</div>

The error code of the program, or 0 if there was no error.

**Returns**:

* `result` (number)

***

### `exitCode`
<div class="search_terms" style="display: none">exitcode</div>

The exit code of the program, or nil if the program has not yet finished.

**Returns**:

* `result` (number, nil)

***

### `ready`
<div class="search_terms" style="display: none">ready</div>

If true, the program is no longer running and output can be read.

**Returns**:

* `result` (boolean)

***

## Methods

### `getOutput`
<div class="search_terms" style="display: none">getoutput, output</div>

Reads the current output of the program, and clears the output buffer.

```lua
local output = myObject:getOutput()
```

**Returns**:

* `output` (string): The output written to stdout by the program.

***

### `wait`
<div class="search_terms" style="display: none">wait</div>

Pauses the main thread, locking up the program until the program has finished.

```lua
myObject:wait()
```

