// Definition of CheckingAccount class.
#include "Jordan_Finn_CheckingAccount.h"

using namespace std;

std::ostream& operator<<(std::ostream& out, CheckingAccount& c)
{
    out << c.getBalance();
    return out;
}

CheckingAccount operator+(double amount, CheckingAccount& a)
{
    CheckingAccount a1(amount, a.transactionFee);
    a1.credit(a.getBalance());
    return a1;
}

// constructor initializes balance and interest rate
CheckingAccount::CheckingAccount(double initialBalance, double fee)
    : Account(initialBalance), transactionFee(0.0) // initialize base class
{
    if (fee >= 0.0)
        transactionFee = fee;
    else
        throw invalid_argument("Transaction fee must be >= 0.0");
} // end CheckingAccount constructor

void CheckingAccount::operator+=(double amount)
{
    credit(amount);
}

void CheckingAccount::operator-=(double amount)
{
    debit(amount);
}

CheckingAccount CheckingAccount::operator+(double amount)
{
    CheckingAccount a(getBalance(), transactionFee);
    a.credit(amount);
    return a;
}

CheckingAccount CheckingAccount::operator+(CheckingAccount& a)
{
    CheckingAccount a1(getBalance(), transactionFee);
    a1.credit(a.getBalance());
    return a1;
}

CheckingAccount CheckingAccount::operator-(double amount)
{
    CheckingAccount a(getBalance(), transactionFee);
    a.debit(amount);
    return a;
}

void CheckingAccount::operator=(const CheckingAccount& a)
{
    memcpy(this, &a, sizeof(CheckingAccount));
}

//charge the transaction fee and update balance
void CheckingAccount::chargeFee()
{
    Account::debit(transactionFee);
} // end function chargeFee

void CheckingAccount::credit(double amount)
{
    if (amount < 0)
    {
        cout << "Credit amount can't be negative." << endl;
        return;
    }

    Account::credit(amount);
    double balance = getBalance();
    if (balance - transactionFee < 0)
    {
        cout << "Transaction fee is more than the net balance." << endl;
        return;
    }

    chargeFee();
} // end function credit

// debit (subtract) an amount from the account balance
// return bool indicating whether money was debited
bool CheckingAccount::debit(double amount)
{
    if (!Account::debit(amount)) // debit amount exceeds balance
    {
        //cout << "Debit amount exceeded account balance." << endl;
        return false;
    } // end if

    // debit amount does not exceed balance
    double balance = getBalance();
    if (balance - transactionFee < 0)
    {
        cout << "Transaction fee is more than the net balance." << endl;
        return false;
    }

    chargeFee();
    return true;
}