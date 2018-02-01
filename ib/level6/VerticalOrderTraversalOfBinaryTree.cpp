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
static void GetMinMax(TreeNode *A, int x, int &min_x, int &max_x)
{
	if (A->left)
	{
		if (x == min_x) min_x--;
		GetMinMax(A->left, x - 1, min_x, max_x);
	}

	if (A->right)
	{
		if (x == max_x) max_x++;
		GetMinMax(A->right, x + 1, min_x, max_x);
	}
}

void GetVertical(TreeNode *A, int x, int y, vector<vector<pair<int, int>>> &result)
{
	if (A == nullptr) return;

	y++;
	if (A->left) GetVertical(A->left, x - 1, y, result);
	if (A->right) GetVertical(A->right, x + 1, y, result);

	result[x].push_back(make_pair(y, A->val));
}

static int TreeComp(pair<int,int> a, pair<int,int> b)
{
	return a.first < b.first;
}

vector<vector<int> > VerticalOrderTraversal(TreeNode* A) 
{
	if (A == nullptr) return vector<vector<int>>();

	int min_x = 0;
	int max_x = 0;
	int x = 0;
	int y = 0;

	GetMinMax(A, x, min_x, max_x);

	int len = 1 + max_x - min_x;
	vector<vector<int>> ret(len);
	vector<vector<pair<int, int>>> result(len);
	
	x = -min_x;
	GetVertical(A, x, y, result);

	for (int i = 0; i < result.size(); i++)
	{
		sort(result[i].begin(), result[i].end(), TreeComp);
		for (auto v : result[i]) ret[i].push_back(v.second);
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