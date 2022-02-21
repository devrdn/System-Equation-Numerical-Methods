#include "include/Header.h"


int main()
{
    setlocale(LC_ALL, "Ru");
    Matrix A(4, 4); // Матрица коэффициентов.
    Matrix b(4, 1); // Матрица свободных членов.
    Matrix res(4, 1);
    Matrix w(4, 1);
    double eps = 0.000001;

    // Ввод матрицы коэффициентов и вектора свободных членов с файла
    string path = "data/in.txt";
    ifstream fin;
    fin.open(path);
    if (fin.is_open()) {
        for (size_t i = 0; i < A.rows; i++)
            for (size_t j = 0; j < A.cols; j++)
                fin >> A.matrix[i][j];
        for (size_t i = 0; i < b.rows; i++)
            fin >> b.matrix[i][0];
    }

    // Вывод матриц.
    cout << "> Matrix A" << endl;
    cout << A << endl;
    cout << "> Vector b" << endl;
    cout << b;


    // Метод Якоби.
    cout << endl << setw(29) << "Jacobi Method: " << endl << endl;
    res = jacobiMethod(A, b, eps);
    cout << "> Result" << endl << res;
    w = A * res - b;
    cout << endl << "> Residual Vector" << endl;
    cout  << w;
    cout << endl;

    // Метод Гаусса-Зейделя.
    cout << endl << setw(38) << "Gauss-Seidel Method: " << endl << endl;
    res = GSMethod(A, b, eps);
    cout << "> Result" << endl << res;
    w = A * res - b;
    cout << endl << "> Residual Vector" << endl;
    cout <<  w;
}
