#pragma once

#include <exception>
using std::exception;

class NoWeedWhackerException : public exception {
public:
	const char * what() const noexcept {
		return "[WARNING] Weed whacker found in store without them in inventory, not counted, please check.";
   }
};