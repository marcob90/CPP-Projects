#ifndef HUGE_INTEGER
#define HUGE_INTEGER

class HugeInteger{
	public:
		HugeInteger();
		
		void input( const int, const int );
		void output() const;
		
		void sum( const HugeInteger & );
		void difference( const HugeInteger & );
		void multiply( const HugeInteger & );
		void divide( const HugeInteger & );
		void modulus( const HugeInteger & );
		void assign( const HugeInteger & );
		
		bool isEqualTo( const HugeInteger & ) const;
		bool isNotEqualTo( const HugeInteger & ) const;
		
		bool isGreaterThan( const HugeInteger & ) const;
		bool isLessThan( const HugeInteger & ) const;
		
		bool isGreaterThanOrEqualTo( const HugeInteger & ) const;
		bool isLessThanOrEqualTo( const HugeInteger & ) const;
		
		bool isZero() const;
		
		static const int DIM = 7;
		
	private:
		void rightShift( const int );
		void leftShift( const int );
		
		int hugeIntegerArray[ DIM ];
};
#endif
