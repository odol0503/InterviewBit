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
#include <utility>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

#define OWN

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#ifdef OWN
vector<vector<int> > VerticalOrderTraversal(TreeNode* A) 
{
	vector<vector<int>> ret;
	map<int, vector<int>> M;
	queue<pair<TreeNode*, int>> Q;
	queue<pair<TreeNode*, int>> Q2;

	if (!A) return ret;

	Q.push({ A, 0 });

	while (Q.size())
	{
		pair<TreeNode*, int> temp = Q.front();
		Q.pop();

		M[temp.second].push_back(temp.first->val);

		if (temp.first->left) Q2.push({ temp.first->left, temp.second - 1 });
		if (temp.first->right) Q2.push({ temp.first->right, temp.second + 1 });

		if (Q.empty())
		{
			swap(Q, Q2);
		}
	}

	for (auto it = M.begin(); it != M.end(); it++)
	{
		ret.push_back(it->second);
	}

	return ret;
}
#else
vector<vector<int> > VerticalOrderTraversal(TreeNode* A)
{
	vector<vector<int> > result;
	// Base case
	if (!A) return result;
	// Create a map of horizontalDistance, ListOfTreeNodes(at that horizontalDistance)
	map <int, vector<int> > m;

	// Create queue to do level order traversal.
	// Every item of queue contains node and horizontal distance.
	queue<pair<TreeNode*, int> > q;
	q.push(make_pair(A, 0)); // root's horizontalDistance is zero

	while (!q.empty()) {
		// get the queue front
		pair<TreeNode*, int> front = q.front();
		q.pop();
		int currentHorizontalDistance = front.second;
		TreeNode* currentTreeNode = front.first;

		// insert current node to hash map
		m[currentHorizontalDistance].push_back(currentTreeNode->val);

		if (currentTreeNode->left != NULL) {
			q.push(make_pair(currentTreeNode->left, currentHorizontalDistance - 1));
		}
		if (currentTreeNode->right != NULL) {
			q.push(make_pair(currentTreeNode->right, currentHorizontalDistance + 1));
		}
	}
	// Traverse the map and print nodes at every horigontal distance
	for (map<int, vector<int> > ::iterator it = m.begin(); it != m.end(); it++) {
		result.push_back(it->second);
	}
	return result;
}
#endif