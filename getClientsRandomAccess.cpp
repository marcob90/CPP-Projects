#include <stdio.h>

struct clientData{
		int account;
		char lastName[15]; 
		char firstName[10];
		double balance;
	};

int main(){
	struct clientData client = {0, "", "", 0.0};
	FILE *cfPtr;
	
	if( ( cfPtr = fopen("clients.dat", "rb") ) == NULL ){
		puts("Error opening file client.txt");
	}
	else{
		printf("%-10s%-10s%-11s%s\n", "Account", "Lastname", "Firstname", "Balance");
		fread(&client, sizeof(struct clientData), 1, cfPtr);
		
		while(!feof(cfPtr)){
			if(client.account != 0)
				printf("%-10d%-10s%-11s%7.2lf\n", client.account, client.lastName, client.firstName, client.balance);
			
			fread(&client, sizeof(struct clientData), 1, cfPtr);
		}
	}
	
	fclose(cfPtr);
	
	return 0;
}
