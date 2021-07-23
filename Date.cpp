#include <iostream>
#include <iomanip>
#include <ctime>

#include "Date.h"

using namespace std;

Date::Date( int d, int m, int y )
{
	setDate( m, d, y );
}

Date::Date()
{
	time_t rawtime;
	struct tm * timeinfo;
	
	time( &rawtime );
	timeinfo = localtime( &rawtime );
	
	day = timeinfo->tm_mday; 
	month = timeinfo->tm_mon + 1; 
	year = timeinfo->tm_year + 1900;
}

Date::~Date()
{
}

void Date::setDate( int mm, int dd, int yy )
{
	month = ( mm >= 1 && mm <= monthsPerYear ) ? mm : 1;
	year = ( yy >= 1900 && yy <= 2100 ) ? yy : 1900;
	
	// test for a leap year
    if ( month == 2 && leapYear( year ) )
    	day = ( dd >= 1 && dd <= 29 ) ? dd : 1;
    else
    	day = ( dd >= 1 && dd <= daysPerMonth[ month ] ) ? dd : 1;
}

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}

//overloaded prefix operator
Date &Date::operator++()
{
	helpIncrement();
	return *this; //reference to create an lvalue
}

//overloaded postfix operator
//notice the dummy value to distinguish it 
Date Date::operator++( int )
{
	Date temp = *this;
	helpIncrement();
	
	return temp; //return not incremented object by value
}

const Date &Date::operator+=( int additionalDays )
{
	for( int i = 1; i <= additionalDays; i++ )
		helpIncrement();
	
	return *this; //enables cascading
}

bool Date::leapYear( int testYear )
{
	// February 29 check for leap year
	if ( testYear % 400 == 0 ||
       ( testYear % 100 != 0 && testYear % 4 == 0 ) )
    	return true; // a leap year
    else
    	return false; // not a leap year
}

bool Date::endOfTheMonth( int d ) const
{
	if( leapYear( year ) && month == 2 )
		return d == 29;
	else
		return d == daysPerMonth[ month ];
}

void Date::printDayFormat() const
{
	cout << setfill( '0' ) << setw( 2 ) << day 
	<< "/" << setw( 2 ) << month << "/" << year;
}

void Date::printMonthFormat() const
{
	cout << setfill( '0' ) << setw( 2 ) << month 
	<< "/" << setw( 2 ) << day << "/" << year;
}

void Date::printNoMonthFormat() const
{
	int totalDays = 0;
	
	for( int i = 1; i < month; i++ ){
		totalDays += daysPerMonth[ i ];
	}
	totalDays += day;
	
	cout << setfill( '0' ) << setw( 3 ) << totalDays 
	<< " " << year;
}

void Date::helpIncrement()
{
	if( !endOfTheMonth( day ) )
		day++;
	else{
		if( month < 12 )
			month++;
		else{
			month = 1;
			year++;
		}
		day = 1;
	}
}

//overloaded output operator
ostream &operator<<( ostream &output, const Date &date )
{
	static const string monthsName[ date.monthsPerYear + 1 ] =
	{ "", "January", "February", "March", "April", "May",
	 "June", "July", "August", "September", "October", 
	 "November", "December" };
	
	output << setfill( '0' ) << monthsName[ date.month ] << 
	" " << setw( 2 ) << date.day << ", " << setw( 2 ) 
	<< date.year;
	
	return output;
}

const int Date::daysPerMonth[] = 
{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

