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

//define A then B or B then A
const int A = 1; //if qauternion A will be the (first) quaternion in the equation  
const int B = 2; //if qauternion B will be the (first) quaternion in the equation  

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
bool GetQuaternionStr(HWND _hDlg, vector<string>* _pStrQuatA, vector<string>* _pStrQuatB);
bool GetQuaternion(HWND _hDlg, vector<float>* _pfQuatA, vector<float>* _pfQuatB);
bool GetScalar(HWND _hDlg, float* _pfScalarA);

//Set text Boxes
bool setResult(HWND _hDlg, vector<float>* _pResultQuat);
bool setResult(HWND _hDlg, float* _pfResult);

//Quaternion Calculations
bool Add(HWND _hDlg);

bool Sub(HWND _hDlg, int _iChoice);

bool MultiplyQuaternion(HWND _hDlg, int _iChoice);

bool ScalarMultiply(HWND _hDlg, int _iChoice);

bool Conjegate(HWND _hDlg, int _iChoice);

bool Inverse(HWND _hDlg, int _iChoice);

bool Mag(HWND _hDlg, int _iChoice);

bool Dot(HWND _hDlg);