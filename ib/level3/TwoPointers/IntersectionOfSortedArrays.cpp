/*************************************************************************************************
Intersection Of Sorted Arrays

Find the intersection of two sorted arrays.
OR in other words,
Given 2 sorted arrays, find all the elements which occur in both the arrays.

Example :

Input :
A : [1 2 3 3 4 5 6]
B : [3 3 5]

Output : [3 3 5]

Input :
A : [1 2 3 3 4 5 6]
B : [3 5]

Output : [3 5]
NOTE : For the purpose of this problem ( as also conveyed by the sample case ),
assume that elements that appear more than once in both arrays should be included 
multiple times in the final output.
*************************************************************************************************/
#include <vector>
using namespace std;

#define OWN

#ifdef OWN
vector<int> Intersect(const vector<int> &A, const vector<int> &B) {
	vector<int> ret;
	int lenA = (int)A.size();
	int lenB = (int)B.size();

	int j = 0;
	for (int i = 0; i < lenA; i++)
	{
		while (j < lenB && A[i] > B[j]) j++;
		if (j < lenB && A[i] == B[j])
		{
			j++;
			ret.push_back(A[i]);
		}
	}

	return ret;
}
#else
vector<int> Intersect(const vector<int> &A, const vector<int> &B) {
	vector<int> intersection;
	int n1 = A.size();
	int n2 = B.size();
	int i = 0, j = 0;
	while (i < n1 && j < n2) {
		if (A[i] > B[j]) {
			j++;
		}
		else if (B[j] > A[i]) {
			i++;
		}
		else {
			intersection.push_back(A[i]);
			i++;
			j++;
		}
	}
	return intersection;
}
#endif