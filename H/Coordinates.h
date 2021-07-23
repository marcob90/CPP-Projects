#ifndef COORDINATES_H
#define COORDINATES_H

struct coordinates
{
	double x;
	double y;
	
	coordinates( double xx, double yy )
	: x( xx ), y( yy )
	{
	}
};

typedef struct coordinates Coordinates;

#endif
