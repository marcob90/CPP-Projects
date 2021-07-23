#ifndef RECTANGLE_H
#define RECTANGLE_H
#define DIM_BOX 25
#define PI 3.14159265

struct coordinates
{
	int x;
	int y;
};

typedef struct coordinates Coordinates;

class Rectangle
{
	public:
		Rectangle( const Coordinates [] );
		
		void setRectangle( const Coordinates [] ); 
		double calculateLength() const;
		double calculateWidth() const;
		double calculatePerimeter() const;
		double calculateArea() const;
		int isASquare() const;
		
		void draw() const;
		void translate( const int, const int );
		void size( const int );
		void rotate( const int );
		
	private:
		int isValid( const int ) const;
		int isARectangle() const;
		int distancesHaveEqualValues() const;
		int checkPythagoreanTheorem() const;
		int pointIsInsideRectangle( const Coordinates ) const;
		
		int calculateSquaredDistance
			(const Coordinates &, const Coordinates &) const;
		
		double calculateAreaOfTriangle
			( const Coordinates &, const Coordinates &, const Coordinates & ) const;
		
		void initializeBox( char [][ DIM_BOX ] ) const;
		void printBox( const char [][ DIM_BOX ] ) const;
		
		int maximum( const int, const int ) const;
		int minimum( const int, const int ) const;
		
		Coordinates rectangleCoordinates[ 4 ]; 
};

#endif
