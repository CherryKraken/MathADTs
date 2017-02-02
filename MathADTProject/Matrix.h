#pragma once
#include <vector>
#include <iostream>

using namespace std;


class Matrix
{
	vector<vector<double>> matrix;

public:
	// Constructors
	void initialize();
	void initialize(int xsize, int ysize);

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
	friend ostream& operator<<(ostream& os, const Matrix& m);
};
