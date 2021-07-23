#include "Triangle.h"

//constructor
Triangle::Triangle( double b, double h )
{
	setBase( b );
	setHeight( h );
}

//validate and set base
void Triangle::setBase( double bb )
{
	base = bb >= 0 ? bb : 0.0;
}

double Triangle::getBase() const
{
	return base;
}

//validate and set height
void Triangle::setHeight( double hh )
{
	height = hh >= 0 ? hh : 0.0;
}

double Triangle::getHeight() const
{
	return height;
}

//area function
double Triangle::getArea() const
{
	return base * height / 2.0;
}
