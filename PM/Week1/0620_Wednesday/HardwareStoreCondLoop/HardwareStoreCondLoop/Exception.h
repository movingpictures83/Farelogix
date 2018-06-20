#pragma once

#include <exception>
using std::exception;

#include <string>
using std::string;

class TerminalException : public exception {
private:
	string msg;
public:
	TerminalException(string m) : msg(m) {}
	const char* what() const {
		return msg.c_str();
	}
};

class RealQuantityException : public TerminalException {
public:
	RealQuantityException(string m) : TerminalException(m) {}
};

class RangeException : public TerminalException {
public:
	RangeException(string m) : TerminalException(m) {}
};



