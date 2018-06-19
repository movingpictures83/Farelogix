
// HardwareStoreObjects.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ios;
using std::fixed;
using std::ofstream;

/*struct Product {
	string name;
	short quantity;
	float price;
};*/

#include "Store.h"


int main()
{
	Store s1("Sweetwater", true);
	Store s2("Homestead");

	s1.print();
	s2.print();

	return 0;


}


