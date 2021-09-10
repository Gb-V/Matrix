#pragma once
#include <cmath>
#include "Matrix.h"

double FDet(double** a, int size) {
	int d = 0;
	if (size == 1) return a[0][0];
	else {
		if (size == 2)
			return a[0][0] * a[1][1] - a[0][1] * a[1][0];
		else {
			for (int k = 0; k < size; k++) {
				double** m = new double* [size - 1];
				for (int i = 0; i < size - 1; i++) {
					m[i] = new double[size - 1];
				}
				for (int i = 1; i < size; i++) {
					int t = 0;
					for (int j = 0; j < size; j++) {
						if (j == k)
							continue;
						m[i - 1][t] = a[i][j];
						t++;
					}
				}
				d += pow(-1, (k + 2)) * a[0][k] * FDet(m, size - 1);
				ClearM(m, size - 1);
			}
		}
		return d;
	}
}

double** matrixInverse(double** matrix, int n)
{
	int SIZE = 2 * n;
	double ratio, max, b;
	int m;
	double** a;
	a = new double* [SIZE];
	for (int i = 0; i < SIZE; i++)
		a[i] = new double[SIZE];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			a[i][j] = matrix[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				a[i][j + n] = 1;
			}
			else {
				a[i][j + n] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (a[i][i] == 0.0) {
			max = a[i][i];
			for (int x = i; x < n; x++) {
				if (max < a[x][i]) {
					m = x;
					max = a[x][i];
				}
			}
			if (max != a[i][i]) {
				for (int x = i; x < 2 * n; x++) {
					b = a[m][x];
					a[m][x] = a[i][x];
					a[i][x] = b;
				}
			}
			else
				break;
		}
		for (int j = 0; j < n; j++) {
			if (i != j) {
				ratio = a[j][i] / a[i][i];
				for (int k = 0; k < SIZE; k++) {
					a[j][k] = a[j][k] - ratio * a[i][k];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = n; j < SIZE; j++) {
			a[i][j] = a[i][j] / a[i][i];
		}
	}

	double **result;
	result = new double* [n];
	for (int i = 0; i < n; i++)
		result[i] = new double[n];

	for (int i = 0; i < n; i++)
	{
		for (int j = n; j < 2 * n; j++)
		{
			result[i][j - n] = a[i][j];
		}
	}
	
	ClearM(a, SIZE);
	return result;
}

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