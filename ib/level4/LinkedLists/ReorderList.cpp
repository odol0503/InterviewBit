/*************************************************************************************************
Reorder List

Given a singly linked list
L: L0 ¡æ L1 ¡æ ¡¦ ¡æ Ln-1 ¡æ Ln,
reorder it to:

L0 ¡æ Ln ¡æ L1 ¡æ Ln-1 ¡æ L2 ¡æ Ln-2 ¡æ ¡¦
You must do this in-place without altering the nodes¡¯ values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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

ListNode* ReorderList(ListNode* A)
{
	if (A == nullptr) return A;
	ListNode *pCur = A;
	int len = GetLen(A);
	int mid = (len - 1) / 2;
	for (int i = 0; i<mid; i++) pCur = pCur->next;
	ListNode *p1 = A;
	ListNode *p2 = pCur->next;
	pCur->next = nullptr;

	p2 = Reverse(p2);

	while (p2)
	{
		ListNode *p1Next = p1->next;
		ListNode *p2Next = p2->next;
		p1->next = p2;
		p2->next = p1Next;
		p1 = p1Next;
		p2 = p2Next;
	}

	return A;
}
#else
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;

	ListNode* head = l1;    // head of the list to return
	l1 = l1->next;

	ListNode* p = head;     // pointer to form new list
							// A boolean to track which list we need to extract from. 
							// We alternate between first and second list. 
	bool curListNum = true;

	while (l1 && l2) {
		if (curListNum == false) {
			p->next = l1;
			l1 = l1->next;
		}
		else {
			p->next = l2;
			l2 = l2->next;
		}
		p = p->next;
		curListNum = !curListNum;
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

ListNode *reverseLinkedList(ListNode *head) {
	if (head->next == NULL) return head;
	ListNode *cur = head, *nextNode = head->next, *tmp;

	while (nextNode != NULL) {
		tmp = nextNode->next;
		nextNode->next = cur;
		cur = nextNode;
		nextNode = tmp;
	}

	head->next = nextNode;
	return cur;
}

ListNode* ReorderList(ListNode *head) {
	if (head == NULL || head->next == NULL || head->next->next == NULL)
		return head;

	//find the middle of the list, and split into two lists.    
	ListNode *slow = head, *fast = head;
	while (slow != NULL && fast != NULL && fast->next != NULL && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	ListNode *mid = slow->next;
	slow->next = NULL;

	//reverse from the middle to the end
	ListNode* secondHalfReversed = reverseLinkedList(mid);

	//merge these two list
	return head = mergeTwoLists(head, secondHalfReversed);
}
#endif