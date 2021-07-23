#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

struct stackNode {
	int data;
	struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

int evaluatePostfixExpression( char [] );
void push( StackNodePtr *, const int );
int pop( StackNodePtr * );
int calculate ( const int, const int, const char );
int isEmpty( StackNodePtr );
void printStack ( StackNodePtr );

int main( void )
{
	char postfixExpression[ 100 ] = "12 3 * 3 ^";
	int result;
	
	printf( "Postfix expression is: %s\n", postfixExpression );
	
	result = evaluatePostfixExpression( postfixExpression );
	
	printf( "Result is: %d\n", result );
	
	return 0;
}

int evaluatePostfixExpression( char postfix[] )
{
	int getNumberDigits( char * );
	int calculateNumber( char *, const int );
	
	StackNodePtr stackPtr = NULL;
	int i;
	int digits, number;
	int x, y, result;
	
	for( i = 0; postfix[ i ] != '\0'; ){
		if( isdigit( postfix[ i ] ) ){
			digits = getNumberDigits( &postfix[ i ] );
			
			number = calculateNumber( &postfix[ i ], digits );

			push( &stackPtr, number );
			
			i += digits;
		}
		else if( postfix[ i ] == ' '){
			i++;
		}
		else{
			x = pop( &stackPtr );
			y = pop( &stackPtr );
			
			result = calculate( y, x, postfix[ i ] ); 
			push( &stackPtr, result );
			i++;
		}
		printStack( stackPtr );
	}
	
	return pop( &stackPtr ); 
}

int calculateNumber( char *pfix, const int dim )
{
	int i;
	int num = 0;
	
	for( i = 0; i < dim; i++ ){
		num +=  ( *( pfix + ( dim - i - 1 ) ) - '0' ) * pow( 10, i );
	}
	
	return num;
}

int getNumberDigits( char *num )
{
	int j;
	int counter = 0;
	
	for( j = 0; *(num + j) != ' ' && *(num + j) != '\0'; j++ ){
		counter++;
	}
	
	return counter;
}

int calculate( const int op1, const int op2, const char operation )
{
	switch( operation ){
		case '+':
			return op1 + op2;
		break;
		case '-':
			return op1 - op2;
		break;
		case '*':
			return op1 * op2;
		break;
		case '/':
			return op1 / op2;
		break;
		case '%':
			return op1 % op2;
		break;
		case '^':
			return pow( op1, op2 );
		break;
		default:
			printf( "Wrong expression" );
			return '\0';
	}
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
