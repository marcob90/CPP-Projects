#include <stdio.h>

void reverse(const char * const);

int main(){
	char sentence[80];
	
	fgets(sentence, 80, stdin);
	
	reverse(sentence);
	return 0;
}

void reverse(const char * const sPtr){
	if(*sPtr == '\0')
		return;
	
	reverse(sPtr + 1);
	putchar(*sPtr);
}
