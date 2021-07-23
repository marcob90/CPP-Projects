#include "IntegerSet.h"

int main()
{
	int a[ 2 ] = { 80, 20 };
	IntegerSet setA;
	IntegerSet setB;
	IntegerSet setC;
	IntegerSet setD;
	IntegerSet setE( a, 2 );
	IntegerSet setF;
	
	setA.insertElement( 44 ).insertElement( 20 ).
	insertElement( 3 ).insertElement( 2 ).
	insertElement( 80 ).insertElement( 20 ).
	insertElement( 7 ).insertElement( 69 );
	
	setB.insertElement( 80 ).insertElement( 20 ).
	insertElement( 9 ).insertElement( 75 ).
	insertElement( 31 ).insertElement( 78 ).
	insertElement( 99 ).insertElement( 1 );
	
	
	setA.printSet();
	setB.printSet();
	setC.unionOfSets( setA, setB ).printSet();
	setD.intersectionOfSets( setA, setB ).printSet();
	
	setC.deleteElement( 31 ).printSet();
	
	setE.printSet();
	
	std::cout << setD.isEqualTo( setE ) << std::endl;
	std::cout << setA.isEqualTo( setC ) << std::endl;
	
	setC.complementOfSets( setC ).printSet();
}
