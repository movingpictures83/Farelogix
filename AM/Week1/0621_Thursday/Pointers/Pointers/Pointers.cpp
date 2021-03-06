// Pointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int x = 4; // Stack (suppose x is at 240)
	int* y = new int; // Heap   * = "memory address"  (say, 140)
	*y = 10;   // * = "value at"    -> value at 140 gets set to 10
	delete y;
	y = &x;    // & = "address of"  -> set y equal to address of x (240)
	*y = 24;
	cout << x << endl;


	y = new int[10]; // allocates space for 10 ints, y gets its address (say, 100)
	*y = 35;         // sets first element of array to 35
	*(y + 1) = 42;   // set second element to 42
	y[2] = 47;  /// third elmeent
	y[3] = -5;

	cout << y[0] << " " << y[1] << endl;
	cout << *(y+0) << " " << *(y + 1) << endl;

	int* z = y + 2;  // sets z to address of the third element of y
	cout << z[0] << endl;  // prints the third elment of y
	cout << z[1] << endl;  // fourth elemnt of y

	delete [] y;
    return 0;
}

