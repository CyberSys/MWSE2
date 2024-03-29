# musicChangeTrack
<div class="search_terms" style="display: none">musicchangetrack</div>

<!---
	This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
	More information: https://github.com/MWSE/MWSE/tree/master/docs
-->

The `musicChangeTrack` event when the game is changing to play a new piece of music.

```lua
--- @param e musicChangeTrackEventData
local function musicChangeTrackCallback(e)
end
event.register(tes3.event.musicChangeTrack, musicChangeTrackCallback)
```

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `context` (string): *Read-only*. A short lowercase string that describes why the music is being played, to give more context. `explore` and `combat` values mean the game has chosen a new background music to play. `title` will play (and loop) on the main menu. `level` will play whenever the player has rested and is ready to level up. `mwscript` means a script has used the `StreamMusic` mwscript command. `death` means the player has died. `lua` means that a lua script has requested new music.
* `crossfade` (number): The number of milliseconds of crossfade that will be used to blend the current music to the new music.
* `music` (string): The track that will be played. This can be changed to a new path, but it must be valid. Note that unlike the `musicSelectTrack` event, this value is not relative to `Data Files\music`.
* `situation` ([tes3.musicSituation](../references/music-situations.md)): *Read-only*. Maps to [`tes3.musicSituation`](https://mwse.github.io/MWSE/references/music-situations/), indicating combat, non-combat, or scripted music.
* `volume` (number): The volume of the track to be played, ranging from `0.0` to `1.0`. This can be modified.


## Related events

[musicSelectTrack](./musicSelectTrack.md){ .md-button }

