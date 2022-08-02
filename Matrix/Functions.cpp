#include "Functions.h"

#include <math.h>


Functions::Functions()
{
}

Mat* InitArr(Mat* mat, int rows, int colons)
{
	mat->data = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		mat->data[i] = new int[colons];
	}
	mat->rows = rows;
	mat->colons = colons;
	return mat;
}

void DeleteArr(int **&arr, int size)
{
	for (int i = 0; i < size; i++)
		delete[] arr[i];
	delete[] arr;
}

Mat* Functions::Sum(Mat* matrix1, Mat* matrix2)
{
	int M = matrix1->rows, N = matrix1->colons;
	Mat* res = new Mat;
	res = InitArr(res, M, N);
	int k = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			res->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
		}
	}		
	return res;
}

Mat* Functions::Diferance(Mat* matrix1, Mat* matrix2)
{
	int M = matrix1->rows, N = matrix1->colons;
	Mat* res = new Mat;
	res = InitArr(res, M, N);	
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			res->data[i][j] = matrix1->data[i][j] - matrix2->data[i][j];
		}
	}	
	return res;
}

Mat* Functions::Mult(Mat* matrix1, Mat* matrix2)
{
	int M = matrix1->rows, N = matrix2->colons;
	Mat* res = new Mat;
	res = InitArr(res, M, N);	
	int temp;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{	
			temp = 0;
			for (int h = 0; h < matrix1->colons; h++)
			{
				temp += matrix1->data[i][h] * matrix2->data[h][j];
			}
			res->data[i][j] = temp;			
		}		
	}	
	return res;	
}

Mat* Functions::Scalar(Mat* matrix, int p)
{
	
	for (int i = 0; i < matrix->rows; i++)
	{
		for (int j = 0; j < matrix->colons; j++)
		{
			matrix->data[i][j] *= p;
		}
	}
	return matrix;
}

Mat* Functions::Transpose(Mat* matrix)
{
	Mat* res = new Mat;
	int M = matrix->colons, N = matrix->rows;
	res = InitArr(res, M, N);
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			res->data[i][j] = matrix->data[j][i];
		}
	}
	return res;
}

int Functions::Determinant(int **arr, int ord)
{
	if (ord == 1)
		return arr[0][0];		
	else
	{
		int i = 0;
		int tmp = 0;
		while (i < ord)
		{
			int **temp = new int*[ord - 1];
			for (int j = 0; j < ord; j++)
				temp[j] = new int[ord - 1];
			for (int j = 0; j < ord - 1; j++)
			{					
				for (int k = 0; k <= ord - 1; k++)
				{
					if (k < i)
					{
						temp[j][k] = arr[j + 1][k];
					}
					if (k > i)
						temp[j][k - 1] = arr[j + 1][k];
				}
			}			
			tmp += arr[0][i] * pow(-1, i) * Determinant(temp, ord - 1);
			i++;
		}
		return tmp;
	}
		
}

int Functions::Addition(int **arr, int ord, int ind1, int ind2)
{
	if (ord == 1)
		return arr[0][0];
	else
	{
		int **temp = new int*[ord - 1];
		for (int i = 0; i < ord; i++)
			temp[i] = new int[ord - 1];

		for (int i = 0; i < ord; i++)
		{
			for (int j = 0; j < ord; j++)
			{
				if (i < ind1)
				{
					if (j < ind2)
						temp[i][j] = arr[i][j];
					if (j > ind2)
						temp[i][j - 1] = arr[i][j];
				}
				if (i > ind1)
				{
					if (j < ind2)
						temp[i - 1][j] = arr[i][j];
					if (j > ind2)
						temp[i - 1][j - 1] = arr[i][j];
				}
			}
		}
		return Determinant(temp, ord - 1);
	}
}

Mat* Functions::Inverse(Mat* matrix)
{
	int ord = matrix->rows;
	Mat* res = new Mat;
	res = InitArr(res, ord, ord);	
	for (int i = 0; i < ord; i++)
	{
		for (int j = 0; j < ord; j++)
		{
			res->data[i][j] = pow(-1, i+j) * Addition(matrix->data, ord, i, j);
		}
	}
	return Transpose(res);
}

int Functions::Convertation(String^ str)
{
	int x;
	try
	{
		x = Convert::ToInt32(str);
	}
	catch (FormatException^)
	{ 
		Exception^ x = gcnew Exception("Введены не все значения");		
		throw x;		
		return NULL;
	}
	x = Convert::ToInt32(str);
	return x;
}

Mat* Functions::Power(Mat* matrix, int n)
{
	if (n < 0)
	{
		MessageBox::Show("Возведение в отрицательную степень невозможно");
		return matrix;
	}
	if (n == 0)
	{
		for (int i = 0; i < matrix->rows; i++)
		{
			for (int j = 0; j < matrix->colons; j++)
			{
				if (i == j)
					matrix->data[i][j] = 1;
				else
					matrix->data[i][j] = 0;
			}
		}
		return matrix;
	}
	int i = 1;
	Mat* M = matrix;
	while (i < n)
	{		
		M = Mult(M, matrix);
		i++;
	}
	return M;
}