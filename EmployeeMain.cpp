#include <iostream>

#include "Date.h"
#include "Employee.h"

int main()
{
	const Date birth( 16, 7, 1990 );
	const Date hire( 26, 10, 2016 );
	Employee firmwareEngineer( "Marco", "Bongini", birth, hire );
	
	cout << endl;
	firmwareEngineer.print();
	cout << endl;
}
