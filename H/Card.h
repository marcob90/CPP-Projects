#ifndef CARD
#define CARD

#include <string>

class Card
{
	public:
		Card( const int, const int );
		std::string toString() const;
		
		int getFace() const;		
	private:
		int face;
		int suit;
		
		const static std::string faceStrings[ 13 ];
		const static std::string suitStrings[ 4 ];
};

#endif
