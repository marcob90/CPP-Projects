#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct stackNode {
	int data;
	struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void convertToPostfix( char [], char [] );
void push( StackNodePtr *, const char );
char pop( StackNodePtr * );
char stackTop ( StackNodePtr );
int isEmpty( StackNodePtr );
void printStack ( StackNodePtr );
int isOperator( const char );
int precedence( const char, const char );

int main( void )
{
	char infixExpression[ 30 ] = "(3+8)*3^2-5*2/2+(2^2-2^1+3)-5";
	char postfixExpression[ 30 ] = "";
	
	printf( "Infix expression is: %s\n", infixExpression );
	
	convertToPostfix( infixExpression, postfixExpression );
	
	printf( "\nPostfix expression is: %s\n", postfixExpression );
	
	return 0;
}

void convertToPostfix( char infix[], char postfix[] )
{
	StackNodePtr stackPtr = NULL;
	size_t currentLength = strlen( infix );
	int i;
	
	push( &stackPtr, '(' );
	infix[ currentLength ] = ')';
	infix[ currentLength + 1 ] = '\0';
	
	for( i = 0; !isEmpty( stackPtr ); i++ ){
		currentLength = strlen( postfix );
		
		if( isdigit( infix[ i ] ) ){
			postfix[ currentLength ] = infix[ i ];
			postfix[ currentLength + 1 ] = '\0';
		}
		else if( infix[ i ] == '(' ){
			push( &stackPtr, '(' );
		}
		else if( isOperator( infix[ i ] ) ){
			while( isOperator( stackTop( stackPtr ) ) && precedence( stackTop( stackPtr ), infix[ i ] ) >= 0 ){
				postfix[ currentLength ] = pop( &stackPtr );
				postfix[ currentLength + 1 ] = '\0';
				currentLength = strlen( postfix );
			}
			
			push( &stackPtr, infix[ i ] );
		}
		else if( infix[ i ] == ')' ){
			while( stackTop( stackPtr ) != '(' ){
				postfix[ currentLength ] = pop( &stackPtr );
				postfix[ currentLength + 1 ] = '\0';
				currentLength = strlen( postfix );	
			}
			
			pop( &stackPtr );
		}
		else{
			printf( "Wrong expression!\n" );
			break;
		}
	}
}

int precedence( const char operator1, const char operator2 )
{
	int orderOp1, orderOp2;
	
	if( operator1 == '^' )
		orderOp1 = 1;
	else if( operator1 == '*' || operator1 == '/' || operator1 == '%' )
		orderOp1 = 2;
	else
		orderOp1 = 3;
	
	if( operator2 == '^' )
		orderOp2 = 1;
	else if( operator2 == '*' || operator2 == '/' || operator2 == '%' )
		orderOp2 = 2;
	else
		orderOp2 = 3;
	
	if( orderOp1 == orderOp2 )
		return 0;
	else if( orderOp1 < orderOp2 )
		return 1;
	else
		return -1;
}

int isOperator( const char op )
{
	if( op == '+' || op == '-' || op == '*' || op == '/' || op == '%' || op == '^' ) 
		return 1;
	
	return 0;
}

char stackTop( StackNodePtr topPtr )
{
	return topPtr->data;
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
