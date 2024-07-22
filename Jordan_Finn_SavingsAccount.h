//SavingAccount.h
// Definition of SavingsAccount class.
#ifndef SAVINGS_H
#define SAVINGS_H

#include "Jordan_Finn_Account.h" // Account class definition

class SavingsAccount :public Account
{
public:
	// constructor initializes balance and interest rate
	SavingsAccount(double, double);

	friend std::ostream& operator<<(std::ostream& out, SavingsAccount& c);

	friend SavingsAccount operator+(double amount, SavingsAccount& a);


	void operator+=(double amount);
	void operator-=(double amount);
	SavingsAccount operator+(double amount);
	SavingsAccount operator+(SavingsAccount& a);
	SavingsAccount operator-(double amount);
	void operator=(const SavingsAccount& a);

	double calculateInterest(); // determine interest owed
private:
	double interestRate; // interest rate (percentage) earned by account
}; // end class SavingsAccount

#endif