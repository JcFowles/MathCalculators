/* Bachelor of Software Engineering 
* Media Design School 
* Auckland 
* New Zealand 
 
* (c) 2005 - 2014 Media Design School 
 
* File Name : Calculations.cpp
* Description : Implementaion for all the calculations and checks used in the calculator
* Author :	Jc Fowles
* Mail :	Jc.Fowles@mediadesign.school.nz	
*/
#pragma once
//local includes
#include "Source.h"

/***********************
* Initialise: Initialises all values in the dialog box of to 0
* @author: Jc Fowles
* @parameter: _hDlg: Handle to the dialog box
* @return: bool: true if no error errors exist, else pop up the error to be fixed via message box
********************/
bool Initialise(HWND _hDlg, HWND _ComboBox)
{
	//initialise the combo box
	LPTSTR Scaling = L"Scaling";
	LPTSTR Skewing = L"Skewing";
	LPTSTR Translation = L"Translation";
	LPTSTR Rotation = L"Rotation";
	LPTSTR Projection = L"Projection";

	SendMessage(_ComboBox, CB_ADDSTRING, 0, (LPARAM)(Scaling));
	SendMessage(_ComboBox, CB_ADDSTRING, 0, (LPARAM)(Skewing));
	SendMessage(_ComboBox, CB_ADDSTRING, 0, (LPARAM)(Translation));
	SendMessage(_ComboBox, CB_ADDSTRING, 0, (LPARAM)(Rotation));
	SendMessage(_ComboBox, CB_ADDSTRING, 0, (LPARAM)(Projection));

	string strTemp = FloatToString(0.0f);
	
	//Inisialise Matrix Row major to 0
	SetDlgItemTextA( _hDlg, IDC_ROW_00,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_ROW_01,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_ROW_02,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_ROW_03,strTemp.c_str());
	
	SetDlgItemTextA( _hDlg, IDC_ROW_10,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_ROW_11,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_ROW_12,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_ROW_13,strTemp.c_str());

	SetDlgItemTextA( _hDlg, IDC_ROW_20,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_ROW_21,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_ROW_22,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_ROW_23,strTemp.c_str());

	SetDlgItemTextA( _hDlg, IDC_ROW_30,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_ROW_31,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_ROW_32,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_ROW_33,strTemp.c_str());
	
	//Inisialise Matrix colomn major to 0
	SetDlgItemTextA( _hDlg, IDC_COL_00,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_COL_01,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_COL_02,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_COL_03,strTemp.c_str());

	SetDlgItemTextA( _hDlg, IDC_COL_10,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_COL_11,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_COL_12,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_COL_13,strTemp.c_str());

	SetDlgItemTextA( _hDlg, IDC_COL_20,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_COL_21,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_COL_22,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_COL_23,strTemp.c_str());

	SetDlgItemTextA( _hDlg, IDC_COL_30,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_COL_31,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_COL_32,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_COL_33,strTemp.c_str());

	SetDlgItemTextA( _hDlg, IDC_SCALE,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_SKEW_X,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_SKEW_Y,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_SKEW_Z,strTemp.c_str());

	SetDlgItemTextA( _hDlg, IDC_TRANSLATE_X,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_TRANSLATE_Y,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_TRANSLATE_Z,strTemp.c_str());

	SetDlgItemTextA( _hDlg, IDC_ROTATION_X,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_ROTATION_Y,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_ROTATION_Z,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_ROTATION_ANGLE,strTemp.c_str());
	
	SetDlgItemTextA( _hDlg, IDC_PROJECTION_D,strTemp.c_str());

	return (true);
}

/***********************
* InputCheck: Checks if a passed in sting is a valid float
* @author: Jc Fowles
* @parameter: _str: refrence to the string to checked
* @return: bool: true of a valid float false if not a valid float
********************/
bool InputCheck(string &_str)
{
	istringstream iss(_str);

    float fFloat;

	//Using noskipws, concat iss into fFloat
    iss >> noskipws >> fFloat; 
	
	// Then check if the concat was successful
	// by checking the state of iss (That it does not have a fail bit or bad bit)
	// and checking to see if we reached the End-of-File of iss 
	if(iss.eof() && !iss.fail())
	{
		return (true);
	}
	else
	{
		return (false);
	}
   
}

/***********************
* FloatToString: converts a passed in float to a string
* @author: Jc Fowles
* @parameter: _kfValue: float to convert
* @return: string: the float in string form
********************/
string FloatToString(const float _kfValue)
{
	stringstream strStream;
	
	//concats the float into the string stream
	strStream << _kfValue;

	//convert the string stream to a string
	string strConverted = strStream.str();
	
	//return the converted string
	return strConverted;
}

/***********************
* WideStringToFloat: converts a passed in WideString To a Float
* @author: Jc Fowles
* @parameter: _kpwstr: WideString to convert
* @return: float: the WideString in float form
********************/
float WideStringToFloat(const wchar_t* _kpwstr)
{
	//gets the string length of the passed in float, plus the null teminator
	size_t stringLength = wcslen(_kpwstr) + 1;
	
	//sets the converted length to 0 
	size_t convertedChars = 0;

	// if the string is empty return 0
	if(stringLength == 1) 
	{
		return (0);
	}

	//A wide char can be 1 or 2 bytes there for we double the array size as a protection
	char* pStr = new char[stringLength*2];

	//wide_character_string_to_multi_byte_string stable convertion
	//convert _kpwstr into pStr
	wcstombs_s(&convertedChars, pStr, stringLength, _kpwstr, _TRUNCATE);

	//convert to string to float using string_to_float
	float fReturn = stof(pStr);
	delete pStr;
	pStr = 0;

	return (fReturn);
}

