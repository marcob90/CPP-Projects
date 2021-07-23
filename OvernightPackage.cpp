#include "OvernightPackage.h"

OvernightPackage::OvernightPackage(const string &n, const double w, 
	const double cost, const Date &ship, const double fee)
	: Package(n, w,cost, ship)
{
	if(fee > 0)
		feePerOunce = fee;
	else
		feePerOunce = 0.0;
}

double OvernightPackage::calculateCost() const
{
	return getWeight() * feePerOunce + Package::calculateCost();
}

void OvernightPackage::printShipment() const
{
	cout << "Overnight shipment\n";
}
