
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

bool GetRow(HWND _hDlg, int _iRowNum, vector<float>* _RowFloats)
{

	wchar_t wstrTempA[100];

	switch(_iRowNum)
	{
	case 1:
		{
			GetDlgItemText( _hDlg, IDC_MATRIX_00, wstrTempA, 100);
			(*_RowFloats).push_back(WideStringToFloat(wstrTempA));

			GetDlgItemText( _hDlg, IDC_MATRIX_01, wstrTempA, 100);
			(*_RowFloats).push_back(WideStringToFloat(wstrTempA));

			GetDlgItemText( _hDlg, IDC_MATRIX_02, wstrTempA, 100);
			(*_RowFloats).push_back(WideStringToFloat(wstrTempA));

			GetDlgItemText( _hDlg, IDC_MATRIX_03, wstrTempA, 100);
			(*_RowFloats).push_back(WideStringToFloat(wstrTempA));
		}
		break;
	case 2:
		{

			GetDlgItemText( _hDlg, IDC_MATRIX_10, wstrTempA, 100);
			(*_RowFloats).push_back(WideStringToFloat(wstrTempA));

			GetDlgItemText( _hDlg, IDC_MATRIX_11, wstrTempA, 100);
			(*_RowFloats).push_back(WideStringToFloat(wstrTempA));
			 
			GetDlgItemText( _hDlg, IDC_MATRIX_12, wstrTempA, 100);
			(*_RowFloats).push_back(WideStringToFloat(wstrTempA));

			GetDlgItemText( _hDlg, IDC_MATRIX_13, wstrTempA, 100);
			(*_RowFloats).push_back(WideStringToFloat(wstrTempA));
		}
		break;
	case 3:
		{
			GetDlgItemText( _hDlg, IDC_MATRIX_20, wstrTempA, 100);
			(*_RowFloats).push_back(WideStringToFloat(wstrTempA));

			GetDlgItemText( _hDlg, IDC_MATRIX_21, wstrTempA, 100);
			(*_RowFloats).push_back(WideStringToFloat(wstrTempA));
			 
			GetDlgItemText( _hDlg, IDC_MATRIX_22, wstrTempA, 100);
			(*_RowFloats).push_back(WideStringToFloat(wstrTempA));

			GetDlgItemText( _hDlg, IDC_MATRIX_23, wstrTempA, 100);
			(*_RowFloats).push_back(WideStringToFloat(wstrTempA));
		}
		break;
	default:
		{
			return false;
		}
	}
	return true;
}

bool SetRow(HWND _hDlg, int _iRowNum, vector<float>* _RowFloats)
{
	string strTemp;


	switch(_iRowNum)
	{
	case 1:
		{
			strTemp = FloatToString((*_RowFloats)[0]);
			SetDlgItemTextA( _hDlg, IDC_MATRIX_00,strTemp.c_str());
			
			strTemp = FloatToString((*_RowFloats)[1]);
			SetDlgItemTextA( _hDlg, IDC_MATRIX_01,strTemp.c_str());
			
			strTemp = FloatToString((*_RowFloats)[2]);
			SetDlgItemTextA( _hDlg, IDC_MATRIX_02,strTemp.c_str());

			strTemp = FloatToString((*_RowFloats)[3]);
			SetDlgItemTextA( _hDlg, IDC_MATRIX_03,strTemp.c_str());
		}
		break;
	case 2:
		{
			strTemp = FloatToString((*_RowFloats)[0]);
			SetDlgItemTextA( _hDlg, IDC_MATRIX_10,strTemp.c_str());
			
			strTemp = FloatToString((*_RowFloats)[1]);
			SetDlgItemTextA( _hDlg, IDC_MATRIX_11,strTemp.c_str());
			
			strTemp = FloatToString((*_RowFloats)[2]);
			SetDlgItemTextA( _hDlg, IDC_MATRIX_12,strTemp.c_str());

			strTemp = FloatToString((*_RowFloats)[3]);
			SetDlgItemTextA( _hDlg, IDC_MATRIX_13,strTemp.c_str());
		}
		break;
	case 3:
		{
			strTemp = FloatToString((*_RowFloats)[0]);
			SetDlgItemTextA( _hDlg, IDC_MATRIX_20,strTemp.c_str());
			
			strTemp = FloatToString((*_RowFloats)[1]);
			SetDlgItemTextA( _hDlg, IDC_MATRIX_21,strTemp.c_str());
			
			strTemp = FloatToString((*_RowFloats)[2]);
			SetDlgItemTextA( _hDlg, IDC_MATRIX_22,strTemp.c_str());

			strTemp = FloatToString((*_RowFloats)[3]);
			SetDlgItemTextA( _hDlg, IDC_MATRIX_23,strTemp.c_str());
		}
		break;
	default:
		{
			return false;
		}
	}
	return true;
}

