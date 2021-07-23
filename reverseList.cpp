#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listNode {
	char data;
	struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert( ListNodePtr *, const char );
ListNodePtr reverse( ListNodePtr );
int isEmpty( ListNodePtr );
void printList ( ListNodePtr );

int main( void )
{
	int i = 0;
	ListNodePtr startPtr = NULL;
	ListNodePtr reversePtr = NULL;
	char itemsList[50];
	
	scanf("%s%*c", itemsList);
	
	for( i = 0; itemsList[ i ] != '\0'; i++){
		insert( &startPtr, itemsList[ i ] );
	}
	
	printList( startPtr );
	
	printf( "I am creating a reversed copy...\n\n");
	
	reversePtr = reverse ( startPtr );
	
	printList( reversePtr );
	
	return 0;
}

ListNodePtr reverse( ListNodePtr sPtr )
{
	ListNodePtr newPtr;
	ListNodePtr currentPtr = sPtr;
	ListNodePtr previousPtr = NULL;
	
	while( currentPtr != NULL ){
		newPtr = ( ListNodePtr )malloc( sizeof( ListNode ) );
		newPtr->data = currentPtr->data;
		newPtr->nextPtr = previousPtr;
		
		previousPtr = newPtr;
		currentPtr = currentPtr->nextPtr;
	}
	
	return newPtr;
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
