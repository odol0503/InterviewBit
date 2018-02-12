/*************************************************************************************************
Merge Two Sorted Lists II

Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note: You have to modify the array A to contain the merge of A and B. Do not output anything 
in your code.
TIP: C users, please malloc the result into a new array and return the result.
If the number of elements initialized in A and B are m and n respectively, the resulting
size of array A after your code is executed should be m + n

Example :

Input :
A : [1 5 8]
B : [6 9]

Modified A : [1 5 6 8 9]
*************************************************************************************************/
#include <vector>
using namespace std;

#define OWN

#ifdef OWN
vector<int> MergeTwoSortedLists2(vector<int> &A, vector<int> &B)
{
	int lenA = (int)A.size();
	int lenB = (int)B.size();

	int j = lenA-1;
	for (int i = lenB-1; i >=0; i--)
	{
		while (A[j] > B[i] && j >= 0) j--;
		A.insert(A.begin() + j + 1, B[i]);
	}

	return A;
}
#else
void MergeTwoSortedLists2(vector<int> &A, vector<int> &B)
{
	vector<int> C = A;
	A.clear();
	int p1 = 0, p2 = 0;
	while (true) {
		if (p1 == C.size() || p2 == B.size())
			break;
		if (C[p1] < B[p2]) {
			A.push_back(C[p1]);
			p1++;
		}
		else if (C[p1] > B[p2]) {
			A.push_back(B[p2]);
			p2++;
		}
		else if (C[p1] == B[p2]) {
			A.push_back(C[p1]);
			A.push_back(B[p2]);
			p1++;
			p2++;
		}
	}
	if (p1 == C.size() && p2 < B.size()) {
		while (p2 < B.size()) {
			A.push_back(B[p2]);
			p2++;
		}
	}
	if (p2 == B.size() && p1 < C.size()) {
		while (p1 < C.size()) {
			A.push_back(C[p1]);
			p1++;
		}
	}

	return A;
}
#endif