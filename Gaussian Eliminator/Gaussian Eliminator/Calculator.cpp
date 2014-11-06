
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

bool CreateMatrix(HWND _hDlg, vector<vector<float>*>* _fMatrix)
{
	wchar_t wstrTempA[100];
	//temp matrix row
	vector<float>* vpfTemp = new vector<float>;

	if (InputCheck(_hDlg))
	{
		//First row enter into the matrix
		GetDlgItemText(_hDlg, IDC_MATRIX_00, wstrTempA, 100);

		(*vpfTemp).push_back(WideStringToFloat(wstrTempA));		

		GetDlgItemText(_hDlg, IDC_MATRIX_01, wstrTempA, 100);
		(*vpfTemp).push_back(WideStringToFloat(wstrTempA));

		GetDlgItemText(_hDlg, IDC_MATRIX_02, wstrTempA, 100);
		(*vpfTemp).push_back(WideStringToFloat(wstrTempA));

		GetDlgItemText(_hDlg, IDC_MATRIX_03, wstrTempA, 100);
		(*vpfTemp).push_back(WideStringToFloat(wstrTempA));

		//add the temp row to the matrix
		(*_fMatrix).push_back(vpfTemp);

		vpfTemp = new vector<float>;
		//clear the temp row
	
		//Second row enter into the matrix
		GetDlgItemText(_hDlg, IDC_MATRIX_10, wstrTempA, 100);
		(*vpfTemp).push_back(WideStringToFloat(wstrTempA));

		GetDlgItemText(_hDlg, IDC_MATRIX_11, wstrTempA, 100);
		(*vpfTemp).push_back(WideStringToFloat(wstrTempA));

		GetDlgItemText(_hDlg, IDC_MATRIX_12, wstrTempA, 100);
		(*vpfTemp).push_back(WideStringToFloat(wstrTempA));

		GetDlgItemText(_hDlg, IDC_MATRIX_13, wstrTempA, 100);
		(*vpfTemp).push_back(WideStringToFloat(wstrTempA));

		//add the temp row to the matrix
		(*_fMatrix).push_back(vpfTemp);

		//clear the temp row
		vpfTemp = new vector<float>;

		//Third row enter into the matrix
		GetDlgItemText(_hDlg, IDC_MATRIX_20, wstrTempA, 100);
		(*vpfTemp).push_back(WideStringToFloat(wstrTempA));

		GetDlgItemText(_hDlg, IDC_MATRIX_21, wstrTempA, 100);
		(*vpfTemp).push_back(WideStringToFloat(wstrTempA));

		GetDlgItemText(_hDlg, IDC_MATRIX_22, wstrTempA, 100);
		(*vpfTemp).push_back(WideStringToFloat(wstrTempA));

		GetDlgItemText(_hDlg, IDC_MATRIX_23, wstrTempA, 100);
		(*vpfTemp).push_back(WideStringToFloat(wstrTempA));

		//add the temp row to the matrix
		(*_fMatrix).push_back(vpfTemp);

		//clear the temp row
		vpfTemp = new vector<float>;
		

		return (true);

	}
	else
	{
		return (false);
	}
			
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

bool InputCheck(HWND _hDlg)
{
	//update this
	return (true);
}

bool RowInputCheck(HWND _hDlg, int _iChoice)
{

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
				iRowA = (GetDlgItemInt(_hDlg, IDC_ADD_ROW_A, 0, 1));
				iRowB = (GetDlgItemInt(_hDlg, IDC_ADD_ROW_B, 0, 1));
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
				iRowA = (GetDlgItemInt(_hDlg, IDC_MULTIPLY_ROW_NUM, 0, 1));
				iRowB = (GetDlgItemInt(_hDlg, IDC_MULTIPLY_ROW_NUM, 0, 1));
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
		MessageBox(_hDlg, TEXT("Error\n Incorrect Row Input \n Please enter a row choice from 1 to 3 only"), TEXT("Error"), MB_ICONQUESTION | MB_OK);
		return false;
	}

}


