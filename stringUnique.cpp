#include <bits/stdc++.h>

using namespace std;

/*bool isUniqueChars(string str){
	//I suppose the string contains ASCII characters
	if(str.size() > 128) return false;
	
	bool char_set[128] = {0};
	for(int i = 0; i < str.size(); i++){
		int key = str[i];
		if(char_set[key])	return false;
		else char_set[key] = true;
	}
	
	return true;
}*/

bool isUniqueChars(string str){
	//let's suppose chars are from a to z lowercase
	int checker = 0;
	for(int i = 0; i < str.size(); i++){
		int val = str[i] - 'a';
		if((checker >> val) & 1) return false;
		else
			checker |= (1 << val);
	}
	
	return true;
}

int main(){
	string s = "poiuytrewqlkjhgfdsazxcvbnm";
	cout << isUniqueChars(s);
}
