#pragma once

#pragma once 

#include "Product.h"
#include <fstream>
#include <vector>
using std::ifstream;
using std::ofstream;
using std::vector;

class Store {
private:
	vector<Product> myproducts;
	//Product myproducts[4]; // Update later when we use pointers, wastes space for now
	bool hasWW;
	string location;
	ifstream inputfile;
	ofstream outputfile;
	string path;
	void readOneProduct();
	void writeOneProduct(short);
	string print();
public:
	Store();
	Store(bool, string);
	~Store();

	// Accessor Methods
	bool getHasWW() { return hasWW; }
	string getLocation() { return location; }
	Product getProduct(int x) { return myproducts[x]; }
	void setProduct(int x, Product p);
	void set(bool, string, string p = "C:\\Users\\student\\source\\repos\\");

	void readFile();
	void writeFile();

};