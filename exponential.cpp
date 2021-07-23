#include "Exponential.h"
#include <cmath>

/*template <class T>
ostream &operator<<( ostream &output, const Exponential< T > &e)
{
	output << e.base << " ^ " <<
	e.exp << " = " << e.calculate()
	<< endl;
	
	return output;
}*/

template <class T>
Exponential< T >::Exponential( T b, T e ) :
base(b), exp(e)
{
}

template <class T>
T Exponential< T >::calculate() const
{
	return pow( base, exp );
}
	
