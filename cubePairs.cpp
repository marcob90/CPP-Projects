#include <bits/stdc++.h>
#define POW3(x) (x) * (x) * (x)

using namespace std;

void printPairs(int n){
	unordered_map<int, vector<pair<int, int>>> map;
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			int result = POW3(i) + POW3(j);
			map[result].push_back(make_pair(i, j));
		}
		
	for(const auto& elem : map)
		for(const auto& pair1 : elem.second)
			for(const auto& pair2 : elem.second)
				if(pair1.first != pair2.first && pair1.first != pair2.second)
					cout << "(" << pair1.first << ", " << pair1.second << ")" <<
					" , " << "(" << pair2.first << ", " << pair2.second << ")" << endl;
	
}

int main(){
	int n = 1000;
	printPairs(n);
}
