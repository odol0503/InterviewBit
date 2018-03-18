/*************************************************************************************************
Invert the Binary Tree

Given a binary tree, invert the binary tree and return it.
Look at the example for more details.

Example :
Given binary tree
     1
   /   \
  2     3
 / \   / \
4   5 6   7
invert and return
     1
   /   \
  3     2
 / \   / \
7   6 5   4
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
static void InvertTree(TreeNode *A)
{
	if (A == nullptr) return;
	TreeNode *pTemp = A->left;
	A->left = A->right;
	A->right = pTemp;
	if (A->left) InvertTree(A->left);
	if (A->right) InvertTree(A->right);
}

TreeNode* InvertBinaryTree(TreeNode* A) {
	InvertTree(A);
	return A;
}
#else
TreeNode* InvertBinaryTree(TreeNode *root) {
	if (!root) return root;
	root->left = InvertBinaryTree(root->left);
	root->right = InvertBinaryTree(root->right);
	TreeNode *temp = root->left;
	root->left = root->right;
	root->right = temp;
	return root;
}
#endif