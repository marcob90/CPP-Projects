#include <iostream>

#include "BasePlusCommissionEmployee.h"

using namespace std;

// constructor
BasePlusCommissionEmployee::BasePlusCommissionEmployee(
const string &first, const string &last, const string &ssn,
const Date &bb, double sales, double rate, double salary )
: CommissionEmployee( first, last, ssn, bb, sales, rate )
{
	setBaseSalary( salary ); // validate and store base salary
} // end BasePlusCommissionEmployee constructor

 // set base salary
void BasePlusCommissionEmployee::setBaseSalary( double salary )
{
	baseSalary = ( salary < 0.0 ) ? 0.0 : salary;
} // end function setBaseSalary

// return base salary
double BasePlusCommissionEmployee::getBaseSalary() const
{
	return baseSalary;
} // end function getBaseSalary

// calculate earnings
double BasePlusCommissionEmployee::earnings() const
{
	return baseSalary + CommissionEmployee::earnings();
} // end function earnings

void BasePlusCommissionEmployee::print() const
{
	cout << "Base-salaried ";
	CommissionEmployee::print();
	cout << "; base salary: " << getBaseSalary();
}