/***********************
* WideStringToString: converts a passed in WideString To a string
* @author: Jc Fowles
* @parameter: _kpwstr: WideString to convert
* @return: string: the WideString in string form
********************/
string WideStringToString(const wchar_t* _kpwstr)
{
	//gets the string length of the passed in float, plus the null teminator
	size_t stringLength = wcslen(_kpwstr) + 1;
	
	//sets the converted length to 0 
	size_t convertedChars = 0;

	// if the string is empty return 0
	if(stringLength == 1) 
	{
		return (0);
	}

	//A wide char can be 1 or 2 bytes there for we double the array size as a protection
	char* pStr = new char[stringLength*2];

	//wide_character_string_to_multi_byte_string stable convertion
	//convert _kpwstr into pStr
	wcstombs_s(&convertedChars, pStr, stringLength, _kpwstr, _TRUNCATE);
	
	string sReturn = pStr;
	delete pStr;
	pStr = 0;

	return sReturn;
}

/***********************
* GetStrMatrix: Gets the values from the Matrices dialog boxes and stores it into a string vector 
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _pMatrixA: a pointer to the matrix in whcih Row Matrix is to be stored
* @parameter: _pMatrixB: a pointer to the matrix in whcih column Matrix is to be stored
* @return: bool: return true
********************/
bool GetStrMatrix(HWND _hDlg, vector<vector<string>*>* _pMatrixA,vector<vector<string>*>* _pMatrixB)
{
	wchar_t wstrTempA[100];
	//temp matrix row
	vector<string>* vpstrTempA = new vector<string>;
	vector<string>* vpstrTempB = new vector<string>;
	
	
	//First row enter into the row matrix 
	GetDlgItemText(_hDlg, IDC_ROW_00, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));		

	GetDlgItemText(_hDlg, IDC_ROW_01, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_ROW_02, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_ROW_03, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));

	//First row enter into the column matrix 
	GetDlgItemText(_hDlg, IDC_COL_00, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));		

	GetDlgItemText(_hDlg, IDC_COL_01, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_COL_02, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_COL_03, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));

	//add the temp row to the matrix
	(*_pMatrixA).push_back(vpstrTempA);
	(*_pMatrixB).push_back(vpstrTempB);

	//clear the temp row
	vpstrTempA = new vector<string>;
	vpstrTempB = new vector<string>;


	//Second row enter into the row matrix 
	GetDlgItemText(_hDlg, IDC_ROW_10, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));		

	GetDlgItemText(_hDlg, IDC_ROW_11, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_ROW_12, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_ROW_13, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));

	//Second row enter into the column matrix 
	GetDlgItemText(_hDlg, IDC_COL_10, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));		

	GetDlgItemText(_hDlg, IDC_COL_11, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_COL_12, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_COL_13, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));

	//add the temp row to the matrix
	(*_pMatrixA).push_back(vpstrTempA);
	(*_pMatrixB).push_back(vpstrTempB);

	//clear the temp row
	vpstrTempA = new vector<string>;
	vpstrTempB = new vector<string>;
	

	//Third row enter into the row matrix 
	GetDlgItemText(_hDlg, IDC_ROW_20, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));		

	GetDlgItemText(_hDlg, IDC_ROW_21, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_ROW_22, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_ROW_23, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));

	//Third row enter into the column matrix 
	GetDlgItemText(_hDlg, IDC_COL_20, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));		

	GetDlgItemText(_hDlg, IDC_COL_21, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_COL_22, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_COL_23, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));

	//add the temp row to the matrix
	(*_pMatrixA).push_back(vpstrTempA);
	(*_pMatrixB).push_back(vpstrTempB);

	//clear the temp row
	vpstrTempA = new vector<string>;
	vpstrTempB = new vector<string>;


	//Fourth row enter into the row matrix
	GetDlgItemText(_hDlg, IDC_ROW_30, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));		

	GetDlgItemText(_hDlg, IDC_ROW_31, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_ROW_32, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_ROW_33, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));

	//fOURTH row enter into the Column matrix
	GetDlgItemText(_hDlg, IDC_COL_30, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));		

	GetDlgItemText(_hDlg, IDC_COL_31, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_COL_32, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_COL_33, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));


	//add the temp row to the matrix
	(*_pMatrixA).push_back(vpstrTempA);
	(*_pMatrixB).push_back(vpstrTempB);

	return (true);
}

