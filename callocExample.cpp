#include <stdio.h>
#include <stdlib.h>


int main()
{
	int *ptr = NULL;
	int i;
	
	ptr = ( int* )malloc( 10 * sizeof( int ) );
	
	if( ptr != NULL ){
		*( ptr + 5 ) = 2;
	}
	
	for( i = 0; i < 10 ; i++ ){
		printf( "%d\n", *( ptr + i ) );
	}
	
	free( ptr );
}

