#pragma once
#include <iostream> 
#include <iomanip>
using namespace std;

/// <summary>
/// Заполнение квадратной матрицы с клавиатуры
/// </summary>
/// <param name="a"></param>
/// <param name="size"></param>
void FillByHand(double** a, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Cтрока " << i + 1 << ": ";
		for (int j = 0; j < size; j++) {
			cin >> a[i][j];
		}
	}
}

/// <summary>
/// Заполнение квадратной матрицы случайными числами
/// </summary>
/// <param name="a"> Матрица </param>
/// <param name="size"> Размер матрицы </param>
void FillRandom(double** a, int size) { 
	int down = -2, up = 5;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			a[i][j] = down + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (up - down)));
		}
	}
}

/// <summary>
/// Заполнение квадратной матрицы последовательностью натуральных чисел
/// </summary>
/// <param name="a"> Матрица </param>
/// <param name="size"> Размер матрицы </param>
void FillNatSequence(double** a, int size) {
	int k = 1;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			a[i][j] = k++;
		}
	}
}

/// <summary>
/// Вывод матрицы в консоль
/// </summary>
/// <param name="matrix"> Матрица </param>
/// <param name="size"> Размер матрицы </param>
void ShowMatrix(double** matrix, int size) {
	cout << endl << "     №    ";
	for (int i = 1; i <= size; i++)
		cout << setw(13) << i;
	for (int i = 0; i < size; i++) {
		cout << endl << "Cтрока " << i + 1 << ": ";
		for (int j = 0; j < size; j++)
			cout << setw(13) <<fixed<<setprecision(3)<< matrix[i][j];
	}
	cout << endl;
}