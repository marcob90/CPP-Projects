#include <bits/stdc++.h>
#define SIZE 5
using namespace std;

int merge(vector<int> &arr, vector<int> &temp, int left, int mid, int right)
{
	int i = left, j = mid + 1, k = left;
	int inv_count = 0;
	
	while ((i <= mid) && (j <= right)) 
    { 
        if (arr[i] <= arr[j]) 
            temp[k++] = arr[i++]; 
        else
        { 
            temp[k++] = arr[j++]; 
            cout << mid + 1 - i << endl;
  
            inv_count = inv_count + (mid + 1 - i); 
        } 
    } 
	
	/* Copy the remaining elements of left subarray 
     (if there are any) to temp*/
    while (i <= mid) 
        temp[k++] = arr[i++]; 
  
    /* Copy the remaining elements of right subarray 
     (if there are any) to temp*/
    while (j <= right) 
        temp[k++] = arr[j++]; 
  
    /*Copy back the merged elements to original array*/
    for (i=left; i <= right; i++) 
        arr[i] = temp[i]; 
        
	//for(auto &x : arr) cout << x << " ";
//	cout << endl;
  
    return inv_count; 
}

int mergeSort(vector<int> &a, vector<int> &t, int l, int r)
{
	int count = 0;
	
	if(l < r){
		int m = l + (r - l) / 2;
		
		count = mergeSort(a, t, l, m);
		count += mergeSort(a, t, m + 1, r);
		
		count += merge(a, t, l, m, r);
	}
	
	return count;
}

int countSwaps(vector<int> &a)
{
	vector<int> temp(SIZE);
	return mergeSort(a, temp, 0, SIZE - 1);
}

int main()
{
	vector<int> array{31, 1, 45, 7, 2};
	
	srand(time(NULL));
	
//	for(auto &x : array) x = rand() % 50;
	for(auto &x : array) cout << x << " ";
	cout << "\n\n";
	
	int swaps = countSwaps(array);
	cout << endl;
	for(auto &x : array) cout << x << " ";
	cout << endl;
	
	cout << "Number of swaps is: " << swaps;
}
