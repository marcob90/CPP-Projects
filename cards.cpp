#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	const char *suit;
	const char *face;
}Card;

void fillDeck(Card * const wDeck, const char * const wSuite[], const char * const wFace[]);
void shuffle(Card * const wDeck);
void deal(const Card * const wDeck);

int main(){
	const char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
	const char *face[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
	"Nine", "Ten", "Jack", "Queen", "King"};
	
	Card deck[52];
	
	fillDeck(deck, suit, face);
	
	shuffle(deck);
	
	deal(deck);
	
	return 0;
}

void fillDeck(Card * const wDeck, const char * const wSuit[], const char * const wFace[]){
	int c; // counter
	
	for(c = 0; c < 52; c++){
		wDeck[ c ].suit = wSuit[ c / 13 ];
		wDeck[ c ].face = wFace[ c % 13 ];
	}
	
}

void shuffle(Card * const wDeck){
	int c; // counter
	int j; //variable to hold the position of the card in the deck
	Card temp;
	
	srand(time(NULL));
	
	for(c = 0; c < 52; c++){
		j = rand() % 52;
		temp = wDeck[ c ];
		wDeck[ c ] = wDeck[ j ];
		wDeck[ j ] = temp;
	}
	
}

void deal(const Card * const wDeck){
	int c; // counter
	
	for(c = 0; c < 52; c++){
		printf("%5s of %-8s", wDeck[c].face, wDeck[c].suit);
		
		(c + 1) % 4 == 0 ? putchar('\n') : printf("  ");
	}
	
}
