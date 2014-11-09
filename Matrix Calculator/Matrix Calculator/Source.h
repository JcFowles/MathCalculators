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

const int A = 1;
const int B = 2;
const int Result = 3;

const int mag = 1;
const int Multiply = 2;

//functions Prototypes 
//Inisialise Value in Text boxes
bool Initialise(HWND _hDlg);

//Input checks
bool InputCheck(string &_str);

//Conversions
string FloatToString(const float _kfValue);
float WideStringToFloat(const wchar_t* _kpwstr);
string WideStringToString(const wchar_t* _kpwstr);

//Get Matrices from the text boxes
bool GetMatrix(HWND _hDlg, vector<vector<string>*>* _pMatrixA,vector<vector<string>*>* _pMatrixB);
bool GetMatrix(HWND _hDlg, vector<vector<float>*>* _pMatrixA,vector<vector<float>*>* _pMatrixB);
float GetScalar(HWND _hDlg, int _iMatrixChoice, int _iScalarChoice);

//Set the matrices Text boxes
bool SetMatrix(HWND _hDlg, vector<vector<float>*>* _pMatrix, int _iChoice);

//single matrix calculations
bool SetToI(HWND _hDlg, int _iChoice);
bool Magnitude(HWND _hDlg, int _iChoice);
bool Transpose(HWND _hDlg, int _iChoice);
bool Inverse(HWND _hDlg, int _iChoice);
bool ScalarMultiply(HWND _hDlg, int _iChoice);

//multiple matrix calculations
bool Add(HWND _hDlge);
bool Sub(HWND _hDlge);
bool Sub(HWND _hDlge, int _Choice);