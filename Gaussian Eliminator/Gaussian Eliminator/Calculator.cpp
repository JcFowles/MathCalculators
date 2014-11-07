/*
* Bachelor of Software Engineering 
* Media Design School 
* Auckland 
* New Zealand 
 
* (c) 2005 - 2014 Media Design School 
 
* File Name : Calculator.cpp
* Description : Implementaion for all the calculations and checks used in the calculator
* Author :	Jc Fowles
* Mail :	Jc.Fowles@mediadesign.school.nz	
*/

//local include
#include "Source.h"

/***********************
* GaussianMultiply: Multiply each element in a given row by a given scalar value 
* @author: Jc Fowles
* @parameter: _hDlg: Handle to the dialog box
* @return: bool: true if no error errors exist, else pop up the error to be fixed via message box
********************/
bool GaussianMultiply(HWND _hDlg)
{
	//gets the Row to multiply
	int iRow = (GetDlgItemInt(_hDlg, IDC_MULTIPLY_ROW_NUM, 0, 1));
	iRow = iRow - 1; // - minus 1 for index shift
	
	//gets the scalar to multiply the row by
	wchar_t wstrTemp[100];
	GetDlgItemText(_hDlg, IDC_MULTIPLY_AMOUNT, wstrTemp, 100);
	float fScalar = (WideStringToFloat(wstrTemp));

	//create the matrix from given values 
	vector<vector<float>*>* TheMatrix = new vector<vector<float>*>;
	if(CreateMatrix(_hDlg, TheMatrix))
	{

		for (int i = 0; i < 4; i++)
		//multiply each element in choosen row by the fScalar
		{
			((*(*TheMatrix)[iRow])[i]) = fScalar*((*(*TheMatrix)[iRow])[i]);
		}

		//set text boxes using the matrix
		SetTextBox(_hDlg, TheMatrix);
	}
	else //could not create the matrix because invalid input was found
	{

		MessageBox(_hDlg, TEXT("Invalid Input Found in Matrix"), TEXT("ERROR"), MB_ICONSTOP | MB_OK);
		return false;
	}
	return (true);
	
}

/***********************
* GaussianSwap: Swaps two given rows
* @author: Jc Fowles
* @parameter: _hDlg: Handle to the dialog box
* @return: bool: true if no error errors exist, else pop up the error to be fixed via message box
********************/
bool GaussianSwap(HWND _hDlg)
{
	//gets the Rows to swap
	int iRowA = (GetDlgItemInt(_hDlg, IDC_SWAP_ROW_A, 0, 1));
	int iRowB = (GetDlgItemInt(_hDlg, IDC_SWAP_ROW_B, 0, 1));
	// - minus 1 for index shift
	iRowA = iRowA - 1;
	iRowB = iRowB - 1;
	
	//create the matrix from given values 
	vector<vector<float>*>* TheMatrix = new vector<vector<float>*>;
	if(CreateMatrix(_hDlg, TheMatrix))
	{

		float fTemp;
		for (int i = 0; i < 4; i++)
		{
			//swap the rows
			fTemp = ((*(*TheMatrix)[iRowA])[i]);
			((*(*TheMatrix)[iRowA])[i]) = ((*(*TheMatrix)[iRowB])[i]);
			((*(*TheMatrix)[iRowB])[i]) = fTemp;
		}

		//set text boxes using the matrix
		SetTextBox(_hDlg, TheMatrix);
		
	}
	else //could not create the matrix because invalid input was found
	{
		MessageBox(_hDlg, TEXT("Invalid Input Found in Matrix"), TEXT("ERROR"), MB_ICONSTOP | MB_OK);
		return false;
	}
	return (true);
}

