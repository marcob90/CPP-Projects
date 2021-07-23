#include <stdio.h>

void * square( const void * );

int main()
{
	int num = 6;
	int sq_int;
	
	sq_int = *( int * )square( &num );
	
	printf( "%d\n", sq_int );
}

void * square( const void * n )
{
	static int result;
	
	result = ( *( int * )n ) * ( *( int * )n );
	
	return &result;
}
