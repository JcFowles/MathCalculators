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
		//buttons
	    switch(LOWORD(wParam))
	    {
		
		case IDC_APPLY_MUTLIPY:
			{
				if (RowInputCheck(hDlg, 1))
				{
					GaussianMultiply(hDlg);
				}
				if (EchelonCheck(hDlg))
				{
					if(ReducedEchelonCheck(hDlg))
					{
						MessageBox(hDlg, TEXT("Reduced Row Echelon"), TEXT("Reduced Row Echelon"), MB_ICONEXCLAMATION | MB_OK);
					}
					else
					{
						MessageBox(hDlg, TEXT("Row Echelon"), TEXT("Row Echelon"), MB_ICONEXCLAMATION | MB_OK);
					}

				}
				break;
			}
		case IDC_APPLY_SWAP:
			{
				if (RowInputCheck(hDlg, 2))
				{
					GaussianSwap(hDlg);
				}
				if (EchelonCheck(hDlg))
				{
					if(ReducedEchelonCheck(hDlg))
					{
						MessageBox(hDlg, TEXT("Reduced Row Echelon"), TEXT("Reduced Row Echelon"), MB_ICONEXCLAMATION | MB_OK);
					}
					else
					{
						MessageBox(hDlg, TEXT("Row Echelon"), TEXT("Row Echelon"), MB_ICONEXCLAMATION | MB_OK);
					}

				}
				break;
			}
		case IDC_APPLY_ADD:
			{
				if (RowInputCheck(hDlg, 3))
				{
					GaussianAdd(hDlg);
				}
				if (EchelonCheck(hDlg))
				{
					if(ReducedEchelonCheck(hDlg))
					{
						MessageBox(hDlg, TEXT("Reduced Row Echelon"), TEXT("Reduced Row Echelon"), MB_ICONEXCLAMATION | MB_OK);
					}
					else
					{
						MessageBox(hDlg, TEXT("Row Echelon"), TEXT("Row Echelon"), MB_ICONEXCLAMATION | MB_OK);
					}

				}
				break;
			}

		}
		break;
		// closing the window
	case WM_CLOSE:
		{
			//check if you are sure you want to close
			if (MessageBox(hDlg, TEXT("Close the program?"), TEXT("Close"),
				MB_ICONQUESTION | MB_YESNO) == IDYES)
			{
				DestroyWindow(hDlg);
			}

			return TRUE;
		}
		break;
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
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE h0, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hDlg;
	MSG msg;
	BOOL ret;

	hDlg = CreateDialogParam(hInst, MAKEINTRESOURCE(IDD_GAUSSIAN), 0, DialogProc, 0);
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


