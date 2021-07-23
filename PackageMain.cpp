#include <iostream>
#include <iomanip>
#include <vector>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

using namespace std;

int main()
{
	cout << setprecision(2) << fixed;
	
	//TwoDayPackage twoDayPackage("Stefano Colombo", 2.0, 5.0, Date(3, 5, 2017), 15.0);
	OvernightPackage overnightPackage("Marco Bongini", 3.0, 5.0, Date(7, 5, 2017), 2.0);
	
	Package *pPtr = new TwoDayPackage("Stefano Colombo", 2.0, 5.0, Date(3, 5, 2017), 15.0);
	Package *oPtr = &overnightPackage;
	
	cout << pPtr->calculateCost() << endl;
	pPtr->printShipment();
	
	cout << oPtr->calculateCost() << endl;
	oPtr->printShipment();
	
	vector <Package *> packages(2);
	
	packages[0] = pPtr;
	packages[1] = oPtr;
	
	for(size_t i = 0; i < 2; i++){
		OvernightPackage *derivedPackage = 
			dynamic_cast<OvernightPackage *>(packages[i]);
		
		if(derivedPackage != 0)
			cout << "Package number " << i << " is overnight\n";
	}
		
}

