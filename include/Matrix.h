#pragma once
#include <iostream>
const unsigned int MIN_ROWS = 3;
const unsigned int MIN_COLS = 3;

using namespace std;

class Matrix
{
public:
	int rows;
	int cols;
	float** matrix;
	Matrix() : rows(0), cols(0), matrix(0) {}
	Matrix(int rows, int cols);
	Matrix(const Matrix& mat);
	~Matrix();
	double getNorm();
	void operator= (const Matrix mat);
	Matrix operator*(const Matrix& m1);
	Matrix operator-(const Matrix& m1);
	Matrix operator+(const Matrix& m1);
	float operator() (int rows, int cols);
	friend ostream& operator << (ostream& out, Matrix& mat);
	friend istream& operator >> (istream& in, Matrix& mat);
};

