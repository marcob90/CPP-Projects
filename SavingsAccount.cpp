#include <iostream>

#include "SavingsAccount.h"

using namespace std;

double SavingsAccount::annualInterestRate = 0.03;

void SavingsAccount::modifyInterestRate( double interest )
{
	annualInterestRate = interest;
}

SavingsAccount::SavingsAccount( double savings )
: savingsBalance( savings )
{
	print();
}

void SavingsAccount::setSavings( double savings )
{
	savingsBalance = savings;
}

double SavingsAccount::getSavings() const
{
	return savingsBalance;
}

void SavingsAccount::print() const
{
	cout << "Balance is $" << getSavings() << endl;
}

double SavingsAccount::calculateMonthlyInterest()
{
	double interest = getSavings() * annualInterestRate / monthsPerYear;
	
	setSavings( getSavings() + interest );
	
	return interest;
}




