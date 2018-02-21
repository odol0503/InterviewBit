/*************************************************************************************************
Partition List
Given a linked list and a value x, partition it such that all nodes less than x come 
before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

#ifdef OWN
ListNode* PartitionList(ListNode* A, int B) {
	ListNode *dummy1 = new ListNode(0);
	ListNode *dummy = new ListNode(0);
	ListNode *p = dummy;
	dummy1->next = A;
	ListNode *pPrev = dummy1;
	ListNode *pCur = dummy1->next;

	while (pCur)
	{
		ListNode *pNext = pCur->next;
		if (pCur->val >= B)
		{
			if (pPrev) pPrev->next = pCur->next;
			p->next = pCur;
			p = p->next;
			p->next = nullptr;
		}
		else
		{
			pPrev = pCur;
		}
		pCur = pNext;
	}

	pCur = dummy1->next;
	while (pCur)
	{
		pPrev = pCur;
		pCur = pCur->next;
	}
	pPrev->next = dummy->next;
	delete dummy;

	return dummy1->next;
}
#else
ListNode *PartitionList(ListNode *head, int x) {

	if (!head) return NULL;
	ListNode * iterator = head;

	ListNode * start = new ListNode(0); // list of nodes greater than x
	ListNode * tail = start;

	ListNode * newHead = new ListNode(0);
	newHead->next = head;
	ListNode * pre = newHead; // previous node, we need it for removing


	while (iterator) {
		if (iterator->val >= x) {
			pre->next = iterator->next; // remove from our list
			tail->next = iterator; // add to list of nodes greater than x
			tail = tail->next;
			iterator = iterator->next;
			tail->next = NULL;
		}
		else
			pre = iterator, iterator = iterator->next;
	}
	pre->next = start->next;
	return newHead->next;
		}
#endif