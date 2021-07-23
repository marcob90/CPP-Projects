#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define HAND_SIZE 5

void shuffle(int [][13]);
void initDeck(int [][13]);
void deal(const int [][13], const char *[], const char *[], const char *[][HAND_SIZE], const int);
int pair(const char *[], const int);
int twopairs(const char *[], const int);
int threeOfAKind(const char *[], const int);
int fourOfAKind(const char *[], const int);
int flush(const char *[], const int);
int straight(const char *[][HAND_SIZE], const int, const char*[]);

int main(){
	int games = 1;
	int counter[6] = {0};
	int deck[4][13] = {0};
	const char *hand[2][HAND_SIZE];
	const char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
	const char *face[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
	"Nine", "Ten", "Jack", "Queen", "King"};
	
	srand(time(NULL));
	initDeck(deck);

	while(games <= 1000){
	initDeck(deck);
	shuffle(deck);
	
	printf("Your hand:\n\n");
	deal(deck, suit, face, hand, HAND_SIZE);
	
	if(pair(hand[0], HAND_SIZE)){
		counter[0]++;
	}
	if(twopairs(hand[0], HAND_SIZE)){
		counter[1]++;
	}
	if(threeOfAKind(hand[0], HAND_SIZE)){
		counter[2]++;
	}
	if(fourOfAKind(hand[0], HAND_SIZE)){
		counter[3]++;
	}
	if(flush(hand[1], HAND_SIZE)){
		counter[4]++;
	}
	if(straight(hand, HAND_SIZE, face)){
		counter[5]++;
	}
	
	games++;
	}
	
	printf("\nPairs: %d\nTwoPairs: %d\nThree of a kind: %d\nFour of a kind: %d\nFlush: %d\nStraight: %d\n", counter[0], counter[1],counter[2],counter[3],counter[4],counter[5]);
	return 0;
}

void shuffle(int wDeck[][13]){
	void swapCards(int *, int *);
	int row, column;
	int pass = 0;
	
	while(pass < 10){
		for(row = 0; row < 4; row++){
			for(column = 0; column < 13; column++){
				swapCards(&wDeck[row][column], &wDeck[rand() % 4][rand() % 13]);
			}
		}
		pass++;
	}
}

void swapCards(int *card1Ptr, int *card2Ptr){
	int hold;
	
	hold = *card2Ptr;
	*card2Ptr = *card1Ptr;
	*card1Ptr = hold;
}

void initDeck(int wDeck[][13]){
	int row, column;
	int card = 1;
	
	for(row = 0; row < 4; row++){
		for(column = 0; column < 13; column++){
			wDeck[row][column] = card;
			card++;
		}
	}
}

void deal(const int wDeck[][13], const char *wSuit[], const char *wFace[], const char *wHand[][HAND_SIZE],  const int size){
	int i, j;
	int card = 1;
	
	while(card <= size){
		for(i = 0; i < 4; i++){
			for(j = 0; j < 13; j++){
				if(wDeck[i][j] == card){
					printf("%s of %s\n", wFace[j], wSuit[i]);
					wHand[0][card - 1] = wFace[j];
					wHand[1][card - 1] = wSuit[i];
				}
			}
		}

		card++;
	}
	printf("\n");
}


int pair(const char *wHand[], const int size){
	int i, j;
	
	for(i = 0; i < HAND_SIZE - 1; i++){
		for(j = i + 1; j < HAND_SIZE; j++){
			if(wHand[i] == wHand[j])
				return 1;
		}
	}
	
	return 0;
}

int twopairs(const char *wHand[], const int size){
	int i, j;
	int pair = 0;
	const char *hold;
	
	for(i = 0; i < size - 1; i++){
		for(j = i + 1; j < size; j++){
			if(wHand[i] == wHand[j] && pair == 0){
				hold = wHand[j];
				pair++;
				j = size;
			}
			else if((wHand[i] == wHand[j]) && wHand[j] != hold)
				return 1;
		}
	}
		
	return 0;
}

int threeOfAKind(const char *wHand[], const int size){
	int i, j;
	int equalCards = 1;
	
	for(i = 0; i < size - 2; i++){
		for(j = i + 1; j < size; j++){
			if(wHand[i] == wHand[j])
				equalCards++;
		}
		if(3 == equalCards)
			return 1;
		else
			equalCards = 1;
	}
	
	return 0;
}

int fourOfAKind(const char *wHand[], const int size){
	int i, j;
	int equalCards = 1;
	
	for(i = 0; i < size - 3; i++){
		for(j = i + 1; j < size; j++){
			if(wHand[i] == wHand[j])
				equalCards++;
		}
		if(4 == equalCards)
			return 1;
		else
			equalCards = 1;
	}
	
	return 0;
}

int flush(const char *wHand[], const int size){
	int i;
	
	for(i = 1; i < size; i++){
		if(wHand[0] != wHand[i])
			return 0;
	}
	
	return 1;
}

int straight(const char *wHand[][HAND_SIZE], const int size, const char *wFace[]){
	void bubbleSort(const char *[][HAND_SIZE], const int);
	int i, j;
	
	bubbleSort(wHand, size);
	
	for(j = 0; wHand[0][0] != wFace[j]; j++){
		//empty body
	}
		
	for(i = 1; i < size ; i++){
		if(wHand[0][i] != wFace[j + i])
			return 0;
	}
		
	return 1;
}

void bubbleSort(const char *aPtr[][HAND_SIZE], const int size){
	void swap(const char *, const char *, const char *, const char *);
	int pass; //count passes 
	int i; //counter to go through the array
	int swaps = 0; //count swaps to improve performances
	
	for(pass = 1; pass < size; pass++){
		
		for(i = 0; i < size - pass; i++){
			
			if(aPtr[0][i] > aPtr[0][i+1]){ //swap two elements
				swap(aPtr[0][i], aPtr[0][i+1], aPtr[1][i], aPtr[1][i+1]);
				swaps++;
			}
		}
		if(swaps == 0){
			break;
		}
		else
			swaps = 0;
	}
}

void swap(const char *element0, const char *element1, const char *element2, const char *element3){
	const char * hold;
	
	hold = element0;
	element0 = element1;
	element1 = hold;
	
	hold = element2;
	element2 = element3;
	element3 = hold;
}
