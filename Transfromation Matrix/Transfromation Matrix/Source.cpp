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
#pragma once
//local includes
#include "Source.h"

HWND g_ComboBox;
stack<int> g_TStack;
TCHAR g_strQueue[256] = _T("");

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
		{
			switch(HIWORD(wParam))
			{
			case ((CBN_SELENDOK)):
				{

					TCHAR temp[256];
					//Get the selected choice from the combo box
					int iIndex = SendMessage(g_ComboBox,  CB_GETCURSEL, 0, 0);
					g_TStack.push(iIndex);
					SendMessage(g_ComboBox,CB_GETLBTEXT , (WPARAM)(iIndex), (LPARAM)temp);
					_tcscat_s(temp, _T("\r\n"));
					_tcscat_s(g_strQueue, temp);
									
					//Print the selected choice to a seprate text box
					SetDlgItemText(hDlg, IDC_Q, (LPCWSTR)g_strQueue);

				}
				break;
			}

			switch(LOWORD(wParam))
			{
			case ((IDC_COMPUTE)):
				{
					//get the two matrices, this is only to used to create the matrix in 4x4, no need for the data
					vector<vector<float>*>* TheRowMatrix = new vector<vector<float>*>;
					vector<vector<float>*>* TheColMatrix = new vector<vector<float>*>;
					GetMatrix(hDlg,TheRowMatrix,TheColMatrix);

					//store the identity matrix in the combined to start with
					vector<vector<float>*>* TheCombineMatrix = new vector<vector<float>*>;
					vector<float>* tempRow = new vector<float>;
					for (int iRow = 0; iRow < 4; iRow++)
					{
						for (int iCol = 0; iCol < 4; iCol++)
						{
							if(iRow == iCol)
							{
								tempRow->push_back(1);
							}
							else
							{
								tempRow->push_back(0);
							}
						}
						TheCombineMatrix->push_back(tempRow);
						tempRow = new vector<float>;
					}

					//if no choice was selected print out the identity matrix
					if(g_TStack.empty())
					{
						SetToI(hDlg);
					}
					else
					{
						while(!(g_TStack.empty()))
						{
							//create a temparary matrix to store the result
							vector<vector<float>*>* TheTempMatrix = new vector<vector<float>*>;
							vector<float>* tempRowA = new vector<float>;
							for (int iRow = 0; iRow < 4; iRow++)
							{
								for (int iCol = 0; iCol < 4; iCol++)
								{
									tempRowA->push_back(0);
								}
								TheTempMatrix->push_back(tempRowA);
								tempRowA = new vector<float>;
							}

							//decide what Transformation 
							switch(g_TStack.top())
							{
							case SCALE:
								{
									TheRowMatrix = Scale(hDlg);									
								}
								break;
							case SKEWING:
								{
									TheRowMatrix = Skew(hDlg);
								}
								break;
							case TRANSLATE:
								{
									TheRowMatrix = Translate(hDlg);
								}
								break;
							case ROTATION:
								{
									TheRowMatrix = Rotate(hDlg);
								}
								break;
							case PROJECTION:
								{
									TheRowMatrix = Projection(hDlg);
								}
								break;
							}
							
							//Multiply the new Matrix with the current combined 
							for (int iRow = 0; iRow < 4; iRow++)
							{
								for (int iCol = 0; iCol < 4; iCol++)
								{
									for (int i = 0; i < 4; i++)
									{
										((*(*TheTempMatrix)[iRow])[iCol]) += ((*(*TheCombineMatrix)[iRow])[i]) * ((*(*TheRowMatrix)[i])[iCol]);
									}
								}
							}

							delete TheCombineMatrix;
							TheCombineMatrix = TheTempMatrix;
							
							//pop the stack then loop again
							g_TStack.pop();

						}

						delete TheRowMatrix;
						TheRowMatrix = TheCombineMatrix;
						
						for (int iRow = 0; iRow < 4; iRow++)
						{
							for (int iCol = 0; iCol < 4; iCol++)
							{
								((*(*TheColMatrix)[iRow])[iCol]) = 	((*(*TheRowMatrix)[iCol])[iRow]);
							}
		
						}

						//set text boxes using the matrix
						SetMatrix(hDlg, TheRowMatrix, TheColMatrix);
						TCHAR reset[] = _T("");

						_tcscpy_s(g_strQueue,reset);
						SetDlgItemText(hDlg, IDC_Q, (LPCWSTR)g_strQueue);
						
						//memory Clean up
						for(int i = 0; i < 4; i++)
						{
							delete (*TheRowMatrix)[i];
							delete (*TheColMatrix)[i];
							(*TheRowMatrix)[i] = 0;
							(*TheColMatrix)[i] = 0;
													
						}
						delete TheRowMatrix;
						delete TheColMatrix;
						TheRowMatrix = 0;
						TheColMatrix = 0;
					}
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
	
	hDlg = CreateDialogParam(hInst, MAKEINTRESOURCE(IDD_TRANSFORMATION), 0, DialogProc, 0);
	g_ComboBox = GetDlgItem(hDlg, IDC_COMBO);
	Initialise(hDlg,g_ComboBox);
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