#include "Matrixs.h"

Matrixs::Matrixs()
{
	matrix1 = new Mat;
	matrix2 = new Mat;
	result = new Mat;
}

Mat* Matrixs::ToRes(int M, int N)
{
	result->data = new int*[M];
	for (int i = 0; i < M; i++)
	{
		result->data[i] = new int[N];
	}
	result->rows = M;
	result->colons = N;
	return result;
}

void Matrixs::AddMatrix1(List<TextBox^>^ textBox, int rows, int colons)
{
	this->matrix1->data = new int*[rows];
	for (int i = 0; i < rows; i++)
		this->matrix1->data[i] = new int[colons];
	matrix1->rows = rows;
	matrix1->colons = colons;
	int k = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colons; j++)
		{
			this->matrix1->data[i][j] = Convert::ToInt32(textBox[k]->Text);
			k++;
		}
	}
}

void Matrixs::AddMatrix2(List<TextBox^>^ textBox, int rows, int colons)
{
	matrix2->data = new int*[rows];
	for (int i = 0; i < rows; i++)
		matrix2->data[i] = new int[colons];
	matrix2->rows = rows;
	matrix2->colons = colons;
	int k = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colons; j++)
		{
			this->matrix2->data[i][j] = Convert::ToInt32(textBox[k]->Text);
			k++;
		}
	}
}

Mat* Matrixs::GetMatrix1()
{
	if (matrix1 != nullptr)
		return this->matrix1;
	else
		MessageBox::Show("Вы не ввели значение первой матрицы!");
}

Mat* Matrixs::GetMatrix2()
{
	if(matrix2 != nullptr)
		return this->matrix2;
	else
		MessageBox::Show("Вы не ввели значение второй матрицы!");
}

void Matrixs::Perform(TextBox^ sign)
{
	if (sign->Text == "+")
	{
		result = ToRes(matrix1->rows, matrix1->colons);
		result = Functions::Sum(matrix1, matrix2);
	}
	if (sign->Text == "-")
	{
		result = ToRes(matrix1->rows, matrix1->colons);
		result = Functions::Diferance(matrix1, matrix2);
	}
	if (sign->Text == "*")
	{
		if (matrix2->rows > 1 || matrix2->colons > 1)
		{
			result = ToRes(matrix1->rows, matrix2->colons);
			result = Functions::Mult(matrix1, matrix2);
		}
		else
		{
			result = ToRes(matrix1->rows, matrix1->colons);
			result = Functions::Scalar(matrix1, matrix2->data[0][0]);
		}
	}	
}

void Matrixs::Transponse()
{
	result = ToRes(matrix1->rows, matrix1->colons);
	result = Functions::Transpose(matrix1);
}

void Matrixs::Invers()
{
	result = ToRes(matrix1->rows, matrix1->colons);
	result = Functions::Inverse(matrix1);
}

List<TextBox^>^ Matrixs::Result(List<TextBox^>^ textBox)
{
	int k = 0;
	for (int i = 0; i < result->rows; i++)
	{
		for (int j = 0; j < result->colons; j++)
		{
			textBox[k]->Text = Convert::ToString(result->data[i][j]);
			k++;
		}
	}
	return textBox;
}

void Matrixs::AXB()
{
	result = ToRes(matrix1->rows, matrix2->colons);
	matrix1 = Functions::Inverse(matrix1);
	result = Functions::Mult(matrix1, matrix2);	
}
void Matrixs::XAB()
{
	result = ToRes(matrix2->rows, matrix1->colons);
	matrix1 = Functions::Inverse(matrix1);
	result = Functions::Mult(matrix2, matrix1);
}

void Matrixs::Power(int n)
{
	result = ToRes(matrix1->rows, matrix1->colons);
	result = Functions::Power(matrix1, n);
}