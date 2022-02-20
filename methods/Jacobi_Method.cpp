#include <iostream>
#include "../include/Header.h"

Matrix jacobiMethod(Matrix Q, Matrix c, double eps) {
	// ������������� ����������.
	Matrix xn;
	Matrix xi(c);
	Matrix epsM;
	int k = 0;

	// ���������� ������� Q � c. 
	for (size_t i = 0; i < Q.rows; i++) {
		for (size_t j = 0; j < Q.cols; j++) {
			if (i != j)
				Q.matrix[i][j] /= (-1)*Q.matrix[i][i];
		}
		c.matrix[i][0] /= Q.matrix[i][i];
		Q.matrix[i][i] = 0;
	}

	// ������� ����� ������� Q � ������� �.
	double q = Q.getNorm();
	xi = c;	
	cout << "> New Matrix A" << endl;
	cout << Q;
	cout << " Norm of Matrix A = " << q;
	cout << endl << endl;

	// ����������� �������� ������� ���������.
	// ������� x_i+1 = Q * x_i + c.
	do {
		cout << "> Itteration (" << k++ << "):" << endl;
		xn = xi;
		xi = Q * xn + c;
		epsM = xn - xi;
		// ������������� ���������� ��� �������.
		cout << " Xi " << endl;
		cout << xi;
		cout << " Abs " << endl;
		cout << epsM;
		cout << " Kr = ";
		cout << q / (1 - q) * epsM.getNorm() << endl << endl;
	} while (!(q / (1 - q) * epsM.getNorm() < eps));
	
	// ���������� ��������� �� ������ �������.
	return xi;
}