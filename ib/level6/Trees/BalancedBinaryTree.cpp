/*************************************************************************************************
Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.
Height-balanced binary tree : is defined as a binary tree 
in which the depth of the two subtrees of every node never differ by more than 1.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :
Input :
  1
 / \
2   3
Return : True or 1

Input 2 :
    3
   /
  2
 /
1

Return : False or 0
Because for the root node, left subtree has depth 2 and right subtree has depth 0.
Difference = 2 > 1.
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
static int GetDepth(TreeNode *A)
{
	if (A == nullptr) return 0;

	return 1 + max(GetDepth(A->left), GetDepth(A->right));
}

int IsBalanced(TreeNode* A) {
	if (A == nullptr) return 1;

	int left_len = GetDepth(A->left);
	int right_len = GetDepth(A->right);

	if (abs(left_len - right_len) <= 1
		&& IsBalanced(A->left)
		&& IsBalanced(A->right)) return 1;

	return 0;
}
#else
bool isBalanced(TreeNode *root) {
	if (root == NULL) return true;
	return isBalancedWithDepth(root).second;
	}

pair<int, bool> isBalancedWithDepth(TreeNode *root) {
	if (root == NULL) return make_pair(0, true);
	pair<int, bool> left = isBalancedWithDepth(root->left);
	pair<int, bool> right = isBalancedWithDepth(root->right);
	int depth = max(right.first, left.first) + 1;
	// The subtree is balanced if right subtree is balanced, left subtree is balanced 
	// and the depth difference is less than 1. 
	bool isbalanced = right.second && left.second && (abs(right.first - left.first) < 2);
	return make_pair(depth, isbalanced);
}
#endif