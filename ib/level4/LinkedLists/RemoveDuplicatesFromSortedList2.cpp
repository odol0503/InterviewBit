/*************************************************************************************************
Remove Duplicates from Sorted List

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*************************************************************************************************/
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

#define OWN

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

#ifdef OWN
ListNode* DeleteDuplicates2(ListNode* A) {
	ListNode *pHead = A;
	ListNode *pPrev = nullptr;
	unordered_set<int> value;

	while (A)
	{
		if (A->next && A->val == A->next->val)
		{
			if (A->next->next) A->next = A->next->next;
			else A->next = nullptr;

			value.insert(A->val);
		}
		A = A->next;
	}

	A = pHead;

	while (A)
	{
		if (value.count(A->val) > 0)
		{
			if (pPrev) pPrev->next = A->next;
			else pHead = A->next;
		}
		else
		{
			pPrev = A;
		}

		A = A->next;
	}

	return pHead;
}
#else
ListNode* DeleteDuplicates2(ListNode* head) {
	if (head == NULL) return NULL;
	ListNode* fakeHead = new ListNode(0);
	fakeHead->next = head;
	ListNode* pre = fakeHead;
	ListNode* cur = head;
	while (cur != NULL) {
		while (cur->next != NULL && cur->val == cur->next->val) {
			cur = cur->next;
		}
		if (pre->next == cur) {
			pre = pre->next;
		}
		else {
			pre->next = cur->next;
		}
		cur = cur->next;
	}
	return fakeHead->next;
}
#endif