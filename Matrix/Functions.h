#pragma once


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;

struct Mat
{
	int rows;
	int colons;
	int** data;
};
ref class Functions
{
public:
	Functions();
	static int Convertation(String^ str);
	static Mat* Sum(Mat* matrix1, Mat* matrix2);
	static Mat* Diferance(Mat* matrix1, Mat* matrix2);
	static Mat* Mult(Mat* matrix1, Mat* matrix2);
	static Mat* Scalar(Mat* matrix, int p);
	static Mat* Transpose(Mat* matrix);
	static int Determinant(int **arr, int ord);
	static int Addition(int **arr, int ord, int ind1, int ind2 );
	static Mat* Inverse(Mat* matrix);	
	static Mat* Power(Mat* matrix, int n);
};