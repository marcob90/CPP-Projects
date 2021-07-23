#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void printArray(const int[], const int);
int linearSearch(const int, const int[], const int);

int main(){
	int array[SIZE] = {0};
	int i, num;
	int index = 0;
	int duplicate;
	
	srand(time(NULL));
	
	for(i = 0; i < SIZE; i++){
		num = rand() % 20 + 1;
		
		duplicate = linearSearch(num, array, SIZE);
		
		if(!duplicate){
			array[index] = num;
			index++;
		}
	}
	
	printArray(array, SIZE);
	
	return 0;
}

int linearSearch(const int n, const int a[], const int size){
	int i;
	
	for(i = 0; i < size; i++){
		if(a[i] == n)
			return 1;
	}
	
	return 0;
}

void printArray(const int a[], const int size){
	int i;
	
	for(i = 0; i < size; i++){
		if(a[i] == 0)
			break;
		
		printf("%4d", a[i]);
	}
}
