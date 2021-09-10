#pragma once
#include <cmath>
#include "Matrix.h"

/// <summary>
/// Возвращает определитель матрицы
/// </summary>
/// <param name="matrix"> Матрица </param>
/// <param name="size"> Размер </param>
/// <returns></returns>
double Det(double** matrix, int size) {
	int d = 0;
	if (size == 1) return matrix[0][0];
	else {
		if (size == 2)
			return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
		else {
			for (int k = 0; k < size; k++) {
				double** Addminor = new double* [size - 1];
				for (int i = 0; i < size - 1; i++) {
					Addminor[i] = new double[size - 1];
				}
				for (int i = 1; i < size; i++) {
					int t = 0;
					for (int j = 0; j < size; j++) {
						if (j == k)
							continue;
						Addminor[i - 1][t] = matrix[i][j];
						t++;
					}
				}
				d += pow(-1, (k + 2)) * matrix[0][k] * Det(Addminor, size - 1);
				DeleteMatrix(Addminor, size - 1);
			}
		}
		return d;
	}
}

/// <summary>
/// Находит обратную матрицу методом Гаусса
/// </summary>
/// <param name="matrix"> Матрица </param>
/// <param name="n"> Размер матрица </param>
/// <returns> Возвращает обратную матрицу </returns>
double** matrixInverse(double** matrix, int n)
{
	int SIZE = 2 * n;
	double ratio, max, b;
	int m;
	double** InverseMatrix;
	InverseMatrix = new double* [SIZE];
	for (int i = 0; i < SIZE; i++)
		InverseMatrix[i] = new double[SIZE];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			InverseMatrix[i][j] = matrix[i][j];
	}
	// Заполнение дополненой матрицы 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				InverseMatrix[i][j + n] = 1;
			}
			else {
				InverseMatrix[i][j + n] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		// Проверка на ноличие 0 на главной диагонали
		// Если есть 0 , то находит наибольший элемент в столбце и меняет местами строки с 0 и с наибольшим значением 
		if (InverseMatrix[i][i] == 0.0) {
			max = InverseMatrix[i][i];
			for (int x = i; x < n; x++) {
				if (max < InverseMatrix[x][i]) {
					m = x;
					max = InverseMatrix[x][i];
				}
			}
			if (max != InverseMatrix[i][i]) {
				for (int x = i; x < 2 * n; x++) {
					b = InverseMatrix[m][x];
					InverseMatrix[m][x] = InverseMatrix[i][x];
					InverseMatrix[i][x] = b;
				}
			}
			else
				break;
		}
		// Метод Гаусса
		for (int j = 0; j < n; j++) {
			if (i != j) {
				ratio = InverseMatrix[j][i] / InverseMatrix[i][i];
				for (int k = 0; k < SIZE; k++) {
					InverseMatrix[j][k] = InverseMatrix[j][k] - ratio * InverseMatrix[i][k];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = n; j < SIZE; j++) {
			InverseMatrix[i][j] = InverseMatrix[i][j] / InverseMatrix[i][i];
		}
	}

	double **result;
	result = new double* [n];
	for (int i = 0; i < n; i++)
		result[i] = new double[n];
	// Копирование обратной матрицы из дополненой 
	for (int i = 0; i < n; i++)
	{
		for (int j = n; j < 2 * n; j++)
		{
			result[i][j - n] = InverseMatrix[i][j];
		}
	}
	
	DeleteMatrix(InverseMatrix, SIZE);
	return result;
}

/// <summary>
/// Произведение 2-ух матриц
/// </summary>
/// <param name="mat1">  Множимое </param>
/// <param name="mat2"> Множитель </param>
/// <param name="size"></param>
/// <returns></returns>
double** matrixMult(double** mat1, double** mat2, int size) {
	double** result;
	result = new double* [size];
	for (int i = 0; i < size; i++)
		result[i] = new double[size];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < size; k++)
				result[i][j] += mat1[i][k] * mat2[k][j];
		}
	}
	return result;
}