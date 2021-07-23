#ifndef STRING_H
#define STRING_H

#include <iostream>

using namespace std;

class String
{
	friend ostream &operator<<( ostream &, const String & );
	friend istream &operator>>( istream &, String & );
	
	public:
		String( const char * = "" ); //default/conversion constructor
		String( const String & ); //copy constructor
		~String(); //destructor
		
		const String &operator=( const String & );
		const String &operator+=( const String & );
		
		bool operator!() const; //is String empty?
		bool operator==( const String & ) const; //test s1 == s2
		bool operator<( const String & ) const; //test s1 < s2
		
		//test s1 != s2
		bool operator!=( const String &right ) const
		{
			return !( *this == right );
		}
		//test s1 > s2
		bool operator>( const String &right ) const
		{
			return right < *this ;
		}
		//test s1 <= s2
		bool operator<=( const String &right ) const
		{
			return !( right < *this );
		}
		//test s1 >= s2
		bool operator>=( const String &right ) const
		{
			return !( *this < right );
		}
		
		char &operator[]( const int );  //modifiable lvalue
		char operator[]( const int ) const; //constant rvalue
		String operator()( const int, const int = 0 ) const;
		
		int getLength() const;
		
	private:
		int length; //lenght of the string (it doesn't include the null char)
		char *sPtr; //pointer to start of pointer-based string
		
		void setString( const char * ); //utility function
};

#endif
