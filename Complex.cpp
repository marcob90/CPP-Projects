#include <iostream>

#include "Complex.h"

using namespace std;

Complex::Complex( double real, double imaginary )
: realPart( real ), imaginaryPart( imaginary )
{
}

void Complex::setRealPart( const double r )
{
	realPart = r;
}

double Complex::getRealPart() const
{
	return realPart;
} 

void Complex::setImaginaryPart( const double i )
{
	imaginaryPart = i;
}

double Complex::getImaginaryPart() const
{
	return imaginaryPart;
}

void Complex::addition( const Complex &complex2 )
{
	setRealPart ( realPart + complex2.realPart );
	setImaginaryPart ( imaginaryPart + complex2.imaginaryPart );
}

void Complex::subtraction( const Complex &complex2 )
{
	setRealPart ( realPart - complex2.realPart );
	setImaginaryPart ( imaginaryPart - complex2.imaginaryPart );
}

void Complex::multiplication( const Complex &complex2 ) 
{
	double mod1 = module();
	double arg1 = argument();
	double mod2 = complex2.module();
	double arg2 = complex2.argument();
	
	setRealPart( mod1 * mod2 * cos( arg1 + arg2 ) );
	setImaginaryPart( mod1 * mod2 * sin( arg1 + arg2 ) );
}

void Complex::division( const Complex &complex2 ) 
{
	double mod1 = module();
	double arg1 = argument();
	double mod2 = complex2.module();
	double arg2 = complex2.argument();
	
	setRealPart( mod1 / mod2 * cos( arg1 - arg2 ) );
	setImaginaryPart( mod1 / mod2 * sin( arg1 - arg2 ) );
}

void Complex::exponent( double n ) 
{
	double mod = module();
	double arg = argument();
	
	mod = pow( mod, n );
	arg *= n;
	
	setRealPart( mod * cos( arg ) );
	setImaginaryPart( mod * sin( arg ) );
}

void Complex::printNumber() const
{
	cout.precision(2);
	cout << fixed << realPart;
	
	( imaginaryPart >= 0.0 ) ? 
	cout << " + " << fixed << imaginaryPart : 
	cout << " - " << fixed << -imaginaryPart;
	
	cout << "j\n" << endl;
}

double Complex::module() const
{
	return sqrt( realPart * realPart + imaginaryPart * imaginaryPart );
}

double Complex::argument() const
{
	return atan2( imaginaryPart, realPart );
}

void Complex::roots( int n ) const
{
	double mod = module();
	double arg = argument();
	
	mod = pow( mod, 1./n);
	
	cout << "The " << n << " roots are:\n";
	
	for( int i = 0; i < n; i++ ){
		Complex temp;
		
		temp.setRealPart( mod * cos( ( arg + 2 * M_PI * i ) / n ) );
		temp.setImaginaryPart( mod * sin( ( arg + 2 * M_PI * i ) / n ) );
		
		cout << i + 1 << ") ";
		temp.printNumber();
	}
}

Complex Complex::operator+( Complex complex2 ) const
{
	Complex temp = *this;
	temp.addition( complex2 );
	
	return temp;
}

Complex Complex::operator-( Complex complex2 ) const
{
	Complex temp = *this;
	temp.subtraction( complex2 );
	
	return temp;
}

Complex Complex::operator*( Complex complex2 ) const
{
	Complex temp = *this;
	temp.multiplication( complex2 );
	
	return temp;
}

Complex Complex::operator/( Complex complex2 ) const
{
	Complex temp = *this;
	temp.division( complex2 );
	
	return temp;
}

Complex Complex::operator^( double n ) const
{
	Complex temp = *this;
	temp.exponent( n );
	
	return temp;
}
