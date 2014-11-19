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
	float fReturn = stof(pStr);
	delete pStr;
	pStr = 0;

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
	
	string sReturn = pStr;
	delete pStr;
	pStr = 0;

	return sReturn;
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
	//creates a string matrix
	vector<vector<string>*>* strMatrixA = new vector<vector<string>*>;
	vector<vector<string>*>* strMatrixB = new vector<vector<string>*>;
	GetStrMatrix(_hDlg , strMatrixA, strMatrixB);

	for(int iRow = 0; iRow < 4; iRow++)
	{
		vector<float>* vpfTempA = new vector<float>;
		vector<float>* vpfTempB = new vector<float>;
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
				
				deleteMatrix(strMatrixA);
				deleteMatrix(strMatrixB);
								
				return false;
			}
		}
		
		//add the temp row to the matrix
		(*_pMatrixA).push_back(vpfTempA);
		(*_pMatrixB).push_back(vpfTempB);
		
		//clear the temp row
	}
	
	//clean Up
	deleteMatrix(strMatrixA);
	deleteMatrix(strMatrixB);

	return true;
}

/***********************
* GetScalar: Gets and convert data from the scalar t dialog box
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _iMatrixChoice: Which matrix are you working with A or B
* @parameter: _fpScalar: a pointer to float, in which to store the scalar
* @return: bool: return true, if no errors exist
********************/
bool GetScalar(HWND _hDlg, int _iMatrixChoice, float* _fpScalar)
{
	//String Pointer to store the string values of the scalar
	string strScalar;

	//temp stringh to store the value in the dialog box
	wchar_t wstrTempA[100];

	
	switch(_iMatrixChoice)
	{
	case A:
		{
			//Get the Scalar value
			GetDlgItemText(_hDlg, IDC_A_SCALAR, wstrTempA, 100);
			(strScalar) = (WideStringToString(wstrTempA));	
		}
		break;
	case B:
		{
			//Get the Scalar value
			GetDlgItemText(_hDlg, IDC_B_SCALAR, wstrTempA, 100);
			(strScalar) = (WideStringToString(wstrTempA));	
		}
		break;
	}
	

	if(InputCheck(strScalar))
	{
		(*_fpScalar) = stof(strScalar);
		return true;
	}
	else
	{
		MessageBox(_hDlg, TEXT("Error\n Invalid Input detected Please only enter numerical values"), TEXT("Error"), MB_ICONERROR | MB_OK);
		return false;
	}
}

