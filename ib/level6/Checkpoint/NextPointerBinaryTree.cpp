/*************************************************************************************************
Next Pointer Binary Tree

Given a binary tree
struct TreeLinkNode {
TreeLinkNode *left;
TreeLinkNode *right;
TreeLinkNode *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, 
the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:
You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level,
and every parent has two children).

Example :
Given the following perfect binary tree,

       1
      /  \
     2    5
    / \  / \
   3  4  6  7
After calling your function, the tree should look like:

       1 -> NULL
      /  \
     2 -> 5 -> NULL
    / \  / \
   3->4->6->7 -> NULL

Note that using recursion has memory overhead and does not qualify for constant space.
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <queue>
#include <functional>
using namespace std;

#define OWN

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

#ifdef OWN
void NextPointerBinaryTree(TreeLinkNode* A) {
	queue<TreeLinkNode*> Q;
	queue<TreeLinkNode*> Q2;
	Q.push(A);
	TreeLinkNode *pPrev = nullptr;

	while (!Q.empty())
	{
		TreeLinkNode *pNode = Q.front();
		Q.pop();
		if (pPrev) pPrev->next = pNode->left;
		if (pNode->left)
		{
			pNode->left->next = pNode->right;
			Q2.push(pNode->left);
			Q2.push(pNode->right);
		}

		if (Q.empty())
		{
			pPrev = nullptr;
			Q.swap(Q2);
		}
		else
		{
			pPrev = pNode->right;
		}
	}
}
#endif