#include <bits/stdc++.h>

using namespace std;

void displayBinary(const unsigned n){
	unsigned mask = 1 << CHAR_BIT * sizeof(unsigned) - 1;
	int c; //counter
	
	printf("%u = ", n);
	
	for(c = 1; c <= CHAR_BIT * sizeof(unsigned); c++){
		putchar(n & mask ? '1' : '0');
		mask >>= 1;
		
		if(c % 8 == 0)
			putchar(' ');
	}
	putchar('\n');
}

void swapNibbles(unsigned &n){
	unsigned mask = 0x0f0f0f0f;
	int c; //counter
	
	n = ((n & mask) << 4) | ((n & (mask << 4)) >> 4);
}

int main(){
		unsigned num;
	
	puts("Insert an integer number: ");
	cin >> num;
	
	displayBinary(num);
	
	swapNibbles(num);
	displayBinary(num);
}

