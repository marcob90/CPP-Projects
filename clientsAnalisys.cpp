#include <stdio.h>

int main(){
	int request;
	int account;
	char name[30];
	double balance;
	FILE *cfPtr;
	
	if( ( cfPtr = fopen("clients.txt", "r") ) == NULL ){
		puts("Error opening file client.txt");
	}
	else{
		printf( "Enter request\n"
	           " 1 - List accounts with zero balances\n"
	           " 2 - List accounts with credit balances\n"
	           " 3 - List accounts with debit balances\n"
	           " 4 - End of run\n? " );
		scanf("%d", &request);
		
		while(request != 4){

			fscanf(cfPtr, "%d%s%lf", &account, name, &balance);
			
			switch(request){
				case 1:
					printf("Accounts with zero balance:\n");
					while( !feof( cfPtr ) ){
						if(balance == 0.0)
							printf("%-10d%-13s%7.2lf\n", account, name, balance);
							
						fscanf(cfPtr, "%d%s%lf", &account, name, &balance);
					}	
					break;
				
				case 2:
					printf("Accounts with credit balance:\n");
					while( !feof( cfPtr ) ){
						if(balance < 0.0)
							printf("%-10d%-13s%7.2lf\n", account, name, balance);
							
						fscanf(cfPtr, "%d%s%lf", &account, name, &balance);
					}
					break;
				
				case 3:
					printf("Accounts with debit balance:\n");
					while( !feof( cfPtr ) ){
						if(balance > 0.0)
							printf("%-10d%-13s%7.2lf\n", account, name, balance);
							
						fscanf(cfPtr, "%d%s%lf", &account, name, &balance);
					}
					break;
				
				default:
					puts("Request not correct");	
					
			} //end of switch
			
			rewind(cfPtr);
			
			putchar('?');
			scanf("%d", &request);
		}//end of while
	}//end of else
	
	printf("End of run\n");
	fclose(cfPtr);
	
	return 0;
}
