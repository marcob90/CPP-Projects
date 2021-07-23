#include <stdio.h>
#include <stdlib.h>

struct queueNode {
	char data;
	struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

void enqueue( QueueNodePtr *, QueueNodePtr *, const char );
char dequeue( QueueNodePtr *, QueueNodePtr * );
int isEmpty( QueueNodePtr );
void printQueue ( QueueNodePtr );
void instructions( void );

int main( void )
{
	QueueNodePtr headPtr = NULL;
	QueueNodePtr tailPtr = NULL;
	int choice;
	char item;
	
	instructions();
	printf("? ");
	scanf("%d%*c", &choice);
	
	while( choice != 3 ){
		switch(choice){
			case 1:
				printf( "Enter a character: " );
				scanf( "%c%*c", &item );
				
				enqueue( &headPtr, &tailPtr, item );
				printQueue( headPtr );
				break;
			case 2:
				if( !isEmpty( headPtr ) ) {
					item = dequeue( &headPtr, &tailPtr );
					printf( "%c deleted\n", item );
					printQueue( headPtr );
				}
				else {
					printf( "Queue is empty\n" );
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

void enqueue( QueueNodePtr *topPtr, QueueNodePtr *bottomPtr, const char value )
{
	QueueNodePtr newPtr;
	
	newPtr = ( QueueNodePtr ) malloc( sizeof( QueueNode ) );
	
	if( newPtr != NULL ) {
		newPtr->data = value;
		newPtr->nextPtr = NULL;
		
		
		if( isEmpty( *topPtr ))
			*topPtr = newPtr;
		else
			( *bottomPtr )->nextPtr = newPtr;
		
		*bottomPtr = newPtr;	
	}
	else {
		printf("%c not inserted. Memory not available\n", value);
	}
}

char dequeue( QueueNodePtr *topPtr, QueueNodePtr *bottomPtr )
{
	QueueNodePtr tempPtr;
	char dequeuedValue;
	
	tempPtr = *topPtr;
	dequeuedValue = ( *topPtr )->data;
	*topPtr = ( *topPtr )->nextPtr;
	free( tempPtr );
	
	if( isEmpty( *topPtr ) )
		*bottomPtr = NULL;
	
	return dequeuedValue;
}

int isEmpty( QueueNodePtr sPtr )
{
	return sPtr == NULL;
}

void printQueue( QueueNodePtr currentPtr )
{	
	if( currentPtr == NULL )
		printf("The queue is empty\n");
	else {
		printf( "The queue is:\n" );
		
		while( currentPtr != NULL ){
			printf( "%c --> ", currentPtr->data );
			
			currentPtr = currentPtr->nextPtr;
		}
		
		printf("NULL\n\n");
	}	
}
void instructions( void )
{
	printf( "Enter your choice:\n"
 			" 1 to insert an element into the queue.\n"
 			" 2 to delete an element from the queue.\n"
 			" 3 to end.\n" );
}
