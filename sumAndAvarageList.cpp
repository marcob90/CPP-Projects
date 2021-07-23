#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM_LIST 25

struct listNode {
	int data;
	struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert( ListNodePtr *, const int );
int sum( ListNodePtr );
int isEmpty( ListNodePtr );
void printList ( ListNodePtr );

int main( void )
{
	int i = 0;
	int result;
	ListNodePtr startPtr = NULL;
	
	srand( time( NULL ) );
	
	for( i = 0; i < DIM_LIST; i++){
		insert( &startPtr, rand() % 101 );
	}
	
	printList( startPtr );
	
	printf( "The sum of elements of the list is: %d\n", result = sum( startPtr ) );
	printf( "The average is: %.2f\n", ( float )result / DIM_LIST);

	return 0;
}

void insert( ListNodePtr *sPtr, const int value )
{
	ListNodePtr newPtr;
	ListNodePtr currentPtr;
	ListNodePtr previousPtr;
	
	newPtr = ( ListNodePtr ) malloc( sizeof( ListNode ) );
	
	if( newPtr != NULL ) {
		newPtr->data = value;
		newPtr->nextPtr = NULL;
	
		currentPtr = *sPtr;
		previousPtr = NULL;
		
		while( currentPtr != NULL && value > currentPtr->data ) {
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		
		if( previousPtr == NULL ){
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}
		else{
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}
	else {
		printf( "%d not inserted. Memory not available\n", value );
	}
}

int sum( ListNodePtr sPtr )
{
	ListNodePtr currentPtr = sPtr;
	int total = 0;
	
	while( currentPtr != NULL ){
		total += currentPtr->data;
		currentPtr = currentPtr->nextPtr;
	}
	
	return total;
}

int isEmpty( ListNodePtr sPtr )
{
	return sPtr == NULL;
}

void printList( ListNodePtr currentPtr )
{	
	if( currentPtr == NULL )
		printf("The list is empty\n");
	else {
		printf( "The list is:\n" );
		
		while( currentPtr != NULL ){
			printf( "%d --> ", currentPtr->data );
			
			currentPtr = currentPtr->nextPtr;
		}
		
		printf("NULL\n\n");
	}	
}
