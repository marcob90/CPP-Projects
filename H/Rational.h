#ifndef RATIO_H
#define RATIO_H

class Rational{
	public:
		Rational( int = 0, int = 1 );
		void setNumerator( int );
		void setDenominator( int );
		int getNumerator();
		int getDenominator();
		void sumRationals( Rational, Rational );
		void subtractRationals( Rational, Rational );
		void multiplyRationals( Rational, Rational );
		void divideRationals( Rational, Rational );
		void printInStandardForm();
		void printInFloatingPointForm();
		void reduceForm( int, int );
	
	private:
		int numerator;
		int denominator;
		int gcd( int, int );
};

#endif
