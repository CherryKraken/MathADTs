#pragma once
#include <vector>
#include <iostream>


class Matrix
{
	std::vector< std::vector<double> > matrix;
	//double **matrix;

public:
	// Constructors
	
	void init();
	void init(int xsize, int ysize);

	// Operators
	Matrix operator+(const Matrix& other);
	Matrix operator*(const Matrix& other);
	Matrix operator*(const double& other);
	Matrix operator-(const Matrix& other);
	Matrix operator/(const double& other);

	// Methods
	bool isEmpty() const;
	int getX() const;
	int getY() const;
	void transpose();

	// Friends
	friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
};
