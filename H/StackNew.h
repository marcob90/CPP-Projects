#ifndef STACK_H
#define STACK_H

#include <bits/stdc++.h>
using namespace std;

//template class
template < typename T >
class Stack
{
	public:
		Stack( int = 10 ); //default constructor
		
		//destructor
		~Stack()
		{
			//delete stackPtr;
		}
		
		bool push( const T & );
		bool pop( T & );
		
		//is stack empty?
		bool isEmpty() const
		{
			return top == -1;
		}
		
		//is stack full?
		bool isFull() const
		{
			return top == size - 1;
		}
		
	private:
		int top; //location of the top element
		int size; //size of the stack
		vector< T > stackPtr; //pointer to stack
};

//constructor template 
template < typename T >
Stack< T >::Stack( int s )
	: size( s > 0 ? s : 10 ),
	  top( - 1 ),
	  stackPtr( vector< T >(size) )
{
	//empty body
}

//push onto stack
template < typename T >
bool Stack< T >::push( const T &pushValue)
{
	if( !isFull() ){
		stackPtr[++top] = pushValue;
		return true;
	}
	
	return false;
}

//pop element off stack
template < typename T >
bool Stack< T >::pop( T &popValue )
{
	if( !isEmpty() ){
		popValue = stackPtr[ top-- ];
		return true;
	}
	
	return false;
}


#endif
