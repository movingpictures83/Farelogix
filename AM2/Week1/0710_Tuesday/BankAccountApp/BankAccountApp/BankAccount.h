#pragma once

#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

struct Customer {
	string first;
	string last;
};

struct Money {
	int dollars;
	int cents;
};

class BankAccount {
private: // Only accessible within the class
	Customer name;
	Money balance;

public: // Accessible anywhere
	void deposit(int d, int c);
	void withdraw(int d);
	void printBalance() { cout << "$" << balance.dollars << "." << balance.cents; } // Inline
};