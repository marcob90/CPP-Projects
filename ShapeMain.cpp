#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>
#include "Shape.h"
#include "TwoDimensionalShape.h"
#include "ThreeDimensionalShape.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Sphere.h"

using namespace std;

int main()
{
	cout << fixed << setprecision( 2 );
	
	Circle circle( 2.0 );
	Square square( 3.0 );
	Triangle triangle( 2.0, 3.0 );
	Sphere sphere( 2.0 );
	
	vector < Shape * > shapes( 4 );
	
	shapes[ 0 ] = &circle;
	shapes[ 1 ] = &square;
	shapes[ 2 ] = &triangle;
	shapes[ 3 ] = &sphere;
	
	for( vector< Shape * >::iterator it = shapes.begin(); it != shapes.end(); it++ ){
		
		const char * name = typeid( **it ).name(); //return mangled name of object
		
		cout << &name[ 1 ] << endl; //demangle name 
		cout << "Area = " << ( *it )->getArea();
		
		//verify if shape is three dimensional. If it is, print volume
		ThreeDimensionalShape *derivedPtr =
		dynamic_cast < ThreeDimensionalShape * >( *it );
		
		if( derivedPtr != 0 )
			cout << "\nVolume = " << ( *it )->getVolume();
			
		cout << "\n\n";
	}

	return 0;
}
