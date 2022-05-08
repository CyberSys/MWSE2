--- @meta
--- @diagnostic disable:undefined-doc-name

--- A faction game object.
--- @class tes3faction : tes3baseObject
--- @field attributes number[] *Read-only*. An array-style table holding the two attributes that govern advancement. Maps to values in [`tes3.attribute`](https://mwse.github.io/MWSE/references/attributes/) namespace.
--- @field name string The faction's player-facing name.
--- @field playerExpelled boolean The player's expelled state in the faction.
--- @field playerJoined boolean The player's join state for the faction.
--- @field playerRank number The player's current rank in the faction.
--- @field playerReputation number The player's current reputation in the faction.
--- @field ranks tes3factionRank[] *Read-only*. An array-style table holding the ten related [`tes3factionRank`](https://mwse.github.io/MWSE/types/tes3factionRank/)s.
--- @field reactions tes3factionReaction[] *Read-only*. A collection of [`tes3factionReaction`](https://mwse.github.io/MWSE/types/tes3factionReaction/)s.
--- @field skills number[] *Read-only*. An array-style table holding the seven skills that govern advancement. Maps to values in [`tes3.skill`](https://mwse.github.io/MWSE/references/skills/) namespace.
tes3faction = {}

--- This function fetches the player-facing name of a rank in the faction.
--- @param rank number A rank number in range [0, 9] inclusive.
--- @return string result No description yet available.
function tes3faction:getRankName(rank) end

--- This function changes the player-facing name of a given rank in the faction.
--- @param rank number A rank number in range [0, 9] inclusive.
--- @param name string A new name to set.
function tes3faction:setRankName(rank, name) end

