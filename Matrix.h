#pragma once

int N;
short Answer;
double **A, **ResultProd;

double** StorInvM;

/// <summary>
/// ������������� �������
/// </summary>
void InitMatrix() {
	A = new double* [N];
	for (int i = 0; i < N; i++)
		A[i] = new double[N];
	
	ResultProd = new double* [N];
	for (int i = 0; i < N; i++)
		ResultProd[i] = new double[N];
}

/// <summary>
/// �������� �������  
/// </summary>
/// <param name="matrix"> ������� </param>
/// <param name="size"> ������ ������� </param>
void DeleteMatrix(double** matrix, int size) {
	for (int i = 0; i < size; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}
