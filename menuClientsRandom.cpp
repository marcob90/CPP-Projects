#include <stdio.h>

struct clientData {
		int account;
		char lastName[15]; 
		char firstName[10];
		double balance;
};

void textFile( FILE * );
void updateRecord( FILE * );
void newRecord( FILE * );
void deleteRecord( FILE * );
int enterChoice( void );

int main( void )
{
	FILE *cfPtr;
	int choice;
	
	if( ( cfPtr = fopen("clients.dat", "rb+") ) == NULL ){
		puts("Error opening file client.txt");
	}
	else{
		while( ( choice = enterChoice() ) != 5 ){
			switch( choice ){
				case 1:
					textFile( cfPtr );
					break;
				case 2:
					updateRecord( cfPtr );
					break;
				case 3:
					newRecord( cfPtr );
					break;
				case 4:
					deleteRecord( cfPtr );
					break;
				default:
					puts( "Wrong choice" );
			}
		}
		
		printf( "End of run" );
	}
	
	fclose(cfPtr);
	
	return 0;
}

void textFile( FILE *readPtr )
{
	FILE *writePtr;
	struct clientData client = { 0, "" , "" , 0.0 };
	
	if( ( writePtr = fopen("clients.txt", "w") ) == NULL ) {
		puts("Error opening file client.txt");
	}
	else {
		rewind( readPtr );
		fprintf( writePtr, "%-6s%-16s%-11s%10s\n", "Acct", "Last Name", "First Name","Balance" );
		
		while( !feof( readPtr ) ){
			fread( &client, sizeof( struct clientData ), 1, readPtr );
			
			if(client.account != 0)
				fprintf( writePtr, "%-6d%-16s%-11s%10.2lf\n", client.account, client.lastName, client.firstName, client.balance );
		}
	
	fclose( writePtr );
	}//end of else
} //end of textFile()

void updateRecord( FILE * fPtr)
{
	struct clientData client = { 0, "" , "" , 0.0 };
	int acct;
	double transaction;
	
	printf( "Enter account to update ( 1 - 100 ): ");
	
	scanf("%d", &acct);
	
	fseek(fPtr, ( acct - 1 ) * sizeof( struct clientData ), SEEK_SET);
	
	fread( &client, sizeof( struct clientData ), 1, fPtr );
	
	if( client.account == 0 )
		puts( "Empty account" );
	//update
	else{ 
		printf( "%-6d%-16s%-10s%11.2lf\n\n", client.account, client.lastName, client.firstName, client.balance);
		
		/*******request transaction amount per user*******/
		printf("Enter charge ( + ) or payment ( - ): ");
		scanf("%lf", &transaction);
		client.balance += transaction;
		
		printf( "%-6d%-16s%-10s%11.2lf\n\n", client.account, client.lastName, client.firstName, client.balance);
		
		/*******look for correct position in file and update*******/
		fseek(fPtr, ( acct - 1 ) * sizeof( struct clientData ), SEEK_SET);
		
		fwrite( &client, sizeof( struct clientData ), 1, fPtr);
		
	} //end of else
} //end of update

void newRecord( FILE *fPtr )
{
	struct clientData client = { 0, "" , "" , 0.0 };
	int acct;
	
	printf( "Enter new account number ( 1 - 100 ): ");
	scanf("%d", &acct);
	
	fseek( fPtr, ( acct - 1 ) * sizeof( struct clientData ), SEEK_SET );
	
	fread( &client, sizeof( struct clientData ), 1, fPtr );
	
	if( client.account != 0)
		printf( "Record %d already present\n", acct );
	//insert new record
	else{
		printf( "Enter lastname, firstname and balance\n? " );
		fscanf( stdin, "%s%s%lf", client.lastName, client.firstName, &client.balance );
		client.account = acct;
		
		fseek( fPtr, ( acct - 1 ) * sizeof( struct clientData ), SEEK_SET );
		
		fwrite( &client, sizeof( struct clientData ), 1, fPtr);
	} //end of else
} //end of newRecord

void deleteRecord ( FILE *fPtr )
{
	struct clientData blankClient = { 0, "" , "" , 0.0 };
	struct clientData client;
	int acct;
	
	printf( "Enter account number to delete ( 1 - 100 ): ");
	scanf("%d", &acct);
	
	fseek( fPtr, ( acct - 1 ) * sizeof( struct clientData ), SEEK_SET );
	
	fread( &client, sizeof( struct clientData ), 1, fPtr );
	
	if( client.account == 0)
		printf( "Account %d does not exist\n", acct );
	//delete record
	else{
		fseek( fPtr, ( acct - 1 ) * sizeof( struct clientData ), SEEK_SET );
		
		fwrite( &blankClient, sizeof( struct clientData ), 1, fPtr);
	}
}

int enterChoice( void )
{
	int menuChoice;
	
	printf( "\nEnter your choice\n"
 			"1 - store a formatted text file of accounts called\n"
 			" \"accounts.txt\" for printing\n"
 			"2 - update an account\n"
 			"3 - add a new account\n"
 			"4 - delete an account\n"
 			"5 - end program\n? " );

 	scanf( "%d", &menuChoice ); /* receive choice from user */
 	return menuChoice;
}
