/*************************************************************************************************
Preorder Traversal

Given a binary tree, return the preorder traversal of its nodes¡¯ values.

Example :
Given binary tree

1
 \
  2
 / 
3
return [1,2,3].

Using recursion is not allowed.
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
vector<int> PreorderTraversal(TreeNode* A) {
	stack<TreeNode*> st;
	vector<int> ret;

	while (A || !st.empty())
	{
		if (A)
		{
			ret.push_back(A->val);
			st.push(A);
			A = A->left;
		}
		else
		{
			A = st.top();
			st.pop();
			A = A->right;
		}
	}

	return ret;
}
#else
vector<int> PreorderTraversal(TreeNode *root) {
	vector<int> res;
	stack<TreeNode*> nodeStack;

	while (nodeStack.size() != 0 || root != NULL) {
		if (root == NULL) {
			root = nodeStack.top();
			nodeStack.pop();
		}
		else {
			res.push_back(root->val);
			if (root->right != NULL)
				nodeStack.push(root->right);
			root = root->left;
		}
	}
	return res;
}
#endif