#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include <tchar.h>
#include <vector>

#include "resource.h"

using namespace std;

float getFloat();
float setTextFloat();

bool GaussianMultiply();
bool GaussianSwap(HWND _hDlg, int _iRowA, int _iRowB);
bool GaussianAdd();

bool Initialise(HWND _hDlg);

bool InputCheck();

bool GetRow(HWND _hDlg, int _iRowNum, vector<float>* _RowFloats);
bool SetRow(HWND _hDlg, int _iRowNum, vector<float>* _RowFloats);


string FloatToString(const float _kfValue);
float WideStringToFloat(const wchar_t* _kpwstr);

//float conversion
//getting input from boxes as floats
//inputs checks
//setting text in boxes as floats