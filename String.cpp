#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include "String.h"

using namespace std;

//default/conversion constructor
String::String( const char *s )
 : length( ( s != 0 ) ? strlen( s ) : 0 )
{
	cout << "Conversion/default constructor: " << s << endl;
	setString( s );
}

//copy constructor
String::String( const String &s )
 : length( s.length )
{
	cout << "Copy constructor: " << s << endl;
	setString( s.sPtr );
}

//utility function called by constructors and = operator
void String::setString( const char *string2 )
{
	sPtr = new char[ length + 1 ]; //allocate memory
	
	if( string2 != NULL )
		strcpy( sPtr, string2 );
	else
		sPtr[ 0 ] = '\0';
}

//destructor
String::~String()
{
	cout << "Destructor: " << sPtr << endl;
	delete [] sPtr; //release pointer-based string memory
}

//overloaded assignement operator
const String &String::operator=( const String &right )
{
	cout << "Operator= called\n";
	
	if( &right != this ){ //avoid self-assignement
		delete [] sPtr; //memory reallocation
		length = right.length;
		setString( right.sPtr );
	}
	else
		cout << "Attempted to assign a string to itself\n";
	
	return ( *this ); //enables cascading
}

//overloaded concatenation operator
const String &String::operator+=( const String &right )
{
	int newLength = right.length + length;
	char *tempPtr = new char[ newLength + 1 ]; //create memory
	
	strcpy( tempPtr, sPtr );
	strcpy( tempPtr + length, right.sPtr );
	
	delete [] sPtr;
	length = newLength;
	sPtr = tempPtr;
	return ( *this ); //enables cascading
}

//overloaded ! operator
bool String::operator!() const
{
	return length == 0;
}

//overloaded == operator
bool String::operator==( const String &right ) const
{
	return strcmp( sPtr, right.sPtr ) == 0;
}

//overloaded < operator
bool String::operator<( const String &right ) const
{
	return strcmp( sPtr, right.sPtr ) < 0;
}

//overloaded [] for modifiable lvalue
char &String::operator[]( const int subscript )
{
	if( subscript >= 0 && subscript < length )
		return sPtr[ subscript ];
		
	cerr << "\nError 5050: Subscript " << subscript <<
	"Out of range\n";
	
	exit(1);
}

//overloaded [] for constant rvalue
char String::operator[]( const int subscript ) const
{
	if( subscript >= 0 && subscript < length )
		return sPtr[ subscript ];
		
	cerr << "\nError 5050: Subscript " << subscript <<
	"Out of range\n";
	
	exit(1);
}

//return a substring from index of length subLength
String String::operator()( const int index, const int subLength	) const
{
	//if index is out of range or subLength is negative
	//return an empty string
	if( index < 0 || index >= length || subLength < 0 )
		return ""; //converted implicitly to String
	
	int len; //determin length of substring
	
	if( ( subLength == 0 ) || ( index + subLength > length ) )
		len = length - index;
	else
		len = subLength;
	
	char *tempPtr = new char[ len + 1 ];
	
	strncpy( tempPtr, sPtr + index, len );
	tempPtr[ len ] = '\0';
	
	String tempString( tempPtr );
	delete [] tempPtr;
	return tempString; //return copy of temporary String
}

int String::getLength() const
{
	return length;
}

//overloaded output operator
ostream &operator<<( ostream &output, const String &s )
{
	output << s.sPtr;
	
	return output; //enable cascading
}

//overloaded input operator
istream &operator>>( istream &input, String &s )
{
	char buffer[ 100 ]; //buffer to store input
	
	input >> setw( 100 ) >> buffer;
	s = buffer;
	return input; //enable cascading
}
