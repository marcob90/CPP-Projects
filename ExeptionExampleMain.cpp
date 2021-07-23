#include <iostream>
#include <iomanip>
#include "DivideByZeroException.h"
using namespace std;

double quotient( int num, int den )
{
	if( den == 0 )
		throw DivideByZeroException();
	
	return static_cast< double >( num ) / den;
}

int main()
{
	cout << fixed << setprecision( 2 );
	int num1;
	int num2;
	double result;
	
	cout << "Enter to integers (end-of-file to end):\n";
	
	while( cin >> num1 >> num2 )
	{
		try
		{
			result = quotient( num1, num2 );
			cout << "Result is: " << result << endl;
		}
		catch( DivideByZeroException &divideByZeroException )
		{
			cout << "Exeption occurred: " <<
			divideByZeroException.what() << endl;
		}
		
		cout << "Enter to integers (end-of-file to end):\n";
	}
	
	return 0;
}
