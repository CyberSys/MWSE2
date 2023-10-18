#include "DialogLandscapeEditSettingsWindow.h"

#include "CSLandTexture.h"

#include "WinUIUtil.h"

namespace se::cs::dialog::landscape_edit_settings_window {
	namespace LandscapeEditFlag {
		enum LandscapeEditFlag : unsigned int {
			ShowEditRadius = 0x1,
			FlattenVertices = 0x2,
			EditColors = 0x4,
			SoftenVertices = 0x8,
		};
	}

	struct SelectedTextureInfo {
		unsigned int width; // 0x0
		unsigned int height; // 0x4
		BITMAPINFO* bitmapInfo; // 0x8
	};

	using gLandscapeEditFlags = memory::ExternalGlobal<unsigned int, 0x6CE9C8>;

	bool getLandscapeEditFlag(LandscapeEditFlag::LandscapeEditFlag flag) {
		return gLandscapeEditFlags::get() & flag;
	}

	void setLandscapeEditFlag(LandscapeEditFlag::LandscapeEditFlag flag, bool set) {
		auto& flags = gLandscapeEditFlags::get();
		if (set) {
			flags |= flag;
		}
		else {
			flags &= ~flag;
		}
	}

	bool getEditLandscapeColor() {
		return getLandscapeEditFlag(LandscapeEditFlag::EditColors);
	}

	void setEditLandscapeColor(bool set) {
		auto hWnd = gWindowHandle::get();

		setLandscapeEditFlag(LandscapeEditFlag::EditColors, set);
		CheckDlgButton(hWnd, CONTROL_ID_EDIT_COLORS_CHECKBOX, set ? BST_CHECKED : BST_UNCHECKED);

		if (set) {
			setFlattenLandscapeVertices(false);
			EnableWindow(GetDlgItem(hWnd, CONTROL_ID_FLATTEN_VERTICES_CHECKBOX), FALSE);
			setSoftenLandscapeVertices(false);
			EnableWindow(GetDlgItem(hWnd, CONTROL_ID_SOFTEN_VERTICES_CHECKBOX), FALSE);
		}
		else {
			EnableWindow(GetDlgItem(hWnd, CONTROL_ID_FLATTEN_VERTICES_CHECKBOX), TRUE);
			EnableWindow(GetDlgItem(hWnd, CONTROL_ID_SOFTEN_VERTICES_CHECKBOX), TRUE);
		}
	}

	bool getFlattenLandscapeVertices() {
		return getLandscapeEditFlag(LandscapeEditFlag::FlattenVertices);
	}

	void setFlattenLandscapeVertices(bool set) {
		auto hWnd = gWindowHandle::get();

		setLandscapeEditFlag(LandscapeEditFlag::FlattenVertices, set);
		CheckDlgButton(hWnd, CONTROL_ID_FLATTEN_VERTICES_CHECKBOX, set ? BST_CHECKED : BST_UNCHECKED);

		if (set) {
			setSoftenLandscapeVertices(false);
			setEditLandscapeColor(false);
		}
	}

	bool getSoftenLandscapeVertices() {
		return getLandscapeEditFlag(LandscapeEditFlag::SoftenVertices);
	}

	void setSoftenLandscapeVertices(bool set) {
		auto hWnd = gWindowHandle::get();

		setLandscapeEditFlag(LandscapeEditFlag::SoftenVertices, set);
		CheckDlgButton(hWnd, CONTROL_ID_SOFTEN_VERTICES_CHECKBOX, set ? BST_CHECKED : BST_UNCHECKED);

		if (set) {
			setFlattenLandscapeVertices(false);
			setEditLandscapeColor(false);
		}
	}

	LandTexture* getSelectedTexture() {
		auto hWnd = gWindowHandle::get();
		if (hWnd == NULL) {
			return nullptr;
		}

		auto textureList = GetDlgItem(hWnd, CONTROL_ID_TEXTURE_LIST);
		auto selected = ListView_GetNextItem(textureList, -1, LVNI_SELECTED);
		if (selected == -1) {
			return nullptr;
		}

		LVITEMA queryData = {};
		queryData.mask = LVIF_PARAM;
		queryData.iItem = selected;
		if (!ListView_GetItem(textureList, &queryData)) {
			return nullptr;
		}

		return reinterpret_cast<LandTexture*>(queryData.lParam);
	}

	bool setSelectTexture(LandTexture* landTexture) {
		return setSelectTexture(landTexture->texture);
	}

