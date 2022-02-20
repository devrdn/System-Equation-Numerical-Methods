#include "..\include\Matrix.h"
#include <iomanip>


Matrix::Matrix(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	matrix = new float* [rows];
	for (size_t i = 0; i < rows; i++) {
		matrix[i] = new float[cols];
	}
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
			this->matrix[i][j] = 0;
}

Matrix::~Matrix()
{
	for (size_t i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
}

ostream& operator<<(ostream& out, Matrix& mat)
{
	ios state(nullptr);
	state.copyfmt(out);
	for (size_t i = 0; i < mat.rows; i++) {
		for (size_t j = 0; j < mat.rows; j++) {
			out << setw(5)
				<< fixed
				<< setprecision(1)
				<< mat.matrix[i][j];
		}
		out << endl;
	}
	cout.copyfmt(state);
    return out;
}

istream& operator>>(istream& in, Matrix& mat)
{
	for (size_t i = 0; i < mat.rows; i++)
		for (size_t j = 0; j < mat.cols; j++)
			in >> mat.matrix[i][j];
	return in;
}




