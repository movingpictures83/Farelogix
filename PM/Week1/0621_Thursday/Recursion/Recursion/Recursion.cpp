// Recursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using std::cout;
using std::endl;

// O(n) time
int fact(int x) {
	if (x == 1) return 1;
	else return x * fact(x - 1);
}

// O(n) time
int factIter(int x) {
	int prod = 1;
	for (int i = x; i >= 1; i--)
		prod = prod * i;
	return prod;
}

// O(2^n) time
int fib(int n) {
	if (n == 1) return 1;
	else if (n == 2) return 1;
	else
		return fib(n - 1) + fib(n - 2);
}

// O(n) time
int fibIter(int n) {
	int oneBefore = 1;
	int twoBefore = 1;
	int value = 1;
	for (int i = 3; i <= n; i++)
	{
		value = oneBefore + twoBefore;
		twoBefore = oneBefore;
		oneBefore = value;
	}
	return value;
}


int main()
{
	cout << fact(4) << endl;
	cout << factIter(4) << endl;
	cout << fib(5) << endl;
	cout << fibIter(5) << endl;
	return 0;
}

