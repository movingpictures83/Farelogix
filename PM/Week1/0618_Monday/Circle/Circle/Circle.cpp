// Circle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#define PI 3.14159   // Never changes

int main()
{
	// Get the radius of a circle from the user
	unsigned short radius; // 2 B of RAM
	cout << "Enter a radius:";
	cin >> radius;

	// Print the diameter, circumference, and area
	short diameter = radius + radius; // 2 B
	cout << "Diameter: " << diameter << endl; //(radius + radius) << endl; 
							// + faster than *
	cout << "Circumference: " << PI * diameter << endl; // (radius + radius) << endl;
	cout << "Area:" << PI * radius * radius << endl;


    return 0;
}

