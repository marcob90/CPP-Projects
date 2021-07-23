#include <iostream>

#include "Rational.h"

using namespace std;

int main()
{
	Rational number1( 3, 20 );
	Rational number2( -2, 8 );
	Rational number3;
	Rational number4;
	Rational number5;
	Rational number6;
	
	number3.sumRationals( number1, number2 );
	number4.subtractRationals( number1, number2 );
	number5.multiplyRationals( number1, number2 );
	number6.divideRationals( number1, number2 );
	
	cout << "First operand is:\n";
	number1.printInStandardForm();
	number1.printInFloatingPointForm();
	cout << "Second operand is:\n";
	number2.printInStandardForm();
	number2.printInFloatingPointForm();
	
	cout << "\nSum is:\n";
	number3.printInStandardForm();
	number3.printInFloatingPointForm();
	cout << "Subtraction is:\n";
	number4.printInStandardForm();
	number4.printInFloatingPointForm();
	cout << "Product is:\n";
	number5.printInStandardForm();
	number5.printInFloatingPointForm();
	cout << "Division is:\n";
	number6.printInStandardForm();
	number6.printInFloatingPointForm();
}
