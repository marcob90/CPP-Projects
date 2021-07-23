#include "Square.h"

//constructor
Square::Square( double s )
{
	setSide( s );
}

//validate and set side
void Square::setSide( double ss )
{
	side = ss >= 0 ? ss : 0.0;
}

double Square::getSide() const
{
	return side;
}

//area function
double Square::getArea() const
{
	return side * side;
}
