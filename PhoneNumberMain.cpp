#include "PhoneNumber.h"

using namespace std;

int main()
{
	PhoneNumber myPhone;
	
	!( myPhone ) ? ( cout << "Area code is empty\n" ) :
		( cout << "Area code is: " << myPhone.getAreaCode() );
	
	cout << "Enter a phone number: ";
	
	cin >> myPhone;
	
	cout << "\nYou entered: " << static_cast<string>(myPhone) << endl;
	
	!( myPhone ) ? ( cout << "Area code is empty\n" ) :
		( cout << "Area code is: " << myPhone.getAreaCode() );
}
