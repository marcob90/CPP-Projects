#include <bits/stdc++.h>

using namespace std;

string urlify(string s, int trueSize){
	//ex, s = "Mr John Smith    ", trueSize = 13
	int i = s.size() - 1;
	
	for(int trueIndex = trueSize - 1; trueIndex >= 0; trueIndex--){
		if(s[trueIndex] != ' '){
			s[i] = s[trueIndex];
			i--;
		}
		else{
			s[i] = '0';
			s[i - 1] = '2';
			s[i - 2] = '%';
			i -= 3;
		}
	}
	
	return s;
}

int main(){
	string s = "Mr John Smith    ";
	cout << urlify(s, 13);
}
