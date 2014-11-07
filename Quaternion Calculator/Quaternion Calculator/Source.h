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

//Input checks
bool InputCheck(string &_str);

//Conversions
string FloatToString(const float _kfValue);
float WideStringToFloat(const wchar_t* _kpwstr);
string WideStringToString(const wchar_t* _kpwstr);

//Create Row from text box
bool createRowStr(HWND _hDlg, vector<string>* _pStrRow );
bool createRow(HWND _hDlg, vector<float>* _pRow );

//Set text Boxes
bool setResultQuaternion(HWND _hDlg, vector<float>* _pRow);
bool setResultScalar(HWND _hDlg, float _fResult);

bool Add(HWND _hDlg);

bool SubA(HWND _hDlg);
bool SubB(HWND _hDlg);
bool Sub(HWND _hDlg, int _iChoice);
bool Subtract(vector<float>* _pRowOne, vector<float>* _pRowTwo );


bool MultiplyQuaternionAB(HWND _hDlg);
bool MultiplyQuaternionBA(HWND _hDlg);
bool MultiplyQuaternion(HWND _hDlg, int _iChoice);
bool MultiplyQuaternion(vector<float>* _pRowOne, vector<float>* _pRowTwo );


bool ScalarMultiplyA(HWND _hDlg);
bool ScalarMultiplyB(HWND _hDlg);
bool ScalarMultiply(HWND _hDlg, int _iChoice);
bool ScalarMultiply(vector<float>* _pRowOne, vector<float>* _pRowTwo );


bool ConjegateA(HWND _hDlg);
bool ConjegateB(HWND _hDlg);
bool Conjegate(HWND _hDlg, int _iChoice);
bool Conjegate(vector<float>* _pRow);


bool InverseA(HWND _hDlg);
bool InverseB(HWND _hDlg);
bool Inverse(HWND _hDlg, int _iChoice);
bool Inverse(vector<float>* _pRow);

bool Mag(HWND _hDlg);
bool Dot(HWND _hDlg);