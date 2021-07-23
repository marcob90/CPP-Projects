#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char string[15];// = "(702) 886-1413";
	char *tokenPtr;
	int areaCode;
	long phoneNumber = 0;
	
	printf("Enter a phone number in the format (555) 555-5555:\n\n");
	fgets(string, 15, stdin);
	
	tokenPtr = strtok(string + 1, ")");
	areaCode = atoi(tokenPtr);
	
	printf("Area Code: %d\n", areaCode);
	
	tokenPtr = strtok(string + 6, "-");
	phoneNumber = atol(tokenPtr) * 10000L;
	tokenPtr = strtok(NULL, "-");
	phoneNumber += atol(tokenPtr);
	
	printf("\nPhone Number: %ld", phoneNumber);
	
	return 0;
}
