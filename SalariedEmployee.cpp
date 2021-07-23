#include <iostream>

#include "SalariedEmployee.h"

using namespace std;

SalariedEmployee::SalariedEmployee( const string &first, const string &last, const string &ssn,
const Date &bb, const double salary )
: Employee( first, last, ssn, bb )
{
	setWeeklySalary( salary );
}

void SalariedEmployee::setWeeklySalary( const double salary )
{
	weeklySalary = ( salary >= 0.0 ) ? salary : 0.0;
} 

double SalariedEmployee::getWeeklySalary() const
{
	return weeklySalary;
} 

double SalariedEmployee::earnings() const
{
	return getWeeklySalary();
}

void SalariedEmployee::print() const
{
	cout << "Salaried employee:\n";
	Employee::print();
	
	cout << "\tWeekly salary: " << getWeeklySalary();
}

