#include "SavingsAccount.h"

#include <iostream>

SavingsAccount::SavingsAccount(double initialBalance, double rate) : Account(initialBalance), interestRate(rate) {}

double SavingsAccount::calculateInterest() const
{
	return (accountBalance * interestRate);
}