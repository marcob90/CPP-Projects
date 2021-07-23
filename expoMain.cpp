#include "exponential.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream myFile;
	float b, e;
	
	try{
		cin >> b >> e;
		
		if( b == 0 && e <= 0 )
			throw( 99 );
		
		myFile.open("myText.txt");
		
		Exponential <float> expo( b, e );
		cout << expo;
		
		myFile << expo;
		myFile.close();
	}
	catch( int x ){
		cout << "Error " << x << " - values with no meaning\n";
	}
	
	return 0;
}
