#include "Source.h"



BOOL CALLBACK DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_COMMAND:
	    switch(LOWORD(wParam))
	    {
		case IDC_SLERP:
			{
				slerp(hDlg);
				break;
			}
		case IDC_MATRIX_A:
			{
				Matrix(hDlg, A);
				break;
			}
		case IDC_MATRIX_B:
			{
				Matrix(hDlg, B);
				break;
			}
		case IDC_MATRIX_SLERP:
			{
				Matrix(hDlg, SLERP);
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


	hDlg = CreateDialogParam(hInst, MAKEINTRESOURCE(IDD_SLERP_CALC), 0, DialogProc, 0);
	Initialise(hDlg);
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