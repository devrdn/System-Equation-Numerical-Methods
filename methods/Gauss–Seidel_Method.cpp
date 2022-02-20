#include "../include/Header.h"

Matrix GSMethod(Matrix Q, Matrix c, double eps) {
	// Иницилизируем переменные.
	Matrix xn;
	Matrix xi(c);
	Matrix epsM;
	int k = 0;

	// Генерируем матрицу Q и c. 
	for (size_t i = 0; i < Q.rows; i++) {
		for (size_t j = 0; j < Q.cols; j++) {
			if (i != j)
				Q.matrix[i][j] /= (-1) * Q.matrix[i][i];
		}
		c.matrix[i][0] /= Q.matrix[i][i];
		Q.matrix[i][i] = 0;
	}

	// Считаем норму матрицы Q и выводим её.
	double q = Q.getNorm();
	xi = c;
	cout << "> Matrix Q" << endl;
	cout << Q;
	cout << " Norm of Matrix Q = " << q;
	cout << endl << endl;

	// Иницилизируем переменные.
	Matrix xn;
	Matrix xi(c);
	Matrix epsM;
	int k = 0;

	// Генерируем матрицу Q и c. 
	for (size_t i = 0; i < Q.rows; i++) {
		for (size_t j = 0; j < Q.cols; j++) {
			if (i != j)
				Q.matrix[i][j] /= (-1)*Q.matrix[i][i];
		}
		c.matrix[i][0] /= Q.matrix[i][i];
		Q.matrix[i][i] = 0;
	}

	
	


}