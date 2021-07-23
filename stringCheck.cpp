#include <bits/stdc++.h>

using namespace std;

int findMatch(const string &p, const string &t){
	int i, j; /*counters*/
	int m = p.size();
	int n = t.size();
	
	for(i = 0; i <= (n - m); i++){
		j = 0;
		while((j < m) && (p[j] == t[i + j]))
			j++;
		if(j == m) return i;
	}
	
	return -1;
}

int main(){
	string text = "Skyloc is an advanced inspection tool for positioning, measurement and telemetry data acquisition.";
	string key = "data";
	
	cout << findMatch(key, text);
}
