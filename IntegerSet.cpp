#include "IntegerSet.h"

using namespace std;

//the default constructor creates an empty set
IntegerSet::IntegerSet() : set( size )
{
	//empty body
}

IntegerSet::IntegerSet( const int *array, const size_t arraySize )
: set( size )
{
	for( int counter = 0; counter < arraySize; counter++ )
		this->set.at( *( array + counter ) ) = true;
}

IntegerSet &IntegerSet::unionOfSets( const IntegerSet &s1, const IntegerSet &s2 )
{
	for( i = this->set.begin(); i != this->set.end(); i++ )
		if( s1.set.at( i - this->set.begin() ) == true 
		|| s2.set.at( i - this->set.begin() ) == true )
			*i = true;
	
	return ( *this );
}

IntegerSet &IntegerSet::intersectionOfSets( const IntegerSet &s1, const IntegerSet &s2 )
{
	for( i = this->set.begin(); i != this->set.end(); i++ )
		if( s1.set.at( i - this->set.begin() ) == true 
		&& s2.set.at( i - this->set.begin() ) == true )
			*i = true;
	
	return ( *this );
}

IntegerSet &IntegerSet::complementOfSets( const IntegerSet &s1 )
{
	for( i = this->set.begin(); i != this->set.end(); i++ ){
		if( s1.set.at( i - this->set.begin() ) == true )
			*i = false;
		else
			*i = true;
	}
	
	return ( *this );
}

bool IntegerSet::isEqualTo( const IntegerSet &s2 )
{
	return ( this->set == s2.set );
}

IntegerSet &IntegerSet::insertElement( const int element )
{
	if( element >= 0 && element < size )
		this->set.at( element ) = true;
	else
		cout << "***Element is out of range. No element was inserted***\n";

	return ( *this );
}

IntegerSet &IntegerSet::deleteElement( const int element )
{
	if( element >= 0 && element < size )
		this->set.at( element ) = false;
	else
		cout << "***Element is out of range. No element was inserted***\n";
	
	return ( *this );
}

void IntegerSet::printSet()
{
	if( !setIsEmpty() ){
		for( i = this->set.begin(); i != this->set.end(); i++ ){
			if( *i == true )
				cout << ( i - this->set.begin() ) << " ";
		}
	}
	else
		cout << "---";
	
	cout << "\n";
}

bool IntegerSet::setIsEmpty()
{
	for( i = this->set.begin(); i != this->set.end(); i++ ){
		if( *i == true )
			return false;
	}
	
	return true;
}
