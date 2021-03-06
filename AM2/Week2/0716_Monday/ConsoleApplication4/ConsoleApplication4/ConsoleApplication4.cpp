// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;

int factorial(int n) {
	if (n == 1) return 1;
	else return n * factorial(n - 1);
}

int factiter(int n) {
	int product = 1;
	for (int i = 2; i <= n; i++)
		product = product * i;
	return product;
}

int fib(int n) {
	if (n == 1) return 1;
	else if (n == 2) return 1;
	else return fib(n - 1) + fib(n - 2);
}

int fibiter(int n) {
	int twobefore = 1;
	int onebefore = 1;
	if (n == 1) return 1;
	else if (n == 2) return 1;
	else {
		int retval;
		for (int i = 3; i <= n; i++) {
			retval = twobefore + onebefore;
			twobefore = onebefore;
			onebefore = retval;
		}
		return retval;
	}
}

int main()
{
	cout << factorial(4) << endl;
	cout << factiter(4) << endl;
	cout << fib(10) << endl;
	cout << fibiter(10) << endl;
    return 0;
}

