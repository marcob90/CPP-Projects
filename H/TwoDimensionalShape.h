#ifndef TWOD_H
#define TWOD_H

#include <iostream>
#include "Shape.h"

//abstract class
class TwoDimensionalShape : public Shape
{
	public:
		TwoDimensionalShape() //constructor
		{
			//empty body
		} 
		
		//pure virtual functions
		virtual double getArea() const = 0;
		virtual double getVolume() const
		{
			std::cout << "Improper use of function getVolume\n";
			std::cout << "\tShape is two dimensional\n";
			
			return 0.0;
		}
};

#endif
