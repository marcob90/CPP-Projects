#include <iostream>

#include "HugeInteger.h"

using namespace std;

int main()
{
	HugeInteger hugeNumber1;
	HugeInteger hugeNumber2;
	int digit;
	
	cout << "Insert first number digits\n";
	
	for( int i = 0; i < HugeInteger::DIM; i++ ){
		cin >> digit;
		
		hugeNumber1.input( i, digit );
	}
	
	cout << "Insert second number digits\n";
	
	for( int i = 0; i < HugeInteger::DIM; i++ ){
		cin >> digit;
		
		hugeNumber2.input( i, digit );
	}
	
	hugeNumber1.output();
	hugeNumber2.output();
	
	hugeNumber1.sum( hugeNumber2 );
	
	cout << "Sum is:\n";
	hugeNumber1.output();
	
	hugeNumber1.difference( hugeNumber2 );
	
	cout << "Difference is:\n";
	hugeNumber1.output();
	
	if( hugeNumber1.isEqualTo( hugeNumber2 ) ){
		cout << "Numbers are equal\n";
	}
	else
		cout << "They are not equal\n";
		
	if( hugeNumber1.isGreaterThan( hugeNumber2 ) ){
		cout << "Number1 is greater than number 2\n";
	}
	else
		cout << "Number1 is not greater than number2\n";
		
/*	hugeNumber1.multiply( hugeNumber2 );
	cout << "Product is:\n";
	hugeNumber1.output();*/
	
	/*hugeNumber1.divide( hugeNumber2 );
	cout << "Division is:\n";
	hugeNumber1.output();*/
	
	hugeNumber1.modulus( hugeNumber2 );
	cout << "Modulus is:\n";
	hugeNumber1.output();
}
