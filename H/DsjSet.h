#ifndef DSET_H
#define DSET_H

#include <bits/stdc++.h>
using namespace std;

class DsjSet
{	
	public:
		void Union(int, int);
		int find(int);
		int getRank(int);
		
	private:
		unordered_map<int, int> parent;
		unordered_map<int, int> rank;
		unordered_map<int, int>::iterator it;
};

void DsjSet::Union(int x, int y)
{		
	int xset = find(x);
	int yset = find(y);
	
	//cycle
	if(xset == yset) return;
	
	if(rank[xset] < rank[yset]){
		parent[xset] = yset;
		rank[yset] += rank[xset];
	}
	else{
		parent[yset] = xset;
		rank[xset] += rank[yset];
	}
}

int DsjSet::find(int x)
{
	it = parent.find(x);
	
	if(it == parent.end()){
		parent.insert({x, x});
		rank.insert({x, 1});
	}
	else if(it->first != it->second){
		it->second = find(it->second);
	}
	
	return parent[x];
}

int DsjSet::getRank(int x)
{
	it = rank.find(x);
	
	//representative node
	if(it != rank.end() && x == parent[x]) 
		return it->second;
	//look for representative
	else if(it != rank.end() && x != parent[x])
		return rank[find(parent[x])];
	
	return 0;
}
#endif
