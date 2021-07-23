#include <bits/stdc++.h>

using namespace std;

/* a^n = (a^(n/2))^2*/

long long power(int a, int n){
	if(n == 0) return 1;
	
	long long x = power(a, n / 2);
	
	if(n % 2 == 0) return x * x;
	else return x * x * a;
}

int main(){
	int a = 4;
	int n = 0;
	cout << power(a, n);
}
