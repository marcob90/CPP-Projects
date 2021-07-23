#include <iostream>
#include <iomanip>
#include <ctime>

#include "Time.h"

using namespace std;

Time::Time( int hh, int mm, int ss )
{
	setTime( hh, mm, ss );
}

Time::Time()
{
	time_t rawtime;
	struct tm *timeinfo;
	
	time( &rawtime );
	timeinfo = localtime( &rawtime );
	
	setTime( timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec );
}

Time::~Time()
{
	cout << "******************************\n";
}

void Time::setTime( int h, int m, int s )
{
	setHour( h );
	setMinute( m );
	setSecond( s );
}

void Time::setHour( int h )
{
	hour = ( h >= 0 && h < 24 ) ? h : 0;
}

void Time::setMinute( int m )
{
	minute = ( m >= 0 && m < 60 ) ? m : 0;
}

void Time::setSecond( int s )
{
	second = ( s >= 0 && s < 60 ) ? s : 0;
}

int Time::getHour() const
{
	return hour;
}

int Time::getMinute() const
{
	return minute;
}

int Time::getSecond() const
{
	return second;
}

void Time::tick()
{
	if( getSecond() == 59 ){
		if( getMinute() == 59 ){
			setHour( getHour() + 1 );
		}
		
		setMinute( getMinute() + 1 );
	}
	
	setSecond( getSecond() + 1 );
}

void Time::printUniversal() const
{
	cout << setfill( '0' ) << setw( 2 ) << getHour() << ":"
	<< setw( 2 ) << getMinute() << ":" << setw( 2 )
	<< getSecond() << endl;
}

void Time::printStandard() const
{
	cout << ( ( getHour() == 0 || getHour() == 12 ) ? 12 : ( getHour() % 12 ) ) << ":"
	<< setfill( '0' ) << setw( 2 ) << getMinute() << ":"
	<< setw( 2 ) << getSecond() << " " << ( ( getHour() < 12 ) ? "AM" : "PM" ) << endl;
}
