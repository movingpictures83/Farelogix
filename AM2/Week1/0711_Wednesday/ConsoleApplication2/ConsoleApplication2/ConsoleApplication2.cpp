// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int x = 5;
	int* w = new int();
	*w = 25;
	delete w;

	w = &x;

	cout << x << endl; // 5
	*w = 10;
	cout << x << endl; // 10

	int y[10];
	y[0] = 15;
	cout << y[0] << endl;
	*y = 35;
	cout << y[0] << endl;
	*(y + 1) = 45;
	cout << y[1] << endl;

	w = y; // w is at the start of the array
	while (w < y + 10) {
		*w = -18;
		w++; // go to next element in array
	}
	/*for (w = y; w < y + 10; w++)
		*w = -18;*/
	cout << y[8] << endl;

	int* z = &(y[4]);
	z[1] = 55;
	cout << y[5] << endl;

	//delete[] z;  ILLEGAL, cannot delete stack space

	// Array on stack
	float arr[2][3] = { {4.2, 3.5, 9.8}, {0.2, -6.7, -3.3} };
	// Type of arr is an address of a row of the array
	*(*(arr + 0) + 1) = 8;
	cout << arr[0][1] << endl;
	*(*(arr + 1) + 0) = 16;
	cout << arr[1][0] << endl;


	// Array on heap
	float** arrheap;
	arrheap = new float*[2];
	for (int i = 0; i < 2; i++)
		arrheap[i] = new float[3];

	arrheap[0][1] = 8;
	cout << arrheap[0][1] << endl;
	*(*(arrheap + 1) + 0) = 16;
	cout << arrheap[1][0] << endl;
	// Same as *(*(arrheap+0)+1) = 8;


	for (int i = 0; i < 2; i++)
		delete[] arrheap[i];
	delete[] arrheap;
	//arr[0] = *(arr+0)

    return 0;
}

