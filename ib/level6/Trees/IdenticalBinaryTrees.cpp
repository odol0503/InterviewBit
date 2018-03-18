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
void Preorder(TreeNode *A, vector<int> &values)
{
	if (A == nullptr) return;
	values.push_back(A->val);
	Preorder(A->left, values);
	Preorder(A->right, values);
}

int IsSameTree(TreeNode* A, TreeNode* B) {
	vector<int> v1;
	vector<int> v2;

	Preorder(A, v1);
	Preorder(B, v2);

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	return v1 == v2;
}
#else
bool IsSameTree(TreeNode *p, TreeNode *q) {
	if (p == NULL && q == NULL) return true;
	if (p == NULL || q == NULL) return false;
	return ((p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}
#endif