/***********************
* SetMatrix: Sets the matrix text boxes based on choosen matrix
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _pMatrix: a pointer to the matrix which hold the values that we want to set the text boxes to
* @parameter: _iChoice: which of the three matix text boxes to set
* @return: bool: return true
********************/
bool SetMatrix(HWND _hDlg, vector<vector<float>*>* _pMatrix, int _iChoice)
{

	string strTemp;
	switch(_iChoice)
	{
	case A:
		{
			//set the first row
			strTemp = FloatToString((*(*_pMatrix)[0])[0]);
			SetDlgItemTextA(_hDlg, IDC_A_00, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[0])[1]);
			SetDlgItemTextA(_hDlg, IDC_A_01, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[0])[2]);
			SetDlgItemTextA(_hDlg, IDC_A_02, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[0])[3]);
			SetDlgItemTextA(_hDlg, IDC_A_03, strTemp.c_str());

			//set the Second row
			strTemp = FloatToString((*(*_pMatrix)[1])[0]);
			SetDlgItemTextA(_hDlg, IDC_A_10, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[1])[1]);
			SetDlgItemTextA(_hDlg, IDC_A_11, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[1])[2]);
			SetDlgItemTextA(_hDlg, IDC_A_12, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[1])[3]);
			SetDlgItemTextA(_hDlg, IDC_A_13, strTemp.c_str());

			//set the Third row
			strTemp = FloatToString((*(*_pMatrix)[2])[0]);
			SetDlgItemTextA(_hDlg, IDC_A_20, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[2])[1]);
			SetDlgItemTextA(_hDlg, IDC_A_21, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[2])[2]);
			SetDlgItemTextA(_hDlg, IDC_A_22, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[2])[3]);
			SetDlgItemTextA(_hDlg, IDC_A_23, strTemp.c_str());

			//set the fourth row
			strTemp = FloatToString((*(*_pMatrix)[3])[0]);
			SetDlgItemTextA(_hDlg, IDC_A_30, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[3])[1]);
			SetDlgItemTextA(_hDlg, IDC_A_31, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[3])[2]);
			SetDlgItemTextA(_hDlg, IDC_A_32, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[3])[3]);
			SetDlgItemTextA(_hDlg, IDC_A_33, strTemp.c_str());

		}
		break;
	case B:
		{
			//set the first row
			strTemp = FloatToString((*(*_pMatrix)[0])[0]);
			SetDlgItemTextA(_hDlg, IDC_B_00, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[0])[1]);
			SetDlgItemTextA(_hDlg, IDC_B_01, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[0])[2]);
			SetDlgItemTextA(_hDlg, IDC_B_02, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[0])[3]);
			SetDlgItemTextA(_hDlg, IDC_B_03, strTemp.c_str());

			//set the Second row
			strTemp = FloatToString((*(*_pMatrix)[1])[0]);
			SetDlgItemTextA(_hDlg, IDC_B_10, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[1])[1]);
			SetDlgItemTextA(_hDlg, IDC_B_11, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[1])[2]);
			SetDlgItemTextA(_hDlg, IDC_B_12, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[1])[3]);
			SetDlgItemTextA(_hDlg, IDC_B_13, strTemp.c_str());

			//set the Third row
			strTemp = FloatToString((*(*_pMatrix)[2])[0]);
			SetDlgItemTextA(_hDlg, IDC_B_20, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[2])[1]);
			SetDlgItemTextA(_hDlg, IDC_B_21, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[2])[2]);
			SetDlgItemTextA(_hDlg, IDC_B_22, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[2])[3]);
			SetDlgItemTextA(_hDlg, IDC_B_23, strTemp.c_str());

			//set the fourth row
			strTemp = FloatToString((*(*_pMatrix)[3])[0]);
			SetDlgItemTextA(_hDlg, IDC_B_30, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[3])[1]);
			SetDlgItemTextA(_hDlg, IDC_B_31, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[3])[2]);
			SetDlgItemTextA(_hDlg, IDC_B_32, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[3])[3]);
			SetDlgItemTextA(_hDlg, IDC_B_33, strTemp.c_str());

		}
		break;
	case Result:
		{
			//set the first row
			strTemp = FloatToString((*(*_pMatrix)[0])[0]);
			SetDlgItemTextA(_hDlg, IDC_RESULT_00, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[0])[1]);
			SetDlgItemTextA(_hDlg, IDC_RESULT_01, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[0])[2]);
			SetDlgItemTextA(_hDlg, IDC_RESULT_02, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[0])[3]);
			SetDlgItemTextA(_hDlg, IDC_RESULT_03, strTemp.c_str());

			//set the Second row
			strTemp = FloatToString((*(*_pMatrix)[1])[0]);
			SetDlgItemTextA(_hDlg, IDC_RESULT_10, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[1])[1]);
			SetDlgItemTextA(_hDlg, IDC_RESULT_11, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[1])[2]);
			SetDlgItemTextA(_hDlg, IDC_RESULT_12, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[1])[3]);
			SetDlgItemTextA(_hDlg, IDC_RESULT_13, strTemp.c_str());

			//set the Third row
			strTemp = FloatToString((*(*_pMatrix)[2])[0]);
			SetDlgItemTextA(_hDlg, IDC_RESULT_20, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[2])[1]);
			SetDlgItemTextA(_hDlg, IDC_RESULT_21, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[2])[2]);
			SetDlgItemTextA(_hDlg, IDC_RESULT_22, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[2])[3]);
			SetDlgItemTextA(_hDlg, IDC_RESULT_23, strTemp.c_str());

			//set the fourth row
			strTemp = FloatToString((*(*_pMatrix)[3])[0]);
			SetDlgItemTextA(_hDlg, IDC_RESULT_30, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[3])[1]);
			SetDlgItemTextA(_hDlg, IDC_RESULT_31, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[3])[2]);
			SetDlgItemTextA(_hDlg, IDC_RESULT_32, strTemp.c_str());
			strTemp = FloatToString((*(*_pMatrix)[3])[3]);
			SetDlgItemTextA(_hDlg, IDC_RESULT_33, strTemp.c_str());
		}
		break;
	}

	//delete the matrix no longer required
	deleteMatrix(_pMatrix);

	return (true);

}

