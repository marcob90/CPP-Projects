#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 10

struct listNode {
	int data;
	struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert( ListNodePtr *, const int );
int isEmpty( ListNodePtr );
void printList ( ListNodePtr );
void printListBackwards( ListNodePtr );
ListNodePtr searchList( ListNodePtr, const int );

int main( void )
{
	int i;
	ListNodePtr startPtr = NULL;
	int items[ DIM ];
	int object;
	
	srand( time( NULL ) );
	
	for( i = 0; i < DIM; i++){
		items[ i ] = rand() % 15;
		insert( &startPtr, items[ i ] );
	}
	
	printList( startPtr );
	
	printListBackwards( startPtr );
	printf( "NULL\n\n" );
	
	printf( "Insert a value to search: " );
	scanf( "%d", &object );
	
	( searchList( startPtr, object ) == NULL ) ? printf( "Value not found\n" ) : printf( "Value found" );
	
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
		printf("%d not inserted. Memory not available\n", value);
	}
}

int isEmpty( ListNodePtr sPtr )
{
	return sPtr == NULL;
}

ListNodePtr searchList( ListNodePtr currentPtr, int key )
{
	if( currentPtr != NULL ){
		if( currentPtr->data == key )
			return currentPtr;
		else
			return searchList( currentPtr->nextPtr, key );
	}
	
	return NULL;
}

void printListBackwards( ListNodePtr currentPtr )
{
	if( currentPtr != NULL ){
		printListBackwards( currentPtr->nextPtr );
		
		printf( "%d --> ", currentPtr->data );
	}
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
