#include <iostream>
#include "Employee2019.h"

int main()
{
	cout << "Number of employees in the system is: ";
	cout << Employee2019::getCount() << endl;
	
	Employee2019::holidayDate.setDay(25).setMonth(12).setYear(2000);
	
	const Date2019 birth(7, 16, 1990);
	const Date2019 hire(10, 26, 2016);
	string myName = "Marco";
	
	Employee2019 employee1(myName, "Bongini", birth, hire);
	
	cout << employee1;
	
	Date2019 birth2;
	Date2019 hire2;
	birth2.setMonth(5).setDay(23).setYear(1955);
	hire2.setMonth(5).setDay(23).setYear(2001);
	
	Employee2019 employee2("Antonella", "Biancamano", birth2, hire2);
	
	cout << employee2; 
	
	cout << "Number of employees in the system is: ";
	cout << Employee2019::getCount() << endl;
	
	Employee2019 employee3 = employee1;
	
	cin >> employee3;
	
	cout << employee3;
}
