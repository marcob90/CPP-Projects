#include <stdio.h>
#include <stdlib.h>

struct listNode {
	char data;
	struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert( ListNodePtr *, const char );
char deleteNode( ListNodePtr *, const char );
int isEmpty( ListNodePtr );
void printList ( ListNodePtr );
void instructions( void );

int main( void )
{
	ListNodePtr startPtr = NULL;
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
				
				insert( &startPtr, item );
				printList( startPtr );
				break;
			case 2:
				if( !isEmpty( startPtr ) ) {
					printf( "Insert character to be deleted: ");
					scanf( "%c%*c", &item );
					
					if ( deleteNode( &startPtr, item) ) {
						printf( "%c deleted\n", item );
						printList( startPtr );
					}
					else
						printf( "Character not found in the list\n" );
				}
				else {
					printf( "List is empty\n" );
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

void insert( ListNodePtr *sPtr, const char value )
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
		printf("%c not inserted. Memory not available\n", value);
	}
}

char deleteNode( ListNodePtr *sPtr, const char value )
{
	ListNodePtr currentPtr;
	ListNodePtr previousPtr;
	ListNodePtr tempPtr;
	
	if( value == ( *sPtr )->data ) {
		tempPtr = *sPtr;
		*sPtr = ( *sPtr )->nextPtr;
		free( tempPtr );
		return value;
	}
	else {
		previousPtr = *sPtr;
		currentPtr = ( *sPtr )->nextPtr;
		
		while( currentPtr != NULL && value != currentPtr->data ){
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}

		if( currentPtr != NULL ){
			tempPtr = currentPtr;
			previousPtr->nextPtr = currentPtr->nextPtr;
			free( tempPtr );
			return value;
		}
	}
	
	return '\0';
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
void instructions( void )
{
	printf( "Enter your choice:\n"
 			" 1 to insert an element into the list.\n"
 			" 2 to delete an element from the list.\n"
 			" 3 to end.\n" );
}
