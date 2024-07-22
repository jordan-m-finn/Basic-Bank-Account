#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
protected:
	double accountBalance;

public:
	// constructor
	Account(double initialBalance);

	// 3 member functions
	virtual void credit(double amount);
	virtual bool debit(double amount);
	double getBalance() const;
};

#endif