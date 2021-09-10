#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "Matrix.h"
#include "MatrixIO.h"
#include "CalMatrix.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Введите размер матрицы:"; cin >> N;
	cout << "Выберите заполнение матрицы данными(1-с клавиатуры;2-генератором случайных вещественных чисел;3-натуральным рядом чисел):";
	cin >> Answer;
	InitMatrix();

	switch (Answer)
	{
	case 1: {
		cout << "Заполнение матрицы данными с клавиатуры:\n";
		FillByHand(A, N);
	}
		  break;
	case 2: {
		cout << "Заполнение матрицы данными генератором случайных вещественных чисел!\n";
		FillRandom(A, N);
	}
		  break;
	case 3: {
		cout << "Заполнение матрицы натуральным рядом чисел!\n";
		FillNatSequence(A, N);
	}
		  break;
	}
	cout << "Матрица:";
	ShowMatrix(A, N);

	if (Det(A, N) == 0) {
		cout << "\nУ этой матрицы нет обратной";
		exit(1);
	}

	cout <<"\nОбратная матрица:";
	StorInvM = matrixInverse(A,N);
	ShowMatrix(StorInvM, N);
	

	cout << "\nПроизведение прямой и обратной матриц:";
	ResultProd = matrixMult(A, StorInvM, N);
	ShowMatrix(ResultProd, N);

	cout << "\nПроизведение обратной и прямой матриц:";
	ResultProd = matrixMult(StorInvM, A, N);
	ShowMatrix(ResultProd, N);

	DeleteMatrix(A, N);
	DeleteMatrix(ResultProd, N);
	return 0;
}



