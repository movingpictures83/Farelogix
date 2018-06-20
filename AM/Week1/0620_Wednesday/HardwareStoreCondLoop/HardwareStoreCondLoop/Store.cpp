
#include "stdafx.h"
#include "Store.h"
#include "NoWeedWhackerException.h"
#include "NegativeInputException.h"
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
using std::stoi;
using std::stof;
using std::invalid_argument;
using std::out_of_range;

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

void Store::readOneProduct() {
	string n, q, p;

	try { // Try this code
		inputfile >> n >> q >> p;
		// Check for the product name
		// Short circuit evaluation -> check hasWW first
		if (!hasWW && (_strcmpi(n.c_str(), "weedwhacker") == 0))
			throw NoWeedWhackerException();
		short qnum = stoi(q.c_str());
		if (qnum < 0)
			throw InputException("quantity", n, "negative");
		for (int i = 0; i < q.length(); i++)
			if (q[i] == '.')
				throw InputException("quantity", n, "real");
		float pnum = stof(p.c_str());
		if (pnum < 0)
			throw InputException("price", n, "negative");
		//myproducts[x].set(n, q, p);

		myproducts.push_back(Product(n, qnum, pnum));
	}
	catch (invalid_argument ie) { // Characters for quantity or price
		cout << "Invalid parameters for product " << n << ": " << q << "," << p << endl;
		exit(1); // Error, terminate
	}
	catch (out_of_range re) {
		cout << "Parameters out of range for product " << n << ": " << q << "," << p << endl;
		exit(1); // Error, terminate
	}
	catch (NoWeedWhackerException nwwe) { // Non-Terminal
		cout << nwwe.what() << endl;
	}
	catch (exception& ne) { // Non-Terminal
		cout << ne.what() << endl;
		exit(1);
	}


	
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
	//short count = 0; // A
	while (!inputfile.eof()) // B
		readOneProduct(); // D
		   //count++;  // C 

	// Equivalent for
	/*for (short count = 0; !inputfile.eof(); count++)
		readOneProduct(count);*/
}

void Store::writeOneProduct(short x) {
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

	float total = 0;
	for (int i = 0; i < myproducts.size(); i++) {
		writeOneProduct(i);
		total = total + myproducts[i].total();
	}

	// Total
	outputfile.width(50);
	outputfile.flags(ios::left); // Left justify text
	outputfile << "Total";
	outputfile.width(1);
	outputfile << "$";
	outputfile.width(11);
	outputfile.flags(ios::right); // Left justify text
								  // Slower than using the totals array, but saves memory
	outputfile << fixed << total;//totals[0] + totals[1] + totals[2];
	outputfile << endl;
}

string Store::print() {
	string s = "**************** LOCATION: " + location;
	s = s + "  WEED WHACKER AVAILABILE:";
	if (hasWW) s += "YES";
	else s += "NO";
	s += "********************";
	return s;
}
