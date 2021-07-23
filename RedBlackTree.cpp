#include <bits/stdc++.h>

using namespace std;

enum Color{RED, BLACK};

class Node{
	public:
		int data;
		Node *right, *left, *parent;
		Color color;
	
		Node(int d){
			data = d;
			right = left = parent = NULL;
			color = RED;
		}
};

class RBTree{
	private:
		Node *root;
	protected: 
    	void rotateLeft(Node *&, Node *&); 
    	void rotateRight(Node *&, Node *&); 
    	void fixViolation(Node *&, Node *&); 
	public:
		RBTree() : root(NULL){}
		void insert(int);
		void inOrder();
};

Node *BSTInsert(Node *root, Node* newNode){
	if(root == NULL)
		return newNode;
	if(newNode->data < root->data){
		root->left = BSTInsert(root->left, newNode);
		root->left->parent = root; 
	}
	else if(newNode->data > root->data){
		root->right = BSTInsert(root->right, newNode);
		root->right->parent = root; 
	}
}

// Function to insert a new node with given data 
void RBTree::insert(const int &data) 
{ 
    Node *newNode = new Node(data); 
  
    // Do a normal BST insert 
    root = BSTInsert(root, newNode); 
  
    // fix Red Black Tree violations 
    fixViolation(root, newNode); 
} 

int main()
{
	
}
