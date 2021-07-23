#ifndef COMMISSION_H
#define COMMISSION_H

#include "Employee.h"

using namespace std;

class CommissionEmployee : public Employee
{
	public:
		CommissionEmployee( const string &, const string &, const string &,
		const Date &, const double = 0.0, const double = 0.0 );
		
		void setGrossSales( double ); // set gross sales amount
		double getGrossSales() const; // return gross sales amount

		void setCommissionRate( double ); // set commission rate (percentage)
		double getCommissionRate() const; // return commission rate

		virtual double earnings() const; // calculate earnings
		virtual void print() const;
		
	private:
		double grossSales;
		double commissionRate;
};


#endif
