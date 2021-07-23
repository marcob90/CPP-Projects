#include <iostream>
#include <iomanip>

#include "Rectangle.h"

using namespace std;

int main()
{
	Coordinates coorArray[ 4 ] = {
		{ 2, 4 },
		{ 4, 2 },
		{ 7, 5 },
		{ 5, 7 },
	};
	
	/*Coordinates coorArray[ 4 ] = {
		{ 10, 0 },
		{ 16, 0 },
		{ 16, 10 },
		{ 10, 10 },
	};*/
	
	Rectangle rectangle( coorArray );
	
	cout << setprecision( 2 ) << fixed;
	
	cout << "Length is: " << rectangle.calculateLength() << endl;
	cout << "Width is: " << rectangle.calculateWidth() << endl;
	cout << "Perimeter is: " << rectangle.calculatePerimeter() << endl;
	cout << "Area is: " << rectangle.calculateArea() << endl;
	
	rectangle.isASquare() ? ( cout << "\nIt is a square\n" ) : ( cout << "\n" );
	
	rectangle.draw();
	rectangle.size( 2 );
	rectangle.draw();
	rectangle.translate( 3, 4 );
	rectangle.draw();
	rectangle.rotate( 90 );
	rectangle.draw();
}
