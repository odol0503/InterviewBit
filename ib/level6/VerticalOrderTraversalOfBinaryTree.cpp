/*************************************************************************************************
Vertical Order traversal of Binary Tree

Given a binary tree, print a vertical order traversal of it.

Example :
Given binary tree:
6
/   \
3     7
/ \     \
2   5     9
returns
[
[2],
[3],
[6 5],
[7],
[9]
]

Note : If 2 Tree Nodes shares the same vertical level then the one with lesser depth will come first.
*************************************************************************************************/
#include <vector>
using namespace std;

#define OWN

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static void GetMinMax(TreeNode *A, int &min_len, int &max_len)
{
	if (A->left)
	{
		min_len--;
		GetMinMax(A->left, min_len, max_len);
	}

	if (A->right)
	{
		max_len++;
		GetMinMax(A->right, min_len, max_len);
	}

	return;
}

static int GetDistance(TreeNode *A)
{
	if (A == nullptr) return 0;

	int min_len = 0;
	int max_len = 0;

	GetMinMax(A, min_len, max_len);

	return 1 + max_len - min_len;
}

#ifdef OWN
//vector<vector<int> > VerticalOrderTraversal(TreeNode* A) 
int VerticalOrderTraversal(TreeNode* A)
{
	return GetDistance(A);
}
#else

#endif