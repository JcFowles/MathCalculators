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
	
	SetDlgItemTextA( _hDlg, IDC_A_I,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_A_J,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_A_K,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_A,strTemp.c_str());

	SetDlgItemTextA( _hDlg, IDC_B_I,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_B_J,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_B_K,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_B,strTemp.c_str());

	SetDlgItemTextA( _hDlg, IDC_T,strTemp.c_str());
	
	SetDlgItemTextA( _hDlg, IDC_RESULT_I,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_RESULT_J,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_RESULT_K,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_RESULT,strTemp.c_str());


	//the Matrix
	SetDlgItemTextA( _hDlg, IDC_MATRIX_00,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_MATRIX_01,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_MATRIX_02,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_MATRIX_03,strTemp.c_str());

	SetDlgItemTextA( _hDlg, IDC_MATRIX_10,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_MATRIX_11,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_MATRIX_12,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_MATRIX_13,strTemp.c_str());

	SetDlgItemTextA( _hDlg, IDC_MATRIX_20,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_MATRIX_21,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_MATRIX_22,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_MATRIX_23,strTemp.c_str());

	SetDlgItemTextA( _hDlg, IDC_MATRIX_30,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_MATRIX_31,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_MATRIX_32,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_MATRIX_33,strTemp.c_str());

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
	
	string strReturn = pStr;
	delete pStr;
	pStr = 0;

	return strReturn;
}

/***********************
* GetQuaternionStr: Gets the values from the quaternion dialog boxes and stores it into a vector
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _pStrQuatA: a pointer to a vector in which the values are to be stored for quaternion A
* @parameter: _pStrQuatB: a pointer to a vector in which the values are to be stored for quaternion B
* @return: bool: return true
********************/
bool GetQuaternionStr(HWND _hDlg, vector<string>* _pStrQuatA, vector<string>* _pStrQuatB, vector<string>* _pstrQuatSlerp)
{
	//temp stringh to store the value in the dialog box
	wchar_t wstrTempA[100];
			
	//Quaternion A
	GetDlgItemText(_hDlg, IDC_A_I, wstrTempA, 100);
	(*_pStrQuatA).push_back((WideStringToString(wstrTempA)));		

	GetDlgItemText(_hDlg, IDC_A_J, wstrTempA, 100);
	(*_pStrQuatA).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_A_K, wstrTempA, 100);
	(*_pStrQuatA).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_A, wstrTempA, 100);
	(*_pStrQuatA).push_back((WideStringToString(wstrTempA)));


	//Quaternion B
	GetDlgItemText(_hDlg, IDC_B_I, wstrTempA, 100);
	(*_pStrQuatB).push_back((WideStringToString(wstrTempA)));		

	GetDlgItemText(_hDlg, IDC_B_J, wstrTempA, 100);
	(*_pStrQuatB).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_B_K, wstrTempA, 100);
	(*_pStrQuatB).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_B, wstrTempA, 100);
	(*_pStrQuatB).push_back((WideStringToString(wstrTempA)));

	//Quaternion Slerp result
	GetDlgItemText(_hDlg, IDC_RESULT_I, wstrTempA, 100);
	(*_pstrQuatSlerp).push_back((WideStringToString(wstrTempA)));		

	GetDlgItemText(_hDlg, IDC_RESULT_J, wstrTempA, 100);
	(*_pstrQuatSlerp).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_RESULT_K, wstrTempA, 100);
	(*_pstrQuatSlerp).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_RESULT, wstrTempA, 100);
	(*_pstrQuatSlerp).push_back((WideStringToString(wstrTempA)));

	return (true);

}

