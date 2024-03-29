return {
	type = "event",
	description = "The projectileExpire event fires just prior to a fired projectile expiring.",
	related = { "projectileHitActor", "projectileHitObject", "projectileHitTerrain", "projectileExpire" },
	eventData = {
		["mobile"] = {
			type = "tes3mobileProjectile",
			readOnly = true,
			description = "The mobile projectile that is expiring.",
		},
		["firingReference"] = {
			type = "tes3reference",
			readOnly = true,
			description = "Reference to the actor that fired the projectile.",
		},
		["firingWeapon"] = {
			type = "tes3weapon",
			readOnly = true,
			description = "The weapon that fired the projectile.",
		},
	},
}