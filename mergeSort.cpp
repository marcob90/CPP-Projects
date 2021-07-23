#include <bits/stdc++.h>
#define SIZE 1000
using namespace std;

int merge(vector<int> &a, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int inv_count = 0;
	
	vector<int> L(n1), R(n2);
	
	for(i = 0; i < n1; i++) L[i] = a[l + i];
	for(j = 0; j < n2; j++) R[j] = a[m + 1 + j];
	
	i = 0;
	j = 0;
	k = l;
	
	while(i < n1 && j < n2){
		if(L[i] <= R[j]){
			a[k] = L[i];
			i++;
		}
		else{
			a[k] = R[j];
			j++;
			inv_count += m + 1 - i - l;
		}
		
		k++;
	}
	
	while(i < n1){
		a[k] = L[i];
		i++;
		k++;
	}
	
	return inv_count;
}

int mergeSort(vector<int> &a, int l, int r)
{
	int count = 0;
	
	if(l < r){
		int m = l + (r - l) / 2;
		
		count = mergeSort(a, l, m);
		count += mergeSort(a, m + 1, r);
		
		count += merge(a, l, m, r);
	}
	
	return count;
}

int main()
{
	vector<int> a(SIZE);
	
	srand(time(NULL));
	
	for(auto &x : a) x = rand() % SIZE + 1;
/*	for(auto &x : a) cout << x << " ";
	cout << endl;*/
	
	int swaps = mergeSort(a, 0, SIZE - 1);
/*	for(auto &x : a) cout << x << " ";
	cout << endl;*/
	
	cout << "Number of swaps is: " << swaps;
}
