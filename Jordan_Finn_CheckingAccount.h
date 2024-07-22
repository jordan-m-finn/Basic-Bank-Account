//CheckingAccount.cpp

// Definition of CheckingAccount class.
#ifndef CHECKING_H
#define CHECKING_H
#include "Jordan_Finn_Account.h"

class CheckingAccount : public Account
{
public:
	// constructor initializes balance and transaction fee
	CheckingAccount(double, double);

	//std::ostream &operator<<(std::ostream &out);
	friend std::ostream& operator<<(std::ostream& out, CheckingAccount& c);
	friend CheckingAccount operator+(double amount, CheckingAccount& a);

	void operator+=(double amount);
	void operator-=(double amount);
	CheckingAccount operator+(double amount);
	CheckingAccount operator+(CheckingAccount& a);
	CheckingAccount operator-(double amount);
	void operator=(const CheckingAccount& a);

	void credit(double); // redefined credit function
	bool debit(double); // redefined debit function
private:
	double transactionFee; // fee charged per transaction

	// utility function to charge fee
	void chargeFee();
}; // end class CheckingAccount

#endif