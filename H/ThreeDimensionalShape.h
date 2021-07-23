#ifndef THREED_H
#define THREED_H

#include "Shape.h"

//abstract class
class ThreeDimensionalShape : public Shape
{
	public:
		ThreeDimensionalShape() //constructor
		{
			//empty body
		} 
		
		//pure virtual functions
		virtual double getArea() const = 0;
		virtual double getVolume() const = 0;
};

#endif
