/*************************************************************************************************
Sorted Array To Balanced BST

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth 
of the two subtrees of every node never differ by more than 1.

Example :
Given A : [1, 2, 3]
A height balanced BST  :
   2
  / \
 1   3
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
static TreeNode* BalanceTree(const vector<int> &A, int start, int end)
{
	int mid = (start + end) / 2;

	TreeNode *pNode = new TreeNode(A[mid]);

	if (mid > start) pNode->left = BalanceTree(A, start, mid - 1);
	if (mid < end) pNode->right = BalanceTree(A, mid + 1, end);

	return pNode;
}

TreeNode* SortedArrayToBalancedBST(const vector<int> &A) {
	return BalanceTree(A, 0, (int)A.size() - 1);
}
#else
TreeNode* helper(vector<int> &num, int low, int high) {
	if (low > high) { // Done
		return NULL;
	}
	int mid = (low + high) / 2;
	TreeNode* node = new TreeNode(num[mid]);
	node->left = helper(num, low, mid - 1);
	node->right = helper(num, mid + 1, high);
	return node;
	}

TreeNode *SortedArrayToBalancedBST(vector<int> &num) {
	if (num.size() == 0) return NULL;
	return helper(num, 0, ((int)num.size()) - 1);
}
#endif
