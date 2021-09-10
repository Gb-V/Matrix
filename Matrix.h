#pragma once

int N;
short Answer;
double **A, **ResultProd;

double** StorInvM;

/// <summary>
/// Инициализация матрицы
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
/// Удаление матрицы  
/// </summary>
/// <param name="matrix"> Матрциа </param>
/// <param name="size"> Размер матрицы </param>
void DeleteMatrix(double** matrix, int size) {
	for (int i = 0; i < size; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}
