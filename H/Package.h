#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
#include "Date.h"

class Package
{
	public:
		Package(const string &, const double, 
			const double, const Date &);
		double getWeight() const;
		virtual double calculateCost() const;
		virtual void printShipment() const = 0;
		
	private:
		string name;
		double weight; //in ounces
		double costPerOunce;
		Date shipDate;
};

#endif
