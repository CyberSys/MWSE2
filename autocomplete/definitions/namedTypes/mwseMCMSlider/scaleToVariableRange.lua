return {
	type = "method",
	description = [[Scales given `value` from the underlying `tes3uiSlider` widget's range to the range used by the variable. The method on the base MCM Slider component doesn't apply any scale, but the child components may use this to implement scaling.]],
	arguments = {
		{ name = "value", type = "number" }
	},
	returns = {{
		name = "scaledValue", type = "number"
	}}
}
