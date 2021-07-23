#include <stdio.h>

void multiply ( int * );

int main( void )
{
	int a = 4;
	int *aPtr = &a;
	
	multiply(aPtr);
	
	printf("%d", a);
}

void multiply ( int *ptr )
{
	*ptr *= 2;
}
