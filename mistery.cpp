#include <bits/stdc++.h>

using namespace std;

/*function mystery(n)
r := 0
for i := 1 to n - 1 do
for j := i + 1 to n do
for k := 1 to j do
r := r + 1
return(r) */

int mistery(int n){
	int r = 0;
	
	for(int i = 1; i <= n - 1; i++){
		for(int j = i + 1; j <= n; j++){
			for(int k = 1; k <= j; k++){
				r++;
			}
		}
	}
	
	return r;
}



int main(){
	int n = 10;
	cout << mistery(n);
}
