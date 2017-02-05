#include "Matrix.h"
#include <iomanip>
#include <exception>

//#define SIZE_OF(array) (sizeof((array))/sizeof((array[0])))

using namespace std;



/*
Initialize and fill the matrix's 2D vector from user input
Post:
	matrix is a 2D vector initialized from STDIN
*/
void Matrix::init()
{
	int ysize, xsize;
	cin >> xsize >> ysize;

	this->init(xsize, ysize);

	double val;

	for(int y = 0; y < ysize; y++)
	{
		for(int x = 0; x < xsize; x++)
		{
			cin >> val;
			this->matrix[y][x] = val;
		}
	}
}


/*
Initialize the matrix's 2D vector to a given size
Pre:
	xsize: int, number of columns (0 < xsize)
	ysize: int, number of rows (0 < ysize)
Post:
	matrix is an empty 2D vector of zeros
*/
void Matrix::init(int xsize, int ysize)
{
	this->matrix.resize(ysize);

	for(int y = 0; y < ysize; y++)
		this->matrix[y].resize(xsize);
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

	for(int y = 0; y < other.getY(); y++)
		for(int x = 0; x < other.getX(); x++)
			this->matrix[y][x] += other.matrix[y][x];

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
	result.init(this->getY(), other.getX());
	
	double sum;
	
	for(int y = 0; y < this->getY(); y++)
	{
		for(int x = 0; x < other.getX(); x++)
		{
			sum = 0.0;
			for(int k = 0; k < this->getX(); k++)
			{
				sum += this->matrix[y][k] * other.matrix[k][x];
			}
			result.matrix[y][x] = sum;
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
		for(int j = 0; j < this->getX(); j++)
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
		for(int j = 0; j < other.getX(); j++)
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
		for(int j = 0; j < this->getX(); j++)
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
	return (int) matrix[0].size();
}


/*
Get the number of rows in matrix
*/
int Matrix::getY() const
{
	return (int) matrix.size();
}


/*
Transpose matrix by inserting the elements at the inverse indices of a new array
Post:
	create a new matrix to return (can I re-initialize this to the new matrix?)
*/
void Matrix::transpose()
{
	Matrix t;
	t.init(this->getY(), this->getX());
	
	for(int i = 0; i < this->getY(); i++)
		for(int j= 0; j < this->getX(); j++)
			t.matrix[i][j] = this->matrix[j][i];
	
	*this = t;
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
	if(m.isEmpty()) throw exception("Null");

	for(int i = 0; i < m.getY(); i++)
	{
		for(int j = 0; j < m.getX(); j++)
		{
			os << setw(5) << m.matrix[i][j];
		}
		os << endl;
	}
	return os;
}
