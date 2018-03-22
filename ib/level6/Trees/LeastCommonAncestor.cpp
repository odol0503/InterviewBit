/*************************************************************************************************
Least Common Ancestor

Find the lowest common ancestor in an unordered binary tree given two values in the tree.
Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree 
or directed acyclic graph (DAG) is the lowest (i.e. deepest) node 
that has both v and w as descendants.

Example :
         _______3______
        /              \
    ___5__           ___1__
   /      \         /      \
  6       _2_      0        8
         /   \
        7     4
For the above tree, the LCA of nodes 5 and 1 is 3.

LCA = Lowest common ancestor
Please note that LCA for nodes 5 and 4 is 5.

You are given 2 values. Find the lowest common ancestor of the two nodes represented 
by val1 and val2.
No guarantee that val1 and val2 exist in the tree. If one value doesn¡¯t exist 
in the tree then return -1.
There are no duplicate values.
You can use extra memory, helper functions, and can modify the node struct but, 
you can¡¯t add a parent pointer.
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
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

static int GetLen(ListNode *A)
{
	int len = 0;
	while (A)
	{
		len++;
		A = A->next;
	}
	return len;
}

static ListNode* BuildList(TreeNode *A, int val, ListNode **ppHead)
{
	if (A == nullptr) return nullptr;

	if (A->val == val)
	{
		ListNode *pNode = new ListNode(A->val);
		*ppHead = pNode;
		return pNode;
	}

	ListNode *pTemp = nullptr;
	if ((pTemp = BuildList(A->left, val, ppHead)) || (pTemp = BuildList(A->right, val, ppHead)))
	{
		pTemp->next = new ListNode(A->val);
		return pTemp->next;
	}

	return nullptr;
}

int LeastCommonAncestor(TreeNode* A, int B, int C) {
	ListNode *pNode1 = nullptr;
	ListNode *pNode2 = nullptr;

	BuildList(A, B, &pNode1);
	BuildList(A, C, &pNode2);

	if (pNode1 == nullptr || pNode2 == nullptr) return -1;

	int len1 = GetLen(pNode1);
	int len2 = GetLen(pNode2);
	int diff = abs(len1 - len2);

	if (len1 > len2) for (int i = 0; i < diff; i++) pNode1 = pNode1->next;
	else for (int i = 0; i < diff; i++) pNode2 = pNode2->next;

	while (pNode1->val != pNode2->val)
	{
		pNode1 = pNode1->next;
		pNode2 = pNode2->next;
	}

	return pNode1->val;
}
#else
TreeNode *LCA(TreeNode *root, int val1, int val2) {
	if (!root) return NULL;
	if (root->val == val1 || root->val == val2) return root;
	TreeNode *L = LCA(root->left, val1, val2);
	TreeNode *R = LCA(root->right, val1, val2);
	if (L && R) return root; // If val1, val2 are on both sides 
	return L ? L : R; // either one of val1, val2 is on one side OR val1, val2 is not in L&R subtrees
		}

bool find(TreeNode *root, int val1) {
	if (!root) return false;
	if (root->val == val1) return true;
	return (find(root->left, val1) || find(root->right, val1));
}

int LeastCommonAncestor(TreeNode *root, int val1, int val2) {
	if (!find(root, val1) || !find(root, val2)) return -1;
	TreeNode *ans = LCA(root, val1, val2);
	if (!ans) return -1;
	return ans->val;
}
#endif