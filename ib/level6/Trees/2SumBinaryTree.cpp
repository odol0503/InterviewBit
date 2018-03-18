/*************************************************************************************************
2-Sum Binary Tree

Given a binary search tree T, where each node contains a positive integer, 
and an integer K, you have to find whether or not there exist 
two different nodes A and B such that A.value + B.value = K.

Return 1 to denote that two such nodes exist. Return 0, otherwise.
Notes
Your solution should run in linear time and not take memory more than O(height of T).
Assume all values in BST are distinct.
Example :
Input 1:
T :    10
       / \
      9   20
K = 19
Return: 1

Input 2:
T:     10
       / \
      9   20
K = 40
Return: 0
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
static void FindNode(TreeNode *A, TreeNode *origin, int val, int &result)
{
	if (A == nullptr) return;

	if (A->val == val && A != origin)
	{
		result = 1;
		return;
	}
	else if (A->val > val) FindNode(A->left, origin, val, result);
	else FindNode(A->right, origin, val, result);
}

static void PreorderFind(TreeNode *root, TreeNode *A, int B, int &ret)
{
	if (A == nullptr) return;

	int val = B - A->val;
	int result = 0;
	FindNode(root, A, val, result);

	if (result)
	{
		ret = result;
		return;
	}

	PreorderFind(root, A->left, B, ret);
	if (ret) return;
	PreorderFind(root, A->right, B, ret);
}

int TwoSumBinaryTree(TreeNode* A, int B) {
	int ret = 0;
	PreorderFind(A, A, B, ret);
	return ret;
}
#else
class BST {
public:
	stack<TreeNode*> mys1, mys2;
	TreeNode * cur1, *cur2;

	BST(TreeNode *root) {
		cur1 = cur2 = root;
	}
	bool hasNext() {
		if (cur1 == NULL and mys1.empty())return false;
		return true;
	}
	bool hasPrev() {
		if (cur2 == NULL and mys2.empty())return false;
		return true;
	}
	int next() {
		if (cur1 != NULL) {
			mys1.push(cur1);
			cur1 = cur1->left;
			next();
		}
		else {
			if (not mys1.empty()) {
				cur1 = mys1.top();
				int ans = cur1->val;
				mys1.pop();
				cur1 = cur1->right;
				return ans;
			}
		}
	}
	int prev() {
		if (cur2 != NULL) {
			mys2.push(cur2);
			cur2 = cur2->right;
			prev();
		}
		else {
			if (not mys2.empty()) {
				cur2 = mys2.top();
				int ans = cur2->val;
				mys2.pop();
				cur2 = cur2->left;
				return ans;
			}
		}
	}
};

int TwoSumBinaryTree(TreeNode* A, int B) {
	BST a(A);
	int x1 = a.next();
	int x2 = a.prev();
	while (x1<x2) {
		if (x1 + x2 == B)return 1;
		if (x1 + x2<B)
			x1 = a.next();
		else x2 = a.prev();
	}
	return 0;
}
#endif