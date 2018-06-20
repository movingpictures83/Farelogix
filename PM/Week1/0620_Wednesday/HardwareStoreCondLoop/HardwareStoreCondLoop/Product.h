#pragma once

#include <string>
#include <fstream>
using std::string;
using std::ifstream;
using std::ofstream;
using std::fixed;
using std::endl;

class Product {
private:
	string name;
	short quantity;
	float price;

public:
	Product();
	Product(ifstream&);
	~Product();
	float total();

	// Accessor Methods
	string getName() { return name; }
	short getQuantity() { return quantity; }
	float getPrice() { return price; }
	void set(string, short, float);

	// I/O
	void readProduct(ifstream&);
	void writeProduct(ofstream&);
};