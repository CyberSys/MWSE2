#include "NISkinInstanceLua.h"

#include "LuaManager.h"

#include "NISkinInstance.h"

namespace mwse::lua {
	void bindNISkinInstance() {
		// Get our lua state.
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;

		// Binding for NI::SkinInstance.
		{
			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<NI::SkinInstance>("niSkinInstance");
			usertypeDefinition["new"] = sol::no_constructor;

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition[sol::base_classes] = sol::bases<NI::Object>();

			// Basic bindings.
			usertypeDefinition["data"] = &NI::SkinInstance::skinData;
			usertypeDefinition["root"] = &NI::SkinInstance::rootParent;
		}

		// Binding for NI::SkinPartition.
		{
			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<NI::SkinPartition>("niSkinPartition");
			usertypeDefinition["new"] = sol::no_constructor;

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition[sol::base_classes] = sol::bases<NI::Object>();

			// Basic bindings.
			usertypeDefinition["partitions"] = sol::readonly_property(&NI::SkinPartition::getPartitions);
		}

		// Binding for NI::SkinPartition::Partition.
		{
			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<NI::SkinPartition::Partition>("niSkinPartitionPartition");
			usertypeDefinition["new"] = sol::no_constructor;

			// Basic bindings.
			usertypeDefinition["bones"] = sol::readonly_property(&NI::SkinPartition::Partition::getBones);
			usertypeDefinition["bonesPerVertex"] = &NI::SkinPartition::Partition::numBonesPerVertex;
			usertypeDefinition["stripLengths"] = sol::readonly_property(&NI::SkinPartition::Partition::getStripLengths);
			usertypeDefinition["triangles"] = sol::readonly_property(&NI::SkinPartition::Partition::getTriangles);
			usertypeDefinition["vertices"] = sol::readonly_property(&NI::SkinPartition::Partition::getVertices);
		}

		// Binding for NI::SkinData.
		{
			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<NI::SkinData>("niSkinData");
			usertypeDefinition["new"] = sol::no_constructor;

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition[sol::base_classes] = sol::bases<NI::Object>();

			// Basic bindings.
			usertypeDefinition["boneData"] = sol::readonly_property(&NI::SkinData::getBones);
			usertypeDefinition["partition"] = &NI::SkinData::partition;
			usertypeDefinition["rotation"] = &NI::SkinData::rotation;
			usertypeDefinition["scale"] = &NI::SkinData::scale;
			usertypeDefinition["translation"] = &NI::SkinData::translation;
		}

		// Binding for NI::SkinData::BoneData.
		{
			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<NI::SkinData::BoneData>("niSkinDataBoneData");
			usertypeDefinition["new"] = sol::no_constructor;

			// Basic bindings.
			usertypeDefinition["bounds"] = &NI::SkinData::BoneData::bounds;
			usertypeDefinition["rotation"] = &NI::SkinData::BoneData::rotation;
			usertypeDefinition["scale"] = &NI::SkinData::BoneData::scale;
			usertypeDefinition["translation"] = &NI::SkinData::BoneData::translation;
			usertypeDefinition["weights"] = sol::readonly_property(&NI::SkinData::BoneData::getWeights);
		}

		// Binding for NI::SkinData::BoneData::VertexWeight.
		{
			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<NI::SkinData::BoneData::VertexWeight>("niSkinDataBoneDataVertexWeight");
			usertypeDefinition["new"] = sol::no_constructor;

			// Basic bindings.
			usertypeDefinition["index"] = &NI::SkinData::BoneData::VertexWeight::index;
			usertypeDefinition["weight"] = &NI::SkinData::BoneData::VertexWeight::weight;
		}
	}
}
