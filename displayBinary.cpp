#include <stdio.h>
#include <limits.h>

void displayBinary(const unsigned);

int main(){
	unsigned num;
	
	puts("Insert an integer number: ");
	scanf("%u", &num);
	
	displayBinary(num);
	return 0;
}

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
