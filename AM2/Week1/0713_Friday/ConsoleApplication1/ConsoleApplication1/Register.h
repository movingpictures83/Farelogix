#pragma once

#include "Factory.h"

#include <string>
using std::string;

struct Register
{
	Register(string name, BioAdj* (*checkType) ())
	{
		//Factory::getInstance()->stuff[name] = checkType;
		Factory::getInstance()->addMapping(name, checkType);
	}
};