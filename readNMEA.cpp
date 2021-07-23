#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILTER_WEIGHT 7

int main(){
	char sentence[100];
	char rmcSentence[100] = "\0";
	char ggaSentence[100] = "\0";
	char vtgSentence[100] = "\0";
	char time[10] = "\0";
	char sLat[10] = "\0";
	char sLon[10] = "\0";
	char checksum_rmc = 0;
	char checksum_gga = 0;
	char sCheck[10] = "\0";
	int request;
	int counter = 0;
	float latitudeAvg = 0.0f;
	float longitudeAvg = 0.0f;
	char *tokenPtr;
	FILE *cfPtr;
	
	if( ( cfPtr = fopen("SilosCrossNMEA.txt", "r") ) == NULL ){
		puts("Error opening file client.txt");
	}
/*	if( ( cfPtr = fopen("filteredRectangle.txt", "w") ) == NULL ){
		puts("Error opening file client.txt");
	}*/
	else{
		printf( "Enter request\n"
	           "1 - Read sentences\n"
	           "2 - Filter data\n"
	           "4 - End of run\n? " );
		scanf("%d", &request);
		
		while(request != 4){

			fscanf(cfPtr, "%s", sentence);
			
			switch(request){
				case 1:
					printf("NMEA sentences:\n");
					while( !feof( cfPtr ) ){
						printf("%s\n", sentence);
							
						fscanf(cfPtr, "%s", sentence);
					}	
					break;
					
				case 2:
					while( !feof( cfPtr ) ){
						for( int i = 1; i <= FILTER_WEIGHT;){
							tokenPtr = strtok(sentence, ",");
							
							if( !strcmp( tokenPtr, "$GPRMC") ){
								counter = 0;
								
								while( counter < 1 ){
									tokenPtr = strtok( NULL, "," );
									counter++;
								}
								
								strcpy( time, tokenPtr );
								
								while( counter < 3 ){
									tokenPtr = strtok( NULL, "," );
									counter++;
								}
								
								latitudeAvg += atof( tokenPtr );
								
								while( counter < 5 ){
									tokenPtr = strtok( NULL, "," );
									counter++;
								}
								
								longitudeAvg += atof( tokenPtr );
								i++;
							}
							
							fscanf(cfPtr, "%s", sentence);
						}
						
						latitudeAvg /= FILTER_WEIGHT;
						longitudeAvg /= FILTER_WEIGHT;
						
						strcat( rmcSentence, "$GPRMC," );
						strcat( rmcSentence, time );
						strcat( rmcSentence, ",A," );
						
						sprintf( sLat, "%.4f", latitudeAvg );
						
						strcat( rmcSentence, sLat );
						strcat( rmcSentence, ",N,0" );
						
						sprintf( sLon, "%.4f", longitudeAvg );
						
						strcat( rmcSentence, sLon );
						strcat( rmcSentence, ",W,000.0,000.0,271217,000.0,W" );
						
						for( int j = 1; j < strlen( rmcSentence ); j++ ) //checksum calculation for rmc
	                        checksum_rmc ^= rmcSentence[ j ];
	                    
	                    sprintf( sCheck, "%X", checksum_rmc );
	                    
	                    strcat( rmcSentence, "*" );
	                    strcat( rmcSentence, sCheck );
						
						printf("%s\n", rmcSentence);
						
						strcat( ggaSentence, "$GPGGA," );
						strcat( ggaSentence, time );
						strcat( ggaSentence, "," );
						
						sprintf( sLat, "%.4f", latitudeAvg );
						
						strcat( ggaSentence, sLat );
						strcat( ggaSentence, ",N,0" );
						
						sprintf( sLon, "%.4f", longitudeAvg );
						
						strcat( ggaSentence, sLon );
						strcat( ggaSentence, ",W,1,07,1.4,258.5,M,-34.2,M,,0000" );
						
						for( int j = 1; j < strlen( ggaSentence ); j++ ) //checksum calculation for rmc
	                        checksum_gga ^= ggaSentence[ j ];
	                    
	                    sprintf( sCheck, "%X", checksum_gga );
	                    
	                    strcat( ggaSentence, "*" );
	                    strcat( ggaSentence, sCheck );
						
						printf("%s\n", ggaSentence);
						
						strcat( vtgSentence, "$GPVTG,000.0,T,000.0,M,000.0,N,000.0,K*4E" );
						
						printf("%s\n", vtgSentence);
						sprintf( rmcSentence, "%c", '\0' );
						sprintf( ggaSentence, "%c", '\0' );
						sprintf( vtgSentence, "%c", '\0' );
						latitudeAvg = longitudeAvg = 0;
						checksum_rmc = checksum_gga = 0;
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
