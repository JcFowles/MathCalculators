#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include <tchar.h>
#include <vector>
#include <algorithm>

#include "resource.h"

using namespace std;

float getFloat();
float setTextFloat();

bool GaussianMultiply(HWND _hDlg);
bool GaussianSwap(HWND _hDlg);
bool GaussianAdd(HWND _hDlg);

bool EchelonCheck(HWND _hDlg);
bool ReDucedEchelonCheck(HWND _hDlg);

bool Initialise(HWND _hDlg);
bool RandomInitialise(HWND _hDlg);

bool CreateMatrix(HWND _hDlg, vector<vector<float>*>* _TheMatrix);
bool CreateStrMatrix(HWND _hDlg,vector<vector<string>*>* _pStrMatrix );
bool SetTextBox(HWND _hDlg, vector<vector<float>*>* _fMatrix);

bool InputCheck(string &_str);
bool RowInputCheck(HWND _hDlg, int _iChoice);

string FloatToString(const float _kfValue);
float WideStringToFloat(const wchar_t* _kpwstr);
string WideStringToString(const wchar_t* _kpwstr);

//float conversion
//getting input from boxes as floats
//inputs checks
//setting text in boxes as floats