/***********************
* GetMatrix: Gets the values from the Matrices dialog boxes and stores it into a float vector 
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _pMatrixA: a pointer to the matrix in whcih Matrix A to be stored
* @parameter: _pMatrixB: a pointer to the matrix in whcih Matrix B to be stored
* @return: bool: return true
********************/
bool GetMatrix(HWND _hDlg, vector<vector<float>*>* _pMatrixA,vector<vector<float>*>* _pMatrixB)
{

//temp matrix row
	vector<float>* vpfTempA = new vector<float>;
	vector<float>* vpfTempB = new vector<float>;

	//creates a string matrix
	vector<vector<string>*>* strMatrixA = new vector<vector<string>*>;
	vector<vector<string>*>* strMatrixB = new vector<vector<string>*>;
	GetStrMatrix(_hDlg , strMatrixA, strMatrixB);

	for(int iRow = 0; iRow < 4; iRow++)
	{
		for(int iColumn = 0; iColumn < 4; iColumn++)
		{
			//check if valid input
			if (InputCheck(  (*(*strMatrixA)[iRow])[iColumn]) &&
				InputCheck(  (*(*strMatrixB)[iRow])[iColumn]))
			{
				//push valid float input into the temp row 
				(*vpfTempA).push_back( (stof((*(*strMatrixA)[iRow])[iColumn])));
				(*vpfTempB).push_back( (stof((*(*strMatrixB)[iRow])[iColumn])));
			}
			else
			{
				//invalid input found
				MessageBox(_hDlg, TEXT("Error\n Invalid Input detected Please only enter numerical values"), TEXT("Error"), MB_ICONERROR | MB_OK);

				while(!(strMatrixA->empty()))
				{
					delete strMatrixA->back();
					strMatrixA->back() = 0;
					strMatrixA->pop_back();
				}
				delete strMatrixA;
				strMatrixA = 0;

				while(!(strMatrixB->empty()))
				{
					delete strMatrixB->back();
					strMatrixB->back() = 0;
					strMatrixB->pop_back();
				}
				delete strMatrixB;
				strMatrixB = 0;

				return false;
			}
		}
		
		//add the temp row to the matrix
		(*_pMatrixA).push_back(vpfTempA);
		(*_pMatrixB).push_back(vpfTempB);
		
		//clear the temp row
		vpfTempA = new vector<float>;
		vpfTempB = new vector<float>;
	}

	while(!(strMatrixA->empty()))
	{
		delete strMatrixA->back();
		strMatrixA->back() = 0;
		strMatrixA->pop_back();
	}
	delete strMatrixA;
	strMatrixA = 0;

	while(!(strMatrixB->empty()))
	{
		delete strMatrixB->back();
		strMatrixB->back() = 0;
		strMatrixB->pop_back();
	}
	delete strMatrixB;
	strMatrixB = 0;

	
	return true;
}

/***********************
* GetVector: Gets and convert data from the various dialog boxes
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _iChoice: Which matrix are you working with A or B
* @parameter: _fpScalar: a pointer to vector of floats, in which to store the data
* @return: bool: return true, if no errors exist
********************/
bool GetVector(HWND _hDlg, int _iChoice, vector<float>* _fpScalar)
{
	//String Pointer to store the string values of the scalar
	vector<string> strScalar;

	//temp stringh to store the value in the dialog box
	wchar_t wstrTempA[100];

	
	switch(_iChoice)
	{
	case SCALE:
		{
			GetDlgItemText(_hDlg, IDC_SCALE, wstrTempA, 100);
			(strScalar).push_back(WideStringToString(wstrTempA));	
		}
		break;
	case SKEWING:
		{
			GetDlgItemText(_hDlg, IDC_SKEW_X, wstrTempA, 100);
			(strScalar).push_back(WideStringToString(wstrTempA));	
			GetDlgItemText(_hDlg, IDC_SKEW_Y, wstrTempA, 100);
			(strScalar).push_back(WideStringToString(wstrTempA));
			GetDlgItemText(_hDlg, IDC_SKEW_Z, wstrTempA, 100);
			(strScalar).push_back(WideStringToString(wstrTempA));
		}
		break;
	case TRANSLATE:
		{
			GetDlgItemText(_hDlg, IDC_TRANSLATE_X, wstrTempA, 100);
			(strScalar).push_back(WideStringToString(wstrTempA));	
			GetDlgItemText(_hDlg, IDC_TRANSLATE_Y, wstrTempA, 100);
			(strScalar).push_back(WideStringToString(wstrTempA));
			GetDlgItemText(_hDlg, IDC_TRANSLATE_Z, wstrTempA, 100);
			(strScalar).push_back(WideStringToString(wstrTempA));
		}
		break;
	case ROTATION:
		{
			GetDlgItemText(_hDlg, IDC_ROTATION_X, wstrTempA, 100);
			(strScalar).push_back(WideStringToString(wstrTempA));	
			GetDlgItemText(_hDlg, IDC_ROTATION_Y, wstrTempA, 100);
			(strScalar).push_back(WideStringToString(wstrTempA));
			GetDlgItemText(_hDlg, IDC_ROTATION_Z, wstrTempA, 100);
			(strScalar).push_back(WideStringToString(wstrTempA));
			GetDlgItemText(_hDlg, IDC_ROTATION_ANGLE, wstrTempA, 100);
			(strScalar).push_back(WideStringToString(wstrTempA));
		}
		break;
	case PROJECTION:
		{
			if(IsDlgButtonChecked(_hDlg, IDC_AXIS_X) == BST_CHECKED)
			{
				// x axis
				(strScalar).push_back("1");	  
				(strScalar).push_back("0");	
				(strScalar).push_back("0");	
					
			}
			else if(IsDlgButtonChecked(_hDlg, IDC_AXIS_Y) == BST_CHECKED)
			{
				// y axis
				(strScalar).push_back("0");	  
				(strScalar).push_back("1");	
				(strScalar).push_back("0");
			}
			else if(IsDlgButtonChecked(_hDlg, IDC_AXIS_Z) == BST_CHECKED)
			{
				// z axis
				(strScalar).push_back("0");	  
				(strScalar).push_back("0");	
				(strScalar).push_back("1");
			}
			//get distance
			GetDlgItemText(_hDlg, IDC_PROJECTION_D, wstrTempA, 100);
			(strScalar).push_back(WideStringToString(wstrTempA));
		}
		break;
	}
	
	for(unsigned int i = 0; i < strScalar.size() ; i++)
	{
		if(InputCheck(strScalar[i]))
		{
			(*_fpScalar).push_back(stof(strScalar[i]));
		}
		else
		{
			MessageBox(_hDlg, TEXT("Error\n Invalid Input detected Please only enter numerical values"), TEXT("Error"), MB_ICONERROR | MB_OK);
			return false;
		}
	}
	return true;
	
}

