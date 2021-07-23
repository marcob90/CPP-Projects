#include <iostream>
#include <iomanip>
#include <ctime>

#include "Employee2019.h"

int Employee2019::count = 0;
Date2019 Employee2019::holidayDate;

Employee2019::Employee2019(const string &fN, const string &lN,
	const Date2019 &bD, const Date2019 &hD)
	: firstName(fN),
	  lastName(lN),
	  birthDate(bD),
	  hireDate(hD)
{
	calculateAge(*this);
	count++;
}

Employee2019::~Employee2019()
{
	--count;
}

int Employee2019::getCount()
{
	return count;
}

void Employee2019::print() const
{
	cout << lastName << ", " << firstName << "\nHired: ";
 	hireDate.print();
 	cout << " Birthday: ";
 	birthDate.print();
 	cout << endl;
 	cout << "Age: " << age << endl;
}

void calculateAge(Employee2019 &employee)
{
	//get time now
	time_t t = time(0);
	tm *now = localtime(&t);
	
	int d = now->tm_mday; 
	int m = now->tm_mon + 1; 
	int y = now->tm_year + 1900;
	
	if(m < employee.birthDate.getMonth())
		employee.age = y - employee.birthDate.getYear() - 1;
	else if(m > employee.birthDate.getMonth())
		employee.age = y - employee.birthDate.getYear();
	else{
		if(d < employee.birthDate.getDay())
			employee.age = y - employee.birthDate.getYear() - 1;
		else
			employee.age = y - employee.birthDate.getYear();	
	}	
}

ostream &operator<<(ostream &output, const Employee2019 &e)
{
	output << e.lastName << ", " << e.firstName << "\nHired: ";
 	e.hireDate.print();
 	output << " Birthday: ";
 	e.birthDate.print();
 	output << endl;
 	output << "Age: " << e.age << endl;
 	
 	return output;
}

istream &operator>>(istream &input, Employee2019 &e)
{
	int mm, dd, yyyy;
	
	cout << "Insert first name: ";
	input >> e.firstName;
	cout << "Insert last name: ";
	input >> e.lastName;

 	return input;
}
