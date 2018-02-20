/*************************************************************************************************
Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists,
and should also be sorted.

For example, given following linked lists :

5 -> 8 -> 20
4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20
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
ListNode* MergeTwoLists(ListNode* A, ListNode* B) {
	ListNode *ret;
	ListNode *pCur;

	if (A == nullptr && B) return B;
	if (A && B == nullptr) return A;

	if (A->val < B->val)
	{
		ret = A;
		A = A->next;
	}
	else
	{
		ret = B;
		B = B->next;
	}
	pCur = ret;

	while (A && B)
	{
		if (A->val < B->val)
		{
			pCur->next = A;
			pCur = pCur->next;
			A = A->next;
		}
		else
		{
			pCur->next = B;
			pCur = pCur->next;
			B = B->next;
		}
	}

	if (A) pCur->next = A;
	else if (B) pCur->next = B;

	return ret;
}
#else
ListNode* MergeTwoLists(ListNode* l1, ListNode* l2) {
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
#endif