/***********************
* SetScalar: Sets scalar(Magnitude) text box 
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _iMatrixChoice: Which matrix are you working with A or B
* @parameter: _pfResult: a pointer to float,to which you want to set the text baox to
* @return: bool: return true, if no errors exist
********************/
bool SetScalar(HWND _hDlg, int _iMatrixChoice, float* _pfResult)
{
	string strTemp;

	switch(_iMatrixChoice)
	{
	case A:
		{
			//set the result Scalar text boxes
			strTemp = FloatToString(*_pfResult);
			SetDlgItemTextA(_hDlg, IDC_A_MAG_RESULT, strTemp.c_str());
		}
		break;
	case B:
		{
			//set the result Scalar text boxes
			strTemp = FloatToString(*_pfResult);
			SetDlgItemTextA(_hDlg, IDC_B_MAG_RESULT, strTemp.c_str());
		}
		break;
	}
	delete _pfResult;
	_pfResult = 0;

	
	return (true);
}

/***********************
* SetToI: Set the choosen matrix tho the Identity Matrix
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _iMatrixChoice: Which matrix are you working with A or B
* @return: bool: return true, if no errors exist
********************/
bool SetToI(HWND _hDlg, int _iMatrixChoice)
{

	//create the matrix from given values 
	vector<vector<float>*>* TheMatrixA = new vector<vector<float>*>;
	vector<vector<float>*>* TheMatrixB = new vector<vector<float>*>;
	
	if (GetMatrix(_hDlg, TheMatrixA, TheMatrixB))
	{
		vector<vector<float>*>* TheMatrix = 0;
		switch (_iMatrixChoice)
		{
			case A:
			{
				TheMatrix = TheMatrixA;
				deleteMatrix(TheMatrixB);
			}
			break;
			case B:
			{
				TheMatrix = TheMatrixB;
				deleteMatrix(TheMatrixA);
			}
			break;
		}

		for (int iRow = 0; iRow < 4; iRow++)
		{
			for (int iCol = 0; iCol < 4; iCol++)
			{
				//diagonal down all equal ones the rest equal 0
				if (iRow == iCol)
				{
					((*(*TheMatrix)[iRow])[iCol]) = 1;
				}
				else
				{
					((*(*TheMatrix)[iRow])[iCol]) = 0;
				}
			}
			
		}

		//set text boxes using the matrix
		SetMatrix(_hDlg, TheMatrix, _iMatrixChoice);
	}
	else
	{
		return false;
	}
	
	return true;

}

/***********************
* ScalarMultiply: Multiplies a choosen matrix by a given scalar
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _iMatrixChoice: Which matrix are you working with A or B
* @return: bool: return true, if no errors exist
********************/
bool ScalarMultiply(HWND _hDlg, int _iMatrixChoice)
{
	float fpScalar = 0.0f;
	
	//create the matrix from given values 
	vector<vector<float>*>* TheMatrixA = new vector<vector<float>*>;
	vector<vector<float>*>* TheMatrixB = new vector<vector<float>*>;
		
	if (GetMatrix(_hDlg, TheMatrixA, TheMatrixB) && GetScalar(_hDlg, _iMatrixChoice, &fpScalar))
	{
		vector<vector<float>*>* TheMatrix = 0;
		switch (_iMatrixChoice)
		{
		case A:
		{
			TheMatrix = TheMatrixA;
			deleteMatrix(TheMatrixB);
		}
			break;
		case B:
		{
			TheMatrix = TheMatrixB;
			deleteMatrix(TheMatrixA);
		}
			break;
		}

		for (int iRow = 0; iRow < 4; iRow++)
		{
			for (int iCol = 0; iCol < 4; iCol++)
			{
				//multiply every element by the scallar
				((*(*TheMatrix)[iRow])[iCol]) = ((*(*TheMatrix)[iRow])[iCol]) * (fpScalar);
				
			}

		}

		//set text boxes using the matrix
		SetMatrix(_hDlg, TheMatrix, _iMatrixChoice);
		
	}
	else
	{
		deleteMatrix(TheMatrixB);
		deleteMatrix(TheMatrixA);
		return false;
	}
		
	return true;
}

