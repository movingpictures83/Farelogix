
#include "stdafx.h"
#include "Store.h"


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

Store::Store() {
	set(false, "default");
}

Store::Store(bool h, string l) {
	set(h, l);
}

Store::~Store() {}

void Store::setProduct(int x, Product p) { myproducts[x] = p; }
void Store::set(bool h, string l, string p) {
	hasWW = h;
	location = l;
	path = p;
}

void Store::readOneProduct(int x) {
	string n;
	short q;
	float p;

	inputfile >> n;
	inputfile >> q;
	inputfile >> p;
	myproducts[x].set(n, q, p);
}

void Store::readFile() {
	cout << "Enter your input file name for location:" << location << ":";
	string filename;
	cin >> filename;
	filename.insert(0, path);
	
	// Open the file
	inputfile = ifstream(filename, ios::in); // Input mode only
	if (inputfile.fail()) cout << "ERROR" << endl;

	// First line
	readOneProduct(0);
	readOneProduct(1);
	readOneProduct(2);
	if (hasWW) readOneProduct(3);

}

void Store::writeOneProduct(int x) {
	outputfile.width(50);
	outputfile.flags(ios::left); // Left justify text
	outputfile << myproducts[x].getName();
	outputfile.width(1);
	outputfile << "$";
	outputfile.flags(ios::right); // Left justify text
	outputfile.width(11);
	outputfile << fixed << myproducts[x].total();//totals[0];
	outputfile << endl;
}

void Store::writeFile() {	
	cout << "Enter your output file name for location:" << location << ":";
	string outputfilename;
	cin >> outputfilename;
	outputfilename.insert(0, path);

	outputfile = ofstream(outputfilename, ios::out); // Output mode only
												   // Column width = 50
	outputfile << print() << endl;
	outputfile.flags(ios::left); // Left justify text
	outputfile.precision(2); // Two digits of precision
	outputfile.width(50);
	outputfile << "Product";
	outputfile.flags(ios::right); // Left justify text
	outputfile.width(11);
	outputfile << "Total Sales" << endl;
	outputfile << endl;

	writeOneProduct(0);
	writeOneProduct(1);
	writeOneProduct(2);
	if (hasWW) writeOneProduct(3);

	// Total
	outputfile.width(50);
	outputfile.flags(ios::left); // Left justify text
	outputfile << "Total";
	outputfile.width(1);
	outputfile << "$";
	outputfile.width(11);
	outputfile.flags(ios::right); // Left justify text
								  // Slower than using the totals array, but saves memory
	outputfile << fixed << myproducts[0].total() + myproducts[1].total() + myproducts[2].total() + myproducts[3].total();//totals[0] + totals[1] + totals[2];
	outputfile << endl;
}

string Store::print() {
	string s =  "**************** LOCATION: " + location;
	s = s + "  WEED WHACKER AVAILABILE:";
	if (hasWW) s += "YES";
	else s += "NO";
	s += "********************";
	return s;
}
