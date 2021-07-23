#include "TreeNode.h"

int main()
{
	Tree t;
	
	t.insertNode(6);
	t.insertNode(7);
	t.insertNode(1);
	t.inOrder();
	cout << endl;
	
	vector<int> a = {2, 5, 7, 9, 10, 13, 19, 20, 30};
	Tree T;
	T.createMinimalBST(a);
	T.inOrder();
	cout << endl;
	T.deleteNode(5);
	T.deleteNode(7);
	T.inOrder();
	
}
