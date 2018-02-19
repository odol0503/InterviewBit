/*************************************************************************************************
K reverse linked list

Given a singly linked list and an integer K, reverses the nodes of the
list K at a time and returns modified linked list.
NOTE : The length of the list is divisible by K

Example :
Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,
You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

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
ListNode* KReverseList(ListNode* A, int B) {
	if (B <= 1) return A;

	ListNode *pCur = A;
	vector<ListNode*> pHeads;
	vector<ListNode*> pTails;
	ListNode *ret = nullptr;

	while (pCur)
	{
		ListNode *pPrev = nullptr;

		pTails.push_back(pCur);
		for (int i = 0; i<B; i++)
		{
			ListNode *pNext = pCur->next;
			pCur->next = pPrev;
			pPrev = pCur;
			pCur = pNext;
		}
		pHeads.push_back(pPrev);
	}

	ret = pHeads[0];
	for (int i = 0; i<(int)pHeads.size() - 1; i++)
	{
		pTails[i]->next = pHeads[i + 1];
	}

	return ret;
}
#else
ListNode* Reverse(ListNode *A) {
	if (!A->next)
		return A;
	ListNode *next = A->next;
	A->next = NULL;
	ListNode *reversed = Reverse(next);
	next->next = A;
	return reversed;
}

ListNode* KReverseList(ListNode* A, int K) {
	ListNode *prev = new ListNode(0);
	ListNode *first;
	prev->next = A;
	ListNode *last = prev;

	while (last->next) {
		// Find the current bucket
		for (int i = 1; i <= K; i += 1) {
			last = last->next;
		}
		first = prev->next;
		// Unlink the bucket from the list and reverse it
		prev->next = NULL;
		ListNode *next = last->next;
		last->next = NULL;
		Reverse(first);
		// Attack the reversed bucket to the list
		// After the bucket is reversed, first and last are reversed
		prev->next = last;
		first->next = next;
		prev = last = first;
	}
	return reversedFirst;
}
#endif