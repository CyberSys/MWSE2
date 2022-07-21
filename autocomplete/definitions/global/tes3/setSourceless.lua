return {
	type = "function",
	description = [[Sets an object (of any kind) to be sourceless, which are objects the game does not store in savegames. This can be useful for mod-created temporary objects which are not necessary to save.]],
	arguments = {
		{ name = "object", type = "tes3baseObject", description = "The object whose sourceless flag to modify." },
		{ name = "sourceless", type = "boolean", optional = true, default = true, description = "Allows flagging an object as sourceless or undoing that action." },
	},
}
