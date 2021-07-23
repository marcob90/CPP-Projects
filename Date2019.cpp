#include <iostream>
#include <iomanip>
#include "Date2019.h"
using namespace std;

Date2019::Date2019(int m, int d, int y)
	: month(m), day(d), year(y)
{
}

//prefix lvalue/rvalue
Date2019 &Date2019::operator++()
{
	day++;
	return *this;
}

//postfix rvalue
Date2019 Date2019::operator++(int)
{
	Date2019 temp = *this; //create temporary version with unincremented value
	day++;
	return temp;
}

int Date2019::getDay() const
{
	return day;
}

int Date2019::getMonth() const
{
	return month;
}

int Date2019::getYear() const
{
	return year;
}

Date2019 &Date2019::setDay(int d)
{
	day = d;
	return *this;
}

Date2019 &Date2019::setMonth(int m)
{
	month = m;
	return *this;
}

Date2019 &Date2019::setYear(int y)
{
	year = y;
	return *this;
}

void Date2019::print() const
{
	cout << setfill('0') << setw(2) <<
	month << '/' << setw(2) << day <<
	'/' << year;
}
