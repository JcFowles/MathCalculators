/*
* Bachelor of Software Engineering 
* Media Design School 
* Auckland 
* New Zealand 
 
* (c) 2005 - 2014 Media Design School 
 
* File Name : Source.cpp
* Description : Implementaion file for the source application. program starts here
* Author :	Jc Fowles
* Mail :	Jc.Fowles@mediadesign.school.nz	
*/

//local includes
#include "Source.h"
#include "vld.h"

/***********************
* DialogProc: Process the Dialog Box 
* @author: Jc Fowles
* @Parameter: hWnd: Handle to the Window sending the message
* @Parameter: uMsg: The message ID being sent
* @Parameter: wParam: Additional detail about the message being sent
* @Parameter: lParam: Additional detail about the message being sent
* @return: BOOL: result as a boolean
********************/
BOOL CALLBACK DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_COMMAND:
	    switch(LOWORD(wParam))
	    {
		case IDC_A_PLUS_B:
			{
				Add(hDlg);
				break;
			}
		case IDC_A_MIN_B:
			{
				Sub(hDlg, A);
				break;
			}
		case IDC_B_MIN_A:
			{
				Sub(hDlg, B);
				break;
			}
		case IDC_A_B:
			{
				MultiplyQuaternion(hDlg,A);
				break;
			}
		case IDC_B_A:
			{
				MultiplyQuaternion(hDlg,B);
				break;
			}
		case IDC_A_DOT_B:
			{
				Dot(hDlg);
				break;
			}
		case IDC_A_CONJ:
			{
				Conjegate(hDlg, A);
				break;
			}
		case IDC_B_CONJ:
			{
				Conjegate(hDlg, B);
				break;
			}
		case IDC_MAG_A:
			{
				Mag(hDlg, A);
				break;
			}
		case IDC_MAG_B:
			{
				Mag(hDlg, B);
				break;
			}
		case IDC_INV_A:
			{
				Inverse(hDlg, A);
				break;
			}
		case IDC_INV_B:
			{
				Inverse(hDlg, B);
				break;
			}
		case IDC_T_A:
			{
				ScalarMultiply(hDlg, A);
				break;
			}
		case IDC_T_B:
			{
				ScalarMultiply(hDlg, B);
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

/***********************
* WinMain: Program starts here 
* @author: Jc Fowles
* @Parameter: _hInstance: Instance handle that Windows generates for your application
* @Parameter: _hPrevInstance: Tracker for the previous instance for the application
* @Parameter: _lpCmdline: Wide char string that contains the passed in arguments 
* @Parameter: _iCmdshow: Integer passed in during launch, indicating how the application window is opened
* @return: int: Program ends here
********************/
int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE h0, LPTSTR lpCmdLine, int nCmdShow)
{
	HWND hDlg;
	MSG msg;
	BOOL ret;

	
	hDlg = CreateDialogParam(hInst, MAKEINTRESOURCE(IDD_QUATERNION_CALC), 0, DialogProc, 0);
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