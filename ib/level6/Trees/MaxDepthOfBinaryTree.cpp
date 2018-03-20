/*************************************************************************************************
Max Depth of Binary Tree

Given a binary tree, find its maximum depth.

The maximum depth of a binary tree is the number of nodes along the longest path 
from the root node down to the farthest leaf node.

NOTE : The path has to end on a leaf node.
Example :
  1
 /
2
max depth = 2.
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define OWN

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#ifdef OWN
static void FindMaxDepth(TreeNode *A, int depth, int &max_value)
{
	if (A == nullptr) return;

	if (max_value < depth) max_value = depth;

	FindMaxDepth(A->left, depth + 1, max_value);
	FindMaxDepth(A->right, depth + 1, max_value);
}

int MaxDepthOfBinaryTree(TreeNode* A) {
	int ret = 0;
	FindMaxDepth(A, 1, ret);
	return ret;
}
#else
int MaxDepthOfBinaryTree(TreeNode *root) {
	// Corner case. Should never be hit unless the code is called on root = NULL
	if (root == NULL) return 0;
	// Base case : Leaf node. This accounts for height = 1.
	if (root->left == NULL && root->right == NULL) return 1;

	if (!root->left) return MaxDepthOfBinaryTree(root->right) + 1;
	if (!root->right) return MaxDepthOfBinaryTree(root->left) + 1;

	return max(MaxDepthOfBinaryTree(root->left), MaxDepthOfBinaryTree(root->right)) + 1;
}
#endif