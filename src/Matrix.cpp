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


Matrix::Matrix(const Matrix& mat)
{
	this->rows = mat.rows;
	this->cols = mat.cols;
	this->matrix = new float* [mat.rows];
	for (size_t i = 0; i < mat.rows; i++)
		this->matrix[i] = new float[mat.cols];
	for (size_t i = 0; i < mat.rows; i++)
		for (size_t j = 0; j < mat.cols; j++)
			this->matrix[i][j] = mat.matrix[i][j];
}

Matrix::~Matrix()
{
	for (size_t i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
}

void Matrix::operator=(const Matrix mat)
{
	if (this->rows != mat.rows || this->cols != mat.cols) {
		// освобождение пам€ти в левом операнде
		this->~Matrix();
		// выделение пам€ти в левом операнде
		this->rows = mat.rows;
		this->cols = mat.cols;
		this->matrix = new float* [mat.rows];
		for (size_t i = 0; i < mat.rows; i++)
			this->matrix[i] = new float[mat.cols];
	}
	// копирование данных правого операнда в левый
	for (size_t i = 0; i < mat.rows; i++)
		for (size_t j = 0; j < mat.cols; j++)
			this->matrix[i][j] = mat.matrix[i][j];
}


Matrix Matrix::operator*(const Matrix& m1)
{
	// создаем результирующую матрицу.
	Matrix temp(this->rows, m1.cols);
	if (this->rows != m1.rows)
		throw "Invalid rows!";
	// заполн€ем матрицу результат.
	for (size_t i = 0; i < this->rows; i++) {
		for (size_t j = 0; j < m1.cols; j++) {
			temp.matrix[i][j] = 0;
			for (size_t k = 0; k < this->cols; k++) {
				temp.matrix[i][j] += this->matrix[i][k] * m1.matrix[k][j];
			}
		}
	}
	return temp;
}

float Matrix::operator()(int rows, int cols)
{
	if (rows >= this->rows || cols >= this->cols)
		throw "Matrix subscript out of bounds";
	return 0.0f;
}

ostream& operator<<(ostream& out, Matrix& mat)
{
	ios state(nullptr);
	state.copyfmt(out);
	for (size_t i = 0; i < mat.rows; i++) {
		for (size_t j = 0; j < mat.cols; j++) {
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