/***********************
* GaussianAdd: adds a multiple of the first given row to the second given row
* @author: Jc Fowles
* @parameter: _hDlg: Handle to the dialog box
* @return: bool: true if no error errors exist, else pop up the error to be fixed via message box
********************/
bool GaussianAdd(HWND _hDlg)
{
	//gets the scalar to multiply by
	wchar_t wstrTemp[100];
	GetDlgItemText(_hDlg, IDC_ADD_AMOUNT, wstrTemp, 100);
	float fScalar = (WideStringToFloat(wstrTemp));

	//gets the rows to add 
	int iRowA = (GetDlgItemInt(_hDlg, IDC_ADD_ROW_A, 0, 1));
	int iRowB = (GetDlgItemInt(_hDlg, IDC_ADD_ROW_B, 0, 1));
	iRowA = iRowA - 1;
	iRowB = iRowB - 1;

	//create the matrix from given values 
	vector<vector<float>*>* TheMatrix = new vector<vector<float>*>;
	if(CreateMatrix(_hDlg, TheMatrix))
	{

		for (int i = 0; i < 4; i++)
		{
			//adds a multipl of choosen row to the second row
			((*(*TheMatrix)[iRowB])[i]) = fScalar*((*(*TheMatrix)[iRowA])[i]) + ((*(*TheMatrix)[iRowB])[i]);
		}

		//set text boxes using the matrix
		SetTextBox(_hDlg, TheMatrix);
	}
	else //could not create the matrix because invalid input was found
	{
		MessageBox(_hDlg, TEXT("Invalid Input Found in Matrix"), TEXT("ERROR"), MB_ICONSTOP | MB_OK);
		return false;
	}

	return (true);
}




/***********************
* Initialise: Initialises all values in the dialog box to 0
* @author: Jc Fowles
* @parameter: _hDlg: Handle to the dialog box
* @return: bool: true if no error errors exist, else pop up the error to be fixed via message box
********************/
bool Initialise(HWND _hDlg)
{
	string strTemp = FloatToString(0.0f);
	
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

	SetDlgItemTextA( _hDlg, IDC_MULTIPLY_ROW_NUM,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_MULTIPLY_AMOUNT,strTemp.c_str());
	
	SetDlgItemTextA( _hDlg, IDC_SWAP_ROW_A,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_SWAP_ROW_B,strTemp.c_str());

	SetDlgItemTextA( _hDlg, IDC_ADD_AMOUNT,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_ADD_ROW_A,strTemp.c_str());
	SetDlgItemTextA( _hDlg, IDC_ADD_ROW_B,strTemp.c_str());
	return (true);
}

/***********************
* Initialise: Initialises all values in the matrix to a random value (atm Initialises to 1 instead)
* @author: Jc Fowles
* @parameter: _hDlg: Handle to the dialog box
* @return: bool: true if no error errors exist, else pop up the error to be fixed via message box
********************/
bool RandomInitialise(HWND _hDlg)
{
	vector<vector<float>*>* TheMatrix = new vector<vector<float>*>;

	//create the matrix from given values 
	CreateMatrix(_hDlg, TheMatrix);

	float fRandom;

	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			fRandom = 1.0f; //change this to a random number between 1.0 and 10.0 , atm just 1 lol
			((*(*TheMatrix)[k])[i]) = fRandom;
		}
	}

	//set text boxes using the matrix
	SetTextBox(_hDlg, TheMatrix);

	return (true);
}


/***********************
* CreateStrMatrix: creates a matrix, with the values in the form of strings
* @author: Jc Fowles
* @parameter: _hDlg: Handle to the dialog box
* @parameter: strMatrix: pointer to the string matrix
* @return: bool: always true
********************/
bool CreateStrMatrix(HWND _hDlg, vector<vector<string>*>* strMatrix)
{
	wchar_t wstrTempA[100];
	//temp matrix row
	vector<string>* vpstrTemp = new vector<string>;
		
	//First row enter into the matrix
	GetDlgItemText(_hDlg, IDC_MATRIX_00, wstrTempA, 100);
	(*vpstrTemp).push_back((WideStringToString(wstrTempA)));		

	GetDlgItemText(_hDlg, IDC_MATRIX_01, wstrTempA, 100);
	(*vpstrTemp).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_MATRIX_02, wstrTempA, 100);
	(*vpstrTemp).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_MATRIX_03, wstrTempA, 100);
	(*vpstrTemp).push_back((WideStringToString(wstrTempA)));

	//add the temp row to the matrix
	(*strMatrix).push_back(vpstrTemp);

	//clear the temp row
	vpstrTemp = new vector<string>;
	
	//Second row enter into the matrix
	GetDlgItemText(_hDlg, IDC_MATRIX_10, wstrTempA, 100);
	(*vpstrTemp).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_MATRIX_11, wstrTempA, 100);
	(*vpstrTemp).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_MATRIX_12, wstrTempA, 100);
	(*vpstrTemp).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_MATRIX_13, wstrTempA, 100);
	(*vpstrTemp).push_back((WideStringToString(wstrTempA)));

	//add the temp row to the matrix
	(*strMatrix).push_back(vpstrTemp);

	//clear the temp row
	vpstrTemp = new vector<string>;

	//Third row enter into the matrix
	GetDlgItemText(_hDlg, IDC_MATRIX_20, wstrTempA, 100);
	(*vpstrTemp).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_MATRIX_21, wstrTempA, 100);
	(*vpstrTemp).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_MATRIX_22, wstrTempA, 100);
	(*vpstrTemp).push_back((WideStringToString(wstrTempA)));

	GetDlgItemText(_hDlg, IDC_MATRIX_23, wstrTempA, 100);
	(*vpstrTemp).push_back((WideStringToString(wstrTempA)));

	//add the temp row to the matrix
	(*strMatrix).push_back(vpstrTemp);
	
			
	return (true);

}

