#include <iostream>
#include <array>

using namespace std;

void reverse(array<int, 11> &a){
	for(int i = 0; i < a.size() / 2; i++){
		swap(a[i], a[a.size() - 1 - i]);
	}
}

int main(){
	const int size = 11;
	array<int, size> a = {0};
	
	for(int i = 1; i < a.size(); i++){
		a[i] = 1 + a[i - 1]; 
	}
	
	cout << "Original Order: ";
	for(auto &x : a)
		cout << x << " ";
	cout << endl;
	
	cout << "Reverse Order: ";
	reverse(a);
	for(auto &x : a)
		cout << x << " ";
	cout << endl;
}
