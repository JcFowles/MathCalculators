#include "Source.h"



BOOL CALLBACK DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
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
		case IDC_APPPLY_MUTLIPY:
			{
				int rowNum = 0;
				if( (GetDlgItemInt(hDlg,IDC_MULTIPLY_ROW_NUM,0,1) <= 3) &&
					(GetDlgItemInt(hDlg,IDC_MULTIPLY_ROW_NUM,0,1) >= 1) )

				{
					rowNum = (GetDlgItemInt(hDlg,IDC_MULTIPLY_ROW_NUM,0,1));
				}

				if(rowNum != 0)
				{
					//GaussianMultiply();
				}
				else
				{
					MessageBox(hDlg, TEXT("Error\n Incorrect Row choice in Multiply Row \n please enter Number from 1 to 3"), TEXT("Error"),MB_ICONQUESTION | MB_OK) ;
				}
				break;	
				//SetDlgItemInt(hDlg,IDC_MATRIX_00,(GetDlgItemInt(hDlg,IDC_MATRIX_00,0,1)*GetDlgItemInt(hDlg,IDC_MATRIX_00,0,1)),1);
			}
		case IDC_APPPLY_SWAP:
			{
				int iRowA = 0;
				int iRowB = 0;
				if( (GetDlgItemInt(hDlg,IDC_SWAP_ROW_A,0,1) <= 3) &&
					(GetDlgItemInt(hDlg,IDC_SWAP_ROW_A,0,1) >= 1) &&
					(GetDlgItemInt(hDlg,IDC_SWAP_ROW_B,0,1) <= 3) &&
					(GetDlgItemInt(hDlg,IDC_SWAP_ROW_B,0,1) >= 1))

				{
					iRowA = (GetDlgItemInt(hDlg,IDC_SWAP_ROW_A,0,1));
					iRowB = (GetDlgItemInt(hDlg,IDC_SWAP_ROW_B,0,1));
				}

				if( (iRowA != 0) && (iRowB != 0))
				{
					GaussianSwap(hDlg, iRowA, iRowB);
				}
				else
				{
					MessageBox(hDlg, TEXT("Error\n Incorrect Row choice in  Swap Row \n please enter Number from 1 to 3"), TEXT("Error"),MB_ICONQUESTION | MB_OK) ;
				}
				break;
			}
		case IDC_APPPLY_ADD:
			{
				int iRowA = 0;
				int iRowB = 0;
				if( (GetDlgItemInt(hDlg,IDC_ADD_ROW_A,0,1) <= 3) &&
					(GetDlgItemInt(hDlg,IDC_ADD_ROW_A,0,1) >= 1) &&
					(GetDlgItemInt(hDlg,IDC_ADD_ROW_B,0,1) <= 3) &&
					(GetDlgItemInt(hDlg,IDC_ADD_ROW_B,0,1) >= 1))

				{
					iRowA = (GetDlgItemInt(hDlg,IDC_ADD_ROW_A,0,1));
					iRowB = (GetDlgItemInt(hDlg,IDC_ADD_ROW_B,0,1));
				}

				if( (iRowA != 0) && (iRowB != 0))
				{
					//GaussianAdd();
				}
				else
				{
					MessageBox(hDlg, TEXT("Error\n Incorrect Row choice in ADD \n please enter Number from 1 to 3"), TEXT("Error"),MB_ICONQUESTION | MB_OK) ;
				}
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


