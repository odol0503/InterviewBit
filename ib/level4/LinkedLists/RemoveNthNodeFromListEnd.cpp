/*************************************************************************************************
Remove Nth Node from List End

Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
If n is greater than the size of the list, remove the first node of the list.
Try doing it using constant additional space.
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
static int GetLen(ListNode* A)
{
	int len = 0;
	while (A)
	{
		A = A->next;
		len++;
	}
	return len;
}

ListNode* RemoveNthFromEnd(ListNode* A, int B) {
	ListNode *pHead = A;
	int len = GetLen(A);
	int pos = max(len - B, 0);

	if (pos == 0) return A->next;

	for (int i = 0; i<pos - 1; i++) A = A->next;

	if (A->next->next) A->next = A->next->next;
	else A->next = nullptr;

	return pHead;
}

#else
ListNode* RemoveNthFromEnd(ListNode* head, int n) {
	ListNode** t1 = &head, *t2 = head;
	for (int i = 1; i < n; ++i) {
		t2 = t2->next;
	}

	while (t2->next != NULL) {
		t1 = &((*t1)->next);
		t2 = t2->next;
	}
	*t1 = (*t1)->next;
	return head;
}
#endif