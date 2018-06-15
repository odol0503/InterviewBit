/*************************************************************************************************
Inorder Traversal
Given a binary tree, return the inorder traversal of its nodes¡¯ values.

Example :
Given binary tree

1
 \
  2
 /
3
return [1,3,2].
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
vector<int> InorderTraversal(TreeNode* A) {
	vector<int> ret;
	stack<TreeNode*> st;

	while (A || st.size())
	{
		if (A)
		{
			st.push(A);
			A = A->left;
		}
		else
		{
			A = st.top();
			st.pop();
			ret.push_back(A->val);
			A = A->right;
		}
	}

	return ret;
}
#else
vector<int> InorderTraversal(TreeNode *root) {
	vector<int> vector;
	if (!root)
		return vector;
	stack<TreeNode *> stack;
	stack.push(root);
	while (!stack.empty())
	{
		TreeNode *pNode = stack.top();
		if (pNode->left)
		{
			stack.push(pNode->left);
			pNode->left = NULL;
		}
		else
		{
			vector.push_back(pNode->val);
			stack.pop();
			if (pNode->right)
				stack.push(pNode->right);
		}
	}
	return vector;
}
#endif