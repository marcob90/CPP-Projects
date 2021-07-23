#include <bits/stdc++.h>

using namespace std;

vector<string> findCombinations(vector<string> comb, int leftLeft, int leftRight, string str, int index){
	//invalid state
	if(leftLeft > leftRight) return comb;
	
	//base case
	if(leftRight == 0) comb.push_back(str);
	
	if(leftLeft > 0){
		str[index] = '(';
		comb = findCombinations(comb, leftLeft - 1, leftRight, str, index + 1);
	}
	
	if(leftRight > 0){
		str[index] = ')';
		comb = findCombinations(comb, leftLeft, leftRight - 1, str, index + 1);
	}
	
	return comb;
}

vector<string> findCombinations(int n){
	vector<string> comb;
	string str(2 * n, ' ');
	
	return findCombinations(comb, n, n, str, 0);
}

int main(){
	vector<string> comb;
	
	comb = findCombinations(3);
	
	for(auto &x : comb) cout << x << ", ";
}
