#include "Array.h"

using namespace std;

void outputArray( const Array & ); // prototype

int main()
{
	Array integers1( 3 );
	Array integers2( 4 );
	
	cout << "Size of Array integers1 is "
	<< integers1.getSize() 
	<< "\nArray after initialization:\n" << integers1;
	
	cout << "\n\nSize of Array integers2 is "
	<< integers2.getSize() 
	<< "\nArray after initialization:\n" << integers2;
	
	cout << "\n\nEnter 7 integers:\n";
	cin >> integers1 >> integers2;
	
	cout << "\nArray integers1 is\n"
	<< integers1 << "\n\nArray integers2 is\n"
	<< integers2 << endl;
	
	cout << "\nEvaluating: integers1 != integers2\n";
	
	if( integers1 != integers2 )
		cout << "Integers1 and integers2 are not equal\n";
	
	Array integers3(integers1);
	
	cout << "\nSize of Array integers3 is "
	<< integers3.getSize() 
	<< "\nArray after initialization:\n" << integers3;
	
	cout << "\n\nEvaluating integers1 == integers3\n";
	
	if( integers1 == integers3 )
		cout << "Integers1 and integers2 are equal\n";
	
	cout << "\nIntegers1[1] is: " << integers1[ 1 ] << endl;
	
	cout << "\nAssigning 44 to integers[1]\n";
	integers1[ 1 ] = 44;
	
	cout << "\nIntegers1[1] is: " << integers1[ 1 ] << endl;
	
	outputArray(integers1);
	
	return 0;
}

void outputArray( const Array &a)
{
	cout << "Array has size: " << a.getSize() << endl;
} 