/***********************
* CreateMatrix: creates a matrix, using the string matrix, and checking the input values are valid floats
* @author: Jc Fowles
* @parameter: _hDlg: Handle to the dialog box
* @parameter: _fMatrix: pointer to the float matrix
* @return: bool: true if all inputs are valid floats, false if invalid input found
********************/
bool CreateMatrix(HWND _hDlg, vector<vector<float>*>* _fMatrix)
{
	//temp matrix row
	vector<float>* vpfTemp = new vector<float>;

	//creates a string matrix
	vector<vector<string>*>* strMatrix = new vector<vector<string>*>;
	CreateStrMatrix(_hDlg , strMatrix);

	for(int iRow = 0; iRow < 3; iRow++)
	{
		for(int iColumn = 0; iColumn < 4; iColumn++)
		{
			//check if valid input
			if (InputCheck(  (*(*strMatrix)[iRow])[iColumn]) )
			{
				//push valid float input into the temp row 
				(*vpfTemp).push_back( (stof((*(*strMatrix)[iRow])[iColumn])));
			}
			else
			{
				//invalid input found
				return false;
			}
		}
		
		//add the temp row to the matrix
		(*_fMatrix).push_back(vpfTemp);
		
		//clear the temp row
		vpfTemp = new vector<float>;
	}

	return true;
	
}

