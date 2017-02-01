#include "Matrix.h"

void Matrix::initialize(int xsize, int ysize)
{
	this->matrix.resize(ysize);

	for(int i = 0; i < ysize; i++)
		this->matrix[i].resize(xsize);
}


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


Matrix Matrix::operator*(const Matrix & other)
{
	if(this->isEmpty() || other.isEmpty())
		throw exception("Matrix not initialized");
	else if(this->getX() != other.getY())
		throw exception("Swap the two matrices (A_x*y  x  B_y*z");
	
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


Matrix Matrix::operator*(const double & other)
{
	if(this->isEmpty())
		throw exception("Matrix not initialized");

	for(int i = 0; i < this->getY(); i++)
		for(int j = 0; j < this->getX(); i++)
			this->matrix[i][j] *= other;

	return *this;
}


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


Matrix Matrix::operator/(const Matrix & other)
{
	return Matrix();
}


Matrix Matrix::operator/(const double & other)
{
	if(this->isEmpty())
		throw exception("Matrix not initialized");

	for(int i = 0; i < this->getY(); i++)
		for(int j = 0; j < this->getX(); i++)
			this->matrix[i][j] /= other;

	return *this;
}


bool Matrix::isEmpty() const
{
	return this->matrix.empty();
}


int Matrix::getX() const
{
	return matrix[0].size();
}


int Matrix::getY() const
{
	return matrix.size();
}


Matrix Matrix::transpose()
{
	Matrix t;
	t.initialze(this->sizey, this->sizex);
	
	for(int i = 0; i < this->getY; i++)
		for(int j= 0; j < this->getX; j++)
			t.matrix[i][j] = this->matrix[j][i];
	
	return t;
}


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
