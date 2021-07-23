#include <iostream>

#include "CommissionEmployee.h"

using namespace std;

CommissionEmployee::CommissionEmployee( const string &first, const string &last, const string &ssn,
const Date &bb, const double gross, const double commission )
: Employee( first, last, ssn, bb )
{
	setGrossSales( gross );
	setCommissionRate( commission );
}

// set gross sales amount
void CommissionEmployee::setGrossSales( double sales )
{
	grossSales = ( sales < 0.0 ) ? 0.0 : sales;
} // end function setGrossSales

// return gross sales amount
double CommissionEmployee::getGrossSales() const
{
	return grossSales;
} // end function getGrossSales

// set commission rate
void CommissionEmployee::setCommissionRate( double rate )
{
	commissionRate = ( rate > 0.0 && rate < 1.0 ) ? rate : 0.0;
} // end function setCommissionRate

// return commission rate
double CommissionEmployee::getCommissionRate() const
{
	return commissionRate;
} // end function getCommissionRate

// calculate earnings
double CommissionEmployee::earnings() const
{
	return commissionRate * grossSales;
} // end function earnings

void CommissionEmployee::print() const
{
	cout << "Commission employee:\n";
	
	Employee::print();
	
	cout << "\tGross sales: " << getGrossSales()
	<< "\n\tCommission Rate: " << getCommissionRate();
}

