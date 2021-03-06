#include <Windows.h>
#include <CommCtrl.h>
#include <tchar.h>
#include "resource.h"
#include "Source.h"

#pragma comment(lib, "ComCtl32.lib")

INT_PTR CALLBACK DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_COMMAND:
	    switch(LOWORD(wParam))
	    {
		case IDCANCEL:
			{
				SendMessage(hDlg, WM_CLOSE, 0, 0);
				return TRUE;
			}
		case IDC_A_PLUS_B:
			{
				break;
			}
		case IDC_A_MIN_B:
			{
				break;
			}
		case IDC_MAG_A:
			{
				break;
			}
		case IDC_B_MIN_A:
			{
				break;
			}
		case IDC_A_B:
			{
				break;
			}
		case IDC_B_A:
			{
				break;
			}
		case IDC_A_DOT_B:
			{
				break;
			}
		case IDC_A_CONJ:
			{
				break;
			}
		case IDC_B_CONJ:
			{
				break;
			}
		case IDC_MAG_A:
			{
				break;
			}
		case IDC_MAG_B:
			{
				break;
			}
		case IDC_INV_A:
			{
				break;
			}
		case IDC_INV_B:
			{
				break;
			}
		case IDC_T_A:
			{
				break;
			}
		case IDC_T_B:
			{
				break;
			}
	    }
		break;

	case WM_CLOSE:
    if(MessageBox(hDlg, TEXT("Close the program?"), TEXT("Close"),
                            MB_ICONQUESTION | MB_YESNO) == IDYES)
		{
			DestroyWindow(hDlg);
	    }
		
	return TRUE;

	case WM_DESTROY:
		{
			PostQuitMessage(0);
		}
	
		return TRUE;
	}

	return FALSE;
}

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE h0, LPTSTR lpCmdLine, int nCmdShow)
{
	HWND hDlg;
	MSG msg;
	BOOL ret;

	InitCommonControls();
	hDlg = CreateDialogParam(hInst, MAKEINTRESOURCE(IDD_QUATERNION_CALC), 0, DialogProc, 0);
	ShowWindow(hDlg, nCmdShow);

	while((ret = GetMessage(&msg, 0, 0, 0)) != 0)
	{
		if(ret == -1)
		{
			return -1;
		}
		
		if(!IsDialogMessage(hDlg, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return 0;
}