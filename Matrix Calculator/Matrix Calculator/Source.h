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

//The Matrix coice
const int A = 1;		//Matrix A
const int B = 2;		//Matrix B
const int Result = 3;	//Reslut Matrix

const int Mag = 1;		//Magnited Text Box
const int Multiply = 2; //Multipy Text Box

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

//Get Matrices from the text boxes
bool GetStrMatrix(HWND _hDlg, vector<vector<string>*>* _pMatrixA,vector<vector<string>*>* _pMatrixB);
bool GetMatrix(HWND _hDlg, vector<vector<float>*>* _pMatrixA,vector<vector<float>*>* _pMatrixB);
bool GetScalar(HWND _hDlg, int _iMatrixChoice, float* _fpScalar);

//Set the matrices/scalar Text boxes
bool SetMatrix(HWND _hDlg, vector<vector<float>*>* _pMatrix, int _iChoice);
bool SetScalar(HWND _hDlg, int _iMatrixChoice, float* _fpScalar);


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