#include <stdio.h>
#include <string.h>

int main(){
	int a[15] = {0};
	int b[3] = {9, 8, 7};
	
	memmove(b, &b[1], 8);
	printf("%d %d %d",b[0], b[1], b[2]);
	return 0;
}
