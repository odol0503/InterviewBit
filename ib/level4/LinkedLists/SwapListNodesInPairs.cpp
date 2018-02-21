/*************************************************************************************************
Reverse Linked List

Reverse a linked list. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL,
return 5->4->3->2->1->NULL.

PROBLEM APPROACH :
Complete solution code in the hints
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
static int GetListNum(ListNode *A)
{
	int len = 0;
	while (A)
	{
		A = A->next;
		len++;
	}
	return len;
}

ListNode* SwapPairs(ListNode* A) {
	if (A == nullptr) return A;
	ListNode *dummy = new ListNode(0);
	dummy->next = A;
	ListNode *pPrev = dummy;

	int len = GetListNum(A);
	if (len == 1) return A;
	int num = len / 2;

	for (int i = 0; i<num; i++)
	{
		ListNode *pNext;
		pNext = A->next;
		pPrev->next = pNext;
		A->next = A->next->next;
		pPrev = A;
		A = pNext;

		pNext = A->next;
		A->next = pPrev;
		A = pNext;
	}

	ListNode *pHead = dummy->next;
	delete dummy;

	return pHead;
}
#else
ListNode* swap(ListNode* next1, ListNode* next2) {
	next1->next = next2->next;
	next2->next = next1;
	return next2;
}

ListNode *SwapPairs(ListNode *head) {
	ListNode* start = new ListNode(0); //make head no longer a special case
	start->next = head;

	ListNode *cur = start;
	while (cur->next != NULL && cur->next->next != NULL) {
		cur->next = swap(cur->next, cur->next->next);
		cur = cur->next->next;
	}
	return start->next;
}
#endif