#pragma once

#include "CSDefines.h"

#include "NIIteratedList.h"
#include "NIVector3.h"

namespace se::cs::dialog::actor_ai_window {
	constexpr UINT DIALOG_ID = 154;

	// Default IDs.
	constexpr UINT CONTROL_ID_ADD_PACKAGE_COMBO = 1571;
	constexpr UINT CONTROL_ID_ALARM_EDIT = 1576;
	constexpr UINT CONTROL_ID_BARTER_GOLD_EDIT = 1560;
	constexpr UINT CONTROL_ID_BUYSELL_APPARATUS_CHECKBOX = 1535;
	constexpr UINT CONTROL_ID_BUYSELL_ARMOR_CHECKBOX = 1528;
	constexpr UINT CONTROL_ID_BUYSELL_BOOKS_CHECKBOX = 1530;
	constexpr UINT CONTROL_ID_BUYSELL_CLOTHING_CHECKBOX = 1529;
	constexpr UINT CONTROL_ID_BUYSELL_INGREDIENTS_CHECKBOX = 1531;
	constexpr UINT CONTROL_ID_BUYSELL_LIGHTS_CHECKBOX = 1534;
	constexpr UINT CONTROL_ID_BUYSELL_MAGIC_ITEMS_CHECKBOX = 1539;
	constexpr UINT CONTROL_ID_BUYSELL_MISCELLANEOUS_CHECKBOX = 1537;
	constexpr UINT CONTROL_ID_BUYSELL_PICKS_CHECKBOX = 1532;
	constexpr UINT CONTROL_ID_BUYSELL_POTIONS_CHECKBOX = 1540;
	constexpr UINT CONTROL_ID_BUYSELL_PROBES_CHECKBOX = 1533;
	constexpr UINT CONTROL_ID_BUYSELL_REPAIR_ITEMS_CHECKBOX = 1536;
	constexpr UINT CONTROL_ID_BUYSELL_SPELLS_CHECKBOX = 1538;
	constexpr UINT CONTROL_ID_BUYSELL_WEAPONS_CHECKBOX = 1527;
	constexpr UINT CONTROL_ID_CANCEL_BUTTON = 2;
	constexpr UINT CONTROL_ID_FIGHT_EDIT = 1574;
	constexpr UINT CONTROL_ID_FLEE_EDIT = 1575;
	constexpr UINT CONTROL_ID_HELLO_EDIT = 1577;
	constexpr UINT CONTROL_ID_PACKAGE_DETAILS_EDIT = 1570;
	constexpr UINT CONTROL_ID_PACKAGE_LIST_VIEW = 1572;
	constexpr UINT CONTROL_ID_SAVE_BUTTON = 1;
	constexpr UINT CONTROL_ID_SERVICE_ENCHANTING_CHECKBOX = 1544;
	constexpr UINT CONTROL_ID_SERVICE_REPAIR_CHECKBOX = 1545;
	constexpr UINT CONTROL_ID_SERVICE_SPELLMAKING_CHECKBOX = 1543;
	constexpr UINT CONTROL_ID_SERVICE_TRAINING_CHECKBOX = 1542;
	constexpr UINT CONTROL_ID_TRAVEL_SERVICE_1_COMBO = 1551;
	constexpr UINT CONTROL_ID_TRAVEL_SERVICE_1_MARKER_BUTTON = 1555;
	constexpr UINT CONTROL_ID_TRAVEL_SERVICE_2_COMBO = 1552;
	constexpr UINT CONTROL_ID_TRAVEL_SERVICE_2_MARKER_BUTTON = 1556;
	constexpr UINT CONTROL_ID_TRAVEL_SERVICE_3_COMBO = 1553;
	constexpr UINT CONTROL_ID_TRAVEL_SERVICE_3_MARKER_BUTTON = 1557;
	constexpr UINT CONTROL_ID_TRAVEL_SERVICE_4_COMBO = 1554;
	constexpr UINT CONTROL_ID_TRAVEL_SERVICE_4_MARKER_BUTTON = 1558;
	constexpr UINT CONTROL_ID_TRAVEL_SERVICE_RETURN_BUTTON = 1559;

	struct UserData {
		HWND hPackageList; // 0x0
		int unknown_0x4;
		Actor* actor; // 0x8
		short initialHello; // 0xC;
		char initialFight; // 0xE
		char initialFlee; // 0xF
		char initialAlarm; // 0x10
		DWORD initialMerchantFlags; // 0x14
		NI::IteratedList<void*>* travelDestinations; // 0x18
		BYTE unknown_0x1C;
		Cell* returnCell; // 0x20
		NI::Vector3 returnPosition; // 0x24
		BYTE unknown_0x30;
		int unknown_0x34;
	};
	static_assert(sizeof(UserData) == 0x38, "UserData for the actor AI window failed size validation");

	void installPatches();
}