	bool setSelectTexture(NI::Texture* texture) {
		if (texture == nullptr) {
			return false;
		}

		auto hWnd = gWindowHandle::get();
		if (hWnd == NULL) {
			return false;
		}

		LVITEMA queryData = {};
		queryData.mask = LVIF_PARAM;
		auto textureList = GetDlgItem(hWnd, CONTROL_ID_TEXTURE_LIST);
		auto textureCount = ListView_GetItemCount(textureList);
		for (auto row = 0; row < textureCount; ++row) {
			queryData.iItem = row;
			if (!ListView_GetItem(textureList, &queryData)) {
				continue;
			}

			auto landTexture = reinterpret_cast<LandTexture*>(queryData.lParam);
			if (!landTexture) {
				continue;
			}

			if (landTexture->texture == texture) {
				ListView_SetItemState(textureList, row, LVIS_SELECTED, LVIS_SELECTED);
				ListView_EnsureVisible(textureList, row, TRUE);
				return true;
			}
		}

		return false;
	}


	bool incrementEditRadius() {
		auto hWnd = gWindowHandle::get();
		if (hWnd == NULL) {
			return false;
		}

		auto radius = winui::GetDlgItemSignedInt(hWnd, CONTROL_ID_EDIT_RADIUS_EDIT).value_or(1);
		radius = std::min(radius + 1, 30);
		SetDlgItemInt(hWnd, CONTROL_ID_EDIT_RADIUS_EDIT, radius, FALSE);

		return true;
	}

	bool decrementEditRadius() {
		auto hWnd = gWindowHandle::get();
		if (hWnd == NULL) {
			return false;
		}

		auto radius = winui::GetDlgItemSignedInt(hWnd, CONTROL_ID_EDIT_RADIUS_EDIT).value_or(1);
		radius = std::max(radius - 1, 1);
		SetDlgItemInt(hWnd, CONTROL_ID_EDIT_RADIUS_EDIT, radius, FALSE);

		return true;
	}

	bool getLandscapeEditingEnabled() {
		return gLandscapeEditingEnabled::get();
	}

	void setLandscapeEditingEnabled(bool enabled, bool ifWindowOpen) {
		if (ifWindowOpen) {
			enabled = gWindowHandle::get() != NULL;
		}
		gLandscapeEditingEnabled::set(enabled);
	}

	//
	// Patch: Extend Render Window message handling.
	//

	static std::optional<LRESULT> PatchDialogProc_OverrideResult = {};

	void PatchDialogProc_AfterDestroy(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		// Cleanup global handle address so we can rely on it being NULL.
		gWindowHandle::set(0x0);
	}

	LRESULT CALLBACK PatchDialogProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		PatchDialogProc_OverrideResult.reset();

		if (PatchDialogProc_OverrideResult) {
			return PatchDialogProc_OverrideResult.value();
		}

		// Call original function.
		const auto CS_RenderWindowDialogProc = reinterpret_cast<WNDPROC>(0x44D470);
		auto vanillaResult = CS_RenderWindowDialogProc(hWnd, msg, wParam, lParam);

		switch (msg) {
		case WM_DESTROY:
			PatchDialogProc_AfterDestroy(hWnd, msg, wParam, lParam);
			break;
		}

		return PatchDialogProc_OverrideResult.value_or(vanillaResult);
	}

	void __fastcall PatchStretchLandscapePreviewTexture(SelectedTextureInfo* info, DWORD _EDX_, DRAWITEMSTRUCT* drawItem) {
		using winui::GetRectHeight;
		using winui::GetRectWidth;

		const auto bitmapInfo = info->bitmapInfo;
		if (bitmapInfo == nullptr) {
			return;
		}

		// BLACKONWHITE won't work for us here.
		SetStretchBltMode(drawItem->hDC, HALFTONE);
		SetBrushOrgEx(drawItem->hDC, 0, 0, nullptr);

		// Actually render our texture.
		const auto rcItem = &drawItem->rcItem;
		const auto ret = StretchDIBits(drawItem->hDC,
			rcItem->left, rcItem->top, GetRectWidth(rcItem), GetRectHeight(rcItem),
			0, 0, info->width, info->height,
			bitmapInfo->bmiColors, bitmapInfo,
			DIB_RGB_COLORS, SRCCOPY);
	}

	//
	//
	//

	void installPatches() {
		using memory::genJumpEnforced;

		// Patch: Extend Render Window message handling.
		genJumpEnforced(0x4036A7, 0x44D470, reinterpret_cast<DWORD>(PatchDialogProc));

		// Patch: Fix rendering of textures in the terrain edit window.
		genJumpEnforced(0x402D38, 0x475A80, reinterpret_cast<DWORD>(PatchStretchLandscapePreviewTexture));
	}

}
