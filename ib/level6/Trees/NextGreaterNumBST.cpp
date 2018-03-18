/*************************************************************************************************
Next Greater Number BST

Given a BST node, return the node which has value just greater than the given node.
Example:
Given the tree
    100
   /   \
  98    102
 /  \
96    99
 \
  97
Given 97, you should return the node corresponding to 98 as thats the value 
just greater than 97 in the tree.
If there are no successor in the tree ( the value is the largest in the tree, return NULL).

Using recursion is not allowed.
Assume that the value is always present in the tree.
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
TreeNode* NextGreaterNumberBST(TreeNode* A, int B) {
	TreeNode *pCur = A;
	stack<TreeNode*> st;

	while (pCur && pCur->val != B)
	{
		st.push(pCur);
		if (pCur->val > B) pCur = pCur->left;
		else pCur = pCur->right;
	}

	if (pCur->right)
	{
		pCur = pCur->right;
		while (pCur->left) pCur = pCur->left;
		return pCur;
	}

	while (!st.empty())
	{
		if (st.top()->val > B) return st.top();
		st.pop();
	}

	return nullptr;
}
#else
TreeNode* Find(TreeNode *root, int data) {
	while (root != NULL && root->val != data) {
		if (data < root->val) root = root->left;
		else root = root->right;
	}
	if (root != NULL && root->val == data) return root;
	return NULL;
		}

TreeNode* FindMin(TreeNode *root) {
	while (root->left != NULL) root = root->left;
	return root;
}

TreeNode* NextGreaterNumberBST(TreeNode* root, int data) {
	// Search the node O(h)
	TreeNode* current = Find(root, data);
	if (current == NULL) return NULL;
	if (current->right != NULL) { // Case 1 : Node has right subtree
		return FindMin(current->right);
	}
	else {
		TreeNode *successor = NULL, *ancestor = root;
		while (ancestor != current) {
			if (data < ancestor->val) {
				successor = ancestor; // so far this is the deepest node for which current node is in left. 
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return successor;
	}
}
#endif