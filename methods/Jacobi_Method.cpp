#include "../include/Header.h"

/**
* ������� ��������� ��������� ������� �����.
* @param Q - ������� �������������.
* @param c - ������� ��������� ������.
* @param e - ��������.
* @return  ������ �������.
*/
Matrix jacobiMethod(Matrix Q, Matrix c, double eps) {
	// ������������� ����������.
	Matrix xn;
	Matrix xi;
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
	xn = c;	
	cout << "> Matrix Q" << endl;
	cout << Q;
	cout << " Norm of Matrix Q = " << q;
	cout << endl << endl;

	// ����������� �������� ������� ���������.
	// ������� x_i+1 = Q * x_i + c.
	do {
		cout << "> Itteration (" << k++ << "):" << endl;
		xi = Q * xn + c;
		epsM = xn - xi;
		xn = xi;
		// ������������� ���������� ��� �������.
		cout << " Xi " << endl;
		cout << setprecision(8) << xi;
		cout << " Abs " << endl;
		cout << setprecision(8) << epsM;
		cout << " Kr = ";
		cout << setprecision(8) << q / (1 - q) * epsM.getNorm() << endl << endl;
	} while (!(q / (1 - q) * epsM.getNorm() < eps));
	
	
	// ���������� ������ �������.
	return xi;
}