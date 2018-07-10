#include "BankAccount.h"


void BankAccount::deposit(int d, int c)
{
	int cents = balance.cents;

	balance.dollars += d;
	balance.cents += c;
	if (cents >= 100) {
		balance.dollars++;
		balance.cents -= 100;
	}
}