/*************************************************************************************************
Remove Duplicates from Sorted List

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*************************************************************************************************/
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

#define OWN

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

#ifdef OWN
ListNode* DeleteDuplicates(ListNode* A) {
	unordered_set<int> value;
	ListNode *pPrev = nullptr;
	ListNode *ret = A;

	while (A)
	{
		if (value.count(A->val) == 0)
		{
			pPrev = A;
			value.insert(A->val);
			A = A->next;
		}
		else
		{
			pPrev->next = A->next;
			A = A->next;
		}
	}

	return ret;
}
#else
ListNode* DeleteDuplicates(ListNode* head) {
	ListNode *origin = head;
	while (head != NULL) {
		while (head->next != NULL && head->val == head->next->val) {
			head->next = head->next->next;
		}
		head = head->next;
			}
	return origin;
}
#endif