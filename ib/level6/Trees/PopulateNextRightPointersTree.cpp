/*************************************************************************************************
Populate Next Right Pointers Tree

Add to bookmarks (can be accessed from dashboard)
Suggest edits in problem statement.

Populate each next pointer to point to its next right node. 
If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.

Note:
You may only use constant extra space.
Example :
Given the following binary tree,
     1
   /   \
  2     3
 / \   / \
4   5 6   7
After calling your function, the tree should look like:

     1 -> NULL
   /   \
  2 ->  3 -> NULL
 / \   / \
4-> 5->6->7 -> NULL
Note 1: that using recursion has memory overhe
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

#define OWN

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
#ifdef OWN
void PopulateNextRightPointersTree(TreeLinkNode* A) {
	queue<TreeLinkNode*> B;
	queue<TreeLinkNode*> temp;
	B.push(A);

	while (!B.empty())
	{
		TreeLinkNode *pNode = B.front();
		B.pop();

		if (B.empty()) pNode->next = nullptr;
		else pNode->next = B.front();

		if (pNode->left) temp.push(pNode->left);
		if (pNode->right) temp.push(pNode->right);

		if (B.empty())
		{
			B.swap(temp);
		}
	}
}
#else
void PopulateNextRightPointersTree(TreeLinkNode *root) {
	TreeLinkNode* leftWall = NULL; // leftmost node of the next level.
	TreeLinkNode* prev = NULL; // leading node on the next level
	TreeLinkNode* cur = root; // current node on the current level

	while (cur != NULL) {

		while (cur != NULL) {
			if (cur->left != NULL) {
				if (prev != NULL) {
					prev->next = cur->left;
				}
				else {
					leftWall = cur->left;
				}
				prev = cur->left;
			}

			if (cur->right != NULL) {
				if (prev != NULL) {
					prev->next = cur->right;
				}
				else {
					leftWall = cur->right;
				}
				prev = cur->right;
			}

			// move to the next node
			cur = cur->next;
		}

		// move to the next level
		cur = leftWall;
		leftWall = NULL;
		prev = NULL;

	}
}
#endif