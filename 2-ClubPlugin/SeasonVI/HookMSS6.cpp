#include "pch.h"

CHookMSS6 gHookMSS6;

CHookMSS6::CHookMSS6() // OK
{
}

CHookMSS6::~CHookMSS6() // OK
{
}

void CHookMSS6::Init(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (gFeatures.camera3D == 0) return; // Desativa Camera 

	MOUSEHOOKSTRUCTEX* HookStruct = (MOUSEHOOKSTRUCTEX*)lParam;
	switch (wParam)
	{
	/*case WM_LBUTTONDBLCLK:
		STR_ENCRYPT_START
			if (GetForegroundWindow() == *(HWND*)(gOffset.HwndAddress))
			{
				if (gCamera3dS15.m_Start.Active != 2)
				{
					gCamera3dS15.m_Start.Active = 0;
					pDrawMessageS17("Camera 3D mode 2.", 1);
				}
			}
		STR_ENCRYPT_END
			break;
	case WM_RBUTTONDBLCLK:
		STR_ENCRYPT_START
			if (GetForegroundWindow() == *(HWND*)(gOffset.HwndAddress))
			{
				if (gCamera3dS15.m_Start.Active != 2)
				{
					gCamera3dS15.m_Start.Active = 1;
					pDrawMessageS17("Camera 3D mode 1.", 1);
				}
			}
		STR_ENCRYPT_END
			break;*/
	case WM_RBUTTONDOWN:
		STR_ENCRYPT_START
			if (GetForegroundWindow() == *(HWND*)(gOffset.HwndAddress))
			{
				gCamera3dS15.SetIsMove(1);
				gCamera3dS15.SetCursor(HookStruct->pt.x, HookStruct->pt.y);
			}
		STR_ENCRYPT_END
			break;
	case WM_RBUTTONUP:
		STR_ENCRYPT_START
			if (GetForegroundWindow() == *(HWND*)(gOffset.HwndAddress))
			{
				gCamera3dS15.SetIsMove(0);
			}
		STR_ENCRYPT_END
			break;
	case WM_LBUTTONDOWN:
		STR_ENCRYPT_START
			if (GetForegroundWindow() == *(HWND*)(gOffset.HwndAddress))
			{
				gCamera3dS15.SetIsAutoMove(1);
			}
		STR_ENCRYPT_END
			break;
	case WM_LBUTTONUP:
		STR_ENCRYPT_START
			if (GetForegroundWindow() == *(HWND*)(gOffset.HwndAddress))
			{
				gCamera3dS15.SetIsAutoMove(0);
			}
		STR_ENCRYPT_END
			break;
	case WM_MOUSEMOVE:
		STR_ENCRYPT_START
			if (GetForegroundWindow() == *(HWND*)(gOffset.HwndAddress))
			{
				gCamera3dS15.Move(HookStruct);
				gCamera3dS15.AutoMove(HookStruct);
			}
		STR_ENCRYPT_END
			break;
	case WM_MOUSEWHEEL:
		STR_ENCRYPT_START
			if (GetForegroundWindow() == *(HWND*)(gOffset.HwndAddress))
			{
				gCamera3dS15.Zoom(HookStruct);
			}
		STR_ENCRYPT_END
			break;
	default:
		break;
	}
}