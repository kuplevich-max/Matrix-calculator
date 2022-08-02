
#pragma once
#include "Functions.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;

class Matrixs
{
private: 
		Mat *matrix1;
		Mat *matrix2;
		Mat *result;
		
public:
	Matrixs();
	void AddMatrix1(List<TextBox^>^, int rows, int colons);
	void AddMatrix2(List<TextBox^>^, int rows, int colons);
	Mat* GetMatrix1();
	Mat* GetMatrix2();
	List<TextBox^>^ Result(List<TextBox^>^ textBox);
	Mat* GetResult();
	void Perform(TextBox^ sign);
	void Transponse();	
	void Invers();
	Mat* ToRes(int M, int N);
	void AXB();
	void XAB();
	void Power(int n);
};

