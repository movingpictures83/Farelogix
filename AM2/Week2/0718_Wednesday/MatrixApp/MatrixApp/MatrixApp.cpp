// MatrixApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matrix.h"

#include <iostream>
using std::cout;
using std::endl;

typedef Matrix<int> iMat;

int main()
{
	iMat M(2, 2);
	iMat N(2, 2);

	// Initialize M
	// M = |4 2|
	//     |7 5|
	// Uses operator()
	M(0, 0) = 4;
	M(0, 1) = 2;
	M(1, 0) = 7;
	M(1, 1) = 5;

	// Initialize N
	// N = |3 8|
	//     |1 9|
	N(0, 0) = 3;
	N(0, 1) = 8;
	N(1, 0) = 1;
	N(1, 1) = 9;
	
	// Set P = M + N
	// P = |7 10|
	//     |8 14|
	// Uses operator+ and operator=
	Matrix<int> P(2, 2);
	P = M + N;
	
	// Print P
	// Uses operator<<
	cout << P << endl;

	const Matrix<int> Q(M);
	const Matrix<int> R(N);

	const Matrix<int> S = Q + R;
	cout << S(0, 0) << endl;
	cout << S << endl;
	
	Matrix<int> T(1, 1);
	T(0, 0) = 3;
	Matrix<int> U = S + T;
    return 0;
}

