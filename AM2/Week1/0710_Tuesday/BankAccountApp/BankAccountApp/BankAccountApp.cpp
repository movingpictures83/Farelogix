// BankAccountApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BankAccount.h"

#include <string>
using std::string;

int main()
{/*
	string first = "Trevor";
	string last = "Cickovski";
	int dollars = 500;
	int cents = 25;


	string first2 = "Manny";
	string last2 = "Gallardo";
	int dollars2 = 1000;
	int cents = 35;*/

	BankAccount mine;
	BankAccount manny;
	mine.deposit(5, 85);
	manny.deposit(6, 25);
	mine.dollars -= 10;
	mine.withdraw(10);
	f(&mine);

    return 0;
}

