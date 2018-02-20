/*************************************************************************************************
Reverse Link List II
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ¡Â m ¡Â n ¡Â length of list. Note 2:
Usually the version often seen in the interviews is reversing the whole linked list 
which is obviously an easier version of this question.
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
ListNode* ReverseBetween(ListNode* A, int B, int C) {
	if (A == nullptr) return A;
	if (B == C) return A;
	ListNode *pDummy = new ListNode(0);
	pDummy->next = A;
	ListNode *pCur = pDummy->next;
	ListNode *pPrev = pDummy;
	ListNode *pNext = nullptr;
	ListNode *pStart = nullptr;
	ListNode *pEnd = nullptr;

	for (int i = 0; i < B - 1; i++)
	{
		pPrev = pCur;
		pCur = pCur->next;
	}
	pStart = pCur;

	for (int i = B - 1; i < C - 1; i++)
	{
		pCur = pCur->next;
		pNext = pCur->next;
	}
	pEnd = pCur;

	ListNode *pPrevNode = nullptr;
	pCur = pStart;
	while (pCur != pNext)
	{
		ListNode *pNextNode = pCur->next;
		pCur->next = pPrevNode;
		pPrevNode = pCur;
		pCur = pNextNode;
	}

	pStart->next = pNext;
	pPrev->next = pPrevNode;

	ListNode *pDummyNext = pDummy->next;
	delete pDummy;

	return pDummyNext;
}
#else
ListNode *reverseLinkedList(ListNode *head, int size)
{
	if (size <= 1) return head;
	ListNode *cur = head, *nextNode = head->next, *tmp;

	for (int i = 0; i < (size - 1); i++) {
		tmp = nextNode->next;
		nextNode->next = cur;
		cur = nextNode;
		nextNode = tmp;
	}

	head->next = nextNode;
	return cur;
	}

ListNode *ReverseBetween(ListNode *head, int m, int n) {
	// Introduce dummyhead to not handle corner cases. 
	ListNode* dummyHead = new ListNode(0);
	dummyHead->next = head;

	// Figure out the start node of the sublist we are going to reverse
	ListNode* prev = dummyHead;
	ListNode* cur = head;
	int index = 1;
	while (index < m) {
		prev = cur;
		cur = cur->next;
		index++;
	}

	// At this point, we have start of sublist in cur, prev of startSubList in prev.
	// Lets reverse the sublist now. 
	ListNode* endSubList = reverseLinkedList(cur, n - m + 1);
	prev->next = endSubList;

	return dummyHead->next;
}
#endif