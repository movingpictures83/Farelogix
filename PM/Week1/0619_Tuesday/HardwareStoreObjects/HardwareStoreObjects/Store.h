#pragma once

#include "Product.h"

class Store {
private:
	Product myproducts[4]; // Revisit later, wasting one slot potentially
	string location;
	bool hasWW;
	string path;

public:
	Store(string s, bool h=false, string p = "C:\\Users\\student\\source\\repos\\");
	~Store();

	// Accessor Methods
	string getLocation() { return location; }
	bool getHasWW() { return hasWW; }
	Product getProduct(int x) { return myproducts[x]; }
	void setProduct(int, Product);
	void set(string, bool);


	void print();

};