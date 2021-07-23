//this programs calculates the cube an input number
//through an inline function
#include <iostream>

using namespace std;

inline double cube( const double n )
{
	return n * n * n;
}

inline int cube( const int n )
{
	return n * n * n;
}

int main()
{
	double number;
	
	cout << "Enter a number: ";
	cin >> number;
	
	cout << "The cube of " << 
	number << " is " << cube( number );
	cout << endl;
}
