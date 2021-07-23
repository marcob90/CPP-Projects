#include "PokerHand.h"

#include <iostream>

PokerHand::PokerHand( DeckOfCards &deck )
{
	for( int counter = 0; counter < HAND_DIM; counter++ ){
		hand.push_back( deck.dealCard() );
	}
}

void PokerHand::printHand() const
{
	for( int counter = 0; counter < HAND_DIM; counter++ ){
		std::cout << hand.at( counter ).toString();
	}
}

bool PokerHand::pair()
{
	int i, j;
	
	for( i = 0; i < HAND_DIM - 1; i++ ){
		for( j = i + 1; j < HAND_DIM; j++ ){
			if( hand.at( i ).getFace() == hand.at( j ).getFace() )
				return true;
		}
	}
	
	return false;
}
