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
	SetDlgItemTextA( _hDlg, IDC_SCALAR_RESULT,strTemp.c_str());

	SetDlgItemTextA( _hDlg, IDC_RESULT_I,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_RESULT_J,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_RESULT_K,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_RESULT,strTemp.c_str());

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
* GetQuaternionStr: Gets the values from the quaternion dialog boxes and stores it into a vector
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _pStrQuatA: a pointer to a vector in which the values are to be stored for quaternion A
* @parameter: _pStrQuatB: a pointer to a vector in which the values are to be stored for quaternion B
* @return: bool: return true
********************/
bool GetQuaternionStr(HWND _hDlg, vector<string>* _pStrQuatA, vector<string>* _pStrQuatB)
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
bool GetQuaternion(HWND _hDlg, vector<float>* _pfQuatA, vector<float>* _pfQuatB)
{
	//String Pointer to store the string values of the quaternions
	vector<string>* pStrTempQuatA = new vector<string>;
	vector<string>* pStrTempQuatB = new vector<string>;

	GetQuaternionStr(_hDlg, pStrTempQuatA, pStrTempQuatB);

	for(int i = 0; i < 4; i++)
	{
		//check if inputs are valid floats
		if(InputCheck((*pStrTempQuatA)[i]) &&
		   InputCheck((*pStrTempQuatB)[i]) )
		{
			//convert to flaots and push onto the float vector
			(*_pfQuatA).push_back(stof((*pStrTempQuatA)[i]));
			(*_pfQuatB).push_back(stof((*pStrTempQuatB)[i]));
		}
		else
		{
			//invalid input found
			return false;
		}
	}

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
		return true;
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
bool setResult(HWND _hDlg, float* _pfResult)
{
	string strTemp;

	//set the result Scalar text boxes
	strTemp = FloatToString(*_pfResult);
	SetDlgItemTextA(_hDlg, IDC_SCALAR_RESULT, strTemp.c_str());

	return (true);
}

/***********************
* Add: Adds two quaternions together
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @return: bool: return true, if no errors exist
********************/
bool Add(HWND _hDlg)
{
	//The two queternion vectors
	vector<float>* pfQuatA = new vector<float>;
	vector<float>* pfQuatB = new vector<float>;
	
	//The resultant vector
	vector<float>* pfResult = new vector<float>;

	//gets the Quaternions
	if(GetQuaternion(_hDlg, pfQuatA, pfQuatB))
	{

		//Adds the two quaternions together and pushes the result onto the resultant vector
		for(int i = 0; i < 4; i++)
		{
			(*pfResult).push_back( (*pfQuatA)[i] + (*pfQuatB)[i] );
		}

		//Sets the Result into the text box
		setResult(_hDlg, pfResult);
	}
	else //could not create the Quaternion because invalid input was found
	{

		MessageBox(_hDlg, TEXT("Invalid Input Found in Quaternions"), TEXT("ERROR"), MB_ICONSTOP | MB_OK);
		return false;
	}

	//deletes Quaternions no longer required
	delete pfQuatA;
	pfQuatA = 0;
	delete pfQuatB;
	pfQuatB = 0;

	return (true);

}

/***********************
* Sub: Subtracts one quaternion from another, the order is dependant on the choice given
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _iChoice: int value: 1 is A - B and 2 is B - A
* @return: bool: return true, if no errors exist
********************/
bool Sub(HWND _hDlg, int _iChoice)
{
	//The two queternion vectors
	vector<float>* pfQuatA = new vector<float>;
	vector<float>* pfQuatB = new vector<float>;
	
	//The resultant vector
	vector<float>* pfResult = new vector<float>;

	//gets the Quaternions
	if(GetQuaternion(_hDlg, pfQuatA, pfQuatB))
	{
		
		//Subtracts one quaternion from another
		for(int i = 0; i < 4; i++)
		{
			if(_iChoice == 1)
			{
				(*pfResult).push_back( (*pfQuatA)[i] - (*pfQuatB)[i] );
			}
			else if(_iChoice == 2)
			{
				(*pfResult).push_back( (*pfQuatB)[i] - (*pfQuatA)[i] );
			}
		}

		//Sets the Result into the text box
		setResult(_hDlg, pfResult);
	}
	else //could not create the Quaternion because invalid input was found
	{

		MessageBox(_hDlg, TEXT("Invalid Input Found in Quaternions"), TEXT("ERROR"), MB_ICONSTOP | MB_OK);
		return false;
	}

	//deletes Quaternions no longer required
	delete pfQuatA;
	pfQuatA = 0;
	delete pfQuatB;
	pfQuatB = 0;

	return (true);

}

/***********************
* MultiplyQuaternion: Multiplies two quaternions together
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _iChoice: int value: 1 is A * B and 2 is B * A
* @return: bool: return true, if no errors exist
********************/
bool MultiplyQuaternion(HWND _hDlg, int _iChoice)
{
	//The two queternion vectors
	vector<float>* pfQuatA = new vector<float>;
	vector<float>* pfQuatB = new vector<float>;

	//The resultant quaternion
	vector<float>* pfResult =  new vector<float>;

	//gets the Quaternions
	if(GetQuaternion(_hDlg, pfQuatA, pfQuatB) )
	{
		if(_iChoice == 1)
		{
			//R[0] = ( B[3]A[0] + B[0]A[3] - B[1]A[2] + B[2]A[1] )
			(*pfResult).push_back( ((*pfQuatB)[3]*(*pfQuatA)[0])  +  ((*pfQuatB)[0]*(*pfQuatA)[3])	-  ((*pfQuatB)[1]*(*pfQuatA)[2])  +  ((*pfQuatB)[2]*(*pfQuatA)[1]) );
			
			//R[1] = ( B[3]A[1] + B[0]A[2] + B[1]A[3] - B[2]A[0] )
			(*pfResult).push_back( ((*pfQuatB)[3]*(*pfQuatA)[1])  +  ((*pfQuatB)[0]*(*pfQuatA)[2])	+  ((*pfQuatB)[1]*(*pfQuatA)[3])  -  ((*pfQuatB)[2]*(*pfQuatA)[0]) );
			
			//R[2] = ( B[3]A[2] + B[0]A[0] + B[1]A[1] - B[2]A[3] )
			(*pfResult).push_back( ((*pfQuatB)[3]*(*pfQuatA)[2])  -  ((*pfQuatB)[0]*(*pfQuatA)[1])	+  ((*pfQuatB)[1]*(*pfQuatA)[0])  +  ((*pfQuatB)[2]*(*pfQuatA)[3]) );
		
			//R[3] = ( B[3]A[3] + B[0]A[0] + B[1]A[1] - B[2]A[2] )
			(*pfResult).push_back( ((*pfQuatB)[3]*(*pfQuatA)[3])  -  ((*pfQuatB)[0]*(*pfQuatA)[0])	-  ((*pfQuatB)[1]*(*pfQuatA)[1])  -  ((*pfQuatB)[2]*(*pfQuatA)[2]) );
		}
		else if(_iChoice == 2)
		{
			//R[0] = ( A[3]B[0] + A[0]B[3] - A[1]B[2] + A[2]B[1] )
			(*pfResult).push_back( ((*pfQuatA)[3]*(*pfQuatB)[0])  +  ((*pfQuatA)[0]*(*pfQuatB)[3])	-  ((*pfQuatA)[1]*(*pfQuatB)[2])  +  ((*pfQuatA)[2]*(*pfQuatB)[1]) );
			
			//R[1] = ( A[3]B[1] + A[0]B[2] + A[1]B[3] - A[2]B[0] )
			(*pfResult).push_back( ((*pfQuatA)[3]*(*pfQuatB)[1])  +  ((*pfQuatA)[0]*(*pfQuatB)[2])	+  ((*pfQuatA)[1]*(*pfQuatB)[3])  -  ((*pfQuatA)[2]*(*pfQuatB)[0]) );
			
			//R[2] = ( A[3]B[2] + A[0]B[0] + A[1]B[1] - A[2]B[3] )
			(*pfResult).push_back( ((*pfQuatA)[3]*(*pfQuatB)[2])  -  ((*pfQuatA)[0]*(*pfQuatB)[1])	+  ((*pfQuatA)[1]*(*pfQuatB)[0])  +  ((*pfQuatA)[2]*(*pfQuatB)[3]) );
		
			//R[3] = ( A[3]B[3] + A[0]B[0] + A[1]B[1] - A[2]B[2] )
			(*pfResult).push_back( ((*pfQuatA)[3]*(*pfQuatB)[3])  -  ((*pfQuatA)[0]*(*pfQuatB)[0])	-  ((*pfQuatA)[1]*(*pfQuatB)[1])  -  ((*pfQuatA)[2]*(*pfQuatB)[2]) );
		}
		
		//Sets the Result into the text box
		setResult(_hDlg, pfResult);
	}
	else //could not create the Quaternion because invalid input was found
	{

		MessageBox(_hDlg, TEXT("Invalid Input Found in Quaternions"), TEXT("ERROR"), MB_ICONSTOP | MB_OK);
		return false;
	}

	//deletes Quaternions no longer required
	delete pfQuatA;
	pfQuatA = 0;
	delete pfQuatB;
	pfQuatB = 0;


	return (true);

}

/***********************
* ScalarMultiply: Multiplies a quaternions with a scalar
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _iChoice: int value: 1 is quaternion A and 2 is quaternion B 
* @return: bool: return true, if no errors exist
********************/
bool ScalarMultiply(HWND _hDlg, int _iChoice)
{
	//The two queternion vectors
	vector<float>* pfQuatA = new vector<float>;
	vector<float>* pfQuatB = new vector<float>;

	//The scalar t
	float* pfScalar = new float;

	//The resultant quaternion
	vector<float>* pfResult =  new vector<float>;

	//gets the Quaternions
	if(GetQuaternion(_hDlg, pfQuatA, pfQuatB) && GetScalar(_hDlg, pfScalar))
	{
		
		//Multiply a quaternion with the passed in scalar
		for(int i = 0; i < 4; i++)
		{
			if(_iChoice == 1)
			{
				(*pfResult).push_back( (*pfScalar) * (*pfQuatA)[i] );
			}
			else if(_iChoice == 2)
			{
				(*pfResult).push_back( (*pfScalar) * (*pfQuatB)[i] );
			}
		}

		//Sets the Result into the text box
		setResult(_hDlg, pfResult);
	}
	else //could not create the Quaternion because invalid input was found
	{

		MessageBox(_hDlg, TEXT("Invalid Input Found in Quaternions"), TEXT("ERROR"), MB_ICONSTOP | MB_OK);
		return false;
	}

	//deletes Quaternions no longer required
	delete pfQuatA;
	pfQuatA = 0;
	delete pfQuatB;
	pfQuatB = 0;
	delete pfScalar;
	pfScalar = 0;

	return (true);

}

/***********************
* Conjegate: multiply each constant multiple of a complex number by -1
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _iChoice: int value: 1 is quaternion A and 2 is quaternion B 
* @return: bool: return true, if no errors exist
********************/
bool Conjegate(HWND _hDlg, int _iChoice)
{
	//The two queternion vectors
	vector<float>* pfQuatA = new vector<float>;
	vector<float>* pfQuatB = new vector<float>;

	//The resultant quaternion
	vector<float>* pfResult =  new vector<float>;

	//gets the Quaternions
	if(GetQuaternion(_hDlg, pfQuatA, pfQuatB))
	{
		
		//multiply each constant multiple of a complex number by -1
		for(int i = 0; i < 4; i++)
		{
			if(_iChoice == 1)
			{
				//only negify the complex constanst
				if(i < 3)
				{
					//multiply each constant multiple of a complex number by -1
					(*pfResult).push_back( -1 * (*pfQuatA)[i] );
				}
				else
				{
					//push on the constanst value unchanged
					(*pfResult).push_back( (*pfQuatA)[i] );
				}
				
			}
			else if(_iChoice == 2)
			{
				//only negify the complex constanst
				if(i < 3)
				{
					//multiply each constant multiple of a complex number by -1
					(*pfResult).push_back( -1 * (*pfQuatB)[i] );
				}
				else
				{
					//push on the constanst value unchanged
					(*pfResult).push_back( (*pfQuatB)[i] );
				}
			}
		}
		
		//Sets the Result into the text box
		setResult(_hDlg, pfResult);
	}
	else //could not create the Quaternion because invalid input was found
	{

		MessageBox(_hDlg, TEXT("Invalid Input Found in Quaternions"), TEXT("ERROR"), MB_ICONSTOP | MB_OK);
		return false;
	}

	//deletes Quaternions no longer required
	delete pfQuatA;
	pfQuatA = 0;
	delete pfQuatB;
	pfQuatB = 0;
	
	return (true);

}

/***********************
* Mag: computes the magnitude of the given quaternion
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _iChoice: int value: 1 is quaternion A and 2 is quaternion B 
* @return: bool: return true, if no errors exist
********************/
bool Mag(HWND _hDlg, int _iChoice)
{
	//The two queternion vectors
	vector<float>* pfQuatA = new vector<float>;
	vector<float>* pfQuatB = new vector<float>;

	//The scalar t
	float pfResult = 0.0f;

	//gets the Quaternions
	if(GetQuaternion(_hDlg, pfQuatA, pfQuatB) )
	{
		
		//add all values squared
		for(int i = 0; i < 4; i++)
		{
			if(_iChoice == 1)
			{
				(pfResult) +=  (*pfQuatA)[i] * (*pfQuatA)[i] ;
			}
			else if(_iChoice == 2)
			{
				(pfResult) +=  (*pfQuatB)[i] * (*pfQuatB)[i] ;
			}
		}

		//square root the final result
		(pfResult) = sqrt((pfResult));


		//Sets the Result into the text box
		setResult(_hDlg, &pfResult);
	}
	else //could not create the Quaternion because invalid input was found
	{

		MessageBox(_hDlg, TEXT("Invalid Input Found in Quaternions"), TEXT("ERROR"), MB_ICONSTOP | MB_OK);
		return false;
	}

	//deletes Quaternions no longer required
	delete pfQuatA;
	pfQuatA = 0;
	delete pfQuatB;
	pfQuatB = 0;
	
	return (true);
}

/***********************
* Dot: Computes the Dot product of the 2 given quaternion
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @return: bool: return true, if no errors exist
********************/
bool Dot(HWND _hDlg)
{
	//The two queternion vectors
	vector<float>* pfQuatA = new vector<float>;
	vector<float>* pfQuatB = new vector<float>;

	//The scalar t
	float pfResult = 0.0f;

	//gets the Quaternions
	if(GetQuaternion(_hDlg, pfQuatA, pfQuatB) )
	{
		
		//compute the dot product
		for(int i = 0; i < 4; i++)
		{
			(pfResult) +=  (*pfQuatA)[i] * (*pfQuatB)[i] ;	
		}

		

		//Sets the Result into the text box
		setResult(_hDlg, &pfResult);
	}
	else //could not create the Quaternion because invalid input was found
	{

		MessageBox(_hDlg, TEXT("Invalid Input Found in Quaternions"), TEXT("ERROR"), MB_ICONSTOP | MB_OK);
		return false;
	}

	//deletes Quaternions no longer required
	delete pfQuatA;
	pfQuatA = 0;
	delete pfQuatB;
	pfQuatB = 0;
	
	return (true);
}

/***********************
* Inverse: computes the Inverse of the given quaternion
* @author: Jc Fowles
* @parameter: _hDlg: handle to the dialog box
* @parameter: _iChoice: int value: 1 is quaternion A and 2 is quaternion B 
* @return: bool: return true, if no errors exist
********************/
bool Inverse(HWND _hDlg, int _iChoice)
{
	//The two queternion vectors
	vector<float>* pfQuatA = new vector<float>;
	vector<float>* pfQuatB = new vector<float>;

	//The resultant quaternion
	vector<float>* pfconjugate =  new vector<float>;

	float fMagSqr = 0;

	vector<float>* pfResult = new vector<float>;
	//gets the Quaternions
	if(GetQuaternion(_hDlg, pfQuatA, pfQuatB))
	{
		
		//multiply each constant multiple of a complex number by -1
		for(int i = 0; i < 4; i++)
		{
			if(_iChoice == 1)
			{
				//only negify the complex constanst
				if(i < 3)
				{
					//multiply each constant multiple of a complex number by -1
					(*pfconjugate).push_back( -1 * (*pfQuatA)[i] );
				}
				else
				{
					//push on the constanst value unchanged
					(*pfconjugate).push_back( (*pfQuatA)[i] );
				}
				//add all contants squared to get magnitude squared
				fMagSqr +=  (*pfQuatA)[i] * (*pfQuatA)[i] ;

			}
			else if(_iChoice == 2)
			{
				//only negify the complex constanst
				if(i < 3)
				{
					//multiply each constant multiple of a complex number by -1
					(*pfconjugate).push_back( -1 * (*pfQuatB)[i] );
				}
				else
				{
					//push on the constanst value unchanged
					(*pfconjugate).push_back( (*pfQuatB)[i] );
				}
				//add all contants squared to get magnitude squared
				fMagSqr +=  (*pfQuatB)[i] * (*pfQuatB)[i] ;
			}
		}

		//push the result of the conj / magintude squared which is the inverse of the given quaternion
		for(int i = 0; i < 4 ; i++)
		{
			(*pfResult).push_back((*pfconjugate)[i] /  fMagSqr);
		}
		
		//if inverse exists
		if(fMagSqr != 0)
		{
			//Sets the Result into the text box
			setResult(_hDlg, pfResult);
		}
		else //else inverse does not exist set text boxes accordingly
		{
			string strNoInverse = "No Inv";
			SetDlgItemTextA(_hDlg, IDC_RESULT_I, strNoInverse.c_str());
			SetDlgItemTextA(_hDlg, IDC_RESULT_J, strNoInverse.c_str());
			SetDlgItemTextA(_hDlg, IDC_RESULT_K, strNoInverse.c_str());
			SetDlgItemTextA(_hDlg, IDC_RESULT, strNoInverse.c_str());
		}
	}
	else //could not create the Quaternion because invalid input was found
	{

		MessageBox(_hDlg, TEXT("Invalid Input Found in Quaternions"), TEXT("ERROR"), MB_ICONSTOP | MB_OK);
		return false;
	}

	//deletes Quaternions no longer required
	delete pfQuatA;
	pfQuatA = 0;
	delete pfQuatB;
	pfQuatB = 0;
	
	return (true);
}