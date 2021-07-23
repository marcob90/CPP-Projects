#ifndef HOURLY_H
#define HOURLY_H

#include "Employee.h"

using namespace std;

class HourlyEmployee : public Employee
{
	public:
		static const int hoursPerWeek = 168;
		
		HourlyEmployee( const string &, const string &, const string &,
		const Date &, const double = 0.0, const double = 0.0 );
		
		void setWage( const double ); 
		double getWage() const; 
		
		void setHours( const double ); 
		double getHours() const; 

		virtual double earnings() const;
		virtual void print() const;
		
	private:
		double wage;
		double hours;
};

#endif
