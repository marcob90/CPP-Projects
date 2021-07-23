#include <iostream>

#include "Employee.h"

using namespace std;

Employee::Employee( const string &first, const string &last, const string &ssn, const Date &bb )
: firstName( first ), lastName( last ), socialSecurityNumber( ssn ), birthday( bb )
{
	// empty body
}

void Employee::setFirstName( const string &first )
{
	firstName = first; // should validate
} // end function setFirstName

 // return first name
string Employee::getFirstName() const
{
	return firstName;
} // end function getFirstName

// set last name
void Employee::setLastName( const string &last )
{
	lastName = last; // should validate
} // end function setLastName

// return last name
string Employee::getLastName() const
{
	return lastName;
} // end function getLastName

// set social security number
void Employee::setSocialSecurityNumber( const string &ssn )
{
	socialSecurityNumber = ssn; // should validate
} // end function setSocialSecurityNumber

// return social security number
string Employee::getSocialSecurityNumber() const
{
	return socialSecurityNumber;
} // end function getSocialSecurityNumber

void Employee::setBirthday( int mm, int dd, int yy )
{
	birthday.setDate( mm, dd, yy );
}

Date Employee::getBirthday() const
{
	return birthday;
}

void Employee::print() const
{
	cout << "\t" << getFirstName() << ' ' << getLastName()
	<< "\n\tBirthday: " << birthday //cout operation is overloaded
	<< "\n\tSocial security number: " << getSocialSecurityNumber() << endl;
}

