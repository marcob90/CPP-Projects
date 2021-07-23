#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

#include "Card.h"
#include "DeckOfCards.h"
#include "PokerHand.h"

int main()
{
	srand( time( NULL ) );
	
	DeckOfCards myDeck;
	myDeck.shuffle();
	
	PokerHand myHand( myDeck );
	
	myHand.printHand();
	
	if( myHand.pair() )
		std::cout << "Pair!" << std::endl;
}
