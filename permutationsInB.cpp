#include <bits/stdc++.h>

using namespace std;

int permutationsInB(string a, string b){
	unordered_map<char, int> aMap;
	unordered_map<char, int> bMap;
	int count = 0;
	
	for(auto &x : a)
		aMap[x]++;
	for(int i = 0; i < a.size(); i++)
		bMap[b[i]]++;
	
	for(int i = 0; i <= b.size() - a.size(); i++){
		if(aMap == bMap) 
			count++;
				
		bMap[b[i]]--;
		
		if(i + a.size() < b.size())
			bMap[b[i + a.size()]]++;
			
		if(bMap[b[i]] == 0) 
			bMap.erase(b[i]);	
	}
	
	return count;
}

bool arePermutations(string a, string b){
	unordered_map<char, int> aMap;
	unordered_map<char, int> bMap;
	int count = 0;
	
	if(a.size() != b.size())
		return false;
	
	for(auto &x : a)
		aMap[x]++;
	for(auto &x : b)
		bMap[x]++;
	
	if(aMap == bMap)
		return true;
	else return false;
}

bool isUnique(string a){
	sort(a.begin(), a.end());
	
	for(int i = 0; i < a.size() - 1; i++){
		if(a[i + 1] == a[i])
			return false;
	}
	
	return true;
}

int countChar(char s[], int start, int end, char c){
	int count = 0;
	
	for(int i = start; i < end; i++){
		if(s[i] == c) count++;
	}
	
	return count;
}

void replaceSpaces(char s[], int trueSize){
	int numberOfSpaces = countChar(s, 0, trueSize, ' ');
	int newIndex = trueSize - 1 + 2 * numberOfSpaces;
	
	if(newIndex + 1 < strlen(s)) s[newIndex + 1] = '\0';
	for(int oldIndex = trueSize - 1; oldIndex >=0; oldIndex--){
		if(s[oldIndex] == ' '){
			s[newIndex] = '0';
			s[newIndex - 1] = '2';
			s[newIndex - 2] = '%';
			newIndex -= 3;
		}
		else{
			s[newIndex] = s[oldIndex];
			newIndex--;
		}
	}
}

bool isPalindromePermutation(string a){
	int checker = 0;
	
	for(auto &x : a)
		if(isalnum(x))
			checker ^= 1 << (tolower(x) - 'a');
	
	return !(checker & (checker - 1));	
}

bool areOneCharAway(string a, string b){
	if(a == b) return true;
	
	bool charFlag = false;
	
	//replace
	if(a.size() == b.size()){
		for(int i = 0; i < a.size(); i++){
			if(a[i] != b[i] && charFlag)
				return false;
			else if(a[i] != b[i] && !charFlag)
				charFlag = true;
		}
		
		return true;
	} //removal/insertion
	else if(abs((int)a.size() - (int)b.size()) == 1){
		for(int i, j = 0; i < a.size() && j < b.size();){
			if(a[i] == b[j]){
				i++;
				j++;
			}
			else if(a[i] != b[j] && !charFlag){
				charFlag = true;
				if(a.size() > b.size()) i++;
				else j++;
			}
			else return false;
		}
		
		return true;
	}
	
	return false;
}

int main(){
	string a = "caba";
	string b = "abcaadcbaaabaca";
	string c = "marco bongini";
	string d = "inoboma rincg";
	string e = "caldo best";
	string f = "PaLe, pal";
	string g = "";
	string h = "";
	char name[] = "Mr John Smith    ";
	cout << "Permutations are " << permutationsInB(a, b) << endl;
	cout << "c and d result: " << arePermutations(c, d) << endl;
	cout << "e is unique: " << isUnique(e) << endl;
	cout << "d is unique: " << isUnique(d) << endl;
	replaceSpaces(name, 13);
	cout << name << endl;
	cout << "string has palindrome permutation: " << isPalindromePermutation(f) << endl;
	cout << "strings are one char away: " << areOneCharAway(g, h) << endl;
}
