#include <iostream>
#include <iomanip>
#include <vector>
#include <limits.h>

#include "Date.h"
#include "Employee.h"
#include "SalariedEmployee.h"
#include "HourlyEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"

using namespace std;

int main()
{
	cout << fixed << setprecision( 2 );
	const Date currentDate( 2, 7, 2019 );

	SalariedEmployee salariedEmployee( "Marco", "Bongini", "111-11-1111", 
	Date( 16, 7, 1990 ), 750.0 ); //weekly salary
	HourlyEmployee hourlyEmployee( "Stefano", "Colombo", "222-22-2222", 
	Date( 22, 9, 1990 ), 15.0, 40.0 );
	CommissionEmployee commissionEmployee( "Andrea", "Bollati", "333-33-3333", 
	Date( 8, 8, 1989 ), 4000.0 , 0.2 ); //gross sales per week
	BasePlusCommissionEmployee basePlusCommissionEmployee( "Anne", "Sheridan", "444-44-4444", 
	Date( 3, 4, 1982 ), 4000.0 , 0.2, 500.0 );
 	
 	// create vector of four base-class pointers
	vector < Employee * > employees( 4 );
	
	employees[ 0 ] = &salariedEmployee;
	employees[ 1 ] = &hourlyEmployee;
	employees[ 2 ] = &commissionEmployee;
	employees[ 3 ] = &basePlusCommissionEmployee;
	
	cout << "Employees processed polymorphically via dynamic binding:\n\n";
	
	for( size_t i = 0; i < employees.size(); i++ ){
		double payroll = employees[ i ]->earnings();
		
		employees[ i ]->print();
		
		if( currentDate.getMonth() == employees[ i ]->getBirthday().getMonth() ){
			cout << "\n\tEarned $" << payroll << 
			" + $100.00 Birthday Bonus = $" << 
			payroll + 100.00 << "\n\n";
		}
		else
			cout << "\n\tEarned $" << payroll << "\n\n";
	}
		
}


