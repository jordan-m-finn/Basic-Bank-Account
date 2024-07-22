#include "Jordan_Finn_Account.h"

#include <stdexcept>
#include <iostream>

using namespace std;

std::ostream& operator<<(std::ostream& out, Account& c)
{
    out << c.getBalance();
    return out;
}

Account operator+(double amount, Account& a)
{
    Account a1(amount);
    a1.credit(a.getBalance());
    return a1;
}

void Account::operator+=(double amount)
{
    credit(amount);
}

void Account::operator-=(double amount)
{
    debit(amount);
}

Account Account::operator+(double amount)
{
    Account a(getBalance());
    a.credit(amount);
    return a;
}

Account Account::operator+(Account& a)
{
    Account a1(getBalance());
    a1.credit(a.getBalance());
    return a1;
}

Account Account::operator-(double amount)
{
    Account a(getBalance());
    a.debit(amount);
    return a;
}

void Account::operator=(const Account& a)
{
    memcpy(this, &a, sizeof(Account));
}

// Account constructor initializes data member balance
Account::Account(double initialBalance)
    : balance(0.0)
{
    // if initialBalance is greater than or equal to 0.0, set this value
    // as the balance of the Account
    if (initialBalance >= 0.0)
        balance = initialBalance;
    else
        throw invalid_argument("Initial balance cannot be negative");
} // end Account constructor

// credit (add) an amount to the account balance
void Account::credit(double amount)
{
    if (amount < 0)
    {
        cout << "Credit amount can't be negative." << endl;
        return;
    }
    balance = balance + amount; // add amount to balance
} // end function credit

// debit (subtract) an amount from the account balance
// return bool indicating whether money was debited
bool Account::debit(double amount)
{
    if (amount > balance) // debit amount exceeds balance
    {
        cout << "Debit amount exceeded account balance." << endl;
        return false;
    } // end if
    else // debit amount does not exceed balance
    {
        balance = balance - amount;
        return true;
    } // end else
}

// set the account balance
void Account::setBalance(double newBalance)
{
    balance = newBalance;
} // end function setBalance

// return the account balance
double Account::getBalance()
{
    return balance;
} // end function getBalance