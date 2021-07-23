#include <iostream>
#include <iomanip>
#include <math.h>

#include "Complex.h"

using namespace std;

int main()
{
	Complex a( -1.0/2, sqrt(3)/2 );
	Complex b( -1.0/2, -sqrt(3)/2 );
	Complex c( 5 * cos( M_PI / 3 ), 5 * sin( M_PI / 3 ) );
	Complex d( 1, sqrt(3) );
	Complex e( 8, 0 );
	Complex result;
	
	/*result = ( c / e );
	cout << "Result is: ";
	result.printNumber();
	
	result = e ^ (1/8);
	cout << "Result is: ";
	result.printNumber();*/
	
	e.roots( 3 );
}
