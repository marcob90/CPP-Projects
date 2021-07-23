#include <iostream>

int main()
{
	int num1;
	int num2;
	int sum;
	
	std::cout << "Enter a number: ";
	
	std::cin >> num1;
	
	std::cout << "Enter a number: ";
	
	std::cin >> num2;
	
	sum = num1 + num2;
	
	std::cout << "The sum is: " << sum << std::endl;
}
