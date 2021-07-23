#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

using namespace std;

class Array
{
	friend ostream &operator<<( ostream &, const Array & ); //output array
	friend istream &operator>>( istream &, Array & ); //input array
	
	public:
		explicit Array( int = 10 ); //constructor
		Array( const Array & ); //copy constructor 
		~Array(); //destructor
		int getSize() const;
		const Array &operator=( const Array & ); //return an rvalue
		bool operator==( const Array & ) const;
		
		bool operator!=( const Array &right ) const 
		{
			return ! ( *this == right ); //pure coding poetry
		}
		
		int &operator[]( const int ); //lvalue []
		int operator[]( const int ) const; //rvalue []
	
	private:
		int size; //size of array
		int *ptr; //pointer to array	
		
};
#endif
