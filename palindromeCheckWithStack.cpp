#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct stackNode {
	int data;
	struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push( StackNodePtr *, const char );
char pop( StackNodePtr * );
int isEmpty( StackNodePtr );
void printStack ( StackNodePtr );
void removePunctuation( char [], const int );

int main( void )
{
	int i;
	StackNodePtr stackPtr = NULL;
	char sentence[ 200 ];
	char reversedSentence[ 200 ];
	
	fgets( sentence, 200, stdin );
	
	removePunctuation( sentence, strlen( sentence ) );
	
	for( i = 0; sentence[ i ] != '\0'; i++ ) {
		push( &stackPtr, sentence[ i ] );
	}
	
	printStack( stackPtr );
	
	for( i = 0; !isEmpty( stackPtr ); i++ ){
		reversedSentence[ i ] = pop( &stackPtr );
	}
	reversedSentence[ i ] = '\0';
	
	if( !strcmp( sentence, reversedSentence ) )
		printf( "Sentence is palindrome\n" );
	else
		printf( "Sentence is not palindrome\n" );
	
	return 0;
}

void push( StackNodePtr *topPtr, const char value )
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

char pop( StackNodePtr *topPtr )
{
	StackNodePtr tempPtr;
	char popValue;
	
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

void removePunctuation(char s[], const int size){
	int i, j;
	int counter = 0;
	
	while( counter < size - 1 ){
		for( i = 0; s[i] != '\0'; i++ )
			if( ispunct( s[ i ] ) || isspace( s[ i ] ) )
				for( j = i; s[j] != '\0'; j++ )
					s[ j ] = s[ j + 1 ];
		
		counter++;
	}
}
