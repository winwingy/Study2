#include <Windows.h>
#include "resource.h"
#include "..\HookWndDLL\HookWndDLL.h"

BOOL CALLBACK WndDlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	switch(uMsg)
	{
	case WM_COMMAND:
		{
			DWORD ctrlId = LOWORD(wParam);
			switch (ctrlId)
			{
			case IDC_BUTTON_INJECT:
				{
					injectWnd();
					break;
				}
			case IDC_BUTTON_UNJECT:
				{
					unjectWnd();
					break;
				}
			}
			break;
		}
	}
	return false;
}


int WINAPI WinMain( 
	__in HINSTANCE hInstance,
	__in_opt HINSTANCE hPrevInstance, 
	__in LPSTR lpCmdLine,
	__in int nShowCmd )
{

	::DialogBoxParamW(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, WndDlgProc, NULL);

	return 0;
}