/***********************
* SetTextBox: using the float matrix sets teh matrix textBoxes to corresponding values
* @author: Jc Fowles
* @parameter: _hDlg: Handle to the dialog box
* @parameter: _fMatrix: pointer to the float matrix
* @return: bool: always true
********************/
bool SetTextBox(HWND _hDlg, vector<vector<float>*>* _fMatrix)
{
	string strTemp;

	//set the first row
	strTemp = FloatToString((*(*_fMatrix)[0])[0]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_00, strTemp.c_str());
	strTemp = FloatToString((*(*_fMatrix)[0])[1]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_01, strTemp.c_str());
	strTemp = FloatToString((*(*_fMatrix)[0])[2]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_02, strTemp.c_str());
	strTemp = FloatToString((*(*_fMatrix)[0])[3]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_03, strTemp.c_str());

	//set the Second row
	strTemp = FloatToString((*(*_fMatrix)[1])[0]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_10, strTemp.c_str());
	strTemp = FloatToString((*(*_fMatrix)[1])[1]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_11, strTemp.c_str());
	strTemp = FloatToString((*(*_fMatrix)[1])[2]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_12, strTemp.c_str());
	strTemp = FloatToString((*(*_fMatrix)[1])[3]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_13, strTemp.c_str());

	//set the Second row
	strTemp = FloatToString((*(*_fMatrix)[2])[0]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_20, strTemp.c_str());
	strTemp = FloatToString((*(*_fMatrix)[2])[1]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_21, strTemp.c_str());
	strTemp = FloatToString((*(*_fMatrix)[2])[2]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_22, strTemp.c_str());
	strTemp = FloatToString((*(*_fMatrix)[2])[3]);
	SetDlgItemTextA(_hDlg, IDC_MATRIX_23, strTemp.c_str());

	//delete the matrix no longer required
	delete _fMatrix;
	_fMatrix = 0;

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
* RowInputCheck: Checks if the choosen rows are an int from 1 to 3, if not throw up a message box
* @author: Jc Fowles
* @parameter: _hDlg: Handle to the dialog box
* @parameter: _iChoice: which button was pressed, first secod or 3rd
* @return: bool: true if valid, false if not
********************/
bool RowInputCheck(HWND _hDlg, int _iChoice)
{
	//the scalar temp as a wstr
	wchar_t wstrTemp[100];
		
	//Temp value to check on at the end
	int iRowA = 0;
	int iRowB = 0;

	switch (_iChoice)  //which button was choosen
	{
		case 3:		// if button APLLY_ADD was selected
		{
			//check if row choices are valid between 1 and 3
			if ((GetDlgItemInt(_hDlg, IDC_ADD_ROW_A, 0, 1) <= 3) &&
				(GetDlgItemInt(_hDlg, IDC_ADD_ROW_A, 0, 1) >= 1) &&
				(GetDlgItemInt(_hDlg, IDC_ADD_ROW_B, 0, 1) <= 3) &&
				(GetDlgItemInt(_hDlg, IDC_ADD_ROW_B, 0, 1) >= 1))

			{
				//get the scalar
				GetDlgItemText(_hDlg, IDC_ADD_AMOUNT, wstrTemp, 100);
				//checks if scalar a valid float
				if(InputCheck(WideStringToString(wstrTemp)))
				{
					iRowA = (GetDlgItemInt(_hDlg, IDC_ADD_ROW_A, 0, 1));
					iRowB = (GetDlgItemInt(_hDlg, IDC_ADD_ROW_B, 0, 1));
				}
				else
				{
					//if scalar not a valid float
					MessageBox(_hDlg, TEXT("Error\n Invalid Amount entered can not multiply by non float"), TEXT("Error"), MB_ICONERROR | MB_OK);
					return false;
				}
			}
		}
			break;
		case 2:		// if button APLLY_SWAP was selected
		{
			//check if row choices are valid between 1 and 3
			if ((GetDlgItemInt(_hDlg, IDC_SWAP_ROW_A, 0, 1) <= 3) &&
				(GetDlgItemInt(_hDlg, IDC_SWAP_ROW_A, 0, 1) >= 1) &&
				(GetDlgItemInt(_hDlg, IDC_SWAP_ROW_B, 0, 1) <= 3) &&
				(GetDlgItemInt(_hDlg, IDC_SWAP_ROW_B, 0, 1) >= 1))

			{
				iRowA = (GetDlgItemInt(_hDlg, IDC_SWAP_ROW_A, 0, 1));
				iRowB = (GetDlgItemInt(_hDlg, IDC_SWAP_ROW_B, 0, 1));
			}
		}
			break;
		case 1:		// if button APLLY_MULTIPLY was selected
		{
			//check if row choices are valid between 1 and 3
			if ((GetDlgItemInt(_hDlg, IDC_MULTIPLY_ROW_NUM, 0, 1) <= 3) &&
				(GetDlgItemInt(_hDlg, IDC_MULTIPLY_ROW_NUM, 0, 1) >= 1)
				)
			{
				//get the scalar
				GetDlgItemText(_hDlg, IDC_MULTIPLY_AMOUNT, wstrTemp, 100);
				//checks if scalar a valid float
				if(InputCheck(WideStringToString(wstrTemp)))
				{
					iRowA = (GetDlgItemInt(_hDlg, IDC_MULTIPLY_ROW_NUM, 0, 1));
					iRowB = (GetDlgItemInt(_hDlg, IDC_MULTIPLY_ROW_NUM, 0, 1));
				}
				else
				{
					//if scalar not a valid float
					MessageBox(_hDlg, TEXT("Error\n Invalid Amount entered can not multiply by non float"), TEXT("Error"), MB_ICONERROR | MB_OK);
					return false;
				}
			}
		}
			break;
	}

	
	if ((iRowA != 0) && (iRowB != 0))
	{
		//values were changed sweet continue as normal
		return true;
	}
	else //if row temps unchanged incorrect row was inputed, throw up an error messsage box
	{
		MessageBox(_hDlg, TEXT("Error\n Incorrect Row Input \n Please enter a row choice from 1 to 3 only"), TEXT("Error"), MB_ICONERROR | MB_OK);
		return false;
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
* EchelonCheck: Checks to see if matrix in in row echelon form
* @author: Jc Fowles
* @parameter: _hDlg: Handle to the dialog box
* @return: bool: true if in row echelon, false if not
********************/
bool EchelonCheck(HWND _hDlg)
{

	vector<vector<float>*>* TheMatrix = new vector<vector<float>*>;

	//create the matrix from given values 
	if(CreateMatrix(_hDlg, TheMatrix))
	{

		float checkValue;
		int LeadingNonZeroColumn= -1;
		int ZeroColumn = -1;
	
		for(int iRow = 0; iRow < 3; iRow++)
		{
			for (int iColumn = 0; iColumn < 4; iColumn++)
			{
				checkValue = (*(*TheMatrix)[iRow])[iColumn];
			
				if(checkValue != 0 )  
				//finds first non zero value, saves the column, and exits the row check
				{
					if(iColumn == 3)
					{
						MessageBox(_hDlg, TEXT("Equation Cant exist \n The last column cant be the first non-Zero value in a row "), TEXT("ERROR"), MB_ICONSTOP | MB_OK);
						return false;
					}
					if(iColumn > LeadingNonZeroColumn) 
					// checks to see if the coloumn index if greater than the saved column
					// (the column where a non zero value has been found)								   
					{
						LeadingNonZeroColumn = iColumn;  // overwrites the saved column with the new one
						iColumn = 4;					 // exits the checking the rest of the values in the row
					}
					else
					{
						return false;					 // if a non-zero was found, but it was to the left of the one above it return false
					}
				}
				else if(checkValue == 0)
				{
					ZeroColumn = iColumn;

					//checks to see that all values bellow the checkValue are also 0,
					//if not return false
					for(int i = 2;i > iRow ; i--)
					{
						if( (*(*TheMatrix)[i])[ZeroColumn] != 0)
						{
							return false;
						}
					}
				
				}
			}
		}
		//if we made it to this point then it means that the matrics in Row Echelon form
		return true;
	}
	

	return false;
}

/***********************
* ReducedEchelonCheck: Checks to see if matrix in in reduced row echelon form
* @author: Jc Fowles
* @parameter: _hDlg: Handle to the dialog box
* @return: bool: true if in reduced row echelon, false if not
********************/
bool ReducedEchelonCheck(HWND _hDlg)
{

	vector<vector<float>*>* TheMatrix = new vector<vector<float>*>;

	//create the matrix from given values 
	if(CreateMatrix(_hDlg, TheMatrix))
	{


		float checkValue;
		int LeadingNonZeroColumn= 4;
		int ZeroColumn = -1;
	
		for(int iRow = 2; iRow >= 0; iRow--)
		{
			for (int iColumn = 0; iColumn < 3; iColumn++)
			{
				checkValue = (*(*TheMatrix)[iRow])[iColumn];
			
				if(checkValue != 0 )  
				//finds first non zero value, saves the column, and exits the row check
				{
					if(checkValue != 1)
					{
						return false;
					}
					else if(iColumn < LeadingNonZeroColumn) 
					// checks to see if the coloumn index if greater than the saved column
					// (the column where a non zero value has been found)								   
					{

						for(int i = 0; i < iRow ; i++)
						//checks to see if all values above it are 0
						{
							if((*(*TheMatrix)[i])[iColumn] != 0)
							{
								return false;
							}
						}

						LeadingNonZeroColumn = iColumn;  // overwrites the saved column with the new one
						iColumn = 4;					 // exits the checking the rest of the values in the row
					}
					else
					{
						return false;					 // if a non-zero was found, but it was to the left of the one above it return false
					}
				}
				else if(checkValue == 0)
				{
					ZeroColumn = iColumn;

					//checks to see that all values bellow the checkValue are also 0,
					//if not return false
					for(int i = 2;i > iRow ; i--)
					{
						if( (*(*TheMatrix)[i])[ZeroColumn] != 0)
						{
							return false;
						}
					}
				
				}
			}
		}
		//if we made it to this point then it means that the matrics in Row Echelon form
		return true;
	}
	return false;
}



