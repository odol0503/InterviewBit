/*************************************************************************************************
Copy List

A linked list is given such that each node contains an additional random pointer 
which could point to any node in the list or NULL.
Return a deep copy of the list.

Example
Given list
1 -> 2 -> 3
with random pointers going from
1 -> 3
2 -> 1
3 -> 1
You should return a deep copy of the list. 
The returned answer should not contain the same node as the original list, but a copy of them. 
The pointers in the returned list should not link to any node in the original input list.
*************************************************************************************************/
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

#define OWN

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

#ifdef OWN
RandomListNode* CopyRandomList(RandomListNode* A) {
	RandomListNode *pCur = A;
	map<RandomListNode*, RandomListNode*> M;
	RandomListNode *pCopy;

	while (pCur)
	{
		pCopy = new RandomListNode(pCur->label);
		M[pCur] = pCopy;
		pCur = pCur->next;
	}

	pCur = A;
	while (pCur)
	{
		M[pCur]->next = M[pCur->next];
		M[pCur]->random = M[pCur->random];
		pCur = pCur->next;
	}

	return M[A];
}
#else
RandomListNode *CopyRandomList(RandomListNode *head) {
	if (head == NULL) {
		return NULL;
	}

	// Step 1: create a new node for each existing node and join them together 
	// eg: A->B->C will be A->A'->B->B'->C->C'
	RandomListNode* node = head;
	while (node != NULL) {
		RandomListNode* copyNode = new RandomListNode(node->label);
		RandomListNode* nextNode = node->next;
		node->next = copyNode;
		copyNode->next = nextNode;
		node = nextNode;
	}

	// Step2: copy the random links: for each new node n', 
	// n'.random = n.random.next
	node = head;
	while (node != NULL) {
		RandomListNode* copyNode = node->next;
		if (node->random != NULL)
			copyNode->random = node->random->next;
		else
			copyNode->random = NULL;
		node = copyNode->next;
	}

	// Step3: detach the list: 
	// basically n.next = n.next.next; n'.next = n'.next.next
	node = head;
	RandomListNode* copyNode = node->next;
	RandomListNode* copyHead = head->next;
	while (copyNode != NULL && node != NULL) {
		node->next = node->next->next;
		if (copyNode->next == NULL) {
			break;
		}
		copyNode->next = copyNode->next->next;

		copyNode = copyNode->next;
		node = node->next;
	}

	return copyHead;
}
#endif