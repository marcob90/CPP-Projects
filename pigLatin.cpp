#include <stdio.h>
#include <string.h>

void printLatinWord(const char *const);

int main(){
	char string[50];
	char *tokenPtr;
	
	fgets(string, 50, stdin);
	strtok(string, "\n");
	
	tokenPtr = strtok(string, " ");
	
	while(tokenPtr != NULL){
		printLatinWord(tokenPtr);
		tokenPtr = strtok(NULL, " ");
	}
}

void printLatinWord(const char *const token){
	
	printf("%s%c%s ", token + 1, token[0], "ty");
	
}
