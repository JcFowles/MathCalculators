
#include "Source.h"

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
			fRandom = 1.0f; //change this to a random number between 1.0 and 10.0
			((*(*TheMatrix)[k])[i]) = fRandom;
		}
	}

	//set text boxes using the matrix
	SetTextBox(_hDlg, TheMatrix);

	return (true);
}

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

	vpstrTemp = new vector<string>;
	//clear the temp row
	
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

	vpstrTemp = new vector<string>;
	//clear the temp row

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

	vpstrTemp = new vector<string>;
	//clear the temp row
	delete vpstrTemp;
	vpstrTemp =0;


	//update this
	return (true);

}

bool CreateMatrix(HWND _hDlg, vector<vector<float>*>* _fMatrix)
{
	//wchar_t wstrTempA[100];
	//temp matrix row
	vector<float>* vpfTemp = new vector<float>;

	vector<vector<string>*>* strMatrix = new vector<vector<string>*>;
	
	CreateStrMatrix(_hDlg , strMatrix);

	for(int iRow = 0; iRow < 3; iRow++)
	{
		for(int iColumn = 0; iColumn < 4; iColumn++)
		{
			if (InputCheck(  (*(*strMatrix)[iRow])[iColumn]) )
			{
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

		vpfTemp = new vector<float>;
		///clear the temp row
	}

	return true;
	
}

bool InputCheck(string &_str)
{
	istringstream iss(_str);
    float f;
    iss >> noskipws >> f; // noskipws considers leading whitespace invalid
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail(); 
}



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

	return (true);
}

string FloatToString(const float _kfValue)
{
	stringstream strStream;
	
	strStream << _kfValue;

	string strConverted = strStream.str();
	return strConverted;
}

float WideStringToFloat(const wchar_t* _kpwstr)
{
	size_t stringLength = wcslen(_kpwstr) + 1;
	size_t convertedChars = 0;

	if(stringLength ==1) // string is empty
	{
		return (0);
	}

	char* pStr = new char[stringLength*2];


	wcstombs_s(&convertedChars, pStr, stringLength, _kpwstr, _TRUNCATE);

	return (stof(pStr));
}

string WideStringToString(const wchar_t* _kpwstr)
{
	size_t stringLength = wcslen(_kpwstr) + 1;
	size_t convertedChars = 0;

	if(stringLength ==1) // string is empty
	{
		return (0);
	}

	char* pStr = new char[stringLength*2];


	wcstombs_s(&convertedChars, pStr, stringLength, _kpwstr, _TRUNCATE);
	
	return pStr;
}




bool RowInputCheck(HWND _hDlg, int _iChoice)
{
	wchar_t wstrTemp[100];
	GetDlgItemText(_hDlg, IDC_MULTIPLY_AMOUNT, wstrTemp, 100);
	
	
	int iRowA = 0;
	int iRowB = 0;

	switch (_iChoice)
	{
		case 3:
		{
			if ((GetDlgItemInt(_hDlg, IDC_ADD_ROW_A, 0, 1) <= 3) &&
				(GetDlgItemInt(_hDlg, IDC_ADD_ROW_A, 0, 1) >= 1) &&
				(GetDlgItemInt(_hDlg, IDC_ADD_ROW_B, 0, 1) <= 3) &&
				(GetDlgItemInt(_hDlg, IDC_ADD_ROW_B, 0, 1) >= 1))

			{
				GetDlgItemText(_hDlg, IDC_ADD_AMOUNT, wstrTemp, 100);
				if(InputCheck(WideStringToString(wstrTemp)))
				{
					iRowA = (GetDlgItemInt(_hDlg, IDC_ADD_ROW_A, 0, 1));
					iRowB = (GetDlgItemInt(_hDlg, IDC_ADD_ROW_B, 0, 1));
				}
				else
				{
					MessageBox(_hDlg, TEXT("Error\n Invalid Amount entered can not multiply by non float"), TEXT("Error"), MB_ICONERROR | MB_OK);
					return false;
				}
			}
		}
			break;
		case 2:
		{
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
		case 1:
		{
		

			if ((GetDlgItemInt(_hDlg, IDC_MULTIPLY_ROW_NUM, 0, 1) <= 3) &&
				(GetDlgItemInt(_hDlg, IDC_MULTIPLY_ROW_NUM, 0, 1) >= 1)
				)
			{
				GetDlgItemText(_hDlg, IDC_MULTIPLY_AMOUNT, wstrTemp, 100);
				if(InputCheck(WideStringToString(wstrTemp)))
				{
					iRowA = (GetDlgItemInt(_hDlg, IDC_MULTIPLY_ROW_NUM, 0, 1));
					iRowB = (GetDlgItemInt(_hDlg, IDC_MULTIPLY_ROW_NUM, 0, 1));
				}
				else
				{
					MessageBox(_hDlg, TEXT("Error\n Invalid Amount entered can not multiply by non float"), TEXT("Error"), MB_ICONERROR | MB_OK);
					return false;
				}
			}
		}
			break;
	}

	if ((iRowA != 0) && (iRowB != 0))
	{
		return true;
	}
	else
	{
		MessageBox(_hDlg, TEXT("Error\n Incorrect Row Input \n Please enter a row choice from 1 to 3 only"), TEXT("Error"), MB_ICONERROR | MB_OK);
		return false;
	}

}

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

bool ReDucedEchelonCheck(HWND _hDlg)
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

bool GaussianSwap(HWND _hDlg)
{
	int iRowA = (GetDlgItemInt(_hDlg, IDC_SWAP_ROW_A, 0, 1));
	int iRowB = (GetDlgItemInt(_hDlg, IDC_SWAP_ROW_B, 0, 1));
	iRowA = iRowA - 1;
	iRowB = iRowB - 1;
	vector<vector<float>*>* TheMatrix = new vector<vector<float>*>;

	//create the matrix from given values 
	if(CreateMatrix(_hDlg, TheMatrix))
	{

		float fTemp;
		for (int i = 0; i < 4; i++)
		{
			fTemp = ((*(*TheMatrix)[iRowA])[i]);
			((*(*TheMatrix)[iRowA])[i]) = ((*(*TheMatrix)[iRowB])[i]);
			((*(*TheMatrix)[iRowB])[i]) = fTemp;
		}

		//set text boxes using the matrix
		SetTextBox(_hDlg, TheMatrix);
		
	}
	else
	{
		MessageBox(_hDlg, TEXT("Invalid Input Found in Matrix"), TEXT("ERROR"), MB_ICONSTOP | MB_OK);
		return false;
	}
	return (true);
}

bool GaussianMultiply(HWND _hDlg)
{
	wchar_t wstrTemp[100];
	vector<vector<float>*>* TheMatrix = new vector<vector<float>*>;

	int iRow = (GetDlgItemInt(_hDlg, IDC_MULTIPLY_ROW_NUM, 0, 1));
	iRow = iRow - 1;
	
	GetDlgItemText(_hDlg, IDC_MULTIPLY_AMOUNT, wstrTemp, 100);
	float fScalar = (WideStringToFloat(wstrTemp));

	//create the matrix from given values 
	if(CreateMatrix(_hDlg, TheMatrix))
	{

		for (int i = 0; i < 4; i++)
		{
			((*(*TheMatrix)[iRow])[i]) = fScalar*((*(*TheMatrix)[iRow])[i]);
		}

		//set text boxes using the matrix
		SetTextBox(_hDlg, TheMatrix);
	}
	else
	{
		MessageBox(_hDlg, TEXT("Invalid Input Found in Matrix"), TEXT("ERROR"), MB_ICONSTOP | MB_OK);
		return false;
	}
	return (true);
	
}

bool GaussianAdd(HWND _hDlg)
{
	wchar_t wstrTemp[100];
	GetDlgItemText(_hDlg, IDC_ADD_AMOUNT, wstrTemp, 100);
	float fScalar = (WideStringToFloat(wstrTemp));

	int iRowA = (GetDlgItemInt(_hDlg, IDC_ADD_ROW_A, 0, 1));
	int iRowB = (GetDlgItemInt(_hDlg, IDC_ADD_ROW_B, 0, 1));
	iRowA = iRowA - 1;
	iRowB = iRowB - 1;
	vector<vector<float>*>* TheMatrix = new vector<vector<float>*>;

	//create the matrix from given values 
	if(CreateMatrix(_hDlg, TheMatrix))
	{

		for (int i = 0; i < 4; i++)
		{
			((*(*TheMatrix)[iRowB])[i]) = fScalar*((*(*TheMatrix)[iRowA])[i]) + ((*(*TheMatrix)[iRowB])[i]);
		}

		//set text boxes using the matrix
		SetTextBox(_hDlg, TheMatrix);
	}
	else
	{
		MessageBox(_hDlg, TEXT("Invalid Input Found in Matrix"), TEXT("ERROR"), MB_ICONSTOP | MB_OK);
		return false;
	}

	return (true);
}