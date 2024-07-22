#include "Account.h"

#include <iostream>

Account::Account(double initialBalance)
{
	if (initialBalance >= 0.0) // could possibly be more benefitial to use a while loop?
	{
		accountBalance = initialBalance;
	}
	else
	{
		accountBalance = 0.0;
		throw std::invalid_argument("The initial balance amount you entered is invalid. The balance will be set to $0.00 by default.");
	}
}

void Account::credit(double amount)
{
	if (amount >= 0.0) // could possibly be more benefitial to use a while loop?
	{
		accountBalance += amount;
	}
	else
	{
		throw std::invalid_argument("The credit amount you entered is invalid.");
	}
}

bool Account::debit(double amount)
{
	if (amount >= 0.0 && amount <= accountBalance) // could possibly be more benefitial to use a while loop?
	{
		accountBalance -= amount;
		return true;
	}
	else
	{
		std::cout << "Debit amount exceeded account balance." << std::endl;
		return false;
	}
}

double Account::getBalance() const
{
	return accountBalance;
}