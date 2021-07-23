#include <stdio.h>
#include <string.h>

void printWord(char *const);

int main(){
	char string[100];
	
	fgets(string, 100, stdin);
	strtok(string, "\n");
	
	printWord(string);
	return 0;
}

void printWord(char *const s){
	char *tokenPtr;
	
	tokenPtr = strtok(s, " ");

	if(tokenPtr != NULL){
		printWord(NULL);
		printf("%s ", tokenPtr);
	}

}
