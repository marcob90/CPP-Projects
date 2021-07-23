#ifndef TIME_H
#define TIME_H

class Time{
		public:
			Time(int, int = 0, int = 0); //default values
			Time(); //overloaded constructor for current time
			~Time();
			void setTime( int, int, int );
			void setHour( int );
			void setMinute( int );
			void setSecond( int );
			int getHour() const;
			int getMinute() const;
			int getSecond() const;
			void tick();
			void printUniversal() const;
			void printStandard() const;
		
		private:
			int hour; //0-23
			int minute; //0-59
			int second; //0-59
};

#endif
