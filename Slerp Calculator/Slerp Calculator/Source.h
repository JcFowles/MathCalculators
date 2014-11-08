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

//define A, B and SLERP
const int A = 1;	//Qauternion A 
const int B = 2;	//Qauternion B 
const int SLERP = 3;	//Qauternion SLERP

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
//Inisialise Value in Text boxes
bool Initialise(HWND _hDlg);

//Input checks
bool InputCheck(string &_str);

//Conversions
string FloatToString(const float _kfValue);
float WideStringToFloat(const wchar_t* _kpwstr);
string WideStringToString(const wchar_t* _kpwstr);

//get the values
bool GetQuaternionStr(HWND _hDlg, vector<string>* _pStrQuatA, vector<string>* _pStrQuatB,  vector<string>* _pstrQuatSlerp);
bool GetQuaternion(HWND _hDlg, vector<float>* _pfQuatA, vector<float>* _pfQuatB, vector<float>* _pfQuatSlerp);
bool GetScalar(HWND _hDlg, float* _pfScalarA);

//Set text Boxes
bool setResult(HWND _hDlg, vector<float>* _pResultQuat);
bool setResult(HWND _hDlg, vector<vector<float>*>* _pfMatrix);

//SLERP functions
bool slerp(HWND _hDlg);

bool Matrix(HWND _hDlg, int _iChoice);