#include <stdio.h>

typedef union{
	char c;
	short s;
	long l; 
	int i;
}Integer;

int main(){
	Integer number[4];
	int a;
	
	printf("Enter a char: ");
	scanf("%c", &number[0].c);
	getchar();
	
	printf("Enter a short: ");
	scanf("%hd", &number[1].s);
	
	printf("Enter a long: ");
	scanf("%ld", &number[2].l);
	
	printf("Enter an int: ");
	scanf("%d", &number[3].i);
	
	printf("%17s%7s%7s%7s\n", "char", "short", "long", "int");
	for(a = 0; a < 4; a++){
		printf("\ninteger[%d] =%5c%7hd%7ld%7d\n\n", a, number[a].c, number[a].s, number[a].l, number[a].i);
	}
	
	return 0;
}
