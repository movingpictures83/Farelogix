// Circle2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using std::cout; // We want functionality for cout, from iostream
using std::cin;
using std::endl;

// Value should never change
#define PI 3.14159

int main()
{
	short radius;  // 2 B of RAM
	cout << "Enter a radius:";
	cin >> radius;


	// Print diameter, circumference and area
	// Efficiency: Use + before *
	short diameter = radius + radius; // Faster, but uses more memory
	cout << "Diameter:" << diameter << endl;// radius + radius;
	cout << "Circumference:" << diameter * PI << endl; // (radius + radius)*PI;
	cout << "Area:" << PI * radius*radius << endl;

	
    return 0;
}

