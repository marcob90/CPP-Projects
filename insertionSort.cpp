#include <bits/stdc++.h>

using namespace std;

long long insertionSort(vector<int> &s){
	int i, j;  /*counters*/
	long long swaps = 0;
	
	for(i = 1; i < s.size(); i++){
		j = i;
		while((j > 0) && (s[j] < s[j - 1])){
			swap(s[j], s[j - 1]);
			j--;
			swaps++;
		}
	}
	
	return swaps;
}

int insertionSort(string &s){
	int i, j;  /*counters*/
	int swaps = 0;
	
	for(i = 1; i < s.size(); i++){
		j = i;
		while((j > 0) && (s[j] < s[j - 1])){
			swap(s[j], s[j - 1]);
			j--;
			swaps++;
		}
	}
	
	return swaps;
}

int bubbleSort(vector<char> &s){
	int swaps = 0;
	
	for(int i = 0; i < s.size(); i++){
		for(int j = i + 1; j < s.size(); j++){
			if(s[j] < s[i]){
				swap(s[j], s[i]);
				swaps++;
			}
		}
	}
	
	return swaps;
}

int bubbleSort(string &s){
	int swaps = 0;
	
	for(int i = 0; i < s.size(); i++){
		for(int j = i + 1; j < s.size(); j++){
			if(s[j] < s[i]){
				swap(s[j], s[i]);
				swaps++;
			}
		}
	}
	
	return swaps;
}

int main(){
	vector<int> myList;
	
	srand(time(NULL));
	
	for(int i = 1; i <= 10000; i++){
		myList.push_back(rand() % 10000 + 1);
	}
	
/*	for(auto &x : myList) cout << x << " ";
	cout << endl;*/
	
	long long swaps = insertionSort(myList);
	
	/*for(auto &x : myList) cout << x << " ";
	cout << endl;*/
	cout << "Number of swaps: " << swaps << endl;
	
	/*vector<char> myList = 
	{'I', 'N', 'S', 'E', 'R', 'T', 'I', 'O', 'N', 'S', 'O', 'R', 'T'};
	
	string myString = "ZYTRGDA";
	
	for(auto &x : myList) cout << x << " ";
	cout << endl;
	
	int swaps = insertionSort(myList);
	
	for(auto &x : myList) cout << x << " ";
	cout << endl;
	cout << "Number of swaps: " << swaps << endl;
	
	for(auto &x : myString) cout << x << " ";
	cout << endl;
	
	int swaps2 = insertionSort(myString);
	
	for(auto &x : myString) cout << x << " ";
	cout << endl;
	cout << "Number of swaps: " << swaps2 << endl;*/
}
