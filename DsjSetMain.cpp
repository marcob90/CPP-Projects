#include "DsjSet.h"

int main()
{
	DsjSet set;
	
	set.Union(0, 1);
	set.Union(2, 3);
	set.Union(1, 2);
	set.Union(0, 3);
	set.Union(0, 4);
	set.Union(1, 4);
	
	if(set.find(3) == set.find(0)) cout << "Yes";
	else cout << "No";
	
	cout << endl << set.getRank(0);
}
