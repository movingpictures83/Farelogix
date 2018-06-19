#pragma once
#include <string>
using std::string;

class Product {
private:  // Accessible only within class Product
	string name;
	short quantity;
	float price;


public:
	float total();

	// Constructor
	Product(); // Default -> called if I say Product p;
	Product(string); // Called if I say Product r("Screwdriver");
	Product(string, short, float); // Called if I say Product q("Hammer", 10, 9.99);
	~Product(); // Called when a Product loses scope

	// Accessor Methods
	string getName() { return name; }
	short getQuantity() { return quantity; }
	float getPrice() { return price; }
	void set(string, short, float); // Returns nothing
};