#ifndef POKERHAND
#define POKERHAND

#include <vector>
#include "DeckOfCards.h"
#include "Card.h"

class PokerHand{
	public:
		const static int HAND_DIM = 5;
		
		PokerHand( DeckOfCards & );
		
		void printHand() const;
		bool pair();
	private:
		typedef std::vector< Card > hand_t;
		hand_t hand;
};
#endif
