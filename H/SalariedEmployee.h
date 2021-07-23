#ifndef SALARIED_H
#define SALARIED_H

#include "Employee.h"

using namespace std;

class SalariedEmployee : public Employee
{
	public:
		SalariedEmployee( const string &, const string &, const string &,
		const Date &, const double = 0.0 );
		
		void setWeeklySalary( const double ); 
		double getWeeklySalary() const; 

		virtual double earnings() const;
		virtual void print() const;
		
	private:
		double weeklySalary;
};

#endif