/***********************
* Add: Adds two matrices together 
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @return: bool: return true, if no errors exist
********************/
bool Add(HWND _hDlg)
{
	//create the matrix from given values 
	vector<vector<float>*>* TheMatrixA = new vector<vector<float>*>;
	vector<vector<float>*>* TheMatrixB = new vector<vector<float>*>;
	vector<vector<float>*>* TheMatrix = new vector<vector<float>*>;

	vector<float>* tempRow = new vector<float>;

	for (int iRow = 0; iRow < 4; iRow++)
	{
		for (int iCol = 0; iCol < 4; iCol++)
		{
			tempRow->push_back(0);
		}
		TheMatrix->push_back(tempRow);
		tempRow = new vector<float>;
	}

	if (GetMatrix(_hDlg, TheMatrixA, TheMatrixB))
	{
		
		for (int iRow = 0; iRow < 4; iRow++)
		{
			for (int iCol = 0; iCol < 4; iCol++)
			{
				((*(*TheMatrix)[iRow])[iCol]) = ((*(*TheMatrixA)[iRow])[iCol]) + ((*(*TheMatrixB)[iRow])[iCol]);
			}
		}

		//set text boxes using the matrix
		SetMatrix(_hDlg, TheMatrix, Result);
		
	}
	else
	{
		deleteMatrix(TheMatrixA);
		deleteMatrix(TheMatrixB);
		return false;
	}

	delete tempRow;
	tempRow = 0;
		
	deleteMatrix(TheMatrixA);
	deleteMatrix(TheMatrixB);
		
	return true;

}

/***********************
* Sub: Subtracts matrix B from Matrix A
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @return: bool: return true, if no errors exist
********************/
bool Sub(HWND _hDlg)
{
	//create the matrix from given values 
	vector<vector<float>*>* TheMatrixA = new vector<vector<float>*>;
	vector<vector<float>*>* TheMatrixB = new vector<vector<float>*>;
	vector<vector<float>*>* TheMatrix = new vector<vector<float>*>;

	vector<float>* tempRow = new vector<float>;

	for (int iRow = 0; iRow < 4; iRow++)
	{
		for (int iCol = 0; iCol < 4; iCol++)
		{
			tempRow->push_back(0);
		}
		TheMatrix->push_back(tempRow);
		tempRow = new vector<float>;
	}

	

	if (GetMatrix(_hDlg, TheMatrixA, TheMatrixB))
	{

		for (int iRow = 0; iRow < 4; iRow++)
		{
			for (int iCol = 0; iCol < 4; iCol++)
			{
				((*(*TheMatrix)[iRow])[iCol]) = ((*(*TheMatrixA)[iRow])[iCol]) - ((*(*TheMatrixB)[iRow])[iCol]);
			}

		}

		//set text boxes using the matrix
		SetMatrix(_hDlg, TheMatrix, Result);
		//return true;
	}
	else
	{
		deleteMatrix(TheMatrixA);
		deleteMatrix(TheMatrixB);
		delete tempRow;
		tempRow = 0;
		return false;
	}
	
	delete tempRow;
	tempRow = 0;
	deleteMatrix(TheMatrixA);
	deleteMatrix(TheMatrixB);

	return true;
}

/***********************
* Transpose: Transposes the choosen Matrix
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _iMatrixChoice: Which matrix are you working with A or B
* @return: bool: return true, if no errors exist
********************/
bool Transpose(HWND _hDlg, int _iMatrixChoice)
{
	
	//create the matrix from given values 
	vector<vector<float>*>* TheMatrixA = new vector<vector<float>*>;
	vector<vector<float>*>* TheMatrixB = new vector<vector<float>*>;
	vector<vector<float>*>* TheMatrix = new vector<vector<float>*>;

	vector<float>* tempRow = new vector<float>;

	for (int iRow = 0; iRow < 4; iRow++)
	{
		for (int iCol = 0; iCol < 4; iCol++)
		{
			tempRow->push_back(0);
		}
		TheMatrix->push_back(tempRow);
		tempRow = new vector<float>;
	}

	if (GetMatrix(_hDlg, TheMatrixA, TheMatrixB))
	{
		switch (_iMatrixChoice)
		{
		case A:
		{
			for (int iRow = 0; iRow < 4; iRow++)
			{
				for (int iCol = 0; iCol < 4; iCol++)
				{
					//Sets the rows to columns and columns to rows
					((*(*TheMatrix)[iRow])[iCol]) = ((*(*TheMatrixA)[iCol])[iRow]);

				}

			}
		}
			break;
		case B:
		{
			for (int iRow = 0; iRow < 4; iRow++)
			{
				for (int iCol = 0; iCol < 4; iCol++)
				{
					//Sets the rows to columns and columns to rows
					((*(*TheMatrix)[iRow])[iCol]) = ((*(*TheMatrixB)[iCol])[iRow]);

				}

			}
		}
			break;
		}

		

		//set text boxes using the matrix
		SetMatrix(_hDlg, TheMatrix, _iMatrixChoice);
	
	}
	else
	{
		delete tempRow;
		tempRow = 0;
		deleteMatrix(TheMatrixA);
		deleteMatrix(TheMatrixB);
		return false;
	}

	delete tempRow;
	tempRow = 0;
	deleteMatrix(TheMatrixA);
	deleteMatrix(TheMatrixB);
	return true;

}

