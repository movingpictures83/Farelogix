#pragma once

#include <string>
using std::string;

class BioNode {
private:
	string name;
	BioNode* next;
public:
	BioNode(string s, BioNode* n) : name(s), next(n) {}
    // Accessor Methods
	string getName() { return name; }
	void setName(string s) { name = s; }
	BioNode* getNext() { return next; }
	void setNext(BioNode* n) { next = n; }
};