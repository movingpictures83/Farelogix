#pragma once

#include <string>
#include <exception>
using std::exception;
using std::string;

class InputException : public exception {
private:
	string value;
public:
	InputException(string k, string p, string t) {
	    value = "[ERROR] " + t + " value for " + k + " on product " + p;
	}
	const char * what() const throw()  {
		return value.c_str();
	}
};