/***********************
* Multiply: Transposes the choosen Matrix
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _iMatrixChoice: Which matrix are you working with A or B
* @return: bool: return true, if no errors exist
********************/
bool MatrixMultiply(HWND _hDlg, int _iMatrixChoice)
{

	//create the matrix from given values 
	vector<vector<float>*>* TheMatrixA = new vector<vector<float>*>;
	vector<vector<float>*>* TheMatrixB = new vector<vector<float>*>;
	vector<vector<float>*>* TheMatrix = new vector<vector<float>*>;

	vector<float>* tempRow = new vector<float>;

	for (int iRow = 0; iRow < 4; iRow++)
	{
		for (int iCol = 0; iCol < 4; iCol++)
		{
			tempRow->push_back(0);
		}
		TheMatrix->push_back(tempRow);
		tempRow = new vector<float>;
	}
	

	if (GetMatrix(_hDlg, TheMatrixA, TheMatrixB))
	{

		switch (_iMatrixChoice)
		{
		case A:
		{
			for (int iRow = 0; iRow < 4; iRow++)
			{
				for (int iCol = 0; iCol < 4; iCol++)
				{
					for (int i = 0; i < 4; i++)
					{
						((*(*TheMatrix)[iRow])[iCol]) += ((*(*TheMatrixA)[iRow])[i]) * ((*(*TheMatrixB)[i])[iCol]);
					}
				}
			}
		}
			break;
		case B:
		{
			for (int iRow = 0; iRow < 4; iRow++)
			{
				for (int iCol = 0; iCol < 4; iCol++)
				{
					for (int i = 0; i < 4; i++)
					{
						((*(*TheMatrix)[iRow])[iCol]) += ((*(*TheMatrixB)[iRow])[i]) * ((*(*TheMatrixA)[i])[iCol]);
					}
				}

			}
		}
			break;
		}

		

		//set text boxes using the matrix
		SetMatrix(_hDlg, TheMatrix, Result);
		
	}
	else
	{
		delete tempRow;
		tempRow = 0;
		deleteMatrix(TheMatrixA);
		deleteMatrix(TheMatrixB);
		return false;
	}

	delete tempRow;
	tempRow = 0;
	deleteMatrix(TheMatrixA);
	deleteMatrix(TheMatrixB);
	
	return true;
}

/***********************
* Magnitude: Calculates the magnitude of the choosen matrix
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _iMatrixChoice: Which matrix are you working with A or B
* @return: bool: return true, if no errors exist
********************/
bool Magnitude(HWND _hDlg, int _iMatrixChoice)
{
	
	//create the matrix from given values 
	vector<vector<float>*>* TheMatrixA = new vector<vector<float>*>;
	vector<vector<float>*>* TheMatrixB = new vector<vector<float>*>;
	
	float* pfMag = new float;
	(*pfMag) = 0;
		
	if (GetMatrix(_hDlg, TheMatrixA, TheMatrixB) )
	{
		vector<vector<float>*>* TheMatrix = 0;
		switch (_iMatrixChoice)
		{
		case A:
		{
			TheMatrix = TheMatrixA;
			deleteMatrix(TheMatrixB);
		}
			break;
		case B:
		{
			TheMatrix = TheMatrixB;
			deleteMatrix(TheMatrixA);
		
		}
			break;
		}
		
		(*pfMag) = Det(TheMatrix);

		//set text boxes using the matrix
		SetScalar(_hDlg, _iMatrixChoice, pfMag);
		deleteMatrix(TheMatrix);
	}
	else
	{
		return false;
	}
		
}

