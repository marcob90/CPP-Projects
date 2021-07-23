#include <bits/stdc++.h>
using namespace std;

int fromBDtoD(int n)
{
	int digit = 1;
	int remainder = 10;
	int power = 1;
	int singleDigit;
	int decimal = 0;
	
	while(digit <= 3){
		singleDigit = (n % remainder / (remainder / 10));
		
		decimal += singleDigit * power;
		digit++;
		remainder *= 10;
		power *= 2;
	}
	
	return decimal;
}

int main()
{
	for(int i = 0; i < 150; i++){
		if(i % 10 == 0) cout << "\nbinaryDecimal\tDecimal\n";
		cout << i << "\t\t" << fromBDtoD(i) << endl;
	}
}
