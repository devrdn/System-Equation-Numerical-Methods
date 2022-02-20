#pragma once
#include <iostream>
const unsigned int MIN_ROWS = 2;
const unsigned int MIN_COLS = 2;

using namespace std;

class Matrix
{
	int rows;
	int cols;
	float** matrix;
public:
	Matrix() : Matrix(MIN_ROWS, MIN_COLS) {}
	Matrix(int rows, int cols);
	~Matrix();
	
	friend ostream& operator << (ostream& out, Matrix& mat);
	friend istream& operator >> (istream& in, Matrix& mat);
};

