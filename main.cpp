#include <iostream>
#include <vector>
#include "include/Header.h"
int main()
{
    setlocale(LC_ALL, "Ru");
    Matrix A(4, 4); // Матрица коэффициентов.
    Matrix b(4, 1); // Матрица свободных членов.
    Matrix res(4, 1);
    double eps = 0.000001;

    // Ввод матриц.
    cout << "> Enter coefficient matrix: " << endl;
    cin >> A;
    cout << endl << "> Enter the matrix of free terms: " << endl;
    cin >> b;

    // Метод Якоби.
    cout << endl << setw(20) << "Jacobi Method: " << endl << endl;
    res = jacobiMethod(A, b, eps);
    cout << "> Result" << endl << res;

    // Метод Гаусса-Зейделя.
    cout << endl << setw(20) << "Gauss-Seidel Method: " << endl << endl;
    res = GSMethod(A, b, eps);
    cout << "> Result" << endl << res;
}
