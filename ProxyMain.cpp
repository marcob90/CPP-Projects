#include <iostream>
#include "Interface.h"

using namespace std;

int main()
{
	Interface inter( 5 );
	
	cout << inter.getValue() << endl;
	
	inter.setValue( 10 );
	
	cout << inter.getValue() << endl;
	return 0;
}
