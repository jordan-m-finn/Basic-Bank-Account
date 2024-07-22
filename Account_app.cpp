#include <iostream>
#include <iomanip>
#include "Jordan_Finn_Account.h" // Account class definition
#include "Jordan_Finn_SavingsAccount.h" // SavingsAccount class definition
#include "Jordan_Finn_CheckingAccount.h" // CheckingAccount class definition

using namespace std;

int main()
{
   Account account1( 50.0 ); // create Account object
   SavingsAccount account2( 25.0, .03 ); // create SavingsAccount object
   CheckingAccount account3( 80.0, 1.0 ); // create CheckingAccount object

   cout << fixed << setprecision( 2 );

   // display initial balance of each object
   cout << "account1 balance: $" << account1.getBalance() << endl;
   cout << "account2 balance: $" << account2.getBalance() << endl;
   cout << "account3 balance: $" << account3.getBalance() << endl;

   // * ADDITION FROM ASSIGNMENT 10 * * * * * * * * * * * * * * * * * 
   cout << "\nOperator overloading for Account class";
   account1 += 400;
   account1 -= 200;
   account1 = account1 + 300;
   account1 = account1 - 300;
   account1 = 300 + account1;
   Account a1 = account1;
   
   cout << a1 << endl;
   cout << "\nUpdated account1 balance: $" << a1 << endl;

   cout << "\nOperator overloading for SavingsAccount class";
   account2 += 400;
   account2 -= 200;
   account2 = account2 + 300;
   account2 = account2 - 300;
   account2 = 300 + account2;
   Account a2 = account1;

   cout << a2 << endl;
   cout << "\nUpdated account2 balance: $" << a2 << endl;

   cout << "\nOperator overloading for CheckingAccount class";
   account3 += 400;
   account3 -= 200;
   account3 = account3 + 300;
   account3 = account3 - 300;
   account3 = 300 + account3;
   Account a3 = account1;

   cout << a3 << endl;
   cout << "\nUpdated account3 balance: $" << a3 << endl;
   // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

   cout << "\nAttempting to debit $25.00 from account1." << endl;
   account1.debit( 25.0 ); // try to debit $25.00 from account1
   cout << "\nAttempting to debit $30.00 from account2." << endl;
   account2.debit( 30.0 ); // try to debit $30.00 from account2
   cout << "\nAttempting to debit $40.00 from account3." << endl;
   account3.debit( 40.0 ); // try to debit $40.00 from account3

   // display balances
   cout << "\naccount1 balance: $" << account1.getBalance() << endl;
   cout << "account2 balance: $" << account2.getBalance() << endl;
   cout << "account3 balance: $" << account3.getBalance() << endl;

   cout << "\nCrediting $40.00 to account1." << endl;
   account1.credit( 40.0 ); // credit $40.00 to account1
   cout << "\nCrediting $65.00 to account2." << endl;
   account2.credit( 65.0 ); // credit $65.00 to account2
   cout << "\nCrediting $20.00 to account3." << endl;
   account3.credit( 20.0 ); // credit $20.00 to account3

   // display balances
   cout << "\naccount1 balance: $" << account1.getBalance() << endl;
   cout << "account2 balance: $" << account2.getBalance() << endl;
   cout << "account3 balance: $" << account3.getBalance() << endl;

   // add interest to SavingsAccount object account2
   double interestEarned = account2.calculateInterest();
   cout << "\nAdding $" << interestEarned << " interest to account2." 
      << endl;
   account2.credit( interestEarned );

   cout << "\nNew account2 balance: $" << account2.getBalance() << endl;

   system("PAUSE");
   return 0;
   
}