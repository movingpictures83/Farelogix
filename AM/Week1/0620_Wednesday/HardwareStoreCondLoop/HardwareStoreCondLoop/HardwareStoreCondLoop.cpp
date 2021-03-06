// HardwareStore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>
using std::string;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::cin;
using std::endl;
using std::ios;
using std::fixed;

//#include "Product.h"
#include "Store.h"

// Object, use capital letters
/*struct Product {
string name;
short quantity;
float price;
};*/


int main()
{
	// Read File
	// Arrays
	//Product myproducts[3];
	Store s1(true, "Kendall");
	Store s2(false, "Miramar");

	//float totals[3];
	// Get input file name

	s1.readFile();
	////////////////////////////////////////////////////////////
	// TEST FOR FILE READING
	////////////////////////////////////////////////////////////
	float eps =  0.0000000001f;
	if (s1.getProduct(0).getName().compare("Lawnmower") != 0 || s1.getProduct(0).getQuantity() != 5 || (s1.getProduct(0).getPrice() > 129.99 - eps && s1.getProduct(0).getPrice() < 129.99 + eps))
	{
		cout << "File Reading Failed.  Product: " << (s1.getProduct(0).getName().compare("Lawnmower") == 0) << " Quantity: " << (s1.getProduct(0).getQuantity() == 5) << " Price: " << (s1.getProduct(0).getPrice() == 129.99) << endl;
	}

	s2.readFile();

	s1.writeFile();
	s2.writeFile();

	return 0;
}

