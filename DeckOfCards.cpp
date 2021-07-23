#include "DeckOfCards.h"
#include <stdlib.h>

DeckOfCards::DeckOfCards() :
currentCard( 52 )
{
	for( int nFace = 1; nFace <= 13; nFace++ ){
		for( int nSuit = 1; nSuit <= 4; nSuit++ ){
			deck.push_back( Card( nFace, nSuit ) );
		}
	}
}

Card &DeckOfCards::dealCard()
{
	return ( deck.at( --currentCard ) );
}

bool DeckOfCards::moreCards() const
{
	return ( currentCard > 0 ) ? 1 : 0;
}

void DeckOfCards::shuffle()
{		
	for( it = deck.begin(); it != deck.end(); it++ ){
		iter_swap( it, deck.begin() + rand() % 52 );
	}
}
