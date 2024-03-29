return {
	type = "method",
	description = [[Damages the actor's fatigue, with accompanying reaction from the reciever. Invokes the [`damageHandToHand`](https://mwse.github.io/MWSE/events/damageHandToHand/) and [`damagedHandToHand`](https://mwse.github.io/MWSE/events/damagedHandToHand/) events, with `tes3.damageSource.script` source. Returns the actual fatigue damage done.]],
	arguments = {
		{ name = "fatigueDamage", type = "number", description = "The amount of fatigue damage to apply." },
		{ name = "swing", type = "number", optional = true, description = "The attack swing magnitude, range 0-1. Only modifies hit volume." },
		{ name = "alwaysPlayHitVoice", type = "boolean", optional = true, description = "Always play the hit reaction voiceover." },
	},
	valuetype = "number",
}