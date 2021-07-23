#include <stdio.h>
#include <stdlib.h>

struct stackNode {
	int data;
	struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push( StackNodePtr *, const int );
int pop( StackNodePtr * );
int isEmpty( StackNodePtr );
void printStack ( StackNodePtr );

int main( void )
{
	int i;
	StackNodePtr stackPtr = NULL;
	char sentence[ 50 ];
	
	fgets( sentence, 50, stdin );
	
	for( i = 0; sentence[ i ] != '\0' && sentence[ i ] != '\n'; i++){
		push( &stackPtr, sentence[ i ] );
	}
	
	printStack( stackPtr );
	
	return 0;
}

void push( StackNodePtr *topPtr, const int value )
{
	StackNodePtr newPtr;
	
	newPtr = ( StackNodePtr ) malloc( sizeof( StackNode ) );
	
	if( newPtr != NULL ) {
		newPtr->data = value;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;
	}
	else {
		printf("%c not inserted. Memory not available\n", value);
	}
}

int pop( StackNodePtr *topPtr )
{
	StackNodePtr tempPtr;
	int popValue;
	
	tempPtr = *topPtr;
	popValue = ( *topPtr )->data;
	*topPtr = ( *topPtr )->nextPtr;
	free( tempPtr );
	
	return popValue;
}

int isEmpty( StackNodePtr sPtr )
{
	return sPtr == NULL;
}

void printStack( StackNodePtr currentPtr )
{	
	if( currentPtr == NULL )
		printf("The stack is empty\n");
	else {
		printf( "The stack is:\n" );
		
		while( currentPtr != NULL ){
			printf( "%c --> ", currentPtr->data );
			
			currentPtr = currentPtr->nextPtr;
		}
		
		printf("NULL\n\n");
	}	
}
