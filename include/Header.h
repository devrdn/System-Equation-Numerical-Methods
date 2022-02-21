#pragma once
#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;


/**
* Решение линейного уравнения методом Якоби.
* @param Q - матрица коэффициентов.
* @param c - матрица свободных членов.
* @param e - точность.
* @return  вектор решений.
*/
Matrix jacobiMethod(Matrix Q, Matrix c, double eps);

/**
* Решение линейного уравнения методом Гауса-«ейдел¤.
* @param Q - матрица коэффициентов.
* @param c - матрица свободных членов.
* @param e - точность.
* @return  вектор решений.
*/
Matrix GSMethod(Matrix Q, Matrix c, double eps);