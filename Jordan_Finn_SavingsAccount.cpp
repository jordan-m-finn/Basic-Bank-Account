#include "Jordan_Finn_SavingsAccount.h"

#include <iostream>

using namespace std;

std::ostream& operator<<(std::ostream& out, SavingsAccount& c)
{
    out << c.getBalance();
    return out;
}

SavingsAccount operator+(double amount, SavingsAccount& a)
{
    SavingsAccount a1(amount, a.interestRate);
    a1.credit(a.getBalance());
    return a1;
}


// constructor initializes balance and interest rate
SavingsAccount::SavingsAccount(double initialBalance, double rate)
    : Account(initialBalance), interestRate(0.0) // initialize base class
{
    if (rate >= 0.0)
        interestRate = rate;
    else
        throw invalid_argument("Interest rate must be >= 0.0");
} // end SavingsAccount constructor


void SavingsAccount::operator+=(double amount)
{
    credit(amount);
}

void SavingsAccount::operator-=(double amount)
{
    debit(amount);
}

SavingsAccount SavingsAccount::operator+(double amount)
{
    SavingsAccount a(getBalance(), interestRate);
    a.credit(amount);
    return a;
}

SavingsAccount SavingsAccount::operator+(SavingsAccount& a)
{
    SavingsAccount a1(getBalance(), interestRate);
    a1.credit(a.getBalance());
    return a1;
}

SavingsAccount SavingsAccount::operator-(double amount)
{
    SavingsAccount a(getBalance(), interestRate);
    a.debit(amount);
    return a;
}

void SavingsAccount::operator=(const SavingsAccount& a)
{
    memcpy(this, &a, sizeof(SavingsAccount));
}

// return the amount of interest earned
double SavingsAccount::calculateInterest()
{
    return getBalance() * interestRate;
} // end function calculateInterest