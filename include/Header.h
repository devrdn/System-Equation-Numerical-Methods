#pragma once
#include "Matrix.h"
#include <iomanip>

/**
* –ешение линейного уравнени€ методом якоби.
* @param Q - матрица коэффициентов.
* @param c - матрица свободных членов.
* @param e - точность.
* @return  вектор решений.
*/
Matrix jacobiMethod(Matrix Q, Matrix c, double eps);

/**
* –ешение линейного уравнени€ методом √ауса-«ейдел€.
* @param Q - матрица коэффициентов.
* @param c - матрица свободных членов.
* @param e - точность.
* @return  вектор решений.
*/
Matrix GSMethod(Matrix Q, Matrix c, double eps);