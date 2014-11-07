/*
* Bachelor of Software Engineering 
* Media Design School 
* Auckland 
* New Zealand 
 
* (c) 2005 - 2014 Media Design School 
 
* File Name : Source.h
* Description : Header file containing all used fucntions and #includes
* Author :	Jc Fowles
* Mail :	Jc.Fowles@mediadesign.school.nz	
*/

#pragma once

//librarty includes 
#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include <tchar.h>
#include <vector>
#include <algorithm>

//local includes
#include "resource.h"

//namespace
using namespace std;

//functions Prototypes 

//Gaussian Eliminations
bool GaussianMultiply(HWND _hDlg);
bool GaussianSwap(HWND _hDlg);
bool GaussianAdd(HWND _hDlg);

//Row Echelon Checks
bool EchelonCheck(HWND _hDlg);
bool ReducedEchelonCheck(HWND _hDlg);

//Initialise the matrix values
bool Initialise(HWND _hDlg);
bool RandomInitialise(HWND _hDlg);

//creating the matrix from the text boxes
bool CreateMatrix(HWND _hDlg, vector<vector<float>*>* _TheMatrix);
bool CreateStrMatrix(HWND _hDlg,vector<vector<string>*>* _pStrMatrix );

//seting the textbox
bool SetTextBox(HWND _hDlg, vector<vector<float>*>* _fMatrix);

//input checks
bool InputCheck(string &_str);
bool RowInputCheck(HWND _hDlg, int _iChoice);

//conversions
string FloatToString(const float _kfValue);
float WideStringToFloat(const wchar_t* _kpwstr);
string WideStringToString(const wchar_t* _kpwstr);

