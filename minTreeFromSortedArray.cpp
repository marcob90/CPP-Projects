#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
	public:
		int value;
		TreeNode *leftNode;
		TreeNode *rightNode;
	
		TreeNode(int val) :
		value(val),
		leftNode(NULL),
		rightNode(NULL)
		{ /*empty body*/}
		
		void inOrder(){
			if(this != NULL){
				this->leftNode->inOrder();
				cout << this->value << " ";
				this->rightNode->inOrder();
			}
		}	
};

class Node
{
	public:
		int value;
		Node *leftNode;
		Node *rightNode;
		Node *parent;
	
		Node(int val) :
		value(val),
		leftNode(NULL),
		rightNode(NULL),
		parent(NULL)
		{ /*empty body*/}
		
		void inOrder(){
			if(this != NULL){
				this->leftNode->inOrder();
				cout << this->value << " ";
				this->rightNode->inOrder();
			}
		}	
};

Node* push(Node *node, int val){
	if(node == NULL){
		//create node
		return new Node(val);	
	}	

	if(val < node->value){
		node->leftNode = push(node->leftNode, val);
		node->leftNode->parent = node;
	}
	else{
		node->rightNode = push(node->rightNode, val);
		node->rightNode->parent = node;
	}
	
	return node;
}

TreeNode* push(TreeNode *node, int val){
	if(node == NULL){
		//create node
		return new TreeNode(val);	
	}	

	if(val < node->value){
		node->leftNode = push(node->leftNode, val);
	}
	else{
		node->rightNode = push(node->rightNode, val);
	}
	
	return node;
}

TreeNode* createMinHeightTree(const vector<int> &v, int low, int high){
	if(low <= high){
		int middleIndex = (high + low) / 2;
		TreeNode *treeNode = new TreeNode(v[middleIndex]);
		treeNode->leftNode = createMinHeightTree(v, low, middleIndex - 1);
		treeNode->rightNode = createMinHeightTree(v, middleIndex + 1, high);
		return treeNode;
	}
	
	return NULL;
}

TreeNode* createMinHeightTree(const vector<int> &v){
	return createMinHeightTree(v, 0, v.size() - 1);
}

//function that visits each level implementing DFS
void createLevelLinkedList(TreeNode *node, 
vector<list<TreeNode *> *> &lists, int level){
	if(node == NULL) return; //leaf reached
	
	list<TreeNode *> *linkedList = NULL;
	if(lists.size() == level){
		linkedList = new list<TreeNode *>;
		lists.push_back(linkedList);
	}
	else
		linkedList = lists[level];
	
	linkedList->push_back(node);	
	createLevelLinkedList(node->leftNode, lists, level + 1);
	createLevelLinkedList(node->rightNode, lists, level + 1);
}

//find lists of depths with DFS
vector<list<TreeNode *> *> createLevelLinkedList(TreeNode *node){
	vector<list<TreeNode *> *> lists;
	createLevelLinkedList(node, lists, 0);
	return lists;
}

//find lists of depths with BFS
vector<list<TreeNode *> *> createLevelLinkedListBFS(TreeNode *node){
	vector<list<TreeNode *> *> lists;
	list<TreeNode *> *current = new list<TreeNode *>;
	current->push_back(node);
	
	while(!current->empty()){
		lists.push_back(current);
		list<TreeNode *> *parents = current;
		current = new list<TreeNode *>;	
		
		for(auto &parent : *(parents)){
			if(parent->leftNode != NULL){
				current->push_back(parent->leftNode);
			}
			if(parent->rightNode != NULL){
				current->push_back(parent->rightNode);
			}
		}
	}
	
	return lists;
}

int getHeight(TreeNode *root){
	if(root == NULL) return -1;
	
	int x = getHeight(root->leftNode);
	int y = getHeight(root->rightNode);
	return max(x, y) + 1;
}

//modified version of getHeight()
//time complexity: O(N). Pass back an error code if tree is not balanced
int checkHeight(TreeNode *root){
	if(root == NULL) return -1;
	
	int x = checkHeight(root->leftNode);
	int y = checkHeight(root->rightNode);
	
	if(x == INT_MIN || y == INT_MIN)
		return INT_MIN; //pass back error code
	
	if(abs(x - y) > 1){
		return INT_MIN; //error code
	}
	else
		return max(x, y) + 1;
}

bool isBalanced(TreeNode *root){
	return checkHeight(root) != INT_MIN;
}

void printList(list<TreeNode *> *linkedList){
	for(auto &node : *(linkedList)){
		cout << node->value << " ";
	}
	cout << endl;
}

bool isBST(TreeNode *node, int *min, int *max){
	if(node == NULL) return true;
	if((max != NULL && node->value >= *max) || (min != NULL && node->value <= *min))
		return false;
	
	return isBST(node->leftNode, min, &(node->value)) &&
		   isBST(node->rightNode, &(node->value), max);
}

bool isBST(TreeNode *node){
	return isBST(node, NULL, NULL);
}

Node *findInorderSuccessor(Node* node){
	//if right node is not NULL
		//go to left child of right node and go as left as you can
	//if right node is NULL
		//if node is left child 
			//return parent
		//else if node is right child
			//return granparent
	
	if(node == NULL) return NULL;
	
	if(node->rightNode != NULL){
		Node *successor = node->rightNode;
		while(successor->leftNode != NULL){
			successor = successor->leftNode;
		}
		
		return successor;
	}
	else{ //right node is NULL
		Node *n = node;
		Node *p = node->parent;
		while(p != NULL && p->leftNode != n){
			n = p;
			p = n->parent;
		}
		return p;
	}
}

int main()
{
	vector<int> v = {5, 0, 1, 7, 3, 8, 10, 4, 21};
	
	Node *root = new Node(9);
	for(auto &x : v){
		push(root, x);
	}
	
	root->inOrder();
	cout << endl;
	Node *n = findInorderSuccessor(root);
	if(n)
		cout << n->value;
	else
		cout << "NULL";
	
	//TreeNode *t = createMinHeightTree(v);
/*	TreeNode *t = new TreeNode(8);
	for(auto &x : v){
		push(t, x);
	}
	t->inOrder();
	
	vector<list<TreeNode *> *> arr1 = createLevelLinkedList(t);
	vector<list<TreeNode *> *> arr2 = createLevelLinkedListBFS(t);
	
	for(auto &x : arr1){
		printList(x);
	}
	
	cout << endl;
	
	for(auto &x : arr2){
		printList(x);
	}
	
	cout << endl << isBalanced(t) << endl;
	t->value = 80;
	cout << isBST(t);*/
}
