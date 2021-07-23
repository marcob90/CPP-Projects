#ifndef SQUARE_H
#define SQUARE_H

#include "TwoDimensionalShape.h"

//concrete class
class Square : public TwoDimensionalShape
{
	public:
		Square( double = 0.0 ); //constructor
		void setSide( double );
		double getSide() const;
		
		//virtual functions
		virtual double getArea() const;
	
	private:
		double side;
};

#endif
