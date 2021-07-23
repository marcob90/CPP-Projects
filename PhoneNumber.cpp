#include <iomanip>

#include "PhoneNumber.h"

using namespace std;

/*ostream &operator<<( ostream &output, const PhoneNumber &number )
{
	output << '(' << number.areaCode << ')' <<
	' ' << number.exchange << '-' << number.line;
	
	return output;
}*/

PhoneNumber::operator string() const
{
	return areaCode+exchange+line;
}

istream &operator>>( istream &input, PhoneNumber &number )
{
	input.ignore();
	input >> setw( 3 ) >> number.areaCode;
	input.ignore();
	input.ignore();
	input >> setw( 3 ) >> number.exchange;
	input.ignore();
	input >> setw( 4 ) >> number.line;
	
	return input;
}

string PhoneNumber::getAreaCode() const
{
	return areaCode;
}

bool PhoneNumber::operator!() const
{
	return getAreaCode().empty();
}
