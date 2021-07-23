#include "TreeNode.h"

TreeNode *Tree::insertNode(int value)
{
	root = insertNode(root, value);
	return root;
}

TreeNode *Tree::insertNode(TreeNode *leaf, int val)
{
	if(leaf == NULL)
		return new TreeNode(val);
	else if(val < leaf->data)
		leaf->left = insertNode(leaf->left, val);
	else
		leaf->right = insertNode(leaf->right, val);
	
	return leaf;
}

TreeNode *Tree::deleteNode(int value)
{
	root = deleteNode(root, value);
	return root;
}

TreeNode *Tree::minValueNode(TreeNode *leaf){
	if(leaf == NULL || leaf->left == NULL) return leaf;
	else return minValueNode(leaf->left);
}

TreeNode *Tree::deleteNode(TreeNode *leaf, int value)
{
	//base case
	if(leaf == NULL) return NULL;
	
	// If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
	if(value < leaf->data){
		leaf->left = deleteNode(leaf->left, value);
	}
	// If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
	else if(value > leaf->data){
		leaf->right = deleteNode(leaf->right, value);
	}
	//key found
	else{
		//node with only one child or none
		if(leaf->left == NULL){
			TreeNode *temp = leaf->right;
			delete leaf;
			return temp;	 
		}
		else if(leaf->right == NULL){
			TreeNode *temp = leaf->left;
			delete leaf;
			return temp;
		}
		//node with two children
		else{
			//find min successor
			TreeNode *temp = minValueNode(leaf->right);
			
			//change key
			leaf->data = temp->data;
			
			//delete successor node
			leaf->right = deleteNode(leaf->right, temp->data);	
		}
	}
	
	return leaf;
}

void Tree::inOrder(const TreeNode *treePtr) const
{
	if(treePtr != NULL){
		inOrder(treePtr->left);
		cout << treePtr->data << " ";
		inOrder(treePtr->right);
	}
}

TreeNode *Tree::createMinimalBST(const vector<int> &a, int start, int end){
	if(end >= start){
		int mid = (end + start) / 2;
		TreeNode *newNode = new TreeNode(a[mid]);
		newNode->left = createMinimalBST(a, start, mid - 1);
		newNode->right = createMinimalBST(a, mid + 1, end);
		return newNode;
	}
	else
		return NULL;
}
