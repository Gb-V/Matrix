#pragma once
#include <iostream> 
#include <iomanip>
using namespace std;

/// <summary>
/// ���������� ���������� ������� � ����������
/// </summary>
/// <param name="a"></param>
/// <param name="size"></param>
void FillByHand(double** a, int size) {
	for (int i = 0; i < size; i++) {
		cout << "C����� " << i + 1 << ": ";
		for (int j = 0; j < size; j++) {
			cin >> a[i][j];
		}
	}
}

/// <summary>
/// ���������� ���������� ������� ���������� �������
/// </summary>
/// <param name="a"> ������� </param>
/// <param name="size"> ������ ������� </param>
void FillRandom(double** a, int size) { 
	int down = -2, up = 5;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			a[i][j] = down + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (up - down)));
		}
	}
}

/// <summary>
/// ���������� ���������� ������� ������������������� ����������� �����
/// </summary>
/// <param name="a"> ������� </param>
/// <param name="size"> ������ ������� </param>
void FillNatSequence(double** a, int size) {
	int k = 1;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			a[i][j] = k++;
		}
	}
}

/// <summary>
/// ����� ������� � �������
/// </summary>
/// <param name="matrix"> ������� </param>
/// <param name="size"> ������ ������� </param>
void ShowMatrix(double** matrix, int size) {
	cout << endl << "     �    ";
	for (int i = 1; i <= size; i++)
		cout << setw(13) << i;
	for (int i = 0; i < size; i++) {
		cout << endl << "C����� " << i + 1 << ": ";
		for (int j = 0; j < size; j++)
			cout << setw(13) <<fixed<<setprecision(3)<< matrix[i][j];
	}
	cout << endl;
}