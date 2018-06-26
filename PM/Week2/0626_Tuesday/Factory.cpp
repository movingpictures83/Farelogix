#include "stdafx.h"
#include "Factory.h"

bool Factory::instanceFlag = false;
Factory* Factory::instance = NULL;
//unordered_map<string, BioAdj*(*) ()> Factory::stuff = {};

Factory* Factory::getInstance() {
	if (!instanceFlag) {
		instance = new Factory();
		instanceFlag = true;
		return instance;
	}
	else
		return instance;
}
