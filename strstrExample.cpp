#include <stdio.h>
#include <string.h>

int main(){
	char string[100];
	char searchKey[10];
	char *searchPtr = &string[0];
	//int i = 0;
	
	fgets(string, 100, stdin);
	strtok(string, "\n");
	
	fgets(searchKey, 10, stdin);
	strtok(searchKey, "\n");
	
	while( ( searchPtr = strstr(searchPtr, searchKey) ) != NULL ){
		printf("%s\n", searchPtr);
		searchPtr++;
	}
	
	return 0;
}
