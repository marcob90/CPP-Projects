#ifndef TWODAYP_H
#define TWODAYP_H

#include "Package.h"

class TwoDayPackage : public Package
{
	public:
		TwoDayPackage(const string &, const double, 
			const double, const Date &, const double);
			
		virtual double calculateCost() const;
		virtual void printShipment() const;
		
	private:
		double flatFee;
};

#endif
