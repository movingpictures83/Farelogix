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

template<class T>
class BioAdjList : public BioAdj<T>
{
public:
	static BioAdj<T>* make() { return new BioAdjList; }
	void print() { cout << "BIOADJLIST" << endl; }
	static Register reg;
};

