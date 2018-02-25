/*************************************************************************************************
SUBTRACT

Given a singly linked list, modify the value of first half nodes such that :
1st node¡¯s new value = the last node¡¯s value - first node¡¯s current value
2nd node¡¯s new value = the second last node¡¯s value - 2nd node¡¯s current value,
and so on ¡¦

NOTE :
If the length L of linked list is odd, then the first half implies at first floor(L/2) nodes.
So, if L = 5, the first half refers to first 2 nodes.
If the length L of linked list is even, then the first half implies at first L/2 nodes.
So, if L = 4, the first half refers to first 2 nodes.

Example :
Given linked list 1 -> 2 -> 3 -> 4 -> 5,
You should return 4 -> 2 -> 3 -> 4 -> 5

as
for first node, 5 - 1 = 4
for second node, 4 - 2 = 2
Try to solve the problem using constant extra space.
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
static ListNode* Reverse(ListNode *A)
{
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

ListNode* Subtract(ListNode* A) {
	ListNode *pSlow = A;
	ListNode *pFast = A;
	ListNode *p1 = A;

	while (pFast->next && pFast->next->next)
	{
		pSlow = pSlow->next;
		pFast = pFast->next->next;
	}

	ListNode *p2ndNode = pSlow->next;
	p2ndNode = Reverse(p2ndNode);
	ListNode *p2 = p2ndNode;

	while (p2)
	{
		p1->val = p2->val - p1->val;
		p1 = p1->next;
		p2 = p2->next;
	}
	pSlow->next = Reverse(p2ndNode);

	return A;
}
#else

#endif