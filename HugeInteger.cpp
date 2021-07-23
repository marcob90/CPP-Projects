#include <iostream>

#include "HugeInteger.h"

using namespace std;

HugeInteger::HugeInteger()
{
	for( int i = 0; i < DIM; i++ ){
		hugeIntegerArray[ i ] = 0;
	}
}

void HugeInteger::input( const int index, const int number )
{
	hugeIntegerArray[ index ] = ( number < 10 && number >= 0 ) ? number : 0;
}

void HugeInteger::output() const
{
	for( int i = 0; i < DIM; i++ ){
		cout << hugeIntegerArray[ i ];
	}
	
	cout << endl;
}

void HugeInteger::sum( const HugeInteger &number2 )
{
	int sumOfDigits;
	int carry = 0;
	
	for( int i = DIM - 1 ; i >= 0; i-- ){
		sumOfDigits = hugeIntegerArray[ i ] + number2.hugeIntegerArray[ i ] + carry;
		
		if( sumOfDigits > 9 ){
			hugeIntegerArray[ i ] = sumOfDigits % 10;
			carry = 1;
		}
		else{
			hugeIntegerArray[ i ] = sumOfDigits;
			carry = 0;
		}
	}
	
	if( carry == 1 )
		cout << "Sum out of range\n";
}

void HugeInteger::difference( const HugeInteger &number2 )
{
	int carry = 0;
	
	for( int i = DIM - 1 ; i >= 0; i-- ){
		
		if( hugeIntegerArray[ i ] < number2.hugeIntegerArray[ i ] + carry ){
			hugeIntegerArray[ i ] = hugeIntegerArray[ i ] + 10 - ( number2.hugeIntegerArray[ i ] + carry );
			carry = 1;
		}
		else{
			hugeIntegerArray[ i ] = hugeIntegerArray[ i ] - ( number2.hugeIntegerArray[ i ] + carry );
			carry = 0;
		}
	}
	
	if( carry == 1 ){
		//cout << "Difference is negative\n";
		//difference( *this ); //set number to zero
	}
}

void HugeInteger::multiply( const HugeInteger &number2 )
{
	HugeInteger partialResultsArray[ DIM ];
	int partialFactor;
	int carry = 0;
	
	for( int i = 0 ; i < DIM; i++ ){
		for( int j = DIM - 1 ; j >= 0; j-- ){
			partialFactor = hugeIntegerArray[ j ] * number2.hugeIntegerArray[ DIM - 1 - i ];
			
			//check Overflow
			if( j < i && partialFactor != 0 ){
				cout << "Overflow!\n";
				return;
			}
			else if( j < i && partialFactor == 0)
				continue;
			
			if( partialFactor < 10 ){
				partialResultsArray[ i ].hugeIntegerArray[ j - i ] = partialFactor + carry;
				carry = 0;
			}
			else{
				partialResultsArray[ i ].hugeIntegerArray[ j - i ] = partialFactor % 10 + carry;
				carry = partialFactor / 10;
			}
		}
		
		if( carry != 0 ){
			cout << "Overflow!\n";
			return;
		}
	}

	difference( *this ); //set number to zero
	
	for( int i = 0 ; i < DIM; i++ ){
		sum( partialResultsArray[ i ] );
	}
}

