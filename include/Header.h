#pragma once
#include "Matrix.h"
#include <iomanip>

/**
* ������� ��������� ��������� ������� �����.
* @param Q - ������� �������������.
* @param c - ������� ��������� ������.
* @param e - ��������.
* @return  ������ �������.
*/
Matrix jacobiMethod(Matrix Q, Matrix c, double eps);

/**
* ������� ��������� ��������� ������� �����-�������.
* @param Q - ������� �������������.
* @param c - ������� ��������� ������.
* @param e - ��������.
* @return  ������ �������.
*/
Matrix GSMethod(Matrix Q, Matrix c, double eps);