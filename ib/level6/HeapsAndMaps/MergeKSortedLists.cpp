/*************************************************************************************************
Merge K Sorted Lists

Merge k sorted linked lists and return it as one sorted list.

Example :
1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <functional>
#include <iostream>
using namespace std;

#define OWN

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

#ifdef OWN
ListNode* MergeKSortedLists(vector<ListNode*> &A) {
	ListNode *ret = nullptr;
	ListNode *pDummy = new ListNode(0);
	priority_queue<pair<int, ListNode*>,
		vector<pair<int, ListNode*>>,
		greater<pair<int, ListNode*>>> P;
	ListNode *pCur;

	for (int i = 0; i<(int)A.size(); i++)
	{
		pCur = A[i];
		while (pCur)
		{
			P.push({ pCur->val, pCur });
			pCur = pCur->next;
		}
	}

	pCur = pDummy;
	int num = (int)P.size();
	for (int i = 0; i<num; i++)
	{
		pCur->next = P.top().second;
		P.pop();
		pCur = pCur->next;
	}

	ret = pDummy->next;
	delete pDummy;

	return ret;
}
#else
struct CompareNode {
	bool operator()(ListNode* const & p1, ListNode* const & p2) {
		// return "true" if "p1" is ordered before "p2", for example:
		return p1->val > p2->val;
	}
};

ListNode *MergeKSortedLists(vector<ListNode *> &lists) {
	ListNode* dummy = new ListNode(0);
	ListNode* tail = dummy;

	priority_queue<ListNode*, vector<ListNode*>, CompareNode> queue;

	for (int i = 0; i < lists.size(); i++) {
		if (lists[i] != NULL) {
			queue.push(lists[i]);
		}
	}

	while (!queue.empty()) {
		tail->next = queue.top();
		queue.pop();
		tail = tail->next;

		if (tail->next) {
			queue.push(tail->next);
		}
	}

	return dummy->next;
}
#endif