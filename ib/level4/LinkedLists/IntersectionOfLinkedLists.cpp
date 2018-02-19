/*************************************************************************************************
Intersection Of Linked Lists

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:
A:a1   ¡æ    a2
              ¢Ù
                c1 ¡æ c2 ¡æ c3
              ¢Ö
B:b1 ¡æ b2 ¡æ b3

begin to intersect at node c1.

Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN6

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

#ifdef OWN
int GetLen(ListNode *A)
{
	int len = 0;
	while (A)
	{
		len++;
		A = A->next;
	}

	return len;
}

ListNode* GetIntersectionNode(ListNode* A, ListNode* B) {
	int lenA = GetLen(A);
	int lenB = GetLen(B);
	int diff = 0;

	if (lenA > lenB)
	{
		diff = lenA - lenB;
		for (int i = 0; i < diff; i++) A = A->next;
	}
	else
	{
		diff = lenB - lenA;
		for (int i = 0; i < diff; i++) B = B->next;
	}

	while (A)
	{
		if (A == B) return A;
		A = A->next;
		B = B->next;
	}

	return nullptr;
}
#else
int getLength(ListNode *head) {
	int ret = 0;
	while (head) {
		ret++;
		head = head->next;
	}
	return ret;
}

ListNode* GetIntersectionNode(ListNode* headA, ListNode* headB) {
	if (!headA || !headB)
		return NULL;
	int lenA = getLength(headA), lenB = getLength(headB);
	int lenDiff = lenA - lenB;
	ListNode *pa = headA;
	ListNode *pb = headB;
	if (lenDiff > 0) {
		while (lenDiff != 0) {
			pa = pa->next;
			lenDiff--;
		}
	}
	else if (lenDiff < 0) {
		while (lenDiff != 0) {
			pb = pb->next;
			lenDiff++;
		}
	}
	while (pa && pb) {
		if (pa == pb)
			return pa;
		pa = pa->next;
		pb = pb->next;
	}
	return NULL;
}
#endif