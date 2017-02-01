#include "Matrix.h"

/*
Initialize the matrix's 2D vector to a given size
Pre:
	xsize: int, number of columns (0 < xsize)
	ysize: int, number of rows (0 < ysize)
Post:
	matrix is an empty 2D vector of zeros
*/
void Matrix::initialize(int xsize, int ysize)
{
	this->matrix.resize(ysize);

	for(int i = 0; i < ysize; i++)
		this->matrix[i].resize(xsize);
}


/*
Overload "+" operator to add two matrices
Pre:
	other: Matrix, must have been initialized
		dimensions of this and other must match
Post:
	return a Matrix resulting from addition
*/
Matrix Matrix::operator+(const Matrix & other)
{
	if(this->isEmpty() || other.isEmpty())
		throw exception("Matrix not initialized");
	else if(this->getY() != other.getY() || this->getX() != other.getX())
		throw exception("Matrices A and B must have the same dimensions");

	for(int i = 0; i < other.getY(); i++)
		for(int j = 0; j < other.getX(); i++)
			this->matrix[i][j] += other.matrix[i][j];

	return *this;
}


/*
Overload "*" operator to multiply two matrices
Pre:
	other: Matrix, must have been initialized
		One dimension must match the reciprocal dimension of this (A_n*m  x  B_m*p)
Post:
	return a Matrix resulting from matrix multiplication
*/
Matrix Matrix::operator*(const Matrix & other)
{
	if(this->isEmpty() || other.isEmpty())
		throw exception("Matrix not initialized");
	else if(this->getX() != other.getY())
		throw exception("Swap the two matrices (A_n*m  x  B_m*p)");
	
	Matrix result;
	int sum;

	result.initialize(this->getY(), other.getX());
	
	for(int i = 0; i < this->getY(); i++)
	{
		for(int j = 0; j < other.getX(); j++)
		{
			sum = 0;
			for(int k = 0; k < other.getY(); k++)
			{
				sum += this->matrix[i][k] * other.matrix[k][j];
			}
			result.matrix[i][j] = sum;
		}
	}

	return result;
}


/*
Overload "*" operator to multiply a matrix by a real number
Pre:
	other: double
Post:
	return a Matrix resulting from real number multiplication
*/
Matrix Matrix::operator*(const double & other)
{
	if(this->isEmpty())
		throw exception("Matrix not initialized");

	for(int i = 0; i < this->getY(); i++)
		for(int j = 0; j < this->getX(); i++)
			this->matrix[i][j] *= other;

	return *this;
}


/*
Overload "-" operator to subtract two matrices
Pre:
	other: Matrix, must have been initialized
		dimensions of this and other must match
Post:
	return a Matrix resulting from subtraction
*/
Matrix Matrix::operator-(const Matrix & other)
{
	if(this->getY() != other.getY() || this->getX() != other.getX())
		throw exception("Matrices A and B must have the same dimensions");
	else if(this->isEmpty() || other.isEmpty())
		throw exception("Matrix not initialized");

	for(int i = 0; i < other.getY(); i++)
		for(int j = 0; j < other.getX(); i++)
			this->matrix[i][j] -= other.matrix[i][j];

	return *this;
}


/*
Overload "/" operator to divide a matrix by a real number
Pre:
	other: double
Post:
	return a Matrix resulting from real number division
*/
Matrix Matrix::operator/(const double & other)
{
	if(this->isEmpty())
		throw exception("Matrix not initialized");

	for(int i = 0; i < this->getY(); i++)
		for(int j = 0; j < this->getX(); i++)
			this->matrix[i][j] /= other;

	return *this;
}


/*
Checks if the 2D vector is empty
*/
bool Matrix::isEmpty() const
{
	return this->matrix.empty();
}


/*
Get the number of columns in matrix
*/
int Matrix::getX() const
{
	return matrix[0].size();
}


/*
Get the number of rows in matrix
*/
int Matrix::getY() const
{
	return matrix.size();
}


/*
Transpose matrix by inserting the elements at the inverse indices of a new array
Post:
	create a new matrix to return (can I re-initialize this to the new matrix?)
*/
Matrix Matrix::transpose()
{
	Matrix t;
	t.initialze(this->sizey, this->sizex);
	
	for(int i = 0; i < this->getY; i++)
		for(int j= 0; j < this->getX; j++)
			t.matrix[i][j] = this->matrix[j][i];
	
	return t;
}


/*
Overload the output stream operator to write the Matrix in n*m format to STDOUT
Post: (example)
	1 2
	3 4
	5 6
*/
ostream & operator<<(ostream & os, const Matrix & m)
{
	for(int i = 0; i < m.getY(); i++)
	{
		for(int j = 0; j < m.getX(); i++)
		{
			os << m.matrix[i][j] << " ";
		}
		os << endl;
	}
	return os;
}
