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
	
	if( ( cfPtr = fopen("clients.dat", "rb+") ) == NULL ){
		puts("Error opening file client.txt");
	}
	else{
		printf( "Enter account number"
				"( 1 to 100, 0 to end input )\n?");
		scanf("%d", &client.account);
		
		while(client.account != 0){
			printf("Insert last name, first name and balance\n?");
			
			fscanf(stdin, "%s%s%lf", client.lastName, client.firstName, &client.balance);
			
			fseek(cfPtr, ( client.account - 1 ) * sizeof(struct clientData), SEEK_SET);
			
			fwrite(&client, sizeof(struct clientData), 1, cfPtr);
			
			printf("Enter account number\n?");
			
			scanf("%d", &client.account);
		}
				
	}
	
	fclose(cfPtr);
	
	return 0;
}
