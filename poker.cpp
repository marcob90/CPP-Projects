#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define HAND_SIZE 5

void shuffle(int [][13]);
void resetDeck(int [][13]);
void deal(const int [][13], const char *[], const char *[], const char *[][HAND_SIZE], const int);
int findCombination(const char *[], const char *[][HAND_SIZE], const int);

int main(){
	int deck[4][13] = {0};
	int dealerCombination, playerCombination;
	const char *dealerHand[2][HAND_SIZE];
	const char *playerHand[2][HAND_SIZE];
	const char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
	const char *face[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
	"Nine", "Ten", "Jack", "Queen", "King"};
	
	srand(time(NULL));

	shuffle(deck);
	
	printf("Dealer hand:\n\n");
	deal(deck, suit, face, dealerHand, HAND_SIZE);
	dealerCombination = findCombination(face, dealerHand, HAND_SIZE);
	
	printf("Player hand:\n\n");
	deal(deck, suit, face, playerHand, HAND_SIZE);
	playerCombination = findCombination(face, playerHand, HAND_SIZE);
	
	if(playerCombination > dealerCombination)
		printf("Player won");
	else if(playerCombination == dealerCombination)
		printf("Tie");
	else
		printf("Dealer won");
	
	return 0;
}

void shuffle(int wDeck[][13]){
	int card, row, column;
	
	for(card = 1; card <= 13*4; card++){
		do{
			row = rand() % 4;
			column = rand() % 13;
		}while(wDeck[row][column] != 0);
		
		wDeck[row][column] = card;
	}
}

void resetDeck(int wDeck[][13]){
	int row, column;
	
	for(row = 0; row < 4; row++){
		for(column = 0; column < 13; column++){
			wDeck[row][column] = 0;
		}
	}
}

void deal(const int wDeck[][13], const char *wSuit[], const char *wFace[], const char *wHand[][HAND_SIZE],  const int size){
	int i, j;
	static int card = 1;
	int pass = 1;
	
	while(pass <= size){
		for(i = 0; i < 4; i++){
			for(j = 0; j < 13; j++){
				if(wDeck[i][j] == card){
					printf("%s of %s\n", wFace[j], wSuit[i]);
					wHand[0][pass - 1] = wFace[j];
					wHand[1][pass - 1] = wSuit[i];
				}
			}
		}

		card++;
		pass++;
	}
	printf("\n");
}

int findCombination(const char *wFace[], const char *wHand[][HAND_SIZE], const int size){
	int pair(const char *[], const int);
	int twopairs(const char *[], const int);
	int threeOfAKind(const char *[], const int);
	int fourOfAKind(const char *[], const int);
	int flush(const char *[], const int);
	int straight(const char *[][HAND_SIZE], const int, const char*[]);
	
	if(straight(wHand, size, wFace)){
		printf("Straight\n\n");
		return 6;}
	else if(flush(wHand[1], size)){
		printf("Flush\n\n");
		return 5;}
	else if(fourOfAKind(wHand[0], size)){
		printf("Four of a kind\n\n");
		return 4;}
	else if(threeOfAKind(wHand[0], size)){
		printf("Three of a kind\n\n");
		return 3;}
	else if(twopairs(wHand[0], size)){
		printf("Two pairs\n\n");
		return 2;}
	else if(pair(wHand[0], size)){
		printf("Pair\n\n");
		return 1;}
	
	return 0;
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
