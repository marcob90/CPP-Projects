#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date
{
	//print literal format
	friend ostream &operator<<( ostream &, const Date & );
	
	public:
		static const int monthsPerYear = 12;
		
		Date( int, int = 1, int = 1900 );
		Date();
		~Date();
		
		Date &operator++(); //lvalue prefix
		Date operator++( int ); //rvalue postfix
		const Date &operator+=( int ); //add a custom number of days
		
		void setDate( int, int, int );
		int getDay() const;
		int getMonth() const;
		int getYear() const;
		
		static bool leapYear( int );
		bool endOfTheMonth( int ) const;
		
		void printDayFormat() const;
		void printMonthFormat() const;
		void printNoMonthFormat() const;
	
	private:
		static const int daysPerMonth[];
		
		int day;
		int month;
		int year;
		
		void helpIncrement();
};

#endif
