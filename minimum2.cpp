#include <stdio.h>

#define DIM 4
#define MINIMUM2( x, y ) ( ( x ) < ( y ) ) ? ( x ) : ( y )
#define MINIMUM3( x, y, z ) ( ( MINIMUM2( x, z ) ) < ( y ) ) ? ( MINIMUM2( x, z ) ) : ( y )
#define PRINT( x ) printf( #x "\n");
#define PRINTARRAY( a, n ) do {    			    \
			int i;                   			\
			for ( i = 0; i < n; i++ ) {    \
		    	printf( "%d\t", a[ i ] );       \
			}                        			\
		} while(0)

int main()
{
	int a = 2;
	int b = 5;
	int c = 1;
	char string[] = "Ciao bello";
	int array[ DIM ] = { 10, 20, 30, 40 };
	
	printf( "Minimum is %d\n", MINIMUM2( a, b ) );
	
	printf( "Minimum is %d\n", MINIMUM3( a, b, c ) );
	
	PRINT( Ciao bello );
	
	PRINTARRAY( array, DIM );
}
