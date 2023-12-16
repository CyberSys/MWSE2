#pragma once

#include "NIGeometry.h"
#include "NISwitchNode.h"

namespace se::cs::dialog::render_window {
	enum WidgetsAxis {
		X = 0,
		Y = 1,
		Z = 2,
	};

	struct WidgetsController {
		NI::Pointer<NI::Node> root;
		NI::Pointer<NI::SwitchNode> axisLines;
		NI::Pointer<NI::Node> gridRoot;
		NI::Pointer<NI::Geometry> debugUnitArrows;
		NI::Pointer<NI::Geometry> debugUnitPlane;
		NI::Pointer<NI::Geometry> debugUnitSphere;

		WidgetsController();
		~WidgetsController();

		void show();
		void hide();
		bool isShown();

		void setAxis(WidgetsAxis axis);
		void setPosition(NI::Vector3& position);

		void updateGrid(NI::Vector3& position, float radius, int gridSnap);
		void showGrid();
		void hideGrid();
	};
}