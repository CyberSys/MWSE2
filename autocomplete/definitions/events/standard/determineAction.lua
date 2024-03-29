return {
	type = "event",
	description = "This event fires when an actor determines an action in a combat session.",
	related = { "determinedAction" },
	eventData = {
		["session"] = {
			type = "tes3combatSession",
			readOnly = true,
			description = "The combat session the action is being determined for.",
		},
	},
	blockable = true,
}