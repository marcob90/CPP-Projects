#include <stdio.h>

int main(){
	const char sentence[] = "Rudolph is 12 years old";
	char str[20];
	int age;
	
	sscanf(sentence, "%s%*s%d", str, &age);
	printf("%s -> %d", str, age);
	return 0;
}
