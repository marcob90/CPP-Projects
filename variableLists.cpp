#include <stdio.h>
#include <stdarg.h>

double average( const int, ... );

int main()
{
	double w = 37.2;
	double x = 2.34;
	double y = 7.90;
	double z = 14.5;
	
	printf( "The average of w and x is: %.3lf\n", average( 2, w, x ) );
	printf( "The average of w, x and y is: %.3lf\n", average( 3, w, x, y ) );
	printf( "The average of w, x, y and z is: %.3lf\n", average( 4, w, x, y, z ) );
	
	return 0;
}

double average( const int i, ... )
{
	double total = 0.0;
	int j;
	
	va_list ap;
	
	va_start( ap, i );
	
	for( j = 1; j <= i; j++){
		total += va_arg( ap, double );
	}
	
	va_end( ap );
	
	return total / i;
}
