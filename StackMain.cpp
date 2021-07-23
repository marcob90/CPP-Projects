#include "StackNew.h"

using namespace std;

//template function. It basically pushes elements till stack is full. It pops them then.
template < typename T >
void testStack( 
	Stack< T > &theStack,
	T value,
	T increment,
	const string &stackName )
{
	//push
	cout << "Pushing elements onto " << stackName << ":\n";
	while( theStack.push( value ) ){
		cout << value << ' ';
		value += increment;
	}
	
	//pop
	cout << "\nPopping elements off " << stackName << ":\n";
	while( theStack.pop( value ) )
		cout << value << ' ';
	
	cout << "\n\n";
}

int main()
{
	Stack< int > intStack;
	Stack< double > doubleStack( 5 );
	
	testStack( intStack, 4, 1, "intStack" );
	testStack( doubleStack, 1.1, 1.1, "doubleStack" );
	
	return 0;
}
