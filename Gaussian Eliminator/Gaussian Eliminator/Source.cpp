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
		case IDC_RANDOM:
			{
				RandomInitialise(hDlg);
				break;
			}	
		case IDC_APPLY_MUTLIPY:
			{
				if (RowInputCheck(hDlg, 1))
				{
					GaussianMultiply(hDlg);
				}
				if (EchelonCheck(hDlg))
				{
					MessageBox(hDlg, TEXT("Row Echelon"), TEXT("Row Echelon"), MB_ICONQUESTION | MB_OK);

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
					MessageBox(hDlg, TEXT("Row Echelon"), TEXT("Row Echelon"), MB_ICONQUESTION | MB_OK);

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
					MessageBox(hDlg, TEXT("Row Echelon"), TEXT("Row Echelon"), MB_ICONQUESTION | MB_OK);

				}
				break;
			}
		case IDC_APPLY_ALL:
			{
				if( (RowInputCheck(hDlg, 1)) &&
					(RowInputCheck(hDlg, 2)) &&
					(RowInputCheck(hDlg, 3)) )
				{
					GaussianMultiply(hDlg);
					GaussianSwap(hDlg);
					GaussianAdd(hDlg);
				}
				if (EchelonCheck(hDlg))
				{
					MessageBox(hDlg, TEXT("Row Echelon"), TEXT("Row Echelon"), MB_ICONQUESTION | MB_OK);

				}
				break;
			}
		}
		break;
	case WM_CLOSE:
		{
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


