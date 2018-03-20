/*************************************************************************************************
Min Depth of Binary Tree

Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path 
from the root node down to the nearest leaf node.

NOTE : The path has to end on a leaf node.
Example :
  1
 /
2
min depth = 2.
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
int MinDepthOfBinaryTree(TreeNode* A) {
	if (A == nullptr) return 0;

	if (A->left == nullptr && A->right == nullptr) return 1;

	if (A->right == nullptr) return MinDepthOfBinaryTree(A->left) + 1;
	if (A->left == nullptr) return MinDepthOfBinaryTree(A->right) + 1;

	return min(MinDepthOfBinaryTree(A->left) + 1, MinDepthOfBinaryTree(A->right) + 1);
}
#else
int MinDepthOfBinaryTree(TreeNode *root) {
	// Corner case. Should never be hit unless the code is called on root = NULL
	if (root == NULL) return 0;
	// Base case : Leaf node. This accounts for height = 1.
	if (root->left == NULL && root->right == NULL) return 1;

	if (!root->left) return MinDepthOfBinaryTree(root->right) + 1;
	if (!root->right) return MinDepthOfBinaryTree(root->left) + 1;

	return min(MinDepthOfBinaryTree(root->left), MinDepthOfBinaryTree(root->right)) + 1;
}
#endif