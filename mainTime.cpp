#include <iostream>

#include "Time.h"

using namespace std;

int main()
{
	Time t;
	int i = 0;
	
	cout << "The initialized current universal time is:\n";
	t.printUniversal();
	cout << "The initialized current standard time is:\n";
	t.printStandard();
	
	Time dinnerTime(19, 30, 00);
	Time &dTime = dinnerTime;
	Time *dinnerTimePtr = &dTime;
	
	dinnerTime.printUniversal();
	dTime.printUniversal();
	dinnerTimePtr->printUniversal();
	
	dinnerTime.setHour(21);
	
	dinnerTime.printUniversal();
	dTime.printUniversal();
	dinnerTimePtr->printUniversal();
	
	dTime.setHour(22);
	
	dinnerTime.printUniversal();
	dTime.printUniversal();
	dinnerTimePtr->printUniversal();
	
	dinnerTimePtr->setHour(23);
	
	dinnerTime.printUniversal();
	dTime.printUniversal();
	dinnerTimePtr->printUniversal();
	
	cout << &dinnerTime << endl;
	cout << &dTime << endl;
	cout << dinnerTimePtr << endl;
	cout << sizeof(dinnerTime) << endl;
	
	/*while( i < 10 ){
		t.tick();
		t.printUniversal();
		t.printStandard();
		cout << endl;
		i++;
	}*/
	
	cout << endl;
}
