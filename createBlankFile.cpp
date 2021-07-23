#include <stdio.h>

struct clientData{
		int account;
		char lastName[15];
		char firstName[10];
		double balance;
	};

int main(){
	struct clientData blankClient = {0, "", "", 0.0};
	FILE *cfPtr;
	int i;
	
	if( ( cfPtr = fopen("clients.dat", "wb") ) == NULL ){
		puts("Error opening file client.txt");
	}
	else{
		for(i = 1; i <= 100; i++){
			fwrite(&blankClient, sizeof(struct clientData), 1, cfPtr);
		}
	}
	
	fclose(cfPtr);
	
	return 0;
}
