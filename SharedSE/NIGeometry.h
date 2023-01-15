#pragma once

#include "NIAVObject.h"
#include "NIGeometryData.h"
#include "NISkinInstance.h"

namespace NI {
	struct Geometry_vTable : AVObject_vTable {
		void* (__thiscall* setModelData)(Geometry*, GeometryData*); // 0x94
		void(__thiscall* calculateNormals)(Geometry*); // 0x98
	};
	static_assert(sizeof(Geometry_vTable) == 0x9C, "NI::Geometry_vTable failed size validation");

	struct Geometry : AVObject {
		void* propertyState; // 0x90
		void* effectState; // 0x94
		Pointer<GeometryData> modelData; // 0x98
		Pointer<SkinInstance> skinInstance; // 0x9C
		Vector3* worldVertices; // 0xA0
		Vector3* worldNormals; // 0xA4
		bool bWorldVerticesDirty; // 0xA8
		bool bWorldNormalsDirty; // 0xA9

		inline GeometryData* getModelData() {
			return modelData;
		}

		inline void setModelData(GeometryData* data) {
			vTable.asGeometry->setModelData(this, data);
		}
	};
	static_assert(sizeof(Geometry) == 0xAC, "NI::Geometry failed size validation");
}