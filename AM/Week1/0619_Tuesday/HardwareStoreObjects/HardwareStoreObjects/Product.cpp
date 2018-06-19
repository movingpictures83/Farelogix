
#include "stdafx.h"
#include "Product.h" 

// Default constructor, good practice
Product::Product() {
	set("product", 0, 0);
}

// Constructor with user-specified parameters
Product::Product(string n, short q=0, float p=0) {
	set(n, q, p);
}

// Destructor
Product::~Product() {}

float Product::total() {
	return quantity*price;
}

void Product::set(string n, short q, float p) {
	name = n;
	quantity = q;
	price = p;
}