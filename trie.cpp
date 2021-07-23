#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

class Node{
    public:
        Node(int d){
            data = d;
            leftPtr = NULL;
            rightPtr = NULL;
        }

        int data;
        Node *leftPtr;
        Node *rightPtr;
};

Node *insertNode(Node *leaf, int d){	
	if(leaf != NULL){
	    if(d == 1 && leaf->rightPtr != NULL){
	        return leaf->rightPtr;
	    }
	    else if(d == 0 && leaf->leftPtr != NULL){
	        return leaf->leftPtr;
	    }
	    
	    Node *newNode = new Node(d);
	    
        if(d == 1) leaf->rightPtr = newNode;
        else leaf->leftPtr = newNode;
        return newNode;
	}
	else return NULL;
}

Node *getNode(Node *leaf, int key){
	if(leaf != NULL){
		if(key == 1 && leaf->rightPtr != NULL)
			return leaf->rightPtr;
		else if(key == 0 && leaf->leftPtr != NULL)
	        return leaf->leftPtr;
	    else if(key == 1 && leaf->rightPtr == NULL)
	    	return leaf->leftPtr;
	    else if(key == 0 && leaf->leftPtr == NULL)
	    	return leaf->rightPtr;
	}
	
	return leaf;
}

void inOrder(Node * treePtr)
{
	if( treePtr != NULL){
		inOrder( treePtr->leftPtr );
		printf( "%3d", treePtr->data );
		inOrder( treePtr->rightPtr ); 
	}
}

void preOrder(Node* treePtr )
{
	if( treePtr != NULL){
		printf( "%3d", treePtr->data );
		preOrder( treePtr->leftPtr );
		preOrder( treePtr->rightPtr ); 
	}
}

// Complete the maxXor function below.
int main() {
    vector<int> xorArr;
    Node *rootNode = new Node(-1);
    vector<int> arr = {4, 5, 3, 9};

    for(int i = 0; i < arr.size(); i++){
    	Node *leafNode = rootNode;
        int bit = 1;
        unsigned mask = 1 << CHAR_BIT * sizeof(unsigned) - 1;
        
        while(bit <= CHAR_BIT * sizeof(unsigned)){
            int d = (arr[i] & mask) ? 1 : 0;
            leafNode = insertNode(leafNode, d);
            cout << leafNode->data << " ";
            bit++;
            mask >>= 1;
        }
        cout << endl;
    }

	int value = 34;
	int bit = 1;
	unsigned mask = 1 << CHAR_BIT * sizeof(unsigned) - 1;
	int result = 0;
	Node *leafNode = rootNode;
	
	while(bit <= CHAR_BIT * sizeof(unsigned)){
        int d = (value & mask) ? 0 : 1;
        leafNode = getNode(leafNode, d);
        
        if(d == leafNode->data) result |= (1 << (CHAR_BIT * sizeof(unsigned) - bit));
        cout << "d = " << d << " leafNode->data = " << leafNode->data << " " << bit << "->" << result << endl;
        bit++;
        mask >>= 1;
    }
    //cout << (value ^ 4);
    
    int maximum = 0;
    for(int j = 0; j < arr.size(); j++){
        maximum = max(maximum, value ^ arr[j]);
    }
    preOrder(rootNode);

    
   // cout << endl << maximum;

}
