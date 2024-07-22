#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account
{
private:
	double fee;

public:
	// constructor
	CheckingAccount(double initialBalance, double feeAmount);

	void credit(double amount) override;
	bool debit(double amount) override;
};

#endif