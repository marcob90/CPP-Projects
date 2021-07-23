#include <stdio.h>

int main(){
	int account;
	char name[30];
	double balance;
	
	FILE *cfPtr;
	
	if( ( cfPtr = fopen("clients.txt", "a") ) == NULL ){
		puts("Error opening file client.txt");
	}
	else{
		puts("Enter the account, name and balance");
		puts("Enter EOF to end input");
		printf("? ");
		scanf("%d%s%lf", &account, name, &balance);
		
		while( !feof( stdin ) ){
			fprintf(cfPtr, "%d %s %.2lf\n", account, name, balance);
			printf("? ");
			scanf("%d%s%lf", &account, name, &balance);
		}
	}
	
	fclose(cfPtr);
	
	return 0;
}
