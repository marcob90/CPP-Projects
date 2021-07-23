#include <bits/stdc++.h>
using namespace std;

struct stackNode{
    char data;
    struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;

StackNode *push(StackNode *head, char value){
    StackNode *newPtr = new StackNode;

    if(newPtr != NULL){
        newPtr->data = value;
        newPtr->nextPtr = head;
    }

    return newPtr;
}

int main()
{
	StackNode *newNode = NULL;
	newNode = push(newNode, '{');
	cout << newNode->data;
}
