#ifndef CIRCLE_H
#define CIRCLE_H

#include "TwoDimensionalShape.h"

//concrete class
class Circle : public TwoDimensionalShape
{
	public:
		Circle( double = 0.0 ); //constructor
		void setRadius( double );
		double getRadius() const;
		
		//virtual functions
		virtual double getArea() const;
	
	private:
		double radius;
};

#endif
