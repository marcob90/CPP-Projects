#include <bits/stdc++.h>

using namespace std;

class MyQueue{
	private:
		stack<int> stackA;
		stack<int> stackB;
		
		void shiftElements()
		{
			while(!stackA.empty()){
				int val = stackA.top();
				stackA.pop();
				stackB.push(val);
			}
		}
	
	public:
		void enqueue(int value)
		{
			stackA.push(value);
		}
		
		void dequeue()
		{
			if(!stackA.empty() && stackB.empty())
				shiftElements();
			
			stackB.pop();
		}
		
		int peek()
		{
			if(!stackA.empty() && stackB.empty())
				shiftElements();
			
			return stackB.top();
		}
};

int main()
{
	MyQueue myQueue;
	for(int i = 1; i <= 10; i++){
		myQueue.enqueue(i);
	}
	
	cout << myQueue.peek() << endl;
	myQueue.dequeue();
	myQueue.enqueue(20);
	cout << myQueue.peek() << endl;
	myQueue.dequeue();
	myQueue.dequeue();
	myQueue.dequeue();
	myQueue.dequeue();
	myQueue.dequeue();
	myQueue.dequeue();
	myQueue.dequeue();
	myQueue.dequeue();
	cout << myQueue.peek() << endl;
	myQueue.dequeue();
	cout << myQueue.peek() << endl;
	for(int i = 1; i <= 10; i++){
		myQueue.enqueue(i);
	}
	cout << myQueue.peek() << endl;
	myQueue.dequeue();
	cout << myQueue.peek() << endl;
}
