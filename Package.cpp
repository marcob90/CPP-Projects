#include "Package.h"

Package::Package(const string &n, const double w, 
	const double cost, const Date &ship)
	: name(n),
	  shipDate(ship)
{
	if(w >= 0.0)
		weight = w;
	else
		weight = 0.0;
		
	if(cost >= 0.0)
		costPerOunce = cost;
	else
		costPerOunce = 0.0;
}

double Package::getWeight() const
{
	return weight;
}

double Package::calculateCost() const
{
	return weight * costPerOunce;
}