/***********************
* SetMatrix: Sets the matrix text boxes based on choosen matrix
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _pMatrix: a pointer to the matrix which hold the values that we want to set the text boxes to
* @parameter: _iChoice: which of the three matix text boxes to set
* @return: bool: return true
********************/
bool SetMatrix(HWND _hDlg, vector<vector<float>*>* _pRowMatrix, vector<vector<float>*>* _pColMatrix)
{

	string strTemp;
	
	//set the first row
	strTemp = FloatToString((*(*_pRowMatrix)[0])[0]);
	SetDlgItemTextA(_hDlg, IDC_ROW_00, strTemp.c_str());
	strTemp = FloatToString((*(*_pRowMatrix)[0])[1]);
	SetDlgItemTextA(_hDlg, IDC_ROW_01, strTemp.c_str());
	strTemp = FloatToString((*(*_pRowMatrix)[0])[2]);
	SetDlgItemTextA(_hDlg, IDC_ROW_02, strTemp.c_str());
	strTemp = FloatToString((*(*_pRowMatrix)[0])[3]);
	SetDlgItemTextA(_hDlg, IDC_ROW_03, strTemp.c_str());

	//set the Second row
	strTemp = FloatToString((*(*_pRowMatrix)[1])[0]);
	SetDlgItemTextA(_hDlg, IDC_ROW_10, strTemp.c_str());
	strTemp = FloatToString((*(*_pRowMatrix)[1])[1]);
	SetDlgItemTextA(_hDlg, IDC_ROW_11, strTemp.c_str());
	strTemp = FloatToString((*(*_pRowMatrix)[1])[2]);
	SetDlgItemTextA(_hDlg, IDC_ROW_12, strTemp.c_str());
	strTemp = FloatToString((*(*_pRowMatrix)[1])[3]);
	SetDlgItemTextA(_hDlg, IDC_ROW_13, strTemp.c_str());

	//set the Third row
	strTemp = FloatToString((*(*_pRowMatrix)[2])[0]);
	SetDlgItemTextA(_hDlg, IDC_ROW_20, strTemp.c_str());
	strTemp = FloatToString((*(*_pRowMatrix)[2])[1]);
	SetDlgItemTextA(_hDlg, IDC_ROW_21, strTemp.c_str());
	strTemp = FloatToString((*(*_pRowMatrix)[2])[2]);
	SetDlgItemTextA(_hDlg, IDC_ROW_22, strTemp.c_str());
	strTemp = FloatToString((*(*_pRowMatrix)[2])[3]);
	SetDlgItemTextA(_hDlg, IDC_ROW_23, strTemp.c_str());

	//set the fourth row
	strTemp = FloatToString((*(*_pRowMatrix)[3])[0]);
	SetDlgItemTextA(_hDlg, IDC_ROW_30, strTemp.c_str());
	strTemp = FloatToString((*(*_pRowMatrix)[3])[1]);
	SetDlgItemTextA(_hDlg, IDC_ROW_31, strTemp.c_str());
	strTemp = FloatToString((*(*_pRowMatrix)[3])[2]);
	SetDlgItemTextA(_hDlg, IDC_ROW_32, strTemp.c_str());
	strTemp = FloatToString((*(*_pRowMatrix)[3])[3]);
	SetDlgItemTextA(_hDlg, IDC_ROW_33, strTemp.c_str());

	
	//set the first row
	strTemp = FloatToString((*(*_pColMatrix)[0])[0]);
	SetDlgItemTextA(_hDlg, IDC_COL_00, strTemp.c_str());
	strTemp = FloatToString((*(*_pColMatrix)[0])[1]);
	SetDlgItemTextA(_hDlg, IDC_COL_01, strTemp.c_str());
	strTemp = FloatToString((*(*_pColMatrix)[0])[2]);
	SetDlgItemTextA(_hDlg, IDC_COL_02, strTemp.c_str());
	strTemp = FloatToString((*(*_pColMatrix)[0])[3]);
	SetDlgItemTextA(_hDlg, IDC_COL_03, strTemp.c_str());

	//set the Second row
	strTemp = FloatToString((*(*_pColMatrix)[1])[0]);
	SetDlgItemTextA(_hDlg, IDC_COL_10, strTemp.c_str());
	strTemp = FloatToString((*(*_pColMatrix)[1])[1]);
	SetDlgItemTextA(_hDlg, IDC_COL_11, strTemp.c_str());
	strTemp = FloatToString((*(*_pColMatrix)[1])[2]);
	SetDlgItemTextA(_hDlg, IDC_COL_12, strTemp.c_str());
	strTemp = FloatToString((*(*_pColMatrix)[1])[3]);
	SetDlgItemTextA(_hDlg, IDC_COL_13, strTemp.c_str());

	//set the Third row
	strTemp = FloatToString((*(*_pColMatrix)[2])[0]);
	SetDlgItemTextA(_hDlg, IDC_COL_20, strTemp.c_str());
	strTemp = FloatToString((*(*_pColMatrix)[2])[1]);
	SetDlgItemTextA(_hDlg, IDC_COL_21, strTemp.c_str());
	strTemp = FloatToString((*(*_pColMatrix)[2])[2]);
	SetDlgItemTextA(_hDlg, IDC_COL_22, strTemp.c_str());
	strTemp = FloatToString((*(*_pColMatrix)[2])[3]);
	SetDlgItemTextA(_hDlg, IDC_COL_23, strTemp.c_str());

	//set the fourth row
	strTemp = FloatToString((*(*_pColMatrix)[3])[0]);
	SetDlgItemTextA(_hDlg, IDC_COL_30, strTemp.c_str());
	strTemp = FloatToString((*(*_pColMatrix)[3])[1]);
	SetDlgItemTextA(_hDlg, IDC_COL_31, strTemp.c_str());
	strTemp = FloatToString((*(*_pColMatrix)[3])[2]);
	SetDlgItemTextA(_hDlg, IDC_COL_32, strTemp.c_str());
	strTemp = FloatToString((*(*_pColMatrix)[3])[3]);
	SetDlgItemTextA(_hDlg, IDC_COL_33, strTemp.c_str());

	/*while(!(_pRowMatrix->empty()))
	{
		delete _pRowMatrix->back();
		_pRowMatrix->back() = 0;
		_pRowMatrix->pop_back();
	}*/

	/*delete _pRowMatrix;
	_pRowMatrix = 0;*/

	/*while(!(_pColMatrix->empty()))
	{
		delete _pColMatrix->back();
		_pColMatrix->back() = 0;
		_pColMatrix->pop_back();
	}
*/
	/*delete _pColMatrix;
	_pColMatrix = 0;*/

	return (true);

}

