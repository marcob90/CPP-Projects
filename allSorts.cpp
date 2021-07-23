#include <bits/stdc++.h>

using namespace std;

void print(vector<int> &v){
	for(auto &x : v){
		cout << x << " ";
	}
	cout << endl;
}
//advanced bubbleSort
//the index stops at size - count because the cue is already "bubbled"
//O(n^2)
void bubbleSort(vector<int> &v){
	for(int count = 1; count < v.size(); count++){
		for(int j = 0; j < v.size() - count; j++){
			if(v[j] > v[j + 1])
				swap(v[j], v[j + 1]);
		}
	}
}

//selection sort: find minimum at every pass
//O(n^2)
void selectionSort(vector<int> &v){
	for(int i = 0; i < v.size() - 1; i++){
		int minIndex = i;
		for(int j = i + 1; j < v.size(); j++){
			if(v[j] < v[minIndex])
				minIndex = j;
		}
		
		swap(v[i], v[minIndex]);
	}
}

void merge(vector<int> &v, int l, int m, int h){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = h - m;
	
	vector<int> L(n1), R(n2);
	
	for(i = 0; i < n1; i++) L[i] = v[l + i];
	for(j = 0; j < n2; j++) R[j] = v[m + 1 + j];
	
	i = 0;
	j = 0;
	k = l;
	
	while(i < n1 && j < n2){
		if(L[i] < R[j]){
			v[k++] = L[i++];
		}
		else{
			v[k++] = R[j++];
		}
	}
	
	//put elements in vector if there are leftovers
	while(i < n1){
		v[k++] = L[i++]; 
	}
}

void mergeSort(vector<int> &v, int low, int high){
	if(low < high){
		int middle = (low + high) / 2;
		
		//sort lower half
		mergeSort(v, low, middle);
		//sort upper half
		mergeSort(v, middle + 1, high);
		//merge two halves
		merge(v, low, middle, high);
	}
}

void mergeSort(vector<int> &v){
	mergeSort(v, 0, v.size() - 1);
}

int partition(vector<int> &v, int low, int high){
	/*int pivot = v[high];
	int i = low - 1; //index that keeps track of smaller elements of pivot
	
	for(int j = low; j <= high; j++){
		if(v[j] < pivot){
			//found smaller element than pivot
			//increment index i
			i++;
			
			//swap elements
			swap(v[i], v[j]);
		}
	}
	//final swaps brings pivot to the right position
	swap(v[i + 1], v[high]);
	return i + 1; //return element at right position*/
	
	int middle = low + rand() % (high - low);//(low + high) / 2;
	int pivot = v[middle];
	int i = low - 1;
	int j = high + 1;
	
	for(;;){
		do{
			i++;
		}while(v[i] < pivot);
		
		do{
			j--;
		}while(v[j] > pivot);
		
		if(j <= i)
			return j;
		
		swap(v[i], v[j]);
	}
}

void quickSort(vector<int> &v, int low, int high){
	if(low < high){
		int pi = partition(v, low, high);
		
		quickSort(v, low, pi);
		quickSort(v, pi + 1, high);
	}
}

void quickSort(vector<int> &v){
	quickSort(v, 0, v.size() - 1);
}

void bucketSort(vector<float> &v){
	/*1) Create n empty buckets (Or lists).
	2) Do following for every array element arr[i].
	.......a) Insert arr[i] into bucket[n*array[i]]
	3) Sort individual buckets using insertion sort.
	4) Concatenate all sorted buckets.*/
	int n = v.size();
	vector<list<float>> buckets(n);
	
	for(auto &x : v){
		int index = n * x;
		buckets[index].push_back(x);
	}
	
	for(auto &x : buckets)
		x.sort();
	
	int index = 0;
	for(auto &x : buckets)
		for(auto &y : x)
			v[index++] = y;
}

void insertionSort(vector<int> &s){
	int i, j;  /*counters*/
	
	for(i = 1; i < s.size(); i++){
		j = i;
		while((j > 0) && (s[j] < s[j - 1])){
			swap(s[j], s[j - 1]);
			j--;
		}
	}
}

int getMax(const vector<int> &v){
	int maxValue = INT_MIN;
	for(auto &x : v){
		maxValue = max(x, maxValue);
	}
	
	return maxValue;
}

void countSort(vector<int> &v){
	int size = getMax(v) + 1;
	
	vector<int> output(v.size(), 0);
	vector<int> count(size, 0);
	
	for(auto &x : v){
		++count[x];
	}
	
	for(int i = 1; i < size; i++){
		count[i] += count[i - 1];
	}
	
	for(auto &x : v){
		output[count[x] - 1] = x;
		--count[x];
	}
	
	for(int i = 0; i < v.size(); i++){
		v[i] = output[i];
	}
}

void countSort(vector<int> &v, int exp){
	vector<int> output(v.size());
	vector<int> count(10, 0);
	
	for(auto &x : v){
		count[(x / exp) % 10]++;
	}
	
	for(int i = 1; i < 10; i++){
		count[i] += count[i - 1];
	}
	
	for(int i = v.size() - 1; i >= 0; i--){
		output[count[(v[i] / exp) % 10] - 1] = v[i];
		count[(v[i] / exp) % 10]--;
	}
	for(int i = 0; i < v.size(); i++){
		v[i] = output[i];
	}
}

void radixSort(vector<int> &v){
	int m = getMax(v);
	
	for(int exp = 1; m/exp > 0; exp *= 10){
		countSort(v, exp);
	}
}

void heapSort(vector<int> &v){
	make_heap(v.begin(), v.end());
	
	vector<int>::iterator it = v.end() - 1;
	
	while(it != v.begin()){
		swap(*(v.begin()), *it);
		make_heap(v.begin(), --it);
	}
}

int main(){
	vector<int> v;
	srand(time(NULL));
	
	for(int i = 1; i <= 100; i++){
		v.push_back(rand() % 1000);
	}
	print(v);
	cout << endl;
	heapSort(v);
	cout << endl;
	print(v);
	
/*	vector<float> a = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
	bucketSort(a);
	for(auto &x : a){
		cout << x << " ";
	}*/
	
}
