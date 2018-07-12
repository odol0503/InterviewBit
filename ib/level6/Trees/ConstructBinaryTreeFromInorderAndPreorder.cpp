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
static TreeNode *makeTree(vector<int> &A, vector<int> &B, int start, int end)
{
	if (A.empty()) return nullptr;
	if (start <= end)
	{
		int val = A.back();
		A.pop_back();
		int i = start;
		for (; i <= end; i++)
		{
			if (A[i] == val) break;
		}

		TreeNode *node = new TreeNode(A[i]);
		node->left = makeTree(A, B, start, i - 1);
		node->right = makeTree(A, B, i + 1, end);
		return node;
	}

	return nullptr;
}

TreeNode* ConstructBinaryTreeFromInorderAndPreorder(vector<int> &A, vector<int> &B) {
	reverse(A.begin(), A.end());
	return makeTree(A, B, 0, B.size() - 1);
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

TreeNode *ConstructBinaryTreeFromInorderAndPreorder(vector<int> &preorder, vector<int> &inorder) {
	return preorder.size() == 0 ? NULL : buildTreeTmp(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
}
#endif