/***********************
* Det: calculates The determinant of a given square matrix
* @author: Jc Fowles
* @parameter: _Matrix: given matrix to calculate determinant of
* @return: float: determinant of a square given matrix
********************/
float Det(vector<vector<float>*>* _Matrix)
{
	vector<float> MatrixElement;

	//base case
	//if we have a 2x2 martix return ( ([0][0]*[1][1]) - ([0][1]*[1][0]) ) (the cofactor)
	if ( ((*_Matrix)[0]->size()) == 2)
	{
		return ( (((*(*_Matrix)[0])[0]) * ((*(*_Matrix)[1])[1])) - (((*(*_Matrix)[0])[1]) * ((*(*_Matrix)[1])[0])) );
	}
	else
	{
		float fReturnVal = 0;
		for (unsigned int i = 0; i < (*_Matrix)[0]->size(); i++)
		{
			vector<vector<float>*>* SmallerMatrix = new vector < vector<float>* > ;
			vector<float>* tempRow = new vector<float>;

			for (unsigned int iRow = 0; iRow < (*_Matrix)[0]->size(); iRow++)
			{
				for (unsigned int iCol = 0; iCol < (*_Matrix)[0]->size(); iCol++)
				{
					//check to disrigard the first row, and column i to create the smaller matrix
					if ((iRow != 0) && (iCol != i))
					{
						tempRow->push_back(((*(*_Matrix)[iRow])[iCol]));
					}
					else if ((iRow == 0) )	//if we are on the first row save the value, matrix element value to be multiplied by the Deteminant of the smaller matrix being created
					{
						//negate the elemant in odd colomns in the matrix
						if (iCol % 2) //i is odd)
						{
							MatrixElement.push_back((-1 * ((*(*_Matrix)[iRow])[iCol])));
						}
						else
						{
							MatrixElement.push_back(((*(*_Matrix)[iRow])[iCol]));
						}
					}
				}
				if (!(tempRow->empty()))
				{
					SmallerMatrix->push_back(tempRow);
					tempRow = new vector<float>;
				}
			}
			//recursion
			//value to be return is the matrix element multiplied by the determinant of the smaller matrix
			fReturnVal += MatrixElement[i] * Det(SmallerMatrix);
			delete tempRow;
			tempRow = 0;
			deleteMatrix(SmallerMatrix);
		}
		

		return fReturnVal;
	}
}

/***********************
* Inverse: Calculates the inverse of the choosen matrix
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _iMatrixChoice: Which matrix are you working with A or B
* @return: bool: return true, if no errors exist
********************/
bool Inverse(HWND _hDlg, int _iMatrixChoice)
{
	//create the matrix from given values 
	vector<vector<float>*>* TheMatrixA = new vector<vector<float>*>;
	vector<vector<float>*>* TheMatrixB = new vector<vector<float>*>;
	
	float oneOverDet = 0;
		
	if (GetMatrix(_hDlg, TheMatrixA, TheMatrixB))
	{
		vector<vector<float>*>* TheMatrix = 0;
		switch (_iMatrixChoice)
		{
		case A:
		{
			TheMatrix = Adj(TheMatrixA);
			oneOverDet = Det(TheMatrixA);
			deleteMatrix(TheMatrixB);
			deleteMatrix(TheMatrixA);
		}
			break;
		case B:
		{
			TheMatrix = Adj(TheMatrixB);
			oneOverDet = Det(TheMatrixB);
			deleteMatrix(TheMatrixA);
			deleteMatrix(TheMatrixB);
		}
			break;
		}

		if(oneOverDet != 0) //if det is not 0 then inverse exists 
		{
			oneOverDet = 1/oneOverDet;
			for (unsigned int iRow = 0; iRow < 4; iRow++)
			{
				for (unsigned int iCol = 0; iCol < 4; iCol++)
				{
					((*(*TheMatrix)[iRow])[iCol]) = ((*(*TheMatrix)[iRow])[iCol]) * oneOverDet;
				}
			}
			
			//set text boxes using the matrix
			//SetMatrix(_hDlg, TheMatrix, _iMatrixChoice);
			deleteMatrix(TheMatrix);
			//return true;
		}
		else //inverse does not exist
		{
			Initialise(_hDlg);
			MessageBox(_hDlg, TEXT("No inverse exists!"), TEXT("No Inverse"), MB_ICONERROR | MB_OK);
			deleteMatrix(TheMatrix);
			//return true;
		}
	}
	else
	{
		deleteMatrix(TheMatrixA);
		deleteMatrix(TheMatrixB);
		return false;
	}
	return true;
	
}

