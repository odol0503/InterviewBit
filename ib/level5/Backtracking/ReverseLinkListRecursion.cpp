/*************************************************************************************************
Reverse Link List Recursion

Reverse a linked list using recursion.

Example :
Given 1->2->3->4->5->NULL,
return 5->4->3->2->1->NULL.
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
ListNode* ReverseLinkedList(ListNode* A) {
	if (A->next == nullptr) return A;

	ListNode *pPrev = nullptr;
	while (A)
	{
		ListNode *pNext = A->next;
		A->next = pPrev;
		pPrev = A;
		A = pNext;
	}

	return pPrev;
}
#else
ListNode *ReverseLinkedList(ListNode *p) {
	if (p->next == NULL || p == NULL) {
		return p;
	}
	ListNode *nextNode = p->next;
	ListNode *head = ReverseLinkedList(p->next);
	nextNode->next = p;
	p->next = NULL;

	return head;
}
#endif