#pragma once

#include <string>
#include <functional>
#include <unordered_map>
using std::string;
using std::function;
using std::unordered_map;

#include "BioAdj.h"

class Factory {
public:
	//name = "B", checkType = address of B::checkType
	static void RegisterType(string name,  void* checkType) { stuff[name] = (BioAdj* (*) ()) checkType; }
	static unordered_map<string,  BioAdj* (*) ()> stuff;
};

unordered_map<string, BioAdj*(*) ()> Factory::stuff = {};

#include "Supported.h"