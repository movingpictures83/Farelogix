#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <numeric>
#include <optional>
#include "Store.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ios;
using std::fixed;
using std::ofstream;
using std::accumulate;
using std::optional;
using std::nullopt;

// Default parameter
Store::Store(string s/*, bool h,*/, string p) {
	setLocation(s/*, h*/);
	path = p;
	// Read from a file
	// Get inputfile from the user
	string inputfile;
	cout << "Enter your input file:";
	cin >> inputfile;
	inputfile = path + inputfile;

	// Open the inputfile
	ifstream infile(inputfile, ios::in); // Open only for input

										 // Temporary solution, waste of space

	while (!infile.eof()) 
		myproducts.emplace_back(infile);
	//myproducts[0].readProduct(infile);
	//myproducts[1].readProduct(infile);
	//myproducts[2].readProduct(infile);

	// Fourth possibly
	//if (hasWW) myproducts[3].readProduct(infile);
}


Store::~Store() {}

/*void Store::setProduct(int x, Product p) {
	myproducts[x] = p;
}*/

bool Store::has(string product) {
	return (getProduct(product).has_value());
}

 optional<Product> Store::getProduct(string product) {
	// Linear Search
	for (int i = 0; i < myproducts.size(); i++)
		if (_strcmpi(myproducts[i].getName().c_str(), product.c_str()) == 0)
			return optional<Product>{myproducts[i]};
	return nullopt;
}

void Store::print() {
	// Get outputfile from the user
	string outputfile;
	cout << "Enter your output file:";
	cin >> outputfile;
	outputfile = path + outputfile;

	// Open the outputfile
	ofstream outfile(outputfile, ios::out);

	// Output
	// First Line
	// Revisit later, operator overloading w/ accumulate
	float total = 0;
	for (int i = 0; i < myproducts.size(); i++) {
		myproducts[i].writeProduct(outfile);
		total = total + myproducts[i].total();
	}

	// Print the Total
	outfile.width(50);
	outfile.flags(ios::left);
	outfile << "Total Sales";
	outfile.width(8);
	outfile.flags(ios::right);
	
	outfile << "$" << fixed << total << endl;
}

