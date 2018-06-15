/*************************************************************************************************
Inorder Traversal of Cartesian Tree

Given an inorder traversal of a cartesian tree, construct the tree.

Cartesian tree : is a heap ordered binary tree, where the root is greater 
than all the elements in the subtree.
Note: You may assume that duplicates do not exist in the tree.

Example :
Input : [1 2 3]
Return :
    3
   /
  2
 /
1
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
TreeNode* InorderTraversalOfCartesianTree(vector<int> &A) {
	if (A.empty()) return nullptr;

	auto it = max_element(A.begin(), A.end());
	TreeNode *node = new TreeNode(*it);

	vector<int> B(A.begin(), it);
	vector<int> C(it + 1, A.end());
	node->left = InorderTraversalOfCartesianTree(B);
	node->right = InorderTraversalOfCartesianTree(C);

	return node;
}
#else
TreeNode *buildTree(vector<int> &inorder, int start, int end) {
	if (start == end) {
		return new TreeNode(inorder[start]);
	}
	if (start > end) return NULL;

	// find max which will be the root. 
	int maxVal = INT_MIN, maxIndex = -1;
	for (int i = start; i <= end; i++) {
		if (inorder[i] > maxVal) {
			maxVal = inorder[i];
			maxIndex = i;
		}
	}

	TreeNode *root = new TreeNode(maxVal);
	root->left = buildTree(inorder, start, maxIndex - 1);
	root->right = buildTree(inorder, maxIndex + 1, end);
	return root;
}

TreeNode *InorderTraversalOfCartesianTree(vector<int> &inorder) {
	if (inorder.size() == 0) return NULL;
	return buildTree(inorder, 0, inorder.size() - 1);
}
#endif