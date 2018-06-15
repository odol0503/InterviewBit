/*************************************************************************************************
Recover Binary Search Tree

Two elements of a binary search tree (BST) are swapped by mistake.
Tell us the 2 values swapping which the tree will be restored.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
Example :
Input :
  1
 / \
2   3

Output :
[1, 2]

Explanation : Swapping 1 and 2 will change the BST to be
  2
 / \
1   3
which is a valid BST
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
void check(TreeNode *A, TreeNode **prev, int &val1, int &val2, int &val3)
{
	if (!A) return;

	check(A->left, prev, val1, val2, val3);

	if (*prev && A->val < (*prev)->val)
	{
		if (val1 == INT_MIN)
		{
			val1 = (*prev)->val;
			val2 = A->val;
		}
		else
		{
			val3 = A->val;
		}
	}
	*prev = A;

	check(A->right, prev, val1, val2, val3);
}

vector<int> RecoverBinarySearchTree(TreeNode* A) {
	TreeNode *prev = nullptr;
	int val1 = INT_MIN;
	int val2 = INT_MIN;
	int val3 = INT_MIN;

	check(A, &prev, val1, val2, val3);

	vector<int> ret;
	if (val3 == INT_MIN)
	{
		ret.push_back(min(val1, val2));
		ret.push_back(max(val1, val2));
	}
	else
	{
		ret.push_back(min(val1, val3));
		ret.push_back(max(val1, val3));
	}

	return ret;
}
#else
vector<int> recoverTree(TreeNode *root) {
	TreeNode *cur, *pre, *node1, *node2;  // node1, node2: Record 2 near nodes
	TreeNode *first, *second;  // At the end, first and second will be the 2 nodes to be swapped. 
	node1 = node2 = first = NULL;
	cur = root;
	while (cur) {
		if (cur->left == NULL) {
			if (node1 == NULL) node1 = cur;
			else if (node2 == NULL) node2 = cur;
			else {
				node1 = node2;
				node2 = cur;
			}
			cur = cur->right;
		}
		else {
			pre = cur->left;
			while (pre->right && pre->right != cur) pre = pre->right;
			if (pre->right == NULL) {
				pre->right = cur;
				cur = cur->left;
				continue;
			}
			else {
				pre->right = NULL;
				if (node2 == NULL) node2 = cur;
				else {
					node1 = node2;
					node2 = cur;
				}
				cur = cur->right;
			}
		}
		if (node1 && node2 && node1->val > node2->val) {

			if (first == NULL)  first = node1;
			second = node2;
		}
	}
	/* Now lets return the answer */
	vector<int> ans;
	ans.push_back(min(first->val, second->val));
	ans.push_back(max(first->val, second->val));
	return ans;
}
#endif