/*************************************************************************************************
Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element appears 
only once and return the new length.

Note that even though we want you to return the new length, make sure to change 
the original array as well in place

Do not allocate extra space for another array, you must do this in place with constant memory.

Example:
Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2].
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
int RemoveDuplicates(vector<int> &A) {
	int len = (int)A.size();

	for (int i = 0; i < len; i++)
	{
		if (i < len - 1 && A[i] == A[i + 1])
		{
			int j = i + 1;
			while (j < len)
			{
				if (A[i] != A[j]) break;
				j++;
			}
			A.erase(A.begin() + i + 1, A.begin() + j);
			len = (int)A.size();
		}
	}

	return (int)A.size();
}
#else
int RemoveDuplicates(vector<int> &A) {
	int count = 0, n = A.size();
	for (int i = 0; i < n; i++) {
		if (i < n - 1 && A[i] == A[i + 1]) continue;
		else {
			A[count] = A[i];
			count++;
		}
	}
	A.erase(A.begin() + count, A.end());
	return count;
}
#endif