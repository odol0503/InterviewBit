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
			}
			else
			{
				st.push(A);
			}
			A = A->right;
		}
	}

	return ret;
}
#else

#endif