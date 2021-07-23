#include <stdio.h>
#include <ctype.h>

int main(){
	char test;
	
	puts("Enter a character:");
	scanf("%c", &test);
	
	if(isdigit(test))
		puts("It is a number");
	
	if(isalpha(test))
		puts("It is a letter");
		
	if(isalnum(test))
		puts("It is an alphanumeric character");
	
	if(isxdigit(test))
		puts("It is a hexadecimal digit");
	
	if(islower(test))
		puts("It is a lowercase character");
	
	if(isupper(test))
		puts("It is an uppercase character");
		
	return 0;
}
