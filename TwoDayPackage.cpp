#include "TwoDayPackage.h"
#include <iostream>

using namespace std;

TwoDayPackage::TwoDayPackage(const string &n, const double w, 
	const double cost, const Date &ship, const double fee)
	: Package(n, w,cost, ship)
{
	if(fee > 0)
		flatFee = fee;
	else
		flatFee = 0.0;
}

double TwoDayPackage::calculateCost() const
{
	return flatFee + Package::calculateCost();
}

void TwoDayPackage::printShipment() const
{
	cout << "Two day shipment\n";
}
