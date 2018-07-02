/*************************************************************************************************
Kth Smallest Element In Tree

Given a binary search tree, write a function to find the kth smallest element in the tree.
Example :
Input :
  2
 / \
1   3
and k = 2
Return : 2
As 2 is the second smallest element in the tree.
NOTE : You may assume 1 <= k <= Total number of nodes in BST
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <cassert>
using namespace std;

#define OWN

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#ifdef OWN
static int GetTree(TreeNode *A, int &B)
{
	int val;
	if (A->left) val = GetTree(A->left, B);

	if (B == 0) return val;
	if (--B == 0) return A->val;

	if (A->right) val = GetTree(A->right, B);
	return INT_MIN;
}

int KthSmallestElementInTree(TreeNode* A, int B) {
	assert(A);
	return GetTree(A, B);
}
#else
int find(TreeNode* root, int &k) {
	if (!root) return -1;
	// We do an inorder traversal here. 
	int k1 = find(root->left, k);
	if (k == 0) return k1; // left subtree has k or more elements.
	k--;
	if (k == 0) return root->val; // root is the kth element.
	return find(root->right, k); // answer lies in the right node.
}

int kthsmallest(TreeNode* root, int k) {
	return find(root, k); // Call another function to pass k by reference.
}
#endif