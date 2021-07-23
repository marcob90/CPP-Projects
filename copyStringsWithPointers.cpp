#include <stdio.h>

void copy1(char * const, const char * const);
void copy2(char *, const char *);

int main(){
	char string1[10];
	const char string2[] = "Hello";
	char string3[10];
	const char *string4 = "Good Bye";
	
	copy1(string1, string2);
	copy2(string3, string4);
	printf("string1 = %s\nstring2 = %s", string1, string3);
	
	return 0;
}

void copy1(char * const s1, const char * const s2){
	int i;
	
	for(i = 0; (s1[i] = s2[i]) != '\0'; i++){
	}
	
}

void copy2(char * s1, const char * s2){
	
	for(; (*s1 = *s2) != '\0'; s1++, s2++){
	}
}


