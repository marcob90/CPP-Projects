#include <stdio.h>

#define SIZE 1000

void sieveOfEratosthenes(int[], const int);
void printPrimeNumbers(const int[], const int);
void initializeArray(int[], const int);

int main(){
	int array[SIZE];
	
	initializeArray(array, SIZE);
	sieveOfEratosthenes(array, SIZE);
	printPrimeNumbers(array, SIZE);
	
	return 0;
}

void sieveOfEratosthenes(int a[], const int size){
	int i, j;
	
	for(i = 2; i < size; i++)
		for(j = 2; j < size; j++){
			if(i*j < size)
				a[i*j] = 0;
			else
				j = size;
		}
	
}

void printPrimeNumbers(const int a[], const int size){
	int i;
	
	for(i = 2; i < size; i++)
		if(a[i] == 1)
			printf("%5d", i);

}

void initializeArray(int a[], const int size){
	int i;
	
	for(i = 0; i < size; i++)
		a[i] = 1;

}