bool GaussianSwap(HWND _hDlg, int _iRowA, int _iRowB)
{
	vector<float>* fValuesA = new vector<float>;
	vector<float>* fValuesB = new vector<float>;
	GetRow(_hDlg, _iRowA, fValuesA);
	GetRow(_hDlg, _iRowB, fValuesB);

	SetRow(_hDlg, _iRowA, fValuesB);
	SetRow(_hDlg, _iRowB, fValuesA);

	delete fValuesA;
	fValuesA = 0;
	delete fValuesB;
	fValuesB = 0;
	return true;



	/*wchar_t wstrTempA[100];
	wchar_t wstrTempB[100];
	wchar_t wstrTempC[100];
	wchar_t wstrTempD[100];
	
	float fValueA = 0.0f;
	float fValueB = 0.0f;
	float fValueC = 0.0f;
	float fValueD = 0.0f;
	
	switch(_iRowA)
	{
	case 1:
		{
			GetDlgItemText( _hDlg, IDC_MATRIX_00, wstrTempA, 100);
			fValueA = WideStringToFloat(wstrTempA);

			GetDlgItemText( _hDlg, IDC_MATRIX_01, wstrTempB, 100);
			fValueB = WideStringToFloat(wstrTempA);

			GetDlgItemText( _hDlg, IDC_MATRIX_02, wstrTempC, 100);
			fValueC = WideStringToFloat(wstrTempA);

			GetDlgItemText( _hDlg, IDC_MATRIX_03, wstrTempD, 100);
			fValueD = WideStringToFloat(wstrTempA);
		}
		break;
	case 2:
		{

			GetDlgItemText( _hDlg, IDC_MATRIX_20, wstrTempA, 100);
			fValueA = WideStringToFloat(wstrTempA);

			GetDlgItemText( _hDlg, IDC_MATRIX_21, wstrTempB, 100);
			fValueB = WideStringToFloat(wstrTempA);
			 
			GetDlgItemText( _hDlg, IDC_MATRIX_22, wstrTempC, 100);
			fValueC = WideStringToFloat(wstrTempA);

			GetDlgItemText( _hDlg, IDC_MATRIX_23, wstrTempD, 100);
			fValueD = WideStringToFloat(wstrTempA);
		}
	case 3:
		{
			GetDlgItemText( _hDlg, IDC_MATRIX_20, wstrTempA, 100);
			fValueA = WideStringToFloat(wstrTempA);

			GetDlgItemText( _hDlg, IDC_MATRIX_21, wstrTempB, 100);
			fValueB = WideStringToFloat(wstrTempA);
			 
			GetDlgItemText( _hDlg, IDC_MATRIX_22, wstrTempC, 100);
			fValueC = WideStringToFloat(wstrTempA);

			GetDlgItemText( _hDlg, IDC_MATRIX_23, wstrTempD, 100);
			fValueD = WideStringToFloat(wstrTempA);
		}
	}


	GetDlgItemText( _hDlg, IDC_MATRIX_00, wstrTempA, 100);
	SetDlgItemTextA( _hDlg, IDC_MATRIX_00,wstrTempA.c_str());*/
}