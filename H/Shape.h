#ifndef SHAPE_H
#define SHAPE_H

//abstract base-class
class Shape
{
	public:
		Shape() //constructor
		{
			//empty body
		} 
		
		//pure virtual functions
		virtual double getArea() const = 0;
		virtual double getVolume() const = 0;
};

#endif
