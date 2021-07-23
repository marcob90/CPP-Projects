#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM_LIST_1 10
#define DIM_LIST_2 10

struct listNode {
	int data;
	struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert( ListNodePtr *, const int );
ListNodePtr merge( ListNodePtr, ListNodePtr );
int isEmpty( ListNodePtr );
void printList ( ListNodePtr );

int main( void )
{
	int i = 0;
	ListNodePtr startPtrList1 = NULL;
	ListNodePtr startPtrList2 = NULL;
	ListNodePtr mergedListPtr = NULL;
	
	srand( time( NULL ) );
	
	for( i = 0; i < DIM_LIST_1; i++){
		insert( &startPtrList1, rand() % 100 );
	}
	for( i = 0; i < DIM_LIST_2; i++){
		insert( &startPtrList2, rand() % 100 );
	}
	
	printList( startPtrList1 );
	printList( startPtrList2 );
	
	mergedListPtr = merge( startPtrList1, startPtrList2 );
	printList( mergedListPtr );

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

ListNodePtr merge( ListNodePtr sPtr1, ListNodePtr sPtr2 )
{
	ListNodePtr currentPtr = sPtr2;
	
	while( currentPtr != NULL ){
		insert( &sPtr1, currentPtr->data );
		currentPtr = currentPtr->nextPtr;
	}
	
	return sPtr1;
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
