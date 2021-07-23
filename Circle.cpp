#include <cmath>
#include "Circle.h"

//constructor
Circle::Circle( double r )
{
	setRadius( r );
}

//validate and set radius
void Circle::setRadius( double rr )
{
	radius = rr >= 0 ? rr : 0.0;
}

double Circle::getRadius() const
{
	return radius;
}

//area function
double Circle::getArea() const
{
	return radius * radius * M_PI;
}
