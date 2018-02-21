/*************************************************************************************************
Add Two Numbers as Lists

You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

342 + 465 = 807
Make sure there are no trailing zeros in the output list
So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN4

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

#ifdef OWN
ListNode* AddTwoNumbers(ListNode* A, ListNode* B) {
	int carry = 0;
	ListNode *dummy = new ListNode(0);
	ListNode *pCur = dummy;

	while (A && B)
	{
		int val = A->val + B->val + carry;
		carry = val / 10;
		pCur->next = new ListNode(val%10);
		A = A->next;
		B = B->next;
		pCur = pCur->next;
	}

	ListNode *pRest = nullptr;
	if (A) pRest = A;
	else if(B) pRest = B;
	else
	{
		if (carry) pCur->next = new ListNode(carry);
	}

	while (pRest)
	{
		int val = pRest->val + carry;
		carry = val / 10;
		pCur->next = new ListNode(val%10);
		pRest = pRest->next;
		pCur = pCur->next;
	}

	if (carry) pCur->next = new ListNode(carry);

	return dummy->next;
}
#else
ListNode *AddTwoNumbers(ListNode *l1, ListNode *l2) {
	if (!l1)
		return l2;
	if (!l2)
		return l1;

	int carry = (l1->val + l2->val) / 10;
	ListNode *l3 = new ListNode((l1->val + l2->val) % 10);
	ListNode *tail = l3;
	l1 = l1->next;
	l2 = l2->next;

	while (l1 || l2 || carry)
	{
		int sum = ((l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry);
		ListNode *t = new ListNode(sum % 10);
		carry = sum / 10;

		if (l1)
			l1 = l1->next;
		if (l2)
			l2 = l2->next;
		tail->next = t;
		tail = t;
	}

	return l3;
		}
#endif