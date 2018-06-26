#pragma once

#include "Factory.h"

#include <string>
using std::string;

struct Register
{
	// name="B"  checkType= address of B::checkType
	Register(string name, void* checkType)
	{
		Factory::RegisterType(name, checkType);
	}
};