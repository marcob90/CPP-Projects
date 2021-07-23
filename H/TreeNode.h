// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

class TreeNode {
    friend class Tree;
    public:
		TreeNode(int d)
		{
			data = d;
			right = NULL;
			left = NULL;
		}
	
	private:		
		int data;
		TreeNode *right;
		TreeNode *left;
};

class Tree {
	public:
		Tree()
		{
			root = NULL;
		}
		
		TreeNode *insertNode(int value);
		TreeNode *deleteNode(int);
		
		void inOrder() const{
			inOrder(root);
		}
		
		TreeNode *createMinimalBST(const vector<int> &a){
			this->root = createMinimalBST(a, 0, a.size() - 1);	
		}
		
	private:
		TreeNode* createMinimalBST(const vector<int> &a, int start, int end);
		void inOrder(const TreeNode *) const;
		TreeNode *insertNode(TreeNode *, int);
		TreeNode *deleteNode(TreeNode *, int);
		TreeNode *minValueNode(TreeNode *);
		TreeNode *root;
};
