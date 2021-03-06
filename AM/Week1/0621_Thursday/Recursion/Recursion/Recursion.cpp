// Recursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using std::cout;
using std::endl;

// O(x) time, recursive version
int factorial(int x) {
	if (x == 1) return 1; // Base Case
	else return x*factorial(x - 1); // Recursive Step
}

// O(x) time, iterative version
int factorialIter(int x) {
	int prod = x;
	for (int i = x - 1; i >= 1; i--)
		prod = prod * i;
	return prod;
}

// O(2^n)
int fib(int n) {
	if (n == 1) return 1;
	else if (n == 2) return 1;
	else return fib(n - 1) + fib(n - 2);
}

// O(n), iterative Fibonacci
int fibIter(int n) {
	int oneBefore = 1;
	int twoBefore = 1;
	if (n <= 2) return 1;
	int sum = 0;
	for (int i = 3; i <= n; i++) {
		sum = oneBefore + twoBefore;
		twoBefore = oneBefore;
		oneBefore = sum;
	}

	return sum;
}

int main()
{
	cout << factorial(4) << endl;
	cout << factorialIter(4) << endl;
	cout << fib(5) << endl;
	cout << fibIter(5) << endl;
    return 0;
}

