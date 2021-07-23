#include <bits/stdc++.h>

using namespace std;

/*bool isPermutationOfPalindrome(string s){
	//bt: check all the permutations if they are palindrome 
	//solution: find repetitions of every letter
	//s is permutation of palindrome if all counts are even or 
	//all counts are even but one count that is odd
	
	int char_set['z' - 'a' + 1] = {0};
	bool oddFound = false;
	
	for(auto &x : s)
		if(isalpha(x))
			char_set[x - 'a']++;
	
	for(auto &x : char_set){
		if(x % 2 == 1 && oddFound)
			return false;
		else if(x % 2 == 1 && !oddFound)
			oddFound = true;
	}
	
	return true;
}*/

void toggle(int *n, int pos){
	(*n) ^= (1 << pos);
}

bool isPermutationOfPalindrome(string s){
	//bt: check all the permutations if they are palindrome 
	//solution: find repetitions of every letter
	//s is permutation of palindrome if all counts are even or 
	//all counts are even but one count that is odd
	
	int checker = 0;
	
	for(auto &x : s)
		if(isalpha(x))
			toggle(&checker, x - 'a');
	
	return !((checker - 1) & checker);
}

int main(){
	string s = "non avevano i topi nipoti";
	
	cout << isPermutationOfPalindrome(s);
}
