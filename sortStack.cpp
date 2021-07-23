#include <bits/stdc++.h>

using namespace std;

void shiftElements(stack<int> &stackA, stack<int> &stackB)
{
	while(!stackB.empty()){
		int val = stackB.top();
		stackB.pop();
		stackA.push(val);
	}
}

void sortStack(stack<int> &stackA)
{
	stack<int> stackB;
	
	while(!stackA.empty()){
		int val = stackA.top();
		stackA.pop();
		while(!stackB.empty() && val < stackB.top()){
			stackA.push(stackB.top());
			stackB.pop();
		}
		
		stackB.push(val);
	}
	
	shiftElements(stackA, stackB);
}

void traverseStack(stack<int> s)
{
	if(s.empty())
		return;
	int value = s.top();
	cout << value << " ";
	s.pop();
	traverseStack(s);
	s.push(value);
}

int main()
{
	stack<int> stackA;
	
	srand(time(NULL));
	
	for(int i = 1; i <= 10; i++){
		int val = rand() % 50;
		stackA.push(val);
	}
	
	traverseStack(stackA);
	cout << endl;
	sortStack(stackA);
	traverseStack(stackA);
	cout << endl;
}



