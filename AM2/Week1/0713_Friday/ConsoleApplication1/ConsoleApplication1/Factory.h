#pragma once

#include <string>
#include <functional>
#include <unordered_map>
using std::string;
using std::function;
using std::unordered_map;

#include "BioAdj.h"

class Factory {
private:
	Factory() { instanceFlag = false; }
	static bool instanceFlag;
	static Factory* instance;
	unordered_map<string, BioAdj* (*) ()> stuff;
public:
	~Factory() { instanceFlag = false; }
	void addMapping(string s, BioAdj* (*f) ()) { stuff[s] = f;}
	static Factory* getInstance();
	BioAdj* create(string s);
};

