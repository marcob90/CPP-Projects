#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    //improving brutal force solution
    
    int n = s.size();
    string result = "";
    int maxLength = 0;
    int start = 0;

    //check odds strings
    //find a center and expands from it, save maxLength string if palindrom is found
    for(int center = 0; center < n; center++){
    	int i = center;
    	int j = center;
    	
    	while(i >= 0 && j < n && s[i] == s[j]){
    			i--;
    			j++;
		}
		
		int length = j - i - 1;
		if(length > maxLength) {
			maxLength = length;
			start = i + 1;
		}	
	}
	
	//check even strings
	//find a center of two and expand from it
	for(int center = 0; center < n; center++){
		if(center + 1 < n && s[center] == s[center + 1]){
			int i = center;
    		int j = center + 1;
    	
	    	while(i >= 0 && j < n && s[i] == s[j]){
    			i--;
    			j++;
			}
			
			int length = j - i - 1;
			if(length > maxLength) {
				maxLength = length;
				start = i + 1;
			}	
		}
	}
	
	return s.substr(start, maxLength);
}

int main(){
	string s = "radarttrada";
	
	cout << longestPalindrome(s);
}
