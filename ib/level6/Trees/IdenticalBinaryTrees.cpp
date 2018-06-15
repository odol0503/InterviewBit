/*************************************************************************************************
Identical Binary Trees

Given two binary trees, write a function to check if they are equal or not.
Two binary trees are considered equal if they are structurally identical 
and the nodes have the same value.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :
Input :
  1       1
 / \     / \
2   3   2   3

Output :
1 or True
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
int isSameTree(TreeNode* A, TreeNode* B) {
	if (!A && !B) return 1;
	if (!A || !B) return 0;

	if (A->val != B->val) return 0;

	return (isSameTree(A->left, B->left) && isSameTree(A->right, B->right));
}
#else
bool IsSameTree(TreeNode *p, TreeNode *q) {
	if (p == NULL && q == NULL) return true;
	if (p == NULL || q == NULL) return false;
	return ((p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}
#endif