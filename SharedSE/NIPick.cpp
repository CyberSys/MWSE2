#include "NIPick.h"

#include "NITriShape.h"
#include "NITriShapeData.h"

#include "ExceptionUtil.h"
#include "MemoryUtil.h"

namespace NI {
	Pick::Pick() {
#if defined(SE_NI_PICK_FNADDR_CTOR) && SE_NI_PICK_FNADDR_CTOR > 0
		// Cleanup automatic cruft.
		se::memory::_delete(results.storage);
		memset(this, 0, sizeof(Pick));

		const auto NI_Pick_ctor = reinterpret_cast<void(__thiscall*)(Pick*)>(SE_NI_PICK_FNADDR_CTOR);
		NI_Pick_ctor(this);
#else
		throw not_implemented_exception();
#endif
	}

	Pick::~Pick() {
#if defined(SE_NI_PICK_FNADDR_DTOR) && SE_NI_PICK_FNADDR_DTOR > 0
		const auto NI_Pick_ctor = reinterpret_cast<void(__thiscall*)(Pick*)>(SE_NI_PICK_FNADDR_DTOR);
		NI_Pick_ctor(this);
#else
		throw not_implemented_exception();
#endif
	}

	bool Pick::pickObjects(const Vector3* origin, const Vector3* direction, bool append, float maxDistance) {
#if defined(SE_NI_PICK_FNADDR_PICKOBJECTS) && SE_NI_PICK_FNADDR_PICKOBJECTS > 0
		const auto TES3_Pick_pickObjects = reinterpret_cast<bool(__thiscall*)(Pick*, const Vector3*, const Vector3*, bool, float)>(SE_NI_PICK_FNADDR_PICKOBJECTS);
		return TES3_Pick_pickObjects(this, origin, direction, append, maxDistance);
#else
		throw not_implemented_exception();
#endif
	}

	struct SavedGeometryState {
		Pointer<TriShape> geometry;
		Pointer<TriShapeData> data;
		Pointer<SkinInstance> skinInstance;
	};

	bool Pick::pickObjectsWithSkinDeforms(const Vector3* origin, const Vector3* direction, bool append, float maxDistance) {
		// Data to restore skinned objects to their original state.
		std::vector<SavedGeometryState> savedGeometryStates;

		// Perform our first test.
		if (!pickObjects(origin, direction, append, maxDistance)) {
			return false;
		}

		// Store if a redo is needed.
		auto needsRedo = false;

		// Check to see if any skinned objects were hit.
		for (auto& result : results) {
			if (result == nullptr) {
				continue;
			}

			// Skip if we're not affecting tri-based geometry.
			if (!result->object->isInstanceOfType(RTTIStaticPtr::NiTriShape)) {
#if _DEBUG
				if (result->object->skinInstance) {
					throw std::exception("Unaccounted for type of skinned object!");
				}
#endif
				continue;
			}

			const auto geometry = static_cast<TriShape*>(result->object);

			// If the geometry is skinned we apply the skin deform and set the redo flag.
			// This way the redo raycast (and future raycasts) can handle the object correctly.
			if (geometry->skinInstance) {
				needsRedo = true;

				// Create our backup data.
				savedGeometryStates.push_back({});
				auto& backup = savedGeometryStates.back();
				backup.geometry = geometry;

				// Clone the data.
				backup.data = geometry->getModelData();
				auto data = backup.data->copyData(true, false, false);
				data->bounds = backup.data->bounds;
				geometry->setModelData(data);

				// Apply the skin deform to the new copy.
				geometry->skinInstance->deform(backup.data->vertex, backup.data->normal, data->vertexCount, data->vertex, data->normal);
				data->markAsChanged();

				// Backup and clear skin instance.
				backup.skinInstance = geometry->skinInstance;
				geometry->skinInstance = nullptr;

				geometry->update();
			}
		}

		// Perform another raytest if necessary.
		// TODO: To optimize this further, perform a second pick in another root with only the skinned geometry, and update the existing distances.
		if (needsRedo) {
			clearResults();
			pickObjects(origin, direction, append, maxDistance);
		}

		// Restore existing geomtry data.
		for (const auto& state : savedGeometryStates) {
			state.geometry->setModelData(state.data);
			state.geometry->skinInstance = state.skinInstance;
			state.geometry->update();
		}

		return true;
	}

	void Pick::clearResults() {
#if defined(SE_NI_PICK_FNADDR_CLEARRESULTS) && SE_NI_PICK_FNADDR_CLEARRESULTS > 0
		const auto TES3_Pick_clearResults = reinterpret_cast<void(__thiscall*)(Pick*)>(SE_NI_PICK_FNADDR_CLEARRESULTS);
		TES3_Pick_clearResults(this);
#else
		throw not_implemented_exception();
#endif
	}

	PickRecord* Pick::getFirstUnskinnedResult() const {
		for (const auto& result : results) {
			if (result && result->object && result->object->skinInstance == nullptr) {
				return result;
			}
		}
		return nullptr;
	}

	std::reference_wrapper<unsigned short[3]> PickRecord::getVertexIndex() {
		return std::ref(vertexIndex);
	}
}