/***********************
* GetQuaternion: Gets and convert data from the quaternion dialog boxes into two float vectors
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _pfQuatA: a pointer to a vector in which the values are to be stored for quaternion A
* @parameter: _pfQuatB: a pointer to a vector in which the values are to be stored for quaternion B
* @return: bool: return true, if no errors exist
********************/
bool GetQuaternion(HWND _hDlg, vector<float>* _pfQuatA, vector<float>* _pfQuatB,  vector<float>* _pfQuatSlerp)
{
	//String Pointer to store the string values of the quaternions
	vector<string>* pStrTempQuatA = new vector<string>;
	vector<string>* pStrTempQuatB = new vector<string>;
	vector<string>* pStrTempQuatSlerp = new vector<string>;

	GetQuaternionStr(_hDlg, pStrTempQuatA, pStrTempQuatB, pStrTempQuatSlerp);

	for(int i = 0; i < 4; i++)
	{
		//check if inputs are valid floats
		if(InputCheck((*pStrTempQuatA)[i]) &&
		   InputCheck((*pStrTempQuatB)[i]) )
		{
			//convert to flaots and push onto the float vector
			(*_pfQuatA).push_back(stof((*pStrTempQuatA)[i]));
			(*_pfQuatB).push_back(stof((*pStrTempQuatB)[i]));
			(*_pfQuatSlerp).push_back(stof((*pStrTempQuatSlerp)[i]));
		}
		else
		{
			//invalid input found
			return false;
		}
	}

	delete pStrTempQuatA;
	pStrTempQuatA = 0;
	delete pStrTempQuatB;
	pStrTempQuatB = 0;
	delete pStrTempQuatSlerp;
	pStrTempQuatSlerp = 0;

	return (true);

}

/***********************
* GetScalar: Gets and convert data from the scalar t dialog box
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _pfQuatA: a pointer to a vector in which the values are to be stored for quaternion A
* @parameter: _pfQuatB: a pointer to a vector in which the values are to be stored for quaternion B
* @return: bool: return true, if no errors exist
********************/
bool GetScalar(HWND _hDlg, float* _fpScalar)
{
	//String Pointer to store the string values of the scalar
	string strScalar;

	//temp stringh to store the value in the dialog box
	wchar_t wstrTempA[100];
			
	//Get the Scalar value
	GetDlgItemText(_hDlg, IDC_T, wstrTempA, 100);
	(strScalar) = (WideStringToString(wstrTempA));	

	if(InputCheck(strScalar))
	{
		*_fpScalar = stof(strScalar);
		if((*_fpScalar) <= 1 &&
		   (*_fpScalar) >= 0)
		{
			return true;
		}
		else
		{
			return false;
		}
		
	}
	else
	{
		return false;
	}

}

/***********************
* setResult: Sets the result, either in quaternion or scalar form dependant on passed in parameter
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _pResultQuat: The Resultant queternion to be set into respective text box
* @return: bool: return true
********************/
bool setResult(HWND _hDlg, vector<float>* _pResultQuat)
{
	string strTemp;

	//set the result Quaternion text boxes
	strTemp = FloatToString((*_pResultQuat)[0]);
	SetDlgItemTextA(_hDlg, IDC_RESULT_I, strTemp.c_str());

	strTemp = FloatToString((*_pResultQuat)[1]);
	SetDlgItemTextA(_hDlg, IDC_RESULT_J, strTemp.c_str());

	strTemp = FloatToString((*_pResultQuat)[2]);
	SetDlgItemTextA(_hDlg, IDC_RESULT_K, strTemp.c_str());

	strTemp = FloatToString((*_pResultQuat)[3]);
	SetDlgItemTextA(_hDlg, IDC_RESULT, strTemp.c_str());

	delete _pResultQuat;
	_pResultQuat = 0;

	return(true);
}

/***********************
* setResult: Sets the result, either in quaternion or scalar form dependant on passed in parameter
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _fResult: The Resultant scalar to be set into respective text box
* @return: bool: return true
********************/
bool setResult(HWND _hDlg, vector<vector<float>*>* _pfMatrix)
{
	string strTemp;

	//set the first row
	strTemp = FloatToString((*(*_pfMatrix)[0])[0]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_00, strTemp.c_str());
	strTemp = FloatToString((*(*_pfMatrix)[0])[1]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_01, strTemp.c_str());
	strTemp = FloatToString((*(*_pfMatrix)[0])[2]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_02, strTemp.c_str());
	strTemp = FloatToString((*(*_pfMatrix)[0])[3]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_03, strTemp.c_str());

	//set the Second row
	strTemp = FloatToString((*(*_pfMatrix)[1])[0]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_10, strTemp.c_str());
	strTemp = FloatToString((*(*_pfMatrix)[1])[1]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_11, strTemp.c_str());
	strTemp = FloatToString((*(*_pfMatrix)[1])[2]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_12, strTemp.c_str());
	strTemp = FloatToString((*(*_pfMatrix)[1])[3]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_13, strTemp.c_str());

	//set the Third row
	strTemp = FloatToString((*(*_pfMatrix)[2])[0]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_20, strTemp.c_str());
	strTemp = FloatToString((*(*_pfMatrix)[2])[1]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_21, strTemp.c_str());
	strTemp = FloatToString((*(*_pfMatrix)[2])[2]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_22, strTemp.c_str());
	strTemp = FloatToString((*(*_pfMatrix)[2])[3]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_23, strTemp.c_str());

	//set the Forth row
	strTemp = FloatToString((*(*_pfMatrix)[3])[0]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_30, strTemp.c_str());
	strTemp = FloatToString((*(*_pfMatrix)[3])[1]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_31, strTemp.c_str());
	strTemp = FloatToString((*(*_pfMatrix)[3])[2]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_32, strTemp.c_str());
	strTemp = FloatToString((*(*_pfMatrix)[3])[3]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_33, strTemp.c_str());

	//delete the matrix no longer required
	while(!(_pfMatrix->empty()))
	{
		delete _pfMatrix->back();
		_pfMatrix->back() = 0;
		_pfMatrix->pop_back();
	}
	delete _pfMatrix;
	_pfMatrix = 0;

	return (true);
}

