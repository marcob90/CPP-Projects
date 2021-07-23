#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Date.h"

using namespace std;

// virtual class
class Employee
{
	public:
		Employee( const string &, const string &, 
		const string &, const Date & );
		
		void setFirstName( const string & ); // set first name
		string getFirstName() const; // return first name

		void setLastName( const string & ); // set last name
		string getLastName() const; // return last name

		void setSocialSecurityNumber( const string & ); // set SSN
		string getSocialSecurityNumber() const; // return SSN
		
		void setBirthday( int, int, int ); // set birthday
		Date getBirthday() const; // return birthday
		
		//pure virtual function
		virtual double earnings() const = 0; // calculate earnings
		virtual void print() const;
		
	private:
		string firstName;
		string lastName;
		string socialSecurityNumber;
		Date birthday;
};

#endif
