/*************************************************************************************************
List Cycle

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Try solving it using constant additional space.
Example :
Input :
          ______
         |     |
         \/    |
1 -> 2 -> 3 -> 4

Return the node corresponding to node 3.
*************************************************************************************************/
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

#define OWN

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

#ifdef OWN
ListNode* DetectCycle(ListNode* A) {
	ListNode *p1 = A;
	ListNode *p2 = A;
	bool bCycle = false;

	while (p1 && p2 && p2->next)
	{
		p1 = p1->next;
		p2 = p2->next->next;
		if (p1 == p2)
		{
			bCycle = true;
			break;
		}
	}

	if (!bCycle) return nullptr;

	p2 = A;
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}

	return p1;
}
#else
ListNode *DetectCycle(ListNode *head) {
	if (head == NULL || head->next == NULL) return NULL;

	ListNode* firstp = head;
	ListNode* secondp = head;
	bool isCycle = false;

	while (firstp != NULL && secondp != NULL) {
		firstp = firstp->next;
		if (secondp->next == NULL) return NULL;
		secondp = secondp->next->next;
		if (firstp == secondp) { isCycle = true; break; }
	}

	if (!isCycle) return NULL;
	firstp = head;
	while (firstp != secondp) {
		firstp = firstp->next;
		secondp = secondp->next;
	}

	return firstp;
}
#endif