#include <stdio.h>
#include <ctype.h>

int main(){
	char string[100];
	int i; //counter 
	
	fgets(string, 100, stdin);

	for(i = 0; string[i] != '\0'; i++){
		printf("%c", tolower(string[i]));
	}
	
	puts("");
	
	for(i = 0; string[i] != '\0'; i++){
		printf("%c", toupper(string[i]));
	}
	
	return 0;
}
