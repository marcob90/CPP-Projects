//this programs calculates the cube an input number
//through an inline function
#include <iostream>

using namespace std;

template <class T>
T cube(const T n)
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
	
	int int1;
	
	cout << "Enter a whole number: ";
	cin >> int1;
	
	cout << "The cube of " << 
	int1 << " is " << cube( int1 );
	cout << endl;
	
	char char1;
	
	cout << "Enter a char: ";
	cin >> char1;
	
	cout << "The cube of " << 
	char1 << " is " << cube( char1 );
	cout << endl;
}
