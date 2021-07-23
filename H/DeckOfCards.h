#ifndef DECK
#define DECK

#include "Card.h"

#include <vector>
#include <algorithm>

class DeckOfCards
{
	public:
		static const int SIZE = 52;
		
		DeckOfCards();
		void shuffle();
		Card &dealCard();
		bool moreCards() const;
		
	private:
		typedef std::vector< Card > deck_t;
		deck_t deck;
		deck_t::iterator it;
		
		int currentCard; //next card to deal
};

#endif
