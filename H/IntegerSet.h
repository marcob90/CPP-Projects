#ifndef INTEGER_SET
#define INTEGER_SET

#include <vector>
#include <iostream>

class IntegerSet
{
	public:
		static const size_t size = 100;
		
		IntegerSet(); //default constructor
		IntegerSet( const int*, const size_t );
		IntegerSet &unionOfSets( const IntegerSet &, const IntegerSet & );
		IntegerSet &intersectionOfSets( const IntegerSet &, const IntegerSet & );
		IntegerSet &complementOfSets( const IntegerSet & );
		bool isEqualTo( const IntegerSet & );
		IntegerSet &insertElement( const int );
		IntegerSet &deleteElement( const int );
		void printSet();
		
	private:
		typedef std::vector< bool > set_t;
		set_t set;
		set_t::iterator i;
		
		bool setIsEmpty();
};

#endif