/***********************
* SetToI: Set the choosen matrix tho the Identity Matrix
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @return: bool: return true, if no errors exist
********************/
bool SetToI(HWND _hDlg)
{

	//create the matrix from given values 
	vector<vector<float>*>* TheRowMatrix = new vector<vector<float>*>;
	vector<vector<float>*>* TheColMatrix = new vector<vector<float>*>;

	if (GetMatrix(_hDlg, TheRowMatrix, TheColMatrix))
	{
		

		for (int iRow = 0; iRow < 4; iRow++)
		{
			for (int iCol = 0; iCol < 4; iCol++)
			{
				//diagonal down all equal ones the rest equal 0
				if (iRow == iCol)
				{
					((*(*TheRowMatrix)[iRow])[iCol]) = 1;
					((*(*TheColMatrix)[iRow])[iCol]) = 1;
				}
				else
				{
					((*(*TheRowMatrix)[iRow])[iCol]) = 0;
					((*(*TheColMatrix)[iRow])[iCol]) = 0;
				}
			}
			
		}

		//set text boxes using the matrix
		SetMatrix(_hDlg, TheRowMatrix, TheColMatrix);
		return true;
	}
	else
	{
		return false;
	}



}

/***********************
* Scale: Creates and returns the transformation matrix of its type (Scale)
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @return: vector<vector<float>*>*: The transformation matrix
********************/
vector<vector<float>*>* Scale(HWND _hDlg)
{

	//create the matrix from given values 
	vector<vector<float>*>* TheRowMatrix = new vector<vector<float>*>;
	vector<vector<float>*>* TheColMatrix = new vector<vector<float>*>;
	vector<float> fScalar;
	if (GetMatrix(_hDlg, TheRowMatrix, TheColMatrix) && GetVector(_hDlg,SCALE,&fScalar))
	{
		

		for (int iRow = 0; iRow < 4; iRow++)
		{
			for (int iCol = 0; iCol < 4; iCol++)
			{
				//diagonal down all equal ones the rest equal 0
				if (iRow == iCol)
				{
					((*(*TheRowMatrix)[iRow])[iCol]) = fScalar[0];
					((*(*TheColMatrix)[iRow])[iCol]) = fScalar[0];
				}
				else
				{
					((*(*TheRowMatrix)[iRow])[iCol]) = 0;
					((*(*TheColMatrix)[iRow])[iCol]) = 0;
				}
			}
			
		}

		((*(*TheRowMatrix)[3])[3]) = 1;
		((*(*TheColMatrix)[3])[3]) = 1;

		//set text boxes using the matrix
		//return TheRowMatrix;
		SetMatrix(_hDlg, TheRowMatrix, TheColMatrix);
		return TheRowMatrix;
	}
	else
	{
		return 0;
	}

}

