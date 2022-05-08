return {
	type = "event",
	description = [[One of the movement events, **calcSwimSpeed** is used when calculating the movement speed while in water when running.

The movement event flow is described below:

- Swimming: [calcWalkSpeed](https://mwse.github.io/MWSE/events/calcWalkSpeed) -> **calcSwimSpeed** -> [calcMoveSpeed](https://mwse.github.io/MWSE/events/calcMoveSpeed)
- Swimming (while running): [calcWalkSpeed](https://mwse.github.io/MWSE/events/calcWalkSpeed) -> **calcSwimSpeed** -> [calcSwimRunSpeed](https://mwse.github.io/MWSE/events/calcSwimRunSpeed) -> [calcMoveSpeed](https://mwse.github.io/MWSE/events/calcMoveSpeed)]],
	related = { "calcMoveSpeed", "calcWalkSpeed", "calcRunSpeed", "calcFlySpeed", "calcSwimSpeed", "calcSwimRunSpeed" },
	eventData = {
		["mobile"] = {
			type = "tes3mobileActor",
			readOnly = true,
			description = "The mobile actor whose speed is being calculated.",
		},
		["reference"] = {
			type = "tes3reference",
			readOnly = true,
			description = "mobile’s related reference.",
		},
		["speed"] = {
			type = "number",
			description = "The previous speed calculated, starting with the base engine values.",
		},
		["type"] = {
			type = "number",
			readOnly = true,
			description = "The type of movement that was calculated. This is always 3 for this event.",
		},
	},
}