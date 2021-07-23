#include "Card.h"

const std::string Card::faceStrings[ 13 ] = 
	{"Ace", "Deuce", "Three", "Four", 
	"Five", "Six", "Seven", "Eight", 
	"Nine", "Ten", "Jack", "Queen", "King"};
		
const std::string Card::suitStrings[ 4 ] = 
	{"Hearts", "Diamonds", "Clubs", "Spades"};
		
Card::Card( const int face_t, const int suit_t )
{
	this->face = ( face_t >= 1 && face_t <= 13 ) ? face_t : 1;
	this->suit = ( suit_t >= 1 && suit_t <= 4 ) ? suit_t : 1;
}

std::string Card::toString() const
{
	return faceStrings[ face - 1 ] + 
	" of " + suitStrings[ suit - 1 ] + "\n";
}

int Card::getFace() const
{
	return face;
}
