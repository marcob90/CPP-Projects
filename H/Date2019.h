#ifndef DATE2019_H
#define DATE2019_H

class Date2019
{
	public:
		Date2019(int = 1, int = 1, int = 1900);
		void print() const;
		int getDay() const;
		int getMonth() const;
		int getYear() const;
		Date2019 &setDay(int);
		Date2019 &setMonth(int);
		Date2019 &setYear(int);
		
		Date2019 &operator++();
		Date2019 operator++(int);
	
	private:
		int month;
		int day;
		int year;	
};

#endif
