/*************************************************************************************************
BST Iterator

Implement an iterator over a binary search tree (BST). 
Your iterator will be initialized with the root node of a BST.

The first call to next() will return the smallest number in BST. 
Calling next() again will return the next smallest number in the BST, and so on.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, 
where h is the height of the tree.
Try to optimize the additional space complexity apart from the amortized time complexity.
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
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


class BSTIterator
{
	queue<int> st;

	void BSTIterator::IterBST(TreeNode *A, queue<int> &st)
	{
		if (A == nullptr) return;
		if (A->left) IterBST(A->left, st);
		st.push(A->val);
		if (A->right) IterBST(A->right, st);
	}

	BSTIterator::BSTIterator(TreeNode *root) {
		while (!st.empty()) st.pop();
		IterBST(root, st);
	}

	/** @return whether we have a next smallest number */
	bool BSTIterator::hasNext() {
		return st.size() > 0;
	}

	/** @return the next smallest number */
	int BSTIterator::next() {
		int ret = st.front();
		st.pop();
		return ret;
	}

	/**
	* Your BSTIterator will be called like this:
	* BSTIterator i = BSTIterator(root);
	* while (i.hasNext()) cout << i.next();
	*/
};
#else

#endif