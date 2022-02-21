#include "../include/Header.h"

/**
* Решение линейного уравнения методом Якоби.
* @param Q - матрица коэффициентов.
* @param c - матрица свободных членов.
* @param e - точность.
* @return  вектор решений.
*/
Matrix jacobiMethod(Matrix Q, Matrix c, double eps) {
	// Иницилизируем переменные.
	Matrix xn;
	Matrix xi;
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

	// Считаем норму матрицы Q и выводим её.
	double q = Q.getNorm();
	xn = c;	
	cout << "> Matrix Q" << endl;
	cout << Q;
	cout << " Norm of Matrix Q = " << q;
	cout << endl << endl;

	// Итеративным способом находим результат.
	// Формула x_i+1 = Q * x_i + c.
	do {
		cout << "> Itteration (" << k++ << "):" << endl;
		xi = Q * xn + c;
		epsM = xn - xi;
		xn = xi;
		// Промежуточные результаты для анализа.
		cout << " Xi " << endl;
		cout << setprecision(8) << xi;
		cout << " Abs " << endl;
		cout << setprecision(8) << epsM;
		cout << " Kr = ";
		cout << setprecision(8) << q / (1 - q) * epsM.getNorm() << endl << endl;
	} while (!(q / (1 - q) * epsM.getNorm() < eps));
	
	
	// Возвращаем вектор ответов.
	return xi;
}