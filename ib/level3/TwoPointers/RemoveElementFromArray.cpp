/*************************************************************************************************
Remove Element from Array

Given an array and a value, remove all the instances of that value in the array.
Also return the number of elements left in the array after the operation.
It does not matter what is left beyond the expected length.

Example:
If array A is [4, 1, 1, 2, 1, 3]
and value elem is 1,
then new length is 3, and A is now [4, 2, 3]
Try to do it in less than linear additional space complexity.
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
int RemoveElement(vector<int> &A, int B) {
	int len = (int)A.size();
	int idx = 0;

	for (int i = 0; i < len; i++)
	{
		if (A[i] == B) continue;
		else A[idx++] = A[i];
	}
	return idx;
}
#else
int RemoveElement(vector<int> &A, int B) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (A[i] == elem) continue;
		else {
			A[count] = A[i];
			count++;
		}
	}
	return count;
}
#endif