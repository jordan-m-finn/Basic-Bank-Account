#include "CheckingAccount.h"

#include <iostream>

CheckingAccount::CheckingAccount(double initialBalance, double feeAmount) : Account(initialBalance), fee(feeAmount) {}

void CheckingAccount::credit(double amount)
{
	Account::credit(amount);
}

bool CheckingAccount::debit(double amount)
{
	bool result = Account::debit(amount);
	if (result)
	{
		accountBalance -= fee;
	}
	return result;
}