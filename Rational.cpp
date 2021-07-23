#include <iostream>
#include <iomanip>
#include <cmath>

#include "Rational.h"

using namespace std;

Rational::Rational( int n, int d )
{
	reduceForm( n, d );
}

void Rational::setNumerator( int n )
{
	numerator = n;
}

void Rational::setDenominator( int d )
{
	denominator = ( d == 0 ) ? 1 : d;
}

int Rational::getNumerator()
{
	return numerator;
}

int Rational::getDenominator()
{
	return denominator;
}

void Rational::sumRationals( Rational r1, Rational r2 )
{
	int n1 = r1.getNumerator();
	int d1 = r1.getDenominator();
	int n2 = r2.getNumerator();
	int d2 = r2.getDenominator();
	int commonDenominator;
	int commonNumerator;
	
	commonDenominator = d1 * d2;
	commonNumerator = n1 * d2 + n2 * d1;
	
	reduceForm( commonNumerator, commonDenominator );
}

void Rational::subtractRationals( Rational r1, Rational r2 )
{
	int n1 = r1.getNumerator();
	int d1 = r1.getDenominator();
	int n2 = r2.getNumerator();
	int d2 = r2.getDenominator();
	int commonDenominator;
	int commonNumerator;
	
	commonDenominator = d1 * d2;
	commonNumerator = n1 * d2 - n2 * d1;
	
	reduceForm( commonNumerator, commonDenominator );
}

void Rational::multiplyRationals( Rational r1, Rational r2 )
{
	int n1 = r1.getNumerator();
	int d1 = r1.getDenominator();
	int n2 = r2.getNumerator();
	int d2 = r2.getDenominator();
	int commonDenominator;
	int commonNumerator;
	
	commonDenominator = d1 * d2;
	commonNumerator = n1 * n2;
	
	reduceForm( commonNumerator, commonDenominator );
}

void Rational::divideRationals( Rational r1, Rational r2 )
{
	int n1 = r1.getNumerator();
	int d1 = r1.getDenominator();
	int n2 = r2.getNumerator();
	int d2 = r2.getDenominator();
	int commonDenominator;
	int commonNumerator;
	
	if( n2 != 0 ){
		commonDenominator = d1 * n2;
		commonNumerator =  n1 * d2;
		
		reduceForm( commonNumerator, commonDenominator );
	}
	else
		cout << "Warning! Division by 0 attempt" << endl;
}

void Rational::printInStandardForm()
{
	( getNumerator() < 0 || getDenominator() < 0 ) ? ( cout << "-" ) : "";
	
	cout << abs( getNumerator() ) << " / " << abs( getDenominator() ) << endl;
}

void Rational::printInFloatingPointForm()
{
	cout << setprecision( 4 ) << ( double )getNumerator() / getDenominator() << endl;
}

void Rational::reduceForm( int n, int d )
{
	int greaterCommonDivisor = gcd( abs( n ), abs( d ) );
	
	setNumerator( n / greaterCommonDivisor );
	setDenominator( d / greaterCommonDivisor );
}

int Rational::gcd( int a, int b )
{
	if( b == 0 )
		return a;
	else
		return gcd( b, a % b );
}
