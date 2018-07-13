#include "stdafx.h"
#include "Factory.h"

bool Factory::instanceFlag = false;
Factory* Factory::instance = NULL;


BioAdj* Factory::create(string s) {
	return stuff[s]();
}

Factory* Factory::getInstance() {
	if (!instanceFlag) {
		instance = new Factory();
		instanceFlag = true;
		return instance;
	}
	else
		return instance;
}
