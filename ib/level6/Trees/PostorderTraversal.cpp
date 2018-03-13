/*************************************************************************************************
Postorder Traversal

Given a binary tree, return the postorder traversal of its nodes¡¯ values.

Example :
Given binary tree
1
 \
  2
 /
3
return [3,2,1].
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
vector<int> PostorderTraversal(TreeNode* A) {
	vector<int> ret;
	stack<TreeNode*> st;

	while (A || !st.empty())
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

			if (A->right == nullptr)
			{
				ret.push_back(A->val);
				A = nullptr;
			}
			else
			{
				st.push(A);
				TreeNode *right = A->right;
				A->right = nullptr;
				A = right;
			}
		}
	}

	return ret;
}
#else
vector<int> PostorderTraversal(TreeNode *root) {
	stack<TreeNode*> nodeStack;
	vector<int> result;
	//base case
	if (root == NULL)
		return result;
	nodeStack.push(root);
	while (!nodeStack.empty()) {
		TreeNode* node = nodeStack.top();
		result.push_back(node->val);
		nodeStack.pop();
		if (node->left)
			nodeStack.push(node->left);
		if (node->right)
			nodeStack.push(node->right);
	}
	reverse(result.begin(), result.end());
	return result;

}
#endif