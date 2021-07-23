#include <bits/stdc++.h>
#define SIZE 6

using namespace std;

// [3,7,9,2,4,7,0]

void printArray(int a[], int n){
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	
	cout << endl;
}

/*void rotateArray(int a[], int n, int z){
	int b[SIZE];
	
	z %= n;
	
	for(int j = 0; j < n; j++){
		b[j] = a[j];
	}
	
	for(int i = 0; i < n; i++){
		int index = (n - z + i) % n;
		a[i] = b[index];
	}
}*/

void rotateArray(int a[], int n, int z){
	z %= n;
	int count = 0;
	
	for(int start = 0; count < n; start++){
		int current = start;
		int leftVal = a[start];
		
		do{
			swap(leftVal, a[(current + z) % n]);
			current = (current + z) % n;
			count++;
		}while(current != start);
	}
}

int main(){
	int a[] = {3, 7, 2, 0, 1, 4, 5, 9, 1, 0};
	printArray(a, SIZE);
	
	rotateArray(a, SIZE, 11);
	
	printArray(a, SIZE);
}
