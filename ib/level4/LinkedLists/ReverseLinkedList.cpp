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
		len++;
		A = A->next;
	}
	return len;
}

ListNode *ReverseList(ListNode* A) {
	if (A == nullptr) return nullptr;
	ListNode *ret;
	int len = GetLen(A);
	ListNode *pA = A;
	vector<ListNode*> addr(len, 0);
	int i = 0;
	while (pA)
	{
		addr[i++] = pA;
		pA = pA->next;
	}
	
	i = 0;
	while (i < len)
	{
		ret = addr[i];
		ret->next = (i > 0 ? addr[i - 1] : nullptr);
	}

	return ret;
}
#else
ListNode *ReverseList(ListNode* head) {
	if (head == NULL) return head;
	ListNode *cur = head, *nextNode, *prevNode;
	prevNode = NULL;

	while (cur != NULL) {
		nextNode = cur->next;
		cur->next = prevNode;
		prevNode = cur;
		cur = nextNode;
	}

	head = prevNode;
	return head;
}
#endif