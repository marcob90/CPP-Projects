#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct queueNode {
	int data;
	struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

void enqueue( QueueNodePtr *, QueueNodePtr *, const int );
int dequeue( QueueNodePtr *, QueueNodePtr * );
int isEmpty( QueueNodePtr );
int determineServiceTime( void );
int determineArriveTime( void );
void printQueue ( QueueNodePtr );

int main( void )
{
	QueueNodePtr headPtr = NULL;
	QueueNodePtr tailPtr = NULL;
	int customerId = 1;
	int servedCustomerId = 1;
	int arrivalTime = 0;
	int serviceTime;
	int minute = 0;
	int completionTime = 0;
	
	srand( time( NULL) );
	
	arrivalTime = determineArriveTime();
	minute = arrivalTime;
	completionTime = arrivalTime + determineServiceTime();
	
	printf( "Minute %d: customer %d has arrived\n", minute, customerId );
	printf( "Minute %d: Serving customer %d\n", minute, customerId );
	
	arrivalTime += determineArriveTime(); // determine arrival time of next customer
	
	while( minute <= 720*2*7 ){
		if( minute == arrivalTime ){
			printf( "Minute %d: %d has arrived\n", minute, ++customerId );
			
			if( servedCustomerId != 0) // if someone else is served, enqueue
				enqueue( &headPtr, &tailPtr, customerId );
			else // start to be served otherwise
				servedCustomerId = customerId;
			
			arrivalTime = minute + determineArriveTime(); // determine arrival time of next customer
		}
		
		if( minute == completionTime ){ // if customer has finished to be served
			printf( "Minute %d: service was completed for customer %d\n", minute, servedCustomerId );
			servedCustomerId = 0; // waiting for next customer to be served
			
			if( !isEmpty( headPtr ) ){  // if queue is not empty, dequeue next customer
				servedCustomerId = dequeue( &headPtr, &tailPtr );
				
				printf( "%20s %d started to be served\n", "customer", servedCustomerId ); 
				
				completionTime = minute + determineServiceTime();
			}
			else // determine next customer's time of completion otherwise and wait for his arrival
				completionTime = arrivalTime + determineServiceTime();
		}
		printf( "Minute %d: ", minute );
		printQueue( headPtr );
		printf( "\n" );
	
		minute++;
	}
	
	return 0;
}

void enqueue( QueueNodePtr *topPtr, QueueNodePtr *bottomPtr, const int value )
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
		printf("%d not inserted. Memory not available\n", value);
	}
}

int dequeue( QueueNodePtr *topPtr, QueueNodePtr *bottomPtr )
{
	QueueNodePtr tempPtr;
	int dequeuedValue;
	
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

int determineServiceTime( void )
{
	return rand() % 4 + 1;
}

int determineArriveTime( void )
{
	return rand() % 4 + 1;
}

void printQueue( QueueNodePtr currentPtr )
{	
	if( currentPtr == NULL )
		printf("The queue is empty\n");
	else {
		printf( "The queue is:\n" );
		
		while( currentPtr != NULL ){
			printf( "%d --> ", currentPtr->data );
			
			currentPtr = currentPtr->nextPtr;
		}
		
		printf("NULL\n\n");
	}	
}
