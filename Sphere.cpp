#include <cmath>
#include "Sphere.h"

//constructor
Sphere::Sphere( double r )
{
	setRadius( r );
}

//validate and set radius
void Sphere::setRadius( double rr )
{
	radius = rr >= 0 ? rr : 0.0;
}

double Sphere::getRadius() const
{
	return radius;
}

//area function
double Sphere::getArea() const
{
	return radius * radius * 4 * M_PI;
}

//volume function
double Sphere::getVolume() const
{
	return radius * radius * radius * 4.0 / 3.0 * M_PI;
}
