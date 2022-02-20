#include "include/Header.h"

int main()
{
    setlocale(LC_ALL, "Ru");
    Matrix A(4, 4); // Матрица коэффициентов.
    Matrix b(4, 1); // Матрица свободных членов.
    Matrix res(4, 1);
    Matrix w(4, 1);
    double eps = 0.000001;

    // Ввод матриц.
    cout << "> Enter coefficient matrix: " << endl;
    cin >> A;
    cout << endl << "> Enter the matrix of free terms: " << endl;
    cin >> b;

    // Метод Якоби.
    cout << endl << setw(29) << "Jacobi Method: " << endl << endl;
    res = jacobiMethod(A, b, eps);
    cout << "> Result" << endl << res;
    w = A * res - b;
    cout << "> Residual Vector" << endl;
    cout << setprecision(8) << w;
    cout << endl;

    // Метод Гаусса-Зейделя.
    cout << endl << setw(38) << "Gauss-Seidel Method: " << endl << endl;
    res = GSMethod(A, b, eps);
    cout << "> Result" << endl << res;
    w = A * res - b;
    cout << "> Residual Vector" << endl;
    cout << setprecision(8) << w;
}
