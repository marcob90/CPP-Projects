#ifndef EXPO
#define EXPO

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

template <typename T>
class Exponential{
	template <typename U>
	friend ostream &operator<<( ostream &, const Exponential< U > & );
	
	template <typename U>
	friend ofstream &operator<<( ofstream &, const Exponential< U > & );
	
	public:
		Exponential( const T, const T );
		
	private:
		T base;
		T exp;
		
		T calculate() const;
};

template <typename T>
Exponential< T >::Exponential( const T b, const T e ) :
base(b), exp(e)
{
}

template <typename T>
T Exponential< T >::calculate() const
{
	return pow( base, exp );
}

template <typename U>
ostream &operator<<( ostream &output, const Exponential< U > &e)
{
	output << e.base << " ^ " <<
	e.exp << " = " << e.calculate()
	<< endl;
	
	return output;
}

template <typename U>
ofstream &operator<<( ofstream &output, const Exponential< U > &e)
{
	output << e.base << " ^ " <<
	e.exp << " = " << e.calculate()
	<< endl;
	
	return output;
}

#endif
