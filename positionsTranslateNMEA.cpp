#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define R_EA 6378137000  //earth semi-major axis in mm
#define ECC 0.08181919
#define DEG_TO_RAD  0.017453292519943295
#define RAD_TO_DEG  57.29577951308232087
#define LATITUDE_A0 42.35507078464972
#define LONGITUDE_A0 -84.6908424990674
#define NORTH 284

void conv2NMEA( const double, const double, int [], int []);

int main(){
	char rmc[100] = "\0";
	char gga[100] = "\0";
	char vtg[100] = "\0";
	char time[7] = "000010";
	int delta_lat[3] = {0};
	int delta_long[3] = {0};
	char lat0[ 3 ], lat1[ 3 ], lat2[ 5 ];
	char lon0[ 3 ], lon1[ 3 ], lon2[ 5 ];
	double X, Y;
	char checksum_rmc = 0;
	char checksum_gga = 0;
	char sCheck[10] = "\0";
	int request;
	char comma;
	FILE *cfPtr;
	
	if( ( ( cfPtr = fopen("SilosCross.txt", "r") ) == NULL ) ){
		puts("Error opening file SilosRepeatibilityCircle.txt");
	}
	else{
		printf( "Enter request\n"
	           "1 - Read positions\n"
	           "2 - Translate to NMEA\n"
	           "4 - End of run\n? " );
		scanf("%d", &request);
		
		while(request != 4){

			fscanf(cfPtr, "%lf%c%lf%c", &X, &comma, &Y, &comma);
			
			switch(request){
				case 1:
					printf("Positions:\n");
					while( !feof( cfPtr ) ){
						printf("%.7lf,%.7lf\n", X, Y);
							
						fscanf(cfPtr, "%lf%c%lf%c", &X, &comma, &Y, &comma);
					}	
					break;
					
				case 2:	
					while( !feof( cfPtr ) ){
						X = ( X - ( int )X ) * 1000000.0;
						Y = ( Y - ( int )Y ) * 1000000.0;

						conv2NMEA( X , Y, delta_lat, delta_long);
						
						sprintf(lat0, "%d", abs(delta_lat[0]));
	                    sprintf(lat1, "%d", delta_lat[1]);
	                    sprintf(lat2, "%d", delta_lat[2]);
	
	                    sprintf(lon0, "%d", abs(delta_long[0]));
	                    sprintf(lon1, "%d", delta_long[1]);
	                    sprintf(lon2, "%d", delta_long[2]);
						
						strcat( rmc, "$GPRMC," );
						strcat( rmc, time );
						strcat( rmc, ",A," );
						
						if( abs( delta_lat[ 0 ] ) < 10 )
	                        strcat( rmc, "0" );
	
	                    strcat( rmc, lat0 );
	
	                    if( delta_lat[ 1 ] < 10 )
	                        strcat( rmc, "0" );
	
	                    strcat( rmc, lat1 );
	                    strcat( rmc, "." );
	
	                    if( delta_lat[ 2 ] < 10)
	                        strcat( rmc, "000" );
	                    else if( delta_lat[ 2 ] < 100 )
	                        strcat( rmc, "00" );
	                    else if( delta_lat[ 2 ] < 1000 )
	                        strcat( rmc, "0" );
						
						strcat( rmc, lat2 );
						
						strcat( rmc, ",N," );
						
						if( abs( delta_long[0] ) < 10 )
	                        strcat( rmc, "00" );
		                else if( abs( delta_long[ 0 ] ) >= 10 && abs( delta_long [0 ] ) < 100 )
		                    strcat( rmc, "0" );
		
		                strcat( rmc, lon0 );
		
		                if( delta_long[ 1 ] < 10 )
		                    strcat( rmc, "0" );
		
		                strcat( rmc, lon1 );
		                strcat( rmc, "." );
		
		                if( delta_long[ 2 ] < 10 )
		                    strcat( rmc, "000" );
		                else if( delta_long[ 2 ] < 100 )
		                    strcat( rmc, "00" );
		                else if( delta_long[ 2 ] < 1000 )
		                    strcat( rmc, "0" );
		
		                strcat(rmc,lon2);
		                
		                strcat( rmc, ",W,000.0,000.0,271217,000.0,W" );
		
		                for( int j = 1; j < strlen( rmc ); j++ ) //checksum calculation for rmc
		                    checksum_rmc ^= rmc[ j ];
		                
		                sprintf( sCheck, "%X", checksum_rmc );
		                strcat( rmc, "*" );
		                strcat( rmc, sCheck );
		                
		                strcat( gga, "$GPGGA," );
						strcat( gga, time );
						strcat( gga, "," );
						
						if( abs( delta_lat[ 0 ] ) < 10 )
	                        strcat( gga, "0" );
	
	                    strcat( gga, lat0 );
	
	                    if( delta_lat[ 1 ] < 10 )
	                        strcat( gga, "0" );
	
	                    strcat( gga, lat1 );
	                    strcat( gga, "." );
	
	                    if( delta_lat[ 2 ] < 10)
	                        strcat( gga, "000" );
	                    else if( delta_lat[ 2 ] < 100 )
	                        strcat( gga, "00" );
	                    else if( delta_lat[ 2 ] < 1000 )
	                        strcat( gga, "0" );
						
						strcat( gga, lat2 );
						
						strcat( gga, ",N," );
						
						if( abs( delta_long[0] ) < 10 )
	                        strcat( gga, "00" );
		                else if( abs( delta_long[ 0 ] ) >= 10 && abs( delta_long [0 ] ) < 100 )
		                    strcat( gga, "0" );
		
		                strcat( gga, lon0 );
		
		                if( delta_long[ 1 ] < 10 )
		                    strcat( gga, "0" );
		
		                strcat( gga, lon1 );
		                strcat( gga, "." );
		
		                if( delta_long[ 2 ] < 10 )
		                    strcat( gga, "000" );
		                else if( delta_long[ 2 ] < 100 )
		                    strcat( gga, "00" );
		                else if( delta_long[ 2 ] < 1000 )
		                    strcat( gga, "0" );
		
		                strcat(gga,lon2);
		                
		                strcat( gga, ",W,1,07,1.4,258.5,M,-34.2,M,,0000" );
		
		                for( int j = 1; j < strlen( gga ); j++ ) //checksum calculation for gga
		                    checksum_gga ^= gga[ j ];
		                
		                sprintf( sCheck, "%X", checksum_gga );
		                strcat( gga, "*" );
		                strcat( gga, sCheck );
		                
		                strcat( vtg, "$GPVTG,000.0,T,000.0,M,000.0,N,000.0,K*4E" );
		                
		                printf("%s\n%s\n%s\n", rmc, gga, vtg );
		                
		                fscanf(cfPtr, "%lf%c%lf%c", &X, &comma, &Y, &comma);
		                
		                sprintf( rmc, "%c", '\0' );
						sprintf( gga, "%c", '\0' );
						sprintf( vtg, "%c", '\0' );
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

void conv2NMEA( const double x_tag, const double y_tag, int delta_latit[ ], int delta_longit[ ]){

	double R_MERID,R_PARAL;
	double delta_lat_dd,delta_long_dd, latitude_tag, longitude_tag;
	double temp_min_lat,temp_min_long;
	double cosalfa, sinalfa;
	double x_tag_r, y_tag_r;
	int delta_deg_lat,delta_min_lat,delta_decmin_lat;
	int delta_deg_long,delta_min_long,delta_decmin_long;
	
	cosalfa = cos( NORTH * DEG_TO_RAD );
	sinalfa = sin( NORTH * DEG_TO_RAD );
	
	//conversione da DMS (riferimento GPS) a DD da mettere nella formula
	
	x_tag_r = x_tag*cosalfa + y_tag*sinalfa;
	y_tag_r = y_tag*cosalfa - x_tag*sinalfa;
	
	R_PARAL = R_EA / sqrt( 1 - ( pow( ECC * sin( LATITUDE_A0 ), 2) ) );                 //approximate curvature in E-W direction
	R_MERID = ( R_EA * ( 1 - pow( ECC, 2 ) ) ) / pow( 1 - pow( ECC * sin( LATITUDE_A0 ), 2), 1.5 ); //approximate curvature in N-S direction
	
	delta_lat_dd=(x_tag_r/R_MERID)*RAD_TO_DEG;    //delta latitude in decimal degrees
	delta_long_dd=(y_tag_r/R_PARAL)*RAD_TO_DEG;   //delta longitude in decimal degrees
	
	latitude_tag = LATITUDE_A0 + delta_lat_dd;
	longitude_tag = LONGITUDE_A0 - delta_long_dd;
	
	if(latitude_tag < 0)
	    latitude_tag = fabs(latitude_tag);
	if(longitude_tag < 0)
    	longitude_tag = fabs(longitude_tag);
	
	// LATITUDE
	
	delta_latit[0] = (int)latitude_tag;
	temp_min_lat = (latitude_tag - delta_latit[0]) * 60.0;
	delta_latit[1] = (int)temp_min_lat;
	delta_latit[2] = (int)((temp_min_lat - delta_latit[1]) * 1e4);
	
	// LONGITUDE
	
	delta_longit[0] = (int)longitude_tag;
	temp_min_long = (longitude_tag - delta_longit[0]) * 60.0;
	delta_longit[1] = (int)temp_min_long;
	delta_longit[2] = (int)((temp_min_long - delta_longit[1]) * 1e4);
}
