#include <stdio.h>
#include <string.h>

int main(){
	char S[] = "SMS messages are really short";
	int K = 8;
	int totalSMS = 0;
	char *tokenPtr;
	int textSize = 0;
	
	tokenPtr = strtok(S, " ");
	
	while(tokenPtr != NULL){
		textSize += strlen(tokenPtr);
		if(textSize > K){
			textSize = strlen(tokenPtr) + 1;
			totalSMS++;
		}
		else{
			textSize++;
		}
		
		tokenPtr = strtok(NULL, " ");
	} 
	
	totalSMS++;
	
	printf("%d\n", totalSMS);
	
	
}
