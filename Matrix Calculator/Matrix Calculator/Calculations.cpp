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
	return (stof(pStr));
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
	
	return pStr;
}

/***********************
* GetStrMatrix: Gets the values from the Matrices dialog boxes and stores it into a string vector 
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _pMatrixA: a pointer to the matrix in whcih Matrix A to be stored
* @parameter: _pMatrixB: a pointer to the matrix in whcih Matrix B to be stored
* @return: bool: return true
********************/
bool GetStrMatrix(HWND _hDlg, vector<vector<string>*>* _pMatrixA,vector<vector<string>*>* _pMatrixB)
{
	wchar_t wstrTempA[100];
	//temp matrix row
	vector<string>* vpstrTempA = new vector<string>;
	vector<string>* vpstrTempB = new vector<string>;
		
	//First row enter into the matrix A
	GetDlgItemText(_hDlg, IDC_A_00, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));		

	GetDlgItemText(_hDlg, IDC_A_01, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_A_02, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_A_03, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));

	//First row enter into the matrix B
	GetDlgItemText(_hDlg, IDC_B_00, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));		

	GetDlgItemText(_hDlg, IDC_B_01, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_B_02, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_B_03, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));

	//add the temp row to the matrix
	(*_pMatrixA).push_back(vpstrTempA);
	(*_pMatrixB).push_back(vpstrTempB);

	//clear the temp row
	vpstrTempA = new vector<string>;
	vpstrTempB = new vector<string>;


	//Second row enter into the matrix A
	GetDlgItemText(_hDlg, IDC_A_10, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));		

	GetDlgItemText(_hDlg, IDC_A_11, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_A_12, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_A_13, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));

	//Second row enter into the matrix B
	GetDlgItemText(_hDlg, IDC_B_10, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));		

	GetDlgItemText(_hDlg, IDC_B_11, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_B_12, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_B_13, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));

	//add the temp row to the matrix
	(*_pMatrixA).push_back(vpstrTempA);
	(*_pMatrixB).push_back(vpstrTempB);

	//clear the temp row
	vpstrTempA = new vector<string>;
	vpstrTempB = new vector<string>;
	

	//Third row enter into the matrix A
	GetDlgItemText(_hDlg, IDC_A_20, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));		

	GetDlgItemText(_hDlg, IDC_A_21, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_A_22, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_A_23, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));

	//Third row enter into the matrix B
	GetDlgItemText(_hDlg, IDC_B_20, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));		

	GetDlgItemText(_hDlg, IDC_B_21, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_B_22, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_B_23, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));

	//add the temp row to the matrix
	(*_pMatrixA).push_back(vpstrTempA);
	(*_pMatrixB).push_back(vpstrTempB);

	//clear the temp row
	vpstrTempA = new vector<string>;
	vpstrTempB = new vector<string>;


	//Fourth row enter into the matrix A
	GetDlgItemText(_hDlg, IDC_A_30, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));		

	GetDlgItemText(_hDlg, IDC_A_31, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_A_32, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_A_33, wstrTempA, 100);
	(*vpstrTempA).push_back((WideStringToString(wstrTempA)));

	//Fourth row enter into the matrix B
	GetDlgItemText(_hDlg, IDC_B_30, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));		

	GetDlgItemText(_hDlg, IDC_B_31, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_B_32, wstrTempA, 100);
	(*vpstrTempB).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_B_33, wstrTempA, 100);
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

}
float GetScalar(HWND _hDlg, int _iMatrixChoice, int _iScalarChoice);
