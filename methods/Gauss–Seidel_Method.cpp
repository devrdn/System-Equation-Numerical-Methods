#include "..\include\Header.h"

/**
* ������� ��������� ��������� ������� �����-������.
* @param Q - ������� �������������.
* @param c - ������� ��������� ������.
* @param e - ��������.
* @return  ������ �������.
*/
Matrix GSMethod(Matrix Q, Matrix c, double eps) {
	// ������������� ����������.
	Matrix xn;
	Matrix xi(c.rows, 1);
	Matrix epsM;
	int k = 0;

	// ���������� ������� Q � c. 
	for (size_t i = 0; i < Q.rows; i++) {
		for (size_t j = 0; j < Q.cols; j++) {
			if (i != j)
				Q.matrix[i][j] /= (-1) * Q.matrix[i][i];
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
	do {
		cout << "> Itteration (" << k++ << "):" << endl;
		for (size_t i = 0; i < Q.rows; i++) {
			xi.matrix[i][0] = 0;
			for (size_t j = 0; j < Q.rows; j++) {
				if (j >= i)
					xi.matrix[i][0] += Q(i, j) * xn(j, 0);
				else
					xi.matrix[i][0] += Q(i, j) * xi(j, 0);

			}
			xi.matrix[i][0] += c(i, 0);
		} 
		epsM = xi - xn;
		xn = xi;
		// ������������� ���������� ��� �������.
		cout << " Xi " << endl;
		cout << setprecision(8) << xi;
		cout << " Abs " << endl;
		cout << setprecision(8) << epsM;
		cout << " Kr = ";
		cout << setprecision(8) << q / (1 - q) * epsM.getNorm() << endl << endl;
	} while (!(q / (1 - q) * epsM.getNorm() < eps));

	// ����������  ������ �������.

	return xi;
}