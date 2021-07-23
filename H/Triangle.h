#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "TwoDimensionalShape.h"

//concrete class
class Triangle : public TwoDimensionalShape
{
	public:
		Triangle( double = 0.0, double = 0.0 ); //constructor
		
		void setBase( double );
		double getBase() const;
		void setHeight( double );
		double getHeight() const;
		
		//virtual functions
		virtual double getArea() const;
	
	private:
		double base;
		double height;
};

#endif
