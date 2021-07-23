#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_LIST_1 5
#define DIM_LIST_2 7

struct listNode {
	char data;
	struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert( ListNodePtr *, const char );
void concatenate ( ListNodePtr, ListNodePtr );
int isEmpty( ListNodePtr );
void printList ( ListNodePtr );

int main( void )
{
	int i = 0;
	ListNodePtr startPtrList1 = NULL;
	ListNodePtr startPtrList2 = NULL;
	char itemsList1[DIM_LIST_1] = { 'M', 'A', 'R', 'C', 'O'};
	char itemsList2[DIM_LIST_2] = { 'B', 'O', 'N', 'G', 'I', 'N', 'I'};
	
	for( i = 0; i < DIM_LIST_1; i++){
		insert( &startPtrList1, itemsList1[ i ]);
	}
	for( i = 0; i < DIM_LIST_2; i++){
		insert( &startPtrList2, itemsList2[ i ]);
	}
	
	printList( startPtrList1 );
	printList( startPtrList2 );
    concatenate( startPtrList1, startPtrList2 );
	
	printList( startPtrList1 );

	return 0;
}

void concatenate( ListNodePtr sPtr1, ListNodePtr sPtr2 )
{
	ListNodePtr currentPtr;
	
	currentPtr = sPtr1;
	
	while( currentPtr->nextPtr != NULL ){
		currentPtr = currentPtr->nextPtr;
	}
	
	currentPtr->nextPtr = sPtr2;
}

void insert( ListNodePtr *sPtr, const char value )
{
	ListNodePtr newPtr;
	ListNodePtr currentPtr;
	
	newPtr = ( ListNodePtr ) malloc( sizeof( ListNode ) );
	
	if( newPtr != NULL ) {
		newPtr->data = value;
		newPtr->nextPtr = NULL;
	
		currentPtr = *sPtr;
		
		if( *sPtr == NULL ){
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}
		else{
			while( currentPtr->nextPtr != NULL ) {
				currentPtr = currentPtr->nextPtr;
			}
			
			currentPtr->nextPtr = newPtr;
		}
	}
	else {
		printf("%c not inserted. Memory not available\n", value);
	}
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
			printf( "%c --> ", currentPtr->data );
			
			currentPtr = currentPtr->nextPtr;
		}
		
		printf("NULL\n\n");
	}	
}
