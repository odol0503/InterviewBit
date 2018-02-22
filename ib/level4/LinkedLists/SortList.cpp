/*************************************************************************************************
Sort List

Sort a linked list in O(n log n) time using constant space complexity.

Example :

Input : 1 -> 5 -> 4 -> 3

Returned list : 1 -> 3 -> 4 -> 5
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
ListNode *Merge(ListNode *A, ListNode *B)
{
	ListNode *pHead;
	if (A->val < B->val)
	{
		pHead = A;
		A = A->next;
	}
	else
	{
		pHead = B;
		B = B->next;
	}

	ListNode *pCur = pHead;
	while (A && B)
	{
		if (A->val < B->val)
		{
			pCur->next = A;
			A = A->next;
		}
		else
		{
			pCur->next = B;
			B = B->next;
		}
		pCur = pCur->next;
	}

	if (A) pCur->next = A;
	else pCur->next = B;

	return pHead;
}

ListNode *MergeSort(ListNode *A)
{
	ListNode *pHead = A;

	if (A==nullptr || A->next == nullptr) return A;
	if (A->next->next == nullptr)
	{
		if (A->val > A->next->val)
		{
			pHead = A->next;
			pHead->next = A;
			A->next = nullptr;
		}
		return pHead;
	}

	ListNode *pSlow = A;
	ListNode *pFast = A;

	while (pFast && pFast->next)
	{
		pSlow = pSlow->next;
		pFast = pFast->next->next;
	}

	ListNode *pHead2 = pSlow->next;
	pSlow->next = nullptr;
	ListNode *p1 = MergeSort(pHead);
	ListNode *p2 = MergeSort(pHead2);

	return Merge(p1, p2);
}

ListNode* SortList(ListNode* A) 
{
	if (A == nullptr || A->next == nullptr) return A;

	return MergeSort(A);
}
#else
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;

	ListNode* head = NULL;    // head of the list to return

							  // find first element (can use dummy node to put this part inside of the loop)
	if (l1->val < l2->val) {
		head = l1;
		l1 = l1->next;
	}
	else {
		head = l2;
		l2 = l2->next;
	}

	ListNode* p = head;     // pointer to form new list

	while (l1 && l2) {
		if (l1->val < l2->val) {
			p->next = l1;
			l1 = l1->next;
		}
		else {
			p->next = l2;
			l2 = l2->next;
		}
		p = p->next;
	}

	// add the rest of the tail, done!
	if (l1) {
		p->next = l1;
	}
	else {
		p->next = l2;
	}

	return head;
}

ListNode *SortList(ListNode *head) {
	if (head == NULL || head->next == NULL)
		return head;

	// find the middle place
	ListNode *p1 = head;
	ListNode *p2 = head->next;
	while (p2 && p2->next) {
		p1 = p1->next;
		p2 = p2->next->next;
	}
	p2 = p1->next;
	p1->next = NULL;

	return mergeTwoLists(SortList(head), SortList(p2));
}
#endif