/*This function is based on a long division algorithm.
A plateau is builded to calculate the result.
The plateau uses the American standard notation for long division*/
void HugeInteger::divide( const HugeInteger &divider )
{
	HugeInteger resultInteger; //final result
	HugeInteger topInteger; //top value of a plateau layer
	HugeInteger bottomInteger; //bottom value of a plateau layer
	HugeInteger divisor; 
	HugeInteger scalarInteger; //simple scalar number represented by HugeInteger class
	int counter;
	
	if( divider.isZero() ){
		cout << "Warning! Zero Division exception.";
		return;
	}
	
	//initialization of the plateau
	bottomInteger.hugeIntegerArray[ 0 ] = this->hugeIntegerArray[ 0 ];
	
	//division routine starts
	for(int i = 0; i < DIM; i++ ){
		//build the divisor
		divisor.assign( bottomInteger );
		divisor.rightShift( DIM - 1 - i );
		
		//this loop finds the result divisor / divider by repeated subtractions
		for( counter = 0; divisor.isGreaterThanOrEqualTo( divider ); counter++ ){
			divisor.difference( divider );
		}
		
		//save the result 
		resultInteger.hugeIntegerArray[ i ] = counter;
		
		//get the scalar for next multiplication
		scalarInteger.hugeIntegerArray[ DIM - 1 ] = counter;
		
		//calculate the top value of current plateau layer
		topInteger.assign( divider );
		topInteger.multiply( scalarInteger );
		topInteger.leftShift( DIM - 1 - i );
		
		//calculate the bottom value of the next plateau layer
		bottomInteger.difference( topInteger );
		
		//pull down a digit from the main divisor to the bottom layer
		if( i != DIM - 1 )
			bottomInteger.hugeIntegerArray[ i + 1 ] = this->hugeIntegerArray[ i + 1 ];
	}
	
	this->assign( resultInteger );
}

void HugeInteger::modulus( const HugeInteger &divider )
{
	HugeInteger tempInteger;
	
	tempInteger.assign( *this );
	
	tempInteger.divide( divider );
	tempInteger.multiply( divider );
	this->difference( tempInteger );
}

void HugeInteger::assign( const HugeInteger &number2 )
{
	for( int i = 0 ; i < DIM; i++ ){
		this->hugeIntegerArray[ i ] = number2.hugeIntegerArray[ i ];
	}
}

void HugeInteger::rightShift( const int s )
{
	HugeInteger tempInteger;
	
	tempInteger.assign( *this );
	
	for( int i = 0 ; i + s < DIM; i++ ){
		hugeIntegerArray[ i + s ] = tempInteger.hugeIntegerArray[ i ];
	}
	
	for( int i = 0 ; i < s; i++ ){
		hugeIntegerArray[ i ] = 0;
	}
}

void HugeInteger::leftShift( const int s )
{
	HugeInteger tempInteger;
	
	tempInteger.assign( *this );
	
	for( int i = DIM - 1 ; i - s >= 0; i-- ){
		hugeIntegerArray[ i - s ] = tempInteger.hugeIntegerArray[ i ];
	}
	
	for( int i = DIM - 1 ; DIM - 1 - i < s; i-- ){
		hugeIntegerArray[ i ] = 0;
	}
}

bool HugeInteger::isEqualTo( const HugeInteger &number2 ) const
{
	for( int i = 0 ; i < DIM; i++ ){
		if( hugeIntegerArray[ i ] != number2.hugeIntegerArray[ i ] )
			return false;
	}
	
	return true;
}

bool HugeInteger::isNotEqualTo( const HugeInteger &number2 ) const
{
	return !isEqualTo( number2 );
}

bool HugeInteger::isGreaterThan( const HugeInteger &number2 ) const
{
	for( int i = 0 ; i < DIM; i++ ){
		if( hugeIntegerArray[ i ] > number2.hugeIntegerArray[ i ] )
			return true;
		else if( hugeIntegerArray[ i ] < number2.hugeIntegerArray[ i ] )
			return false;
	}
}

bool HugeInteger::isLessThan( const HugeInteger &number2 ) const
{
	return !isGreaterThan( number2 ) && isNotEqualTo( number2 );
}

bool HugeInteger::isGreaterThanOrEqualTo( const HugeInteger &number2 ) const
{
	return !isLessThan( number2 );
}

bool HugeInteger::isLessThanOrEqualTo( const HugeInteger &number2 ) const
{
	return !isGreaterThan( number2 );
}

bool HugeInteger::isZero() const
{
	for( int i = 0 ; i < DIM; i++ ){
		if( hugeIntegerArray[ i ] != 0 )
			return false;
	}
	
	return true;
}


