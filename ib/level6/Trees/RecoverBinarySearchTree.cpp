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
static void Inorder(TreeNode *A, vector<int> &array)
{
	if (A == nullptr) return;
	Inorder(A->left, array);
	array.push_back(A->val);
	Inorder(A->right, array);
}

vector<int> RecoverBinarySearchTree(TreeNode* A) {
	vector<int> array;
	vector<int> ret;
	Inorder(A, array);

	if (array.size() == 2)
	{
		ret.push_back(array[1]);
		ret.push_back(array[0]);
		return ret;
	}

	int idx = 0;
	for (int i = 1; i<(int)array.size(); i++)
	{
		if (array[i - 1] > array[i])
		{
			if (ret.size() == 1)
			{
				ret.push_back(array[i]);
				break;
			}
			else
			{
				ret.push_back(array[i - 1]);
				idx = i;
			}
		}
	}

	if (ret.size() == 1) ret.push_back(array[idx]);
	swap(ret[0], ret[1]);

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