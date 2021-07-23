#include <stdio.h>
#include <limits.h>

unsigned power2(const unsigned, const unsigned);
void displayBinary(const unsigned);

int main(){
	unsigned number, pow, result;
	
	puts("Enter a number:");
	scanf("%u", &number);
	puts("Enter a power:");
	scanf("%u", &pow);
	
	printf("Number is ");
	displayBinary(number);
	printf("Power is ");
	displayBinary(pow);
	
	result = power2(number, pow);
	printf("\nResult is ");
	displayBinary(result);
	
	return 0;
}

unsigned power2(const unsigned n, const unsigned p){
	return n << p;
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