/***********************
* Adj: Calculates the adjoint of the given matrix
* @author: Jc Fowles
* @parameter: _Matrix: the matrix to calculate the adjoint of
* @return: vector<vector<float>*>* : pointer to the adjoint matrix
********************/
vector<vector<float>*>* Adj(vector<vector<float>*>* _Matrix)
{

	vector<vector<float>*>* TheMatrix = new vector<vector<float>*>;
	vector<vector<float>*>* TransMatrix = new vector<vector<float>*>;
	vector<float>* tempRowA = new vector<float>;

	//initialises two 4x4 matrices
	for (int iRow = 0; iRow < 4; iRow++)
	{
		for (int iCol = 0; iCol < 4; iCol++)
		{
			tempRowA->push_back(0);
		}
		TheMatrix->push_back(tempRowA);
		tempRowA = new vector<float>;
	}
	

	for (int iRow = 0; iRow < 4; iRow++)
	{
		for (int iCol = 0; iCol < 4; iCol++)
		{
			tempRowA->push_back(0);
		}
		TransMatrix->push_back(tempRowA);
		tempRowA = new vector<float>;
	}
	
	delete tempRowA;
	tempRowA = 0;


	for (unsigned int i = 0; i < 4; i++)
	{
		for (unsigned int j = 0; j < 4; j++)
		{
			vector<vector<float>*>* SmallerMatrix = new vector <vector<float>*>;
			vector<float>* tempRow = new vector<float>;
			//get the minor matrix of each element in the matrix
			for (unsigned int iRow = 0; iRow < 4; iRow++)
			{
				if(iRow != i)
				{
					for (unsigned int iCol = 0; iCol < 4; iCol++)
					{
						if (iCol != j)
						{
							tempRow->push_back(((*(*_Matrix)[iRow])[iCol]));
						}
					}
				}
				if (!(tempRow->empty()))
				{
					SmallerMatrix->push_back(tempRow);
					tempRow = new vector<float>;
				}
				

			}
			delete tempRow;
			tempRow = 0;


			//each element in the matrix become the determinant of its minor matrix
			//and when i + j = and odd number multiply by -1, to get its cofactor matrix
			if ((i + j) % 2) //i is odd)
			{
				(*(*TheMatrix)[i])[j] = -1 * Det(SmallerMatrix);
			}
			else
			{
				(*(*TheMatrix)[i])[j] =  Det(SmallerMatrix);
			}
			deleteMatrix(SmallerMatrix);
		}
	}

	//Translate the matrix to get the adjoint matrix
	for (unsigned int iRow = 0; iRow < 4; iRow++)
	{
		for (unsigned int iCol = 0; iCol < 4; iCol++)
		{
			(*(*TransMatrix)[iRow])[iCol] = (*(*TheMatrix)[iCol])[iRow];
		}
	}

	deleteMatrix(TheMatrix);
			
	return TransMatrix;
}

/***********************
* deleteMatrix: Delete a matrix
* @author: Jc Fowles
* @parameter: _Matrix: The matrix to be deleted
* @return: vector<vector<float>*>* : pointer to the adjoint matrix
********************/
void deleteMatrix(vector<vector<float>*>* _Matrix)
{
	while(!((*_Matrix).empty()))
	{
		delete (*_Matrix).back();
		(*_Matrix).back() = 0;
		(*_Matrix).pop_back();
	}
	delete _Matrix;
	_Matrix = 0;
}

/***********************
* deleteMatrix: Delete a matrix
* @author: Jc Fowles
* @parameter: _Matrix: The matrix to be deleted
* @return: vector<vector<float>*>* : pointer to the adjoint matrix
********************/
void deleteMatrix(vector<vector<string>*>* _Matrix)
{
	while(!((*_Matrix).empty()))
	{
		delete (*_Matrix).back();
		(*_Matrix).back() = 0;
		(*_Matrix).pop_back();
	}
	delete _Matrix;
	_Matrix = 0;
}