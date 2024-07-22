#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

class Account
{
private:

	double balance; // data member that stores the balance

public:
	Account(double); // constructor initializes balance

	friend std::ostream& operator<<(std::ostream& out, Account& c);

	friend Account operator+(double amount, Account& a);

	void operator+=(double amount);
	void operator-=(double amount);
	Account operator+(double amount);
	Account operator+(Account& a);
	Account operator-(double amount);
	void operator=(const Account& a);

	void credit(double); // add an amount to the account balance
	bool debit(double); // subtract an amount from the account balance
	void setBalance(double); // sets the account balance
	double getBalance(); // return the account balance


};

#endif