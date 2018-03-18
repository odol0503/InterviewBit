/*************************************************************************************************
Valid Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node¡¯s key.
The right subtree of a node contains only nodes with keys greater than the node¡¯s key.
Both the left and right subtrees must also be binary search trees.
Example :
Input :
  1
 / \
2   3
Output : 0 or False

Input :
  2
 / \
1   3
Output : 1 or True
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
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
static void CheckValid(TreeNode *A, int &valid)
{
	if (A == nullptr) return;

	if (A->left && A->val <= A->left->val
		|| A->right && A->val >= A->right->val)
	{
		valid = 0;
		return;
	}

	if (A->left) CheckValid(A->left, valid);
	if (valid == 0) return;
	if (A->right) CheckValid(A->right, valid);
}

static void Inorder(TreeNode *A, vector<int> &ret)
{
	if (A == nullptr) return;

	Inorder(A->left, ret);
	ret.push_back(A->val);
	Inorder(A->right, ret);
}

int ValidBST(TreeNode* A) {
	vector<int> ret;
	Inorder(A, ret);
	for (int i = 1; i<(int)ret.size(); i++)
	{
		if (ret[i - 1] >= ret[i]) return 0;
	}
	return 1;
}
#else
/*
* Returns the pair of following :
* min : Minimum of the values in the subtree with root as 'root'
* max : Maximum of the values in the subtree with root as 'root'
* isBST : bool indicating if the subtree is a BST
*/
pair<pair<int, int>, bool> isBST(TreeNode *root) {
	if (root == NULL) return make_pair(make_pair(-1, -1), true);
	// Leaf node 
	if (root->left == NULL && root->right == NULL) return make_pair(make_pair(root->val, root->val), true);

	pair<pair<int, int>, bool> result, result2;
	// If left tree is NULL. Tree is BST if min of the right subtree is greater than node's value
	if (!root->left) {
		result = isBST(root->right);
		return make_pair(make_pair(
			root->val,
			result.first.second),
			result.second && result.first.first > root->val);
	}
	// If right subtree is NULL. Tree is BST if max of the left subtree is less than node's value
	if (!root->right) {
		result = isBST(root->left);
		return make_pair(make_pair(
			result.first.first,
			root->val),
			result.second && result.first.second < root->val);
	}
	// Combination of the above 2 cases
	result = isBST(root->left);
	result2 = isBST(root->right);
	return make_pair(make_pair(
		result.first.first,
		result2.first.second),
		result.second && result2.second && result.first.second < root->val && result2.first.first > root->val);
}

bool isValidBST(TreeNode *root) {
	return isBST(root).second;
}
#endif