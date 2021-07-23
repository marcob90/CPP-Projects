#include <iostream>

#include "Date.h"

using namespace std;

int main()
{
	Date birthday( 16, 7, 1990 );
	
	for( int i = 1; i <= 444; i++ )
		cout << ++birthday << endl; 
}