/***********************
* slerp: 
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @return: bool: return true
********************/
bool slerp(HWND _hDlg)
{
	float fOmega = 0.0f;

	float fScalor = 0.0f;

	vector<float>* pfQuatA = new vector<float>;
	vector<float>* pfQuatB = new vector<float>;

	vector<float>* pfNormQuatA = new vector<float>;
	vector<float>* pfNormQuatB = new vector<float>;

	vector<float>* pfQuatSlerp = new vector<float>;

	//gets the Quaternions
	if(GetQuaternion(_hDlg, pfQuatA, pfQuatB, pfQuatSlerp) && GetScalar(_hDlg, &fScalor))
	{
		//Normalising the 2 quaternions
		//Getting the magnitude
		float fMagA = 0.0f;
		float fMagB = 0.0f;
		//magnitude
		for(int i = 0; i < 4; i++)
		{
			fMagA += (*pfQuatA)[i] * (*pfQuatA)[i] ;
			fMagB += (*pfQuatB)[i] * (*pfQuatB)[i] ;
		}

		fMagA = sqrt(fMagA);
		fMagB = sqrt(fMagB);

		for(int i = 0 ; i < 4; i++)
		{
			pfNormQuatA->push_back((*pfQuatA)[i]/fMagA);
			pfNormQuatB->push_back((*pfQuatB)[i]/fMagB);
		}


		//compute the dot product to get omega
		for(int i = 0; i < 4; i++)
		{
			(fOmega) +=  (*pfNormQuatA)[i] * (*pfNormQuatB)[i] ;	
		}

		// If negative dot, negate one of the input
		// quaternions to take the shorter 4D "arc"
		if(fOmega < 0.0f)
		{
			for(int i = 0; i < 4; i++)
			{
				(*pfNormQuatB)[i] = -1*(*pfNormQuatB)[i];
			}
			fOmega = -1*fOmega;
		}


		// Check if they are very close together to protect
		// against divide-by-zero
		float fScalar0 = 0.0f;
		float fScalar1 = 0.0f;
		if(fOmega > 0.9999f)
		{
			// Very close - just use linear interpolation

			fScalar0 = 1.0f - fScalor;
			fScalar1 = fScalor;
		}
		else
		{
			fScalar0 = ((sin((1 - fScalor)*fOmega))/sin(fOmega));
			fScalar1 = ((sin(fScalor*fOmega))/sin(fOmega));
		}

		//problem here  //need to ensure dot product does not exceed -1 -> 1
		fOmega = acos(fOmega);

		

		for(int i = 0; i < 4; i++)
		{
			//slerp formula using omega
			(*pfQuatSlerp)[i] = (fScalar0 * (*pfQuatA)[i]) + (fScalar1 * (*pfQuatB)[i]);
		}

	}
	else //could not create the Quaternion because invalid input was found
	{

		MessageBox(_hDlg, TEXT("Invalid Input Found in Quaternions \n Or scalar value exceeds the bounds of 0 - 1"), TEXT("ERROR"), MB_ICONSTOP | MB_OK);
		return false;
	}
	
	setResult(_hDlg, pfQuatSlerp);

	//clean up
	delete pfQuatA;
	pfQuatA  = 0 ;
	delete pfQuatB;
	pfQuatB = 0;
	delete pfNormQuatA;
	pfNormQuatA = 0;
	delete pfNormQuatB;
	pfNormQuatB = 0;
	
	return (true);
}

