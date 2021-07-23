#ifndef COMPLEX_H
#define COMPLEX_H

#include <math.h>

class Complex
{
	public:
		Complex( double = 0, double = 0 );
		
		void setRealPart( const double );
		double getRealPart() const;
		void setImaginaryPart( const double );
		double getImaginaryPart() const;
		
		void printNumber() const;
		double module() const;
		double argument() const;
		void roots( int ) const;
		
		Complex operator+( Complex ) const;
		Complex operator-( Complex ) const;
		Complex operator*( Complex ) const;
		Complex operator/( Complex ) const;
		Complex operator^( double ) const;
	
	private:
		double realPart;
		double imaginaryPart;
		
		void addition( const Complex& );
		void subtraction( const Complex& );
		void multiplication( const Complex& );
		void division( const Complex& );
		void exponent( double );
};

#endif
