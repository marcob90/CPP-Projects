#include <bits/stdc++.h>

using namespace std;

class ExtendedStack : public stack<int>
{
	public:
		ExtendedStack() //constructor
		{
			//empty body
		}
		
		void push(int value)
		{
			if(value <= peekMin())
				minStack.push(value);

			stack<int>::push(value);
		}
		
		void pop()
		{
			if(stack<int>::top() == peekMin())
				minStack.pop();
			stack<int>::pop();
		}
		
		int peekMin() const
		{
			if(minStack.empty())
				return INT_MAX;
			else return minStack.top();
		}
		
		void traverseStack()
		{
			if(stack<int>::empty())
				return;
			int value = stack<int>::top();
			cout << value << " ";
			this->pop();
			traverseStack();
			this->push(value);
		}
	private:
		stack<int> minStack;
};

int main()
{
	ExtendedStack exStack;
	srand(time(NULL));
	
	for(int i = 1; i <= 10; i++){
		int val = rand() % 50;
		exStack.push(val);
	}
	exStack.traverseStack();
	cout << endl;
	
	cout << "Minimum Value in stack is: " << exStack.peekMin() << endl;
	exStack.pop();
	exStack.pop();
	exStack.pop();
	exStack.pop();
	exStack.traverseStack();
	cout << endl;
	cout << "Minimum Value in stack is: " << exStack.peekMin() << endl;
}
