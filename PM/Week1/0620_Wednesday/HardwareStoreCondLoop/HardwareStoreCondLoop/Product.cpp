#include "stdafx.h"
#include "Product.h"
#include <fstream>
#include <exception>
#include <iostream>
#include "Exception.h"
using std::ifstream;
using std::ios;
using std::stoi;
using std::stof;
using std::invalid_argument;
using std::cout;
using std::endl;

Product::Product() {
	set("Unknown", 0, 0);
}

Product::Product(ifstream& infile) {
	readProduct(infile);
}

Product::~Product() {}

float Product::total() {
	return quantity * price;
}

void Product::readProduct(ifstream& infile) {
	string q, p;
	try { // Try and see if this works

		infile >> name >> q >> p;
		quantity = stoi(q);
		// Check for whole number
		for (int i = 0; i < q.length(); i++)
			if (q[i] == '.')
				throw RealQuantityException("Non-integer quantity "+q+" for product "+name);
		price = stof(p);
		if (quantity < 0)
			throw RangeException("Negative quantity " + q + " for product " + name);
		else if (price < 0)
			throw RangeException("Negative price " + p + " for product " + name);
	}

	catch (invalid_argument ie) { // Run if something goes wrong
		cout << "Invalid parameters for product " << name << ": " << q << "," << p << endl;
		exit(1);
	}

	catch (exception& e) {
		cout << e.what() << endl;
		exit(1);
	}

}

void Product::writeProduct(ofstream& outfile) {
	outfile.width(50);
	outfile.flags(ios::left);
	outfile << name;
	outfile.width(8);
	outfile.flags(ios::right);
	outfile.precision(2);
	outfile << "$" << fixed << quantity * price << endl;
}

void Product::set(string n, short q, float p) {
	name = n;
	quantity = q;
	price = p;
}