#include <iostream>
#include "Account.h"

using namespace std;

Account::Account( double amount ){
	setBalance( amount );
}
void Account::setBalance( double amount ){
	if( amount >= 0){
		balance = amount;
	}
	else{
		cout << "Balance inserted is not valid\n";
		balance = 0.0;
	}
}
double Account::getBalance(){
	return balance;
}
void Account::credit( double amount ){
	balance += amount;
}
void Account::debit( double amount ){
	if( balance >= amount ){
		balance -= amount;
	}
	else{
		cout << "Your balance is less than amount inserted\n";
	}
}
		
