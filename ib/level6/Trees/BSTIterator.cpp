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
	TreeNode *cur;
	stack<TreeNode*> st;

	BSTIterator::BSTIterator(TreeNode *root) {
		cur = root;
		while (st.size()) st.pop();
	}

	/** @return whether we have a next smallest number */
	bool BSTIterator::hasNext() {
		if (cur || st.size()) return true;
		else return false;
	}

	/** @return the next smallest number */
	int BSTIterator::next() {
		int val = 0;
		while (cur || st.size())
		{
			if (cur)
			{
				st.push(cur);
				cur = cur->left;
			}
			else
			{
				cur = st.top();
				st.pop();
				val = cur->val;
				cur = cur->right;
				break;
			}
		}
		return val;
	}

	/**
	* Your BSTIterator will be called like this:
	* BSTIterator i = BSTIterator(root);
	* while (i.hasNext()) cout << i.next();
	*/
};
#else

#endif