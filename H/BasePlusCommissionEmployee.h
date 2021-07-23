#ifndef BASEPLUS_H
#define BASEPLUS_H

#include "CommissionEmployee.h"

class BasePlusCommissionEmployee : public CommissionEmployee
{
	public:
		BasePlusCommissionEmployee( const string &, const string &,
		const string &, const Date &, double = 0.0, double = 0.0, double = 0.0 );
	
		void setBaseSalary( double ); // set base salary
		double getBaseSalary() const; // return base salary
	
		virtual double earnings() const; // calculate earnings
		virtual void print() const;
	
	private:
		double baseSalary; // base salary
};

#endif
