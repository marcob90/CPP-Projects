#ifndef OVERNIGHTP_H
#define OVERNIGHTP_H

#include "Package.h"

class OvernightPackage : public Package
{
	public:
		OvernightPackage(const string &, const double, 
			const double, const Date &, const double);
			
		virtual double calculateCost() const;
		virtual void printShipment() const;
		
	private:
		double feePerOunce;
};

#endif
