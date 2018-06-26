#pragma once

#pragma once

#include <map>
#include <string>
#include <iostream>
using std::map;
using std::string;
using std::cout;
using std::endl;

#include "Register.h"
#include "BioAdj.h"

class BioAdjList : public BioAdj
{
public:
	static BioAdj* make() { return new BioAdjList; }
	void print() { cout << "BIOADJLIST" << endl; }
	static Register reg;
};

Register BioAdjList::reg = Register(string("BioAdjList"), &BioAdjList::make);