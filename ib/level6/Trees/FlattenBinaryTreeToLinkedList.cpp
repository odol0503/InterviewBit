/*************************************************************************************************
Flatten Binary Tree to Linked List

Given a binary tree, flatten it to a linked list in-place.

Example :
Given
    1
   / \
  2   5
 / \   \
3   4   6

The flattened tree should look like:
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
Note that the left child of all nodes should be NULL.
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
static TreeNode* Preorder(TreeNode *A, TreeNode *pPrev)
{
	if (A == nullptr) return pPrev;

	pPrev->right = new TreeNode(A->val);

	TreeNode *left = A->left;
	TreeNode *right = A->right;
	delete A;

	TreeNode *pTemp = Preorder(left, pPrev->right);
	return Preorder(right, pTemp);
}

TreeNode* FlattenBinaryTreeToLinkedList(TreeNode* A) {
	TreeNode *pDummy = new TreeNode(0);
	Preorder(A, pDummy);
	return pDummy->right;
}
#else
void FlattenBinaryTreeToLinkedList(TreeNode *root) {
	if (!root) return;

	TreeNode* node = root;
	while (node) {

		// Attatches the right sub-tree to the rightmost leaf of the left sub-tree:
		if (node->left) {

			TreeNode *rightMost = node->left;
			while (rightMost->right) {

				rightMost = rightMost->right;
			}
			rightMost->right = node->right;

			// Makes the left sub-tree to the right sub-tree:
			node->right = node->left;
			node->left = NULL;
		}

		// Flatten the rest of the tree:
		node = node->right;
	}
}
#endif