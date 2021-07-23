#include <stdio.h>
#include <string.h>

int main(){
	char string[] = "Once upon a time";
	char *tokenPtr;
	
	printf("Original string is:\n%s\n\nTokenized string is:\n", string);
	
	tokenPtr = strtok(string, " ");
	
	while(tokenPtr != NULL){
		printf("%s\n", tokenPtr);
		tokenPtr = strtok(NULL, " ");
	}
}
