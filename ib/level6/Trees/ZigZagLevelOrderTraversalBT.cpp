/*************************************************************************************************
ZigZag Level Order Traversal BT

Given a binary tree, return the zigzag level order traversal of its nodes¡¯ values. 
(ie, from left to right, then right to left for the next level and alternate between).

Example :
Given binary tree
    3
   / \
  9  20
    /  \
   15   7
return
[
[3],
[20, 9],
[15, 7]
]
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
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
static void Zigzag(vector<TreeNode*> B, bool bRight, vector<vector<int>> &ret)
{
	vector<TreeNode*> temp;
	vector<int> temp2;
	for (int i = (int)B.size() - 1; i >= 0; i--)
	{
		if (bRight)
		{
			if (B[i]->right)
			{
				temp.push_back(B[i]->right);
				temp2.push_back(B[i]->right->val);
			}
			if (B[i]->left)
			{
				temp.push_back(B[i]->left);
				temp2.push_back(B[i]->left->val);
			}
		}
		else
		{
			if (B[i]->left)
			{
				temp.push_back(B[i]->left);
				temp2.push_back(B[i]->left->val);
			}
			if (B[i]->right)
			{
				temp.push_back(B[i]->right);
				temp2.push_back(B[i]->right->val);
			}
		}
	}

	if (!temp.empty())
	{
		ret.push_back(temp2);
		Zigzag(temp, !bRight, ret);
	}
}

vector<vector<int> > ZigZagLevelOrderTraversalBT(TreeNode* A) {
	vector<TreeNode*> B;
	vector<vector<int>> ret;
	bool bRight = true;

	B.push_back(A);
	ret.push_back(vector<int>(1, A->val));
	Zigzag(B, bRight, ret);

	return ret;
}
#else
vector<vector<int> > ZigZagLevelOrderTraversalBT(TreeNode *root) {
	vector<vector<int> > output;
	if (root == NULL) return output;
	stack<TreeNode*> cur_layer;
	cur_layer.push(root);
	stack<TreeNode*> next_layer;
	vector<int> layer_output;
	int d = 0; // 0: left to right; 1: right to left.

	while (!cur_layer.empty()) {
		TreeNode* node = cur_layer.top();
		cur_layer.pop();
		layer_output.push_back(node->val);
		if (d == 0) {
			if (node->left != NULL) next_layer.push(node->left);
			if (node->right != NULL) next_layer.push(node->right);
		}
		else {
			if (node->right != NULL) next_layer.push(node->right);
			if (node->left != NULL) next_layer.push(node->left);
		}

		if (cur_layer.empty()) {
			output.push_back(layer_output);
			layer_output.clear();
			cur_layer.swap(next_layer);
			if (d == 1) d = 0;
			else d = 1;
		}
	}
	return output;
}
#endif