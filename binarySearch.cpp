#include <bits/stdc++.h>
using namespace std;

/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition(vector<int> &a, int low, int high)
{
	int pivot = a.at(high);
	int i = low - 1;
	
	for(int j = low; j < high; j++){
		if(a[j] < pivot){
			++i;
			swap(a[i], a[j]);
		}
	}
	swap(a[high], a[i + 1]);
	return i + 1;
}

void quickSort(vector<int> &a, int low, int high)
{
	if(low < high){
		//after this call, arr[p] is at the right place
		int pi = partition(a, low, high);
		
		//sort elements before partition and after partition
		quickSort(a, low, pi - 1);
		quickSort(a, pi + 1, high);
	}
}

bool binarySearch(const vector<int> &a, int left, int right, int n)
{
	if(right >= left){
		int mid = left + (right - left) / 2;
		
		if(a[mid] == n) return true;
		
		if(a[mid] > n) return binarySearch(a, left, mid - 1, n);
		
		return binarySearch(a, mid + 1, right, n);
	}
	else return false;
}

void printArray(const vector<int> &a)
{
	for(auto &x : a) cout << x << " ";
	cout << endl;
}

int main(){
	vector<int> arr(20);
	int value;
	
	cout << "Enter a whole value between 0 and 49: ";
	cin >> value;
	
	srand(time(NULL));
	
	for(auto &x : arr) x = rand() % 50;
	printArray(arr);
	
	cout << "\nSorted array is:\n";
	quickSort(arr, 0, arr.size() - 1);
	printArray(arr);
	
	if(binarySearch(arr, 0, arr.size() - 1, value)) cout << "\nValue found\n";
	else cout << "\nValue not found\n";
}
