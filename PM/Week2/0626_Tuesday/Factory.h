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
public:
	~Factory() { instanceFlag = false; }
	unordered_map<string, BioAdj* (*) ()> stuff;

	static bool instanceFlag;
	static Factory* instance;
	static Factory* getInstance();
	template<class T> BioAdj<T>* create();
};

template<class T>
BioAdj<T> Factory::create(string s) {
	return stuff[s];
}