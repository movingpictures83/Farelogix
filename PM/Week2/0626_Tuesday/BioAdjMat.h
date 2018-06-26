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



class BioAdjMat : public BioAdj<>
{
public:
	static BioAdj<>* make() { return new BioAdjMat; }
	void print() { cout << "BIOADJMAT" << endl; }
	static Register reg;

};
