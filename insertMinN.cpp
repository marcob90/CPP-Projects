#include <bits/stdc++.h>

using namespace std;

int insertMinN(int N, int M, int i, int j){
	if(i < 0 || i > j || j >= 32) return 0;
	
	//create mask to clean window i-j
	int allOnes = ~0;
	int left = (j < 31) ? allOnes << (j + 1) : 0;
	int right = (1 << (i - 1));
	int mask = left | right;
	
	int output = N & mask;
	output |= (M << i);
	
	return output;
}

void printBits(int num){
	unsigned mask = 1 << (CHAR_BIT * sizeof(num) - 1);
	
	cout << num << " -> ";
	for(int i = 1; i <= CHAR_BIT * sizeof(num); i++){
		int bit = (num & mask) ? 1 : 0;
		cout << bit;
		mask >>= 1;
		if(i % 8 == 0) cout << " ";
	}
	cout << endl;
}

int main(){
	int N = 83790856;
	int M = 56;
	int i = 17;
	int j = 21;
	
	printBits(N);
	printBits(M);
	int P = insertMinN(N, M, i, j);
	printBits(P);
}