/***********************
* Skew: Creates and returns the transformation matrix of its type (Skew)
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @return: vector<vector<float>*>*: The transformation matrix
********************/
vector<vector<float>*>* Skew(HWND _hDlg)
{
	//create the matrix from given values 
	vector<vector<float>*>* TheRowMatrix = new vector<vector<float>*>;
	vector<vector<float>*>* TheColMatrix = new vector<vector<float>*>;
	vector<float> fScalar;
	if (GetMatrix(_hDlg, TheRowMatrix, TheColMatrix) && GetVector(_hDlg,SKEWING,&fScalar))
	{
		
		int i = 0;
		for (int iRow = 0; iRow < 4; iRow++)
		{
			for (int iCol = 0; iCol < 4; iCol++)
			{
				//diagonal down all equal ones the rest equal 0
				if ((iRow == iCol) && (i < 3))
				{
					((*(*TheRowMatrix)[iRow])[iCol]) = fScalar[i];
					((*(*TheColMatrix)[iRow])[iCol]) = fScalar[i];
					i++;
				}
				else
				{
					((*(*TheRowMatrix)[iRow])[iCol]) = 0;
					((*(*TheColMatrix)[iRow])[iCol]) = 0;
				}
			}
			
		}

		((*(*TheRowMatrix)[3])[3]) = 1;
		((*(*TheColMatrix)[3])[3]) = 1;

		//set text boxes using the matrix
		SetMatrix(_hDlg, TheRowMatrix, TheColMatrix);
		return TheRowMatrix;
	}
	else
	{
		return 0;
	}

}

/***********************
* Translate: Creates and returns the transformation matrix of its type (Translate)
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @return: vector<vector<float>*>*: The transformation matrix
********************/
vector<vector<float>*>* Translate(HWND _hDlg)
{
	//create the matrix from given values 
	vector<vector<float>*>* TheRowMatrix = new vector<vector<float>*>;
	vector<vector<float>*>* TheColMatrix = new vector<vector<float>*>;
	vector<float> fScalar;
	if (GetMatrix(_hDlg, TheRowMatrix, TheColMatrix) && GetVector(_hDlg,TRANSLATE,&fScalar))
	{
		
		int i = 0;
		int j = 0;
		for (int iRow = 0; iRow < 4; iRow++)
		{
			for (int iCol = 0; iCol < 4; iCol++)
			{
				//diagonal down all equal ones the rest equal 0
				if ((iRow == iCol))
				{
					((*(*TheRowMatrix)[iRow])[iCol]) = 1;
					((*(*TheColMatrix)[iRow])[iCol]) = 1;
				}
				else if(iCol == 3)
				{
					((*(*TheRowMatrix)[iRow])[iCol]) =  fScalar[i];
					((*(*TheColMatrix)[iRow])[iCol]) = 0;
					i++;
				}
				else if(iRow == 3)
				{
					((*(*TheRowMatrix)[iRow])[iCol]) =  0;
					((*(*TheColMatrix)[iRow])[iCol]) = fScalar[j];
					j++;
				}
				else
				{
					((*(*TheRowMatrix)[iRow])[iCol]) = 0;
					((*(*TheColMatrix)[iRow])[iCol]) = 0;
				}
			}
		
		}

		((*(*TheRowMatrix)[3])[3]) = 1;
		((*(*TheColMatrix)[3])[3]) = 1;

		//set text boxes using the matrix
		SetMatrix(_hDlg, TheRowMatrix, TheColMatrix);
		return TheRowMatrix;
	}
	else
	{
		return 0;
	}

}

