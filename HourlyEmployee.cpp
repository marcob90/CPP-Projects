#include <iostream>

#include "HourlyEmployee.h"

using namespace std;

HourlyEmployee::HourlyEmployee( const string &first, const string &last, const string &ssn,
const Date &bb, const double pay, const double time )
: Employee( first, last, ssn, bb )
{
	setWage( pay );
	setHours( time );
}

void HourlyEmployee::setWage( const double pay )
{
	wage = ( pay >= 0.0 ) ? pay : 0.0;
} 

double HourlyEmployee::getWage() const
{
	return wage;
} 

void HourlyEmployee::setHours( const double time )
{
	hours = ( ( time >= 0.0 ) && ( time <= hoursPerWeek ) ) ? time : 0.0;
} 

double HourlyEmployee::getHours() const
{
	return hours;
} 

double HourlyEmployee::earnings() const
{
	if( getHours() <= 40 )
		return getWage() * getHours();
	else
		return getWage() * 40 + ( getHours() - 40 ) * getWage() * 1.5;
}

void HourlyEmployee::print() const
{
	cout << "Hourly employee:\n";
	Employee::print();
	
	cout << "\tHourly wage: " << getWage() <<
	"\n\tHours worked: " << getHours();
}

