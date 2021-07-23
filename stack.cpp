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
void instructions( void );

int main( void )
{
	StackNodePtr stackPtr = NULL;
	int choice;
	char item;
	
	instructions();
	printf("? ");
	scanf("%d%*c", &choice);
	
	while( choice != 3 ){
		switch(choice){
			case 1:
				printf( "Enter an integer: " );
				scanf( "%d%*c", &item );
				
				push( &stackPtr, item );
				printStack( stackPtr );
				break;
			case 2:
				if( !isEmpty( stackPtr ) ) {
					item = pop( &stackPtr );
					printf( "%d deleted\n", item );
					
					printStack( stackPtr );
				}
				else {
					printf( "Stack is empty\n" );
				}
				break;
			default:
				printf( "Wrong choice\n" );
				instructions();
		}
		
			printf("? ");
				scanf("%d%*c", &choice );
	}
	
	printf( "End of run\n" );
	
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
		printf("%d not inserted. Memory not available\n", value);
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
			printf( "%d --> ", currentPtr->data );
			
			currentPtr = currentPtr->nextPtr;
		}
		
		printf("NULL\n\n");
	}	
}
void instructions( void )
{
	printf( "Enter your choice:\n"
 			" 1 to insert an element into the stack.\n"
 			" 2 to delete an element from the stack.\n"
 			" 3 to end.\n" );
}
