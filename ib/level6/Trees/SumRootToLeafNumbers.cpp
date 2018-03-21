/*************************************************************************************************
Sum Root to Leaf Numbers

Given a binary tree containing digits from 0-9 only, 
each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.
Find the total sum of all root-to-leaf numbers % 1003.

Example :
  1
 / \
2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.
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
static void SumLeafNode(TreeNode *A, int value, int &ret)
{
	if (A == nullptr) return;

	value = ((value * 10) % 1003 + A->val) % 1003;

	if (A->left == nullptr && A->right == nullptr)
	{
		ret = (ret + value) % 1003;
	}

	SumLeafNode(A->left, value, ret);
	SumLeafNode(A->right, value, ret);
}

int SumRootToLeafNumbers(TreeNode* A) {
	int value = 0;
	int ret = 0;
	SumLeafNode(A, value, ret);
	return ret;
}
#else
int sumNumbers(TreeNode *root, int curSum) {
	if (root == NULL) return curSum;
	curSum = (curSum * 10 + root->val) % 1003;
	if (root->left == NULL && root->right == NULL) return curSum;
	if (!root->left) return sumNumbers(root->right, curSum);
	if (!root->right) return sumNumbers(root->left, curSum);
	return (sumNumbers(root->left, curSum) + sumNumbers(root->right, curSum)) % 1003;
		}
int SumRootToLeafNumbers(TreeNode *root) {
	return sumNumbers(root, 0);
}
#endif