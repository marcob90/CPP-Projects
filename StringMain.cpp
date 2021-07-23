#include "String.h"
#include <iostream>

using namespace std;

int main()
{
	String s1("Happy");
	String s2(" birthday");
	String s3;
	
	cout << "\ns1 is \"" << s1 << "\"; s2 is \""
	<< s2 << "\"; s3 is \"" << s3 << "\"\n\n"
	<< boolalpha 
	<< "The results of comparing s2 and s1:"
	<< "\ns2 == s1 yields " << ( s2 == s1 )
	<< "\ns2 != s1 yields " << ( s2 != s1 )
	<< "\ns2 >  s1 yields " << ( s2 >  s1 ) 
	<< "\ns2 <  s1 yields " << ( s2 <  s1 )
	<< "\ns2 >= s1 yields " << ( s2 >= s1 ) 
	<< "\ns2 <= s1 yields " << ( s2 <= s1 );
	
	cout << "\n\nTesting !s3:\n";
	
	if( !s3 ){
		cout << "s3 is empty; assigning s1 to s3;\n";
		s3 = s1; //test assignement operator
		cout << "s3 is \"" << s3 << "\"\n";
	}
	
	cout << "\ns1 += s2 yields s1 = ";
	s1 += s2;
	cout << s1 << endl;
	
	cout << "\ns1 += \" to you\" yields:\n";
	s1 += " to you";
	cout << "s1 = " << s1 << "\n\n";
	
	cout << "The substring of s1 starting at\n"
	<< "location 0 for 14 characters, s1(0, 14), is: "
	<< s1( 0, 14 ) << "\n\n";
	
	cout << "The substring of s1 starting at\n"
	<< "location 15, s1(15), is: "
	<< s1( 15 ) << "\n\n";
	
	//test of copy constructor
	String *s4Ptr = new String( s1 );
	cout << "\n*s4Ptr = " << *s4Ptr << "\n\n";
	
	cout << "Assigning *s4Ptr to *s4Ptr" << endl;
	*s4Ptr = *s4Ptr;
	cout << "*s4Ptr = " << *s4Ptr << "\n\n";
	
	delete s4Ptr;
	
	s1[ 0 ] = 'H';
	s1[ 6 ] = 'B';
	
	cout << "s1 is: " << s1 << "\n\n";
	
	cout << "s1[ 6 ] = " << s1[ 6 ] << "\n\n";
	 
	return 0;
}
