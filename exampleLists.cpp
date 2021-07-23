#include <bits/stdc++.h>
using namespace std;

struct listNode{
	int a;
	char b;
};

typedef listNode ListNode;

ListNode *function1(ListNode *ptr)
{
	ListNode p;
	ListNode *newNodePtr = &p;//new ListNode;
	newNodePtr->a = 3;
	newNodePtr->b = 'f';
	
	ptr = newNodePtr;
	
	return ptr;
}

int main(){
	ListNode *nodePtr = new ListNode;
	nodePtr->a = 4;
	nodePtr->b = 'c';
	
	ListNode *fPtr = new ListNode;
	fPtr = function1(nodePtr);
	cout << fPtr->a << " " << fPtr->b << endl;
	cout << nodePtr->a << " " << nodePtr->b << endl;
}
