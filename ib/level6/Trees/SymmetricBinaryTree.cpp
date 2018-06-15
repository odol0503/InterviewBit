/*************************************************************************************************
Symmetric Binary Tree

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Example :
     1
   /   \
  2     2
 / \   / \
3   4 4   3
The above binary tree is symmetric.
But the following is not:
    1
   / \
  2   2
   \   \
    3   3
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
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
static int isValid(TreeNode *A, TreeNode *B)
{
	if (!A && !B) return 1;
	if (!A || !B) return 0;

	if (A->val != B->val) return 0;

	return isValid(A->left, B->right) && isValid(A->right, B->left);
}

int IsSymmetric(TreeNode* A) {
	if (!A) return 1;
	return isValid(A->left, A->right);
}
#else
bool isSymmetricHelper(TreeNode *leftTree, TreeNode *rightTree) {
	if (leftTree == NULL || rightTree == NULL) return leftTree == rightTree;
	if (leftTree->val != rightTree->val) return false;
	return isSymmetricHelper(leftTree->left, rightTree->right) && isSymmetricHelper(leftTree->right, rightTree->left);
		}
bool IsSymmetric(TreeNode *root) {
	return root == NULL || isSymmetricHelper(root->left, root->right);
}
#endif