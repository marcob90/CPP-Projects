#include "Array.h"

using namespace std;

ostream &operator<<( ostream &output, const Array &array )
{
	for( int i = 0; i < array.size; i++ )
		output << array.ptr[ i ]<< " ";
	
	return output;
}

istream &operator>>( istream &input, Array &array )
{
	int i;
	
	for( i = 0; i < array.size; i++ )
		input >> array.ptr[ i ];
	
	return input;
}

Array::Array( int arraySize )
{
	size = ( arraySize > 0 ) ? arraySize : 10;
	ptr = new int[ size ];
	
	for( int i = 0; i < size; i++ ) //initialize array with 0s
		ptr[ i ] = 0;
}

Array::Array(const Array &arrayToCopy)
	: size(arrayToCopy.getSize())
{
	ptr = new int[size];
	
	for( int i = 0; i < size; i++ )
		ptr[ i ] = arrayToCopy.ptr[i];
}

Array::~Array()
{
	delete [] ptr;
}

int Array::getSize() const
{
	return size;
}

const Array &Array::operator=( const Array &right )
{
	if( &right != this ){  //avoid self-assignment
		
		/*for arrays of different sizez, deallocates first arrays
		and allocate new memory*/
		if( size != right.size ){
			delete [] ptr;
			size = right.getSize();
			
			ptr = new int[ size ];
		}
			
		for( int i = 0; i < size; i++ )
			ptr[ i ] = right.ptr[ i ];
	}
	
	return *this;
}

bool Array::operator==( const Array &right ) const
{
	if( getSize() != right.getSize() )
		return false;
	
	for( int i = 0; i < getSize(); i++ ) 
		if( ptr[ i ] != right.ptr[ i ])
			return false;
	
	return true;
}

//rvalue[]
int Array::operator[]( const int subscript ) const
{
	if( subscript >= 0 && subscript < size )
		return ptr[ subscript ];
		
	cerr << "\nError 5050: Subscript " << subscript <<
	"Out of range\n";
	
	exit(1);
}

//lvalue[]
int &Array::operator[]( const int subscript ) //the reference creates a modifiable lvalue
{
	if( subscript >= 0 && subscript < size )
		return ptr[ subscript ];
		
	cerr << "\nError 5050: Subscript " << subscript <<
	"Out of range\n";
	
	exit(1);
}


