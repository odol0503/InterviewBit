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
static void Preorder(TreeNode *A, vector<int> &B)
{
	if (A == nullptr) return;
	B.push_back(A->val);
	Preorder(A->left, B);
	Preorder(A->right, B);
}

static void RevPreorder(TreeNode *A, vector<int> &B)
{
	if (A == nullptr) return;
	B.push_back(A->val);
	RevPreorder(A->right, B);
	RevPreorder(A->left, B);
}

int IsSymmetric(TreeNode* A) {
	vector<int> L, R;
	Preorder(A, L);
	RevPreorder(A, R);

	return L == R;
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