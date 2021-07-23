#include <iostream>
#define SIZE 10

using namespace std;

void printCommonElements(int a[], int b[]){
	int aIndex = 0;
	int bIndex = 0;
	
	while(bIndex < SIZE){
		if(b[bIndex] == a[aIndex]){ 
			cout << b[bIndex] << " ";
			aIndex++;
			bIndex++;
		}
		else if(b[bIndex] < a[aIndex])
			bIndex++;
		else
			aIndex++;
	}
}

int main(){
	int a[SIZE] = {13, 20, 32, 37, 49, 58, 60, 77, 81, 99};
	int b[SIZE] = {17, 24, 37, 42, 60, 64, 70, 77, 84, 91};
	
	printCommonElements(a, b);
}
