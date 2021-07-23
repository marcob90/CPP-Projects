#include <stdio.h>
#include <math.h>
#define N 3

int main(){
	int A[N] = {4,10,24};
	unsigned long sum = 0;
	int i;
	int dividend, remainder, binary;
	int totalOnes = 0;
	
	for(i = 0; i < N; i++)
		sum += pow(2, A[i]);
	
	sum *= 3;
	
	remainder = sum;
	
	for(dividend = pow(2, 25); dividend >= 1; dividend /= 2){
		binary = remainder / dividend;
		if(binary == 1)
			totalOnes++;
		remainder %= dividend;
	}
	
	printf("%d\n", sum);
	printf("%d", totalOnes);

	
	return 0;
	
	
}
