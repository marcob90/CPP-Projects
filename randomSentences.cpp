#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int main(){
	const char *article[5] = {"the", "a", "one", "some", "any"};
	const char *noun[5] = {"boy", "girl", "dog", "town", "car"};
	const char *verb[5] = {"drove", "jumped", "ran", "walked", "skipped"};
	const char *preposition[5] = {"to", "from", "over", "under", "on"};
	char string[100];
	int i;
	
	srand(time(NULL));
	
	while(i <= 20){
		strcpy(string, article[rand() % 5]);
		strcat(string, " ");
		strcat(string, noun[rand() % 5]);
		strcat(string, " ");
		strcat(string, verb[rand() % 5]);
		strcat(string, " ");
		strcat(string, preposition[rand() % 5]);
		strcat(string, " ");
		strcat(string, article[rand() % 5]);
		strcat(string, " ");
		strcat(string, noun[rand() % 5]);
		strcat(string, ".");
		strcat(string, " ");
		
		string[0] = toupper(string[0]);
		
		printf("%s\n", string);
		i++;
	}
	
	return 0;

}