bool EchelonCheck(HWND _hDlg)
{

	vector<vector<float>*>* TheMatrix = new vector<vector<float>*>;

	//create the matrix from given values 
	CreateMatrix(_hDlg, TheMatrix);

	if( (NonZeroRowCheck(TheMatrix)) &&
		(LeadingCoefficientCheck(TheMatrix)) &&
		(BelowLeadingZero(TheMatrix)))
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

bool NonZeroRowCheck(vector<vector<float>*>* _TheMatrix)
{
	bool bFirstZero = true;
	bool bReturn = true;
	
	float checkValue;

	for (int iRow = 0; iRow < 3; iRow++)
	{
		bFirstZero = true;
		for (int iColumn = 0; iColumn < 4; iColumn++)
		{
			checkValue = (*(*_TheMatrix)[iRow])[iColumn];
			if ((*(*_TheMatrix)[iRow])[iColumn] != 0)
			{
				bFirstZero = false;
				break;
			}
		}
		if (bFirstZero)
		{
			if (iRow == 0)  // if first row is all zeros then all values must be zero , if not return false
			{
				for (int iNewRow = 1; iRow < 3; iRow++)
				{
					for (int iColumn = 0; iColumn < 4; iColumn++)
					{
						checkValue = (*(*_TheMatrix)[iNewRow])[iColumn];
						if ((*(*_TheMatrix)[iNewRow])[iColumn] != 0)
						{
							bReturn = false;
							return bReturn;
							break;
						}
					}

				}
				bReturn = true;
				return bReturn;
			}
			else if (iRow == 1) // if its the second row that has all zeros then the third row must be all zeros if not return false
			{
				for (int iColumn = 0; iColumn < 4; iColumn++)
				{
					checkValue = (*(*_TheMatrix)[2])[iColumn];
					if ((*(*_TheMatrix)[2])[iColumn] != 0)
					{
						bReturn = false;
						return bReturn;
						break;
					}
				}
				bReturn = true;
				return bReturn;
			}
			else  // must be the third row with all zeros, and thats all gravy no extra check required return true
			{
				bReturn = true;
				return bReturn;
			}
		}
	}
	//bReturn = false;
	return bReturn; //if we get here it means no row has only zeros there for return true

}

bool LeadingCoefficientCheck(vector<vector<float>*>* _TheMatrix)
{
	return true;
}

bool BelowLeadingZero(vector<vector<float>*>* _TheMatrix)
{
	return true;
}




bool GaussianSwap(HWND _hDlg)
{
	int iRowA = (GetDlgItemInt(_hDlg, IDC_SWAP_ROW_A, 0, 1));
	int iRowB = (GetDlgItemInt(_hDlg, IDC_SWAP_ROW_B, 0, 1));
	iRowA = iRowA - 1;
	iRowB = iRowB - 1;
	vector<vector<float>*>* TheMatrix = new vector<vector<float>*>;

	//create the matrix from given values 
	CreateMatrix(_hDlg, TheMatrix);

	float fTemp;
	for (int i = 0; i < 4; i++)
	{
		fTemp = ((*(*TheMatrix)[iRowA])[i]);
		((*(*TheMatrix)[iRowA])[i]) = ((*(*TheMatrix)[iRowB])[i]);
		((*(*TheMatrix)[iRowB])[i]) = fTemp;
	}

	//set text boxes using the matrix
	SetTextBox(_hDlg, TheMatrix);

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
	CreateMatrix(_hDlg, TheMatrix);

	for (int i = 0; i < 4; i++)
	{
		((*(*TheMatrix)[iRow])[i]) = fScalar*((*(*TheMatrix)[iRow])[i]);
	}

	//set text boxes using the matrix
	SetTextBox(_hDlg, TheMatrix);

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
	CreateMatrix(_hDlg, TheMatrix);

	for (int i = 0; i < 4; i++)
	{
		((*(*TheMatrix)[iRowB])[i]) = fScalar*((*(*TheMatrix)[iRowA])[i]) + ((*(*TheMatrix)[iRowB])[i]);
	}

	//set text boxes using the matrix
	SetTextBox(_hDlg, TheMatrix);

	return (true);
}