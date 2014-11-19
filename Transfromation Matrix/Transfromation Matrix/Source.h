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

const float PI_OVR_180 = (3.14159265f/180.0f);

const int SCALE = 0;
const int SKEWING = 1;
const int TRANSLATE = 2;
const int ROTATION = 3;
const int PROJECTION = 4;


//librarty includes 
#include <iostream>
#include <cstring>
#include <sstream>
#include <Windows.h>
#include <tchar.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <math.h>

//local includes
#include "resource.h"

//namespace
using namespace std;

//functions Prototypes 
//Inisialise Value in Text boxes
bool Initialise(HWND _hDlg, HWND _ComboBox);

//Input checks
bool InputCheck(string &_str);

//Conversions
string FloatToString(const float _kfValue);
float WideStringToFloat(const wchar_t* _kpwstr);
string WideStringToString(const wchar_t* _kpwstr);

//Get Matrices from the text boxes
bool GetStrMatrix(HWND _hDlg, vector<vector<string>*>* _pMatrixA,vector<vector<string>*>* _pMatrixB);
bool GetMatrix(HWND _hDlg, vector<vector<float>*>* _pMatrixA,vector<vector<float>*>* _pMatrixB);
bool GetVector(HWND _hDlg, int _iChoice, vector<float>* _fpScalar);

//Set the matrices/scalar Text boxes
bool SetMatrix(HWND _hDlg, vector<vector<float>*>* _pRowMatrix, vector<vector<float>*>* _pColMatrix);
bool SetMatrixNA(HWND _hDlg, int _iChoice);

//Transformations
bool SetToI(HWND _hDlg);
vector<vector<float>*>* Scale(HWND _hDlg);
vector<vector<float>*>* Skew(HWND _hDlg);
vector<vector<float>*>* Translate(HWND _hDlg);
vector<vector<float>*>* Rotate(HWND _hDlg);
vector<vector<float>*>* RotateA(HWND _hDlg);
vector<vector<float>*>* Projection(HWND _hDlg);



