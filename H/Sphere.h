#ifndef SPHERE_H
#define SPHERE_H

#include "ThreeDimensionalShape.h"

//concrete class
class Sphere : public ThreeDimensionalShape
{
	public:
		Sphere( double = 0.0 ); //constructor
		void setRadius( double );
		double getRadius() const;
		
		//virtual functions
		virtual double getArea() const;
		virtual double getVolume() const;
	
	private:
		double radius;
};

#endif
