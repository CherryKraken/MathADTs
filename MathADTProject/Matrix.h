#pragma once
#include <vector>
#include <iostream>
#include <exception>

using namespace std;


class Matrix
{
	vector<vector<int>> matrix;

public:
	// Constructors
	void initialize(int xsize, int ysize);

	// Operators
	Matrix operator+(const Matrix& other);
	Matrix operator*(const Matrix& other);
	Matrix operator*(const int& other);
	Matrix operator-(const Matrix& other);
	Matrix operator/(const Matrix& other);
	Matrix operator/(const int& other);

	// Methods
	bool isEmpty() const;
	int getX() const;
	int getY() const;

	// Friends
	friend ostream& operator<<(ostream& os, const Matrix& m);
};