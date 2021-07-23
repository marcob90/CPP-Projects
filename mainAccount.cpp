#include <iostream>
#include "Account.h"

using namespace std;

int main()
{
	Account account1( 873.45 );
	cout << "Balance of Account 1 is equal to: " << account1.getBalance() << "$" << endl;
	
	cout << "Deposit of 44.00$ on Account 1" << endl;
	account1.credit( 44.00 );
	
	cout << "New balance is " << account1.getBalance() << "$" << endl;
	
	cout << "Withdraw of 124.75$ on Account 1" << endl;
	account1.debit( 124.75 );
	
	cout << "New balance is " << account1.getBalance() << "$" << endl;
	cout << endl;
	
	Account account2( -2398.90 );
	cout << "Balance of Account 2 is equal to: " << account2.getBalance() << "$" << endl;
	
	cout << "Deposit of 645.82$ on Account 2" << endl;
	account2.credit( 645.82 );
	
	cout << "New balance is " << account2.getBalance() << "$" << endl;
	
	cout << "Withdraw of 987.90$ on Account 2" << endl;
	account2.debit( 987.90 );
	
	cout << "New balance is " << account2.getBalance() << "$" << endl;
	cout << endl;
}
