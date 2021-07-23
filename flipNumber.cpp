#include <iostream>

using namespace std;

unsigned flipBits(unsigned n){
	return n ^ 0xffffffffu;
}

int main(){
	unsigned num;
	cout << "Enter number: ";
	cin >> num;
	unsigned flippedNum = flipBits(num);
	
	cout << flippedNum;
}
