#pragma once

#include <vector>
using std::vector;
#include <optional>
using std::optional;
#include "Product.h"

class Store {
private:
	vector<Product> myproducts; // Revisit later, wasting one slot potentially
	string location;
	//bool hasWW;
	string path;

public:
	Store(string s, /*bool h = false,*/ string p = "C:\\Users\\student\\source\\repos\\");
	~Store();

	// Accessor Methods
	string getLocation() { return location; }
	bool has(string product);
	//bool getHasWW() { return hasWW; }
	optional<Product>  getProduct(/*int x*/string product);
	//void setProduct(int, Product);
	void setLocation(string s/*, bool*/) {location = s;}


	void print();

};