/***********************
* Rotate: Creates and returns the transformation matrix of its type (Rotate)
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @return: vector<vector<float>*>*: The transformation matrix
********************/
vector<vector<float>*>* Rotate(HWND _hDlg)
{
	//create the matrix from given values 
	vector<vector<float>*>* TheRowMatrix = new vector<vector<float>*>;
	vector<vector<float>*>* TheColMatrix = new vector<vector<float>*>;
	vector<float> fScalar;
	if (GetMatrix(_hDlg, TheRowMatrix, TheColMatrix) && GetVector(_hDlg,ROTATION,&fScalar))
	{
		bool bValidAxis = false;
		int axis = 4;
		for(unsigned int i = 0; i < fScalar.size() - 1 ; i++)
		{
			if(fScalar[i] == 1)
			{
				if(!bValidAxis)
				{
					bValidAxis = true;
					axis = i;
				}
				else
				{
					MessageBox(_hDlg, TEXT("Error\n The choosen axis is not supported"), TEXT("Error"), MB_ICONERROR | MB_OK);
					return false;
				}
			}
			
		}
		if(bValidAxis == false)
		{
			MessageBox(_hDlg, TEXT("Error\n The choosen axis is not supported"), TEXT("Error"), MB_ICONERROR | MB_OK);
			return false;
		}

		switch(axis)
		{
		case 0: //x axis
			{
				for (int iRow = 0; iRow < 4; iRow++)
				{
					for (int iCol = 0; iCol < 4; iCol++)
					{
						//diagonal down all equal ones the rest equal 0
						if ((iRow == 0) && (iCol == 0))
						{
							((*(*TheRowMatrix)[iRow])[iCol]) = 1;
						}
						else if((iRow == 3) && (iCol == 3))
						{
							((*(*TheRowMatrix)[iRow])[iCol]) =  1;
						}
						else if(iRow == iCol ) 
						{

							((*(*TheRowMatrix)[iRow])[iCol]) = static_cast<float>( floor((cos(fScalar[3]*PI_OVR_180 ))*1000+0.5)/1000 );
						}
						else if((iRow == 1) && (iCol == 2))
						{
							((*(*TheRowMatrix)[iRow])[iCol]) =  static_cast<float>( floor((sin(fScalar[3]*PI_OVR_180 ))*1000+0.5)/1000 );
						}
						else if((iRow == 2) && (iCol == 1))
						{
							((*(*TheRowMatrix)[iRow])[iCol]) =  static_cast<float>(floor((-1 * sin(fScalar[3]*PI_OVR_180))*1000+0.5)/1000 );
						}
						else
						{
							((*(*TheRowMatrix)[iRow])[iCol]) = 0;
						}
					}
				}
			}
			break;
		case 1: //y axis
			{
				for (int iRow = 0; iRow < 4; iRow++)
				{
					for (int iCol = 0; iCol < 4; iCol++)
					{
						//diagonal down all equal ones the rest equal 0
						if (iRow == iCol )
						{
							if(iRow % 2 )  //odd row
							{
								((*(*TheRowMatrix)[iRow])[iCol]) = 1;
							}
							else
							{
								((*(*TheRowMatrix)[iRow])[iCol]) =  static_cast<float>( floor((cos(fScalar[3]*PI_OVR_180 ))*1000+0.5)/1000 );
							}
						}
						else if((iRow == 0) && (iCol == 2))
						{
							((*(*TheRowMatrix)[iRow])[iCol]) =  static_cast<float>(floor((-1 * sin(fScalar[3]*PI_OVR_180))*1000+0.5)/1000 );
						}
						else if((iRow == 2) && (iCol == 0))
						{
							((*(*TheRowMatrix)[iRow])[iCol]) =   static_cast<float>(floor((sin(fScalar[3]*PI_OVR_180 ))*1000+0.5)/1000 );
						}
						else
						{
							((*(*TheRowMatrix)[iRow])[iCol]) = 0;
						}
					}
				}
			}
			break;
		case 2: //z Axis
			{
				for (int iRow = 0; iRow < 4; iRow++)
				{
					for (int iCol = 0; iCol < 4; iCol++)
					{
						//diagonal down all equal ones the rest equal 0
						if (iRow == iCol )
						{
							if(iRow > 1 )  //last 2 rows 
							{
								((*(*TheRowMatrix)[iRow])[iCol]) = 1;
							}
							else
							{
								((*(*TheRowMatrix)[iRow])[iCol]) =  static_cast<float>( floor((cos(fScalar[3]*PI_OVR_180 ))*1000+0.5)/1000 );
							}
						}
						else if((iRow == 0) && (iCol == 1))
						{
							((*(*TheRowMatrix)[iRow])[iCol]) =  static_cast<float>(floor((sin(fScalar[3]*PI_OVR_180 ))*1000+0.5)/1000) ;
						}
						else if((iRow == 1) && (iCol == 0))
						{
							((*(*TheRowMatrix)[iRow])[iCol]) =  static_cast<float>(floor((-1 * sin(fScalar[3]*PI_OVR_180))*1000+0.5)/1000 );
						}
						else
						{
							((*(*TheRowMatrix)[iRow])[iCol]) = 0;
						}
					}
				}

			}
			break;
		}
		
		
		for (int iRow = 0; iRow < 4; iRow++)
		{
			for (int iCol = 0; iCol < 4; iCol++)
			{
				((*(*TheColMatrix)[iRow])[iCol]) = 	((*(*TheRowMatrix)[iCol])[iRow]);
			}
		
		}

		//set text boxes using the matrix
		SetMatrix(_hDlg, TheRowMatrix, TheColMatrix);
		return TheRowMatrix;
	}
	else
	{
		return 0;
	}
}

