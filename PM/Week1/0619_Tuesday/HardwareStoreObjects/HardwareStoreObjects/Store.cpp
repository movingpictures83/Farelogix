#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Store.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ios;
using std::fixed;
using std::ofstream;

// Default parameter
Store::Store(string s, bool h, string p) {
	set(s, h);
	path = p;
	// Read from a file
	// Get inputfile from the user
	string inputfile;
	cout << "Enter your input file:";
	cin >> inputfile;
	inputfile =  path + inputfile;

	// Open the inputfile
	ifstream infile(inputfile, ios::in); // Open only for input

										 // Temporary solution, waste of space
	
	myproducts[0].readProduct(infile);
	myproducts[1].readProduct(infile);
	myproducts[2].readProduct(infile);

	// Fourth possibly
	if (hasWW) myproducts[3].readProduct(infile);
}

void Store::set(string s, bool h) {
	location = s;
	hasWW = h;
}

Store::~Store() {}

void Store::setProduct(int x, Product p) {
	myproducts[x] = p;
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
	myproducts[0].writeProduct(outfile);
	myproducts[1].writeProduct(outfile);
	myproducts[2].writeProduct(outfile);
	if (hasWW)
		myproducts[3].writeProduct(outfile);

	// Print the Total
	outfile.width(50);
	outfile.flags(ios::left);
	outfile << "Total Sales";
	outfile.width(8);
	outfile.flags(ios::right);
	outfile << "$" << fixed << myproducts[0].total() + myproducts[1].total() + myproducts[2].total() + myproducts[3].total() << endl;
}

