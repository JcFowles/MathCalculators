/*
* Bachelor of Software Engineering 
* Media Design School 
* Auckland 
* New Zealand 
 
* (c) 2005 - 2014 Media Design School 
 
* File Name : Calculations.cpp
* Description : Implementaion for all the calculations and checks used in the calculator
* Author :	Jc Fowles
* Mail :	Jc.Fowles@mediadesign.school.nz	
*/

//local includes
#include "Source.h"

/***********************
* Initialise: Initialises all values in the dialog box of to 0
* @author: Jc Fowles
* @parameter: _hDlg: Handle to the dialog box
* @return: bool: true if no error errors exist, else pop up the error to be fixed via message box
********************/
bool Initialise(HWND _hDlg)
{
	string strTemp = FloatToString(0.0f);
	
	//Inisialise Matrix A to 0
	SetDlgItemTextA( _hDlg, IDC_A_00,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_A_01,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_A_02,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_A_03,strTemp.c_str());

	SetDlgItemTextA( _hDlg, IDC_A_10,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_A_11,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_A_12,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_A_13,strTemp.c_str());

	SetDlgItemTextA( _hDlg, IDC_A_20,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_A_21,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_A_22,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_A_23,strTemp.c_str());

	SetDlgItemTextA( _hDlg, IDC_A_30,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_A_31,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_A_32,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_A_33,strTemp.c_str());

	//Inisialise Matrix B to 0
	SetDlgItemTextA( _hDlg, IDC_B_00,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_B_01,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_B_02,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_B_03,strTemp.c_str());

	SetDlgItemTextA( _hDlg, IDC_B_10,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_B_11,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_B_12,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_B_13,strTemp.c_str());

	SetDlgItemTextA( _hDlg, IDC_B_20,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_B_21,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_B_22,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_B_23,strTemp.c_str());

	SetDlgItemTextA( _hDlg, IDC_B_30,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_B_31,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_B_32,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_B_33,strTemp.c_str());

	//Inisialise Result Matrix to 0
	SetDlgItemTextA( _hDlg, IDC_RESULT_00,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_RESULT_01,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_RESULT_02,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_RESULT_03,strTemp.c_str());

	SetDlgItemTextA( _hDlg, IDC_RESULT_10,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_RESULT_11,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_RESULT_12,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_RESULT_13,strTemp.c_str());

	SetDlgItemTextA( _hDlg, IDC_RESULT_20,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_RESULT_21,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_RESULT_22,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_RESULT_23,strTemp.c_str());

	SetDlgItemTextA( _hDlg, IDC_RESULT_30,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_RESULT_31,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_RESULT_32,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_RESULT_33,strTemp.c_str());

	//Inisialising the Scalar values to 0
	SetDlgItemTextA( _hDlg, IDC_A_MAG_RESULT,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_B_MAG_RESULT,strTemp.c_str());

	SetDlgItemTextA( _hDlg, IDC_A_SCALAR,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_B_SCALAR,strTemp.c_str());

	return (true);
}