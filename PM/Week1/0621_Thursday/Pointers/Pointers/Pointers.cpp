// Pointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int x = 4; // Space in the stack
	int* y = new int[10]; // Space in the heap (new)  (* = address of)
	*(y + 0) = 8;     // (* = value at)
	*(y + 1) = 16;  
	cout << y[0] << " " << y[1] << endl;
	int* z = y + 2; // z to address of the third element of y
	z[0] = 24;
	cout << y[2] << endl;

	delete y;   // deallocation in the heap

	y = &x;     // (& = address of)
	*y = 10;    // value at address y set equal to 10
	cout << x << endl;
    return 0;
}

