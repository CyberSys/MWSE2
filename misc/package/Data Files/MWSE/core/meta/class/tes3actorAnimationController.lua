-- This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
-- More information: https://github.com/MWSE/MWSE/tree/master/docs

--- @meta
--- @diagnostic disable:undefined-doc-name

--- Works in conjuction with mobile AI to perform idle, movement, and attack animations. Holds data on the status of the current and next desired animation states for the different body sections that can be animated.
--- @class tes3actorAnimationController
--- @field alphaProperty niAlphaProperty The alpha property applied to the actor. Controls the opacity/opaqueness of the actor.
--- @field animationData tes3animationData Access to the actor's animation data.
--- @field animGroupIdle integer The actor's idle animation. Maps to values in [`tes3.animationGroup`](https://mwse.github.io/MWSE/references/animation-groups/) table.
--- @field animGroupIdle2 integer 
--- @field animGroupMovement integer The actor's movement animations group. Maps to values in [`tes3.animationGroup`](https://mwse.github.io/MWSE/references/animation-groups/) table.
--- @field attachTiming number 
--- @field attackFollowTiming number 
--- @field groundPlaneRotation tes3matrix33 The rotation of the actor around the up-down axis. When converted to euler angles, this axis corresponds to the z axis. The rotation range is [-PI, PI], where rotation of 0 corresponds to the game north.
--- @field hitTiming number This it the time of the actor's attack animation in their `.kf`, played during the hit phase for fully charged attack. It's updated for the attacks from different directions.
--- @field materialProperty niMaterialProperty The material property applied to the actor.
--- @field maxAttackTiming number This it the time of the actor's attack animation in their `.kf` file, when the attack animation is fully charged. It's updated for the attacks from different directions.
--- @field minAttackTiming number This it the time of the actor's attack animation in their `.kf` file, at the earliest point the attack animation can end (when the attack button is just clicked and released). It's updated for the attacks from different directions.
--- @field minHitTiming number This it the time of the actor's attack animation in their `.kf`, played during the hit phase for the minimally charged attack. It's updated for the attacks from different directions.
--- @field mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer *Read-only*. The mobile actor that this controller is responsible for.
--- @field patchedOverrideState integer 
--- @field remainingBlockTime number 
--- @field shouldJump integer 
--- @field speedMultiplier number This is the speed multiplier of the current animation. For example, it is used by the game engine to scale the speed of the turning animation whith the speed at which the player is rotating the view with the mouse. In that case the value range is [0.0, 1.5].
--- @field startTime number This it the starting time of the actor's attack animation in their `.kf` file. It's updated for the attacks from different directions.
--- @field strikeWhenAttackSwingReaches number For NPCs this corresponds to how long the weapon was charged by the NPC after the attack landed. The value is in range [0.0, 1.0]. This property isn't used for the player character.
--- @field vertexColorProperty niVertexColorProperty The vertex color property applied to the actor.
--- @field verticalRotation tes3matrix33 Only used for the player. When converted to euler angles, the rotation about x axis will correspond to the rotation obtained from looking up and down. The rotations around other axes are always zero. In degrees the rotations range from -89.95 degrees for looking up, and 89.95 for looking maximally down.
--- @field weaponSpeed number The animation speed scaling of the weapon animations. This includes all weapon related idle, attack, and ready/unready animations. This value is reset at the starting frame of each weapon strike, normally equal to the the weapon speed. Therefore if you use this it should be changed after every strike, and reset after. Ready/unready actions do not change speed, but are affected by speed.
--- 
--- Use by getting the animation controller from the mobile. e.g. `mobile.animationController.weaponSpeed = 0.5`
tes3actorAnimationController = {}

--- Calculates how much an attack is currently being charged. Returns a value ranging from `0.0` to `1.0`. A value of `1.0` indicates that the attack is fully charged. Will always return `0.0` when not currently charging an attack.
--- @return number result No description yet available.
function tes3actorAnimationController:calculateAttackSwing() end

