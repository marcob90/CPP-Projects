#include <iostream>
#include <string>

using namespace std;

void permutation(string str, string index){
	if(str.empty())
		cout << index << endl;
	else{
		for(int i = 0; i < str.size(); i++){
			string rem = str.substr(0, i) + str.substr(i + 1);
			permutation(rem, index + str.at(i));
		}
	}
}

void permutation(string str){
	permutation(str, "");
}

int main(){
	string a = "bongini";
	permutation(a);
}
