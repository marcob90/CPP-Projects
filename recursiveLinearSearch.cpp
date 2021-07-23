#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

void initializeArray(int[], const int);
int recursiveLinearSearch(const int[], const int, const int);
void printArray(const int[], const int);

int main(){
	int array[SIZE];
	int result;
	int searchKey;
	
	srand(time(NULL));
	
	printf("Insert key: ");
	scanf("%d", &searchKey);
	
	initializeArray(array, SIZE);
	result = recursiveLinearSearch(array, searchKey, SIZE);
	
	if(result != -1)
		printf("%d was found at element number %d\n", searchKey, result);
	else
		printf("Element not found\n");
		
	printArray(array, SIZE);	
	return 0;
}

int recursiveLinearSearch(const int a[], const int key, const int size){
	
	while(size > 0){
		if(a[size - 1] != key)
			return recursiveLinearSearch(a, key, size - 1);
		
		return size - 1;
	}
	
	return -1;
}

void initializeArray(int a[], const int size){
	int i;
	
	for(i = 0; i < size; i++){
		a[i] = rand() % 100;
	}
}

void printArray(const int a[], const int size){
	int i;
	
	for(i = 0; i < size; i++){
		printf("%4d", a[i]);
	}
}