/***********************
* Matrix: transfrom a given Quaternion into matrix form
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _iChoice: The choice of which quaternion, 1 = Queternion A, 2 = Quaternion B, and 3 Is the SLERP result Quaternion 
* @return: bool: return true
********************/
bool Matrix(HWND _hDlg, int _iChoice)
{

	//The two queternion vectors
	vector<float>* pfQuatA = new vector<float>;
	vector<float>* pfQuatB = new vector<float>;
	vector<float>* pfQuatSlerp = new vector<float>;

	vector<float>* pfTemp = new vector<float>;

	//The resultant quaternion
	vector<vector<float>*>* pfMatrix =  new vector<vector<float>*>;
	//pfMatrix[4][4];
	
	for(int i = 0; i < 4 ; i++)
	{
		for(int k = 0; k < 4 ; k++)
		{
			(*pfTemp).push_back(0.0f);
		}
		(*pfMatrix).push_back(pfTemp);
		pfTemp = new vector<float>;
	}
		
	vector<float>* pfTempQuat = 0;
	
	//gets the Quaternions
	if(GetQuaternion(_hDlg, pfQuatA, pfQuatB, pfQuatSlerp) )
	{
		switch(_iChoice)
		{
		case A: // Queternion A
			{
				pfTempQuat = pfQuatA;
				delete pfQuatB;
				pfQuatB = 0;
				delete pfQuatSlerp;
				pfQuatSlerp = 0;
			}
			break; 
		case B: // Queternion B
			{
				pfTempQuat = pfQuatB;
				delete pfQuatA;
				pfQuatA = 0;
				delete pfQuatSlerp;
				pfQuatSlerp = 0;
			}
			break;
		case SLERP:  //SLERP result Quaternion 
			{
				pfTempQuat = pfQuatSlerp;
				delete pfQuatA;
				pfQuatA = 0;
				delete pfQuatB;
				pfQuatB = 0;
			}
			break;
		}
	}
	else //could not create the Quaternion because invalid input was found
	{

		MessageBox(_hDlg, TEXT("Invalid Input Found in Quaternions"), TEXT("ERROR"), MB_ICONSTOP | MB_OK);
		return false;
	}
	
	//creates the matrix using the quaternions
	int k = 3;
	for(int i = 0; i < 4; i++)
	{
		//constant value
		// [0][0] = +
		// [1][1] = +
		// [2][2] = +
		// [3][3] = +
		((*(*pfMatrix)[i])[i]) =  (*pfTempQuat)[3]; 

		// k value
		// daigonaly from top right to bottom left
		// [0][3] = +
		// [1][2] = -
		// [2][1] = +
		// [3][0] = -
		if(i % 2) //i is odd
		{
			((*(*pfMatrix)[i])[k]) = -1*(*pfTempQuat)[2]; 
		}
		else
		{
			((*(*pfMatrix)[i])[k]) = (*pfTempQuat)[2];
		}

		//i value
		// [0][1] = +
		// [1][0] = -
		// [2][3] = -
		// [3][2] = +
		if(i % 2) //i is odd
		{
			if(i == 1)
			{
				((*(*pfMatrix)[i])[i-1]) = -1*(*pfTempQuat)[0];  
			}
			else
			{
				((*(*pfMatrix)[i])[i-1]) = (*pfTempQuat)[0];  
			}

		}
		else
		{
			if(i == 0)
			{
				((*(*pfMatrix)[i])[i+1]) = (*pfTempQuat)[0];
			}
			else
			{
				((*(*pfMatrix)[i])[i+1]) = -1*(*pfTempQuat)[0];
			}
		}

		//j value
		// [0][2] = +
		// [1][3] = +
		// [2][0] = -
		// [3][1] = -
		if(i < 2)
		{
			((*(*pfMatrix)[i])[i+2]) = (*pfTempQuat)[1];
		}
		else
		{
			((*(*pfMatrix)[i])[i-2]) = -1*(*pfTempQuat)[1];
		}


		k--;
	}

	setResult(_hDlg, pfMatrix);

	//delete pfMatrix;
	//pfMatrix = 0;

	delete pfTemp; 
	pfTemp = 0;
	delete pfTempQuat; 
	pfTempQuat = 0;
		
	return (true);
}