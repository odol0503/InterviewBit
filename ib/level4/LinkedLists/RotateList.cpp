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
static int GetLen(ListNode *A)
{
	int len = 0;
	while (A)
	{
		A = A->next;
		len++;
	}
	return len;
}

ListNode* RotateRight(ListNode* A, int B) {
	if (A == nullptr) return A;
	ListNode *pCur = A;
	int len = GetLen(A);
	if (len == 1) return A;
	int k = B % len;
	if (k == 0) return A;
	int pos = (len - k - 1);
	for (int i = 0; i<pos; i++) pCur = pCur->next;
	ListNode *pHead = pCur->next;
	pCur->next = nullptr;
	pCur = pHead;
	
	ListNode *pTail = pCur;
	while (pCur)
	{
		
		pTail = pCur;
		pCur = pCur->next;
	}
	pTail->next = A;

	return pHead;
}
#else
ListNode* RotateRight(ListNode* head, int k) {
	if (head == NULL || head->next == NULL) return head;

	ListNode* dummy = new ListNode(0);
	dummy->next = head;

	ListNode *fast = dummy, *slow = dummy;

	int sizeOfList = 0;
	while (fast->next != NULL) {
		fast = fast->next;
		sizeOfList++;
	}

	int firstNodePos = sizeOfList - (k % sizeOfList);
	for (int i = 0; i < firstNodePos; i++) {
		slow = slow->next;
	}

	fast->next = dummy->next;
	dummy->next = slow->next;
	slow->next = NULL;

	return dummy->next;
}
#endif