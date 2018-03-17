/*************************************************************************************************
Construct Binary Tree From Inorder And Preorder

Given preorder and inorder traversal of a tree, construct the binary tree.
Note: You may assume that duplicates do not exist in the tree.

Example :
Input :
Preorder : [1, 2, 3]
Inorder  : [2, 1, 3]

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
static TreeNode* BuildTree(vector<int> &A, vector<int> &B)
{
	int idx = 0;
	for (int i = 0; i<(int)B.size(); i++)
	{
		if (A[0] == B[i])
		{
			idx = i;
			break;
		}
	}

	TreeNode *pNode = new TreeNode(A[0]);

	if (idx > 0)
	{
		vector<int> C(A.begin() + 1, A.begin() + idx + 1);
		vector<int> D(B.begin(), B.begin() + idx);
		pNode->left = BuildTree(C, D);
	}

	if (idx < (int)A.size() - 1)
	{
		vector<int> C(A.begin() + idx + 1, B.end());
		vector<int> D(B.begin() + idx + 1, B.end());
		pNode->right = BuildTree(C, D);
	}

	return pNode;
}

TreeNode* BinaryTreeFromInorderAndPostorder(vector<int> &A, vector<int> &B) {
	return BuildTree(A, B);
}
#else
TreeNode *buildTreeTmp(vector<int>::iterator prel, vector<int>::iterator prer,
	vector<int>::iterator inl, vector<int>::iterator inr){
	if (prel >= prer)
		return NULL;

	int val = *prel;
	TreeNode *root = new TreeNode(val);

	vector<int>::iterator rootIndex = find(inl, inr, val);
	vector<int>::size_type lsize = rootIndex - inl;

	root->left = buildTreeTmp(prel + 1, prel + 1 + lsize, inl, rootIndex);
	root->right = buildTreeTmp(prel + 1 + lsize, prer, rootIndex + 1, inr);

	return root;
}

TreeNode *BinaryTreeFromInorderAndPostorder(vector<int> &preorder, vector<int> &inorder) {
	return preorder.size() == 0 ? NULL : buildTreeTmp(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
}
#endif