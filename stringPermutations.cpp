#include <bits/stdc++.h>

using namespace std;

bool permutation(string s1, string s2){
	if(s1.size() != s2.size()) return false;
	
	unordered_map<char, int> map;
	for(auto &x : s1)
		map[x]++;
	
	for(auto &x : s2){
		if(map.find(x) == map.end() ||
		map[x] == 0)
			return false;
		map[x]--;
	}
	
	return true;
}

int main(){
	string s1 = "poiuytrewqlkjhgfdsazxcvbnm";
	string s2 = "mnbvcxzasdfghjklpoiuytrewa";
	cout << permutation(s1, s2);
}
