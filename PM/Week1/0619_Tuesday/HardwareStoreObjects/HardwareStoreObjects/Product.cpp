#include "stdafx.h"
#include "Product.h"
#include <fstream>
using std::ifstream;
using std::ios;

Product::Product() {
	set("Unknown", 0, 0);
}

Product::~Product() {}

float Product::total() {
	return quantity * price;
}

void Product::readProduct(ifstream& infile) {
	infile >> name >> quantity >> price;
}

void Product::writeProduct(ofstream& outfile) {
	outfile.width(50);
	outfile.flags(ios::left);
	outfile << name;
	outfile.width(8);
	outfile.flags(ios::right);
	outfile.precision(2);
	outfile << "$" << fixed << quantity*price << endl;
}

void Product::set(string n, short q, float p) {
	name = n;
	quantity = q;
	price = p;
}