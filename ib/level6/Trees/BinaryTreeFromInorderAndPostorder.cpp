/*************************************************************************************************
Binary Tree From Inorder And Postorder

Given inorder and postorder traversal of a tree, construct the binary tree.
Note: You may assume that duplicates do not exist in the tree.

Example :
Input :
Inorder : [2, 1, 3]
Postorder : [2, 3, 1]

Return :
   1
  / \
 2   3
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;

#define OWN

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#ifdef OWN
static TreeNode* MakeTree(vector<int> &A, vector<int> &B)
{
	int len = (int)A.size();
	int i = 0;
	for (; i<len; i++)
	{
		if (A[i] == B[len - 1]) break;
	}

	TreeNode *pNode = new TreeNode(A[i]);

	if (i>0)
	{
		vector<int> C(A.begin(), A.begin() + i);
		vector<int> D(B.begin(), B.begin() + i);
		pNode->left = MakeTree(C, D);
	}
	if (i<len - 1)
	{
		vector<int> C(A.begin() + i + 1, A.end());
		vector<int> D(B.begin() + i, B.end());
		pNode->right = MakeTree(C, D);
	}

	return pNode;
}

TreeNode* BinaryTreeFromInorderAndPostorder(vector<int> &A, vector<int> &B) {
	return MakeTree(A, B);
}
#else
TreeNode *BinaryTreeFromInorderAndPostorder(vector<int> &inorder, vector<int> &postorder) {
	if (inorder.size() == 0)return NULL;
	TreeNode* p;
	TreeNode* root;
	vector<int> vint;
	vector<TreeNode*> vtn;
	root = new TreeNode(postorder.back());
	vtn.push_back(root);
	postorder.pop_back();
	while (true)
	{
		if (inorder.back() == vtn.back()->val)
		{
			p = vtn.back();
			vtn.pop_back();
			inorder.pop_back();
			if (inorder.size() == 0) break;
			if (vtn.size())
				if (inorder.back() == vtn.back()->val)continue;
			p->left = new TreeNode(postorder.back());
			postorder.pop_back();
			vtn.push_back(p->left);
		}
		else
		{
			p = new TreeNode(postorder.back());
			postorder.pop_back();
			vtn.back()->right = p;
			vtn.push_back(p);
		}
	}
	return root;
}
#endif