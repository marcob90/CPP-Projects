#include <stdio.h>
#include <stdlib.h>

int main(){
	char s1[10];
	char s2[10];
	char s3[10];
	char s4[10];
	int total = 0;
	
	fgets(s1, 10, stdin);
	total += atoi(s1);
	
	fgets(s2, 10, stdin);
	total += atoi(s2);
	
	fgets(s3, 10, stdin);
	total += atoi(s3);
	
	fgets(s4, 10, stdin);
	total += atoi(s4);
	
	printf("Total is: %d", total);
	
	return 0;
}
