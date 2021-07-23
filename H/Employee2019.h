#ifndef EMPLOYEE2019_H
#define EMPLOYEE2019_H

#include <string>
#include <iostream>
#include "Date2019.h"
using namespace std;

class Employee2019
{
	friend void calculateAge(Employee2019 &);
	friend ostream &operator<<(ostream &, const Employee2019 &);
	friend istream &operator>>(istream &, Employee2019 &);
	
	public:
		Employee2019(const string &, const string &, 
			const Date2019 &, const Date2019 &);
		~Employee2019();
		
		void print() const;
		static int getCount();
		static Date2019 holidayDate;
	
	private:
		string firstName;
		string lastName;
		Date2019 birthDate;
		Date2019 hireDate;
		int age;
		static int count;
};

#endif
