#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account
{
private:
	double interestRate; // percentage

public:
	// constructor
	SavingsAccount(double initialBalance, double rate); // are these parameters correct?

	double calculateInterest() const; // are these parameters correct?
};

#endif