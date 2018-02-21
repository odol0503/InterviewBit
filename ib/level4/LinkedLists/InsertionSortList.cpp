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

#define OWN

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

#ifdef OWN
ListNode* InsertionSortList(ListNode* A) {
	if (A == nullptr || A->next == nullptr) return A;
	ListNode *dummy = new ListNode(0);
	dummy->next = A;
	ListNode *p1 = A;
	ListNode *p2 = A->next;
	ListNode *pPrev = dummy;
	ListNode *pCur = dummy->next;

	while (p2)
	{
		while (pCur != p2)
		{
			if (p2->val < pCur->val)
			{
				p1->next = p2->next;
				pPrev->next = p2;
				p2->next = pCur;
				break;
			}
			pPrev = pCur;
			pCur = pCur->next;
		}

		p1 = p2;
		p2 = p2->next;
		pCur = dummy->next;
		pPrev = dummy;
	}

	ListNode *pHead = dummy->next;
	delete dummy;

	return pHead;
}
#else
ListNode *InsertionSortList(ListNode *head) {
	if (!head) return head;
	if (!head->next) return head;

	ListNode *sorted = NULL;
	ListNode *list = head;
	while (list) {
		ListNode *curr = list;
		list = list->next;
		if (sorted == NULL || sorted->val > curr->val) {
			// first lookup
			curr->next = sorted; //this indicates the end of sorted list
			sorted = curr;
		}
		else {
			// insert somewhere after the fisrt of sorted
			ListNode *tmp = sorted;
			while (tmp) {
				ListNode *s = tmp;
				tmp = tmp->next;

				if (s->next == NULL || s->next->val > curr->val) {
					s->next = curr;
					curr->next = tmp;
					break;
				}
			}
		}
	}
	return sorted;
	}
#endif