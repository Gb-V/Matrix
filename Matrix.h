#pragma once

int N;
short Answer;
double **A, **ResultProd;

double** StorInvM;

void InitMatrix() {
	A = new double* [N];
	for (int i = 0; i < N; i++)
		A[i] = new double[N];
	
	ResultProd = new double* [N];
	for (int i = 0; i < N; i++)
		ResultProd[i] = new double[N];
}

void ClearM(double** a, int size) {
	for (int i = 0; i < size; i++) {
		delete[] a[i];
	}
	delete[] a;
}