/***********************
* Projection: Creates and returns the transformation matrix of its type (Projection)
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @return: vector<vector<float>*>*: The transformation matrix
********************/
vector<vector<float>*>* Projection(HWND _hDlg)
{
	//create the matrix from given values 
	vector<vector<float>*>* TheRowMatrix = new vector<vector<float>*>;
	vector<vector<float>*>* TheColMatrix = new vector<vector<float>*>;
	vector<float> fScalar;
	if (GetMatrix(_hDlg, TheRowMatrix, TheColMatrix) && GetVector(_hDlg,PROJECTION,&fScalar))
	{
		bool bValidAxis = false;
		int axis = 4;
		for(unsigned int i = 0; i < fScalar.size() - 1 ; i++)
		{
			if(fScalar[i] == 1)
			{
				if(!bValidAxis)
				{
					bValidAxis = true;
					axis = i;
				}
				else
				{
					MessageBox(_hDlg, TEXT("Error\n The choosen axis is not supported"), TEXT("Error"), MB_ICONERROR | MB_OK);
					return false;
				}
			}
		}
		if(bValidAxis == false)
		{
			MessageBox(_hDlg, TEXT("Error\n The choosen axis is not supported"), TEXT("Error"), MB_ICONERROR | MB_OK);
			return false;
		}

		for (int iRow = 0; iRow < 4; iRow++)
		{
			for (int iCol = 0; iCol < 4; iCol++)
			{
				//diagonal down all equal ones the rest equal 0
				if ((iRow == iCol ))
				{
					((*(*TheRowMatrix)[iRow])[iCol]) = 1;
				}
				else
				{
					((*(*TheRowMatrix)[iRow])[iCol]) = 0;
				}
			}
		}

		((*(*TheRowMatrix)[3])[3]) = 0;

		switch(axis)
		{
		case 0: //x axis
			{
				((*(*TheRowMatrix)[3])[0]) = 1/fScalar[3];				
			}
			break;
		case 1: //y axis
			{
				((*(*TheRowMatrix)[3])[1]) = 1/fScalar[3];
			}
			break;
		case 2: //z Axis
			{
				((*(*TheRowMatrix)[3])[2]) = 1/fScalar[3];
			}
			break;
		}
		
		
		for (int iRow = 0; iRow < 4; iRow++)
		{
			for (int iCol = 0; iCol < 4; iCol++)
			{
				((*(*TheColMatrix)[iRow])[iCol]) = 	((*(*TheRowMatrix)[iCol])[iRow]);
			}
		
		}

		//set text boxes using the matrix
		SetMatrix(_hDlg, TheRowMatrix, TheColMatrix);
		return TheRowMatrix;
	}
	else
	{
		return 0;
	}
}

vector<vector<float>*>* RotateA(HWND _hDlg)
{
	//create the matrix from given values 
	vector<vector<float>*>* TheRowMatrix = new vector<vector<float>*>;
	vector<vector<float>*>* TheColMatrix = new vector<vector<float>*>;
	vector<float> fScalar;
	if (GetMatrix(_hDlg, TheRowMatrix, TheColMatrix) && GetVector(_hDlg,ROTATION,&fScalar))
	{
		float fVersine = (1 - cos(fScalar[3]*PI_OVR_180));
		float fCosine = (cos(fScalar[3]*PI_OVR_180));
		float fSine = (sin(fScalar[3]*PI_OVR_180));
		float fX = fScalar[0];
		float fY = fScalar[1];
		float fZ = fScalar[2];

		//first Row
		((*(*TheRowMatrix)[0])[0]) = static_cast<float>(floor(((fVersine * (fX * fX) + fCosine))*1000+0.5)/1000);
		((*(*TheRowMatrix)[0])[1]) = static_cast<float>(floor(((fVersine * (fX * fY) + (fSine * fZ)))*1000+0.5)/1000); 
		((*(*TheRowMatrix)[0])[2]) = static_cast<float>(floor((fVersine * (fX * fZ) - (fSine * fY))*1000+0.5)/1000 ); 

		//Second Row
		((*(*TheRowMatrix)[1])[0]) = static_cast<float>(floor((fVersine * (fY * fX) - (fSine * fZ))*1000+0.5)/1000 );
		((*(*TheRowMatrix)[1])[1]) = static_cast<float>(floor((fVersine * (fY * fY) + fCosine)*1000+0.5)/1000 ); 
		((*(*TheRowMatrix)[1])[2]) = static_cast<float>(floor((fVersine * (fY * fZ) + (fSine * fX))*1000+0.5)/1000 ); 
		((*(*TheRowMatrix)[1])[3]) = 0;

		//Third Row
		((*(*TheRowMatrix)[2])[0]) = static_cast<float>(floor((fVersine * (fZ * fX) + (fSine * fY))*1000+0.5)/1000 );
		((*(*TheRowMatrix)[2])[1]) = static_cast<float>(floor((fVersine * (fZ * fY) - (fSine * fX))*1000+0.5)/1000 ); 
		((*(*TheRowMatrix)[2])[2]) = static_cast<float>(floor((fVersine * (fZ * fZ) + fCosine)*1000+0.5)/1000 ); 
		((*(*TheRowMatrix)[2])[3]) = 0;

		//ForthRow
		((*(*TheRowMatrix)[3])[0]) = 0;
		((*(*TheRowMatrix)[3])[1]) = 0;
		((*(*TheRowMatrix)[3])[2]) = 0;
		((*(*TheRowMatrix)[3])[3]) = 1;
		
		
		for (int iRow = 0; iRow < 4; iRow++)
		{
			for (int iCol = 0; iCol < 4; iCol++)
			{
				((*(*TheColMatrix)[iRow])[iCol]) = 	((*(*TheRowMatrix)[iCol])[iRow]);
			}
		
		}

		//set text boxes using the matrix
		//SetMatrix(_hDlg, TheRowMatrix, TheColMatrix);
		return TheRowMatrix;
	}
	else
	{
		return 0;
	}
}