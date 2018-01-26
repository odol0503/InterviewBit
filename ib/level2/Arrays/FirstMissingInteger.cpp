/*************************************************************************************************
First Missing Integer

Given an unsorted integer array, find the first missing positive integer.
Example:
Given [1,2,0] return 3,
[3,4,-1,1] return 2,
[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.
*************************************************************************************************/
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
int FirstMissingInteger(vector<int> &A)
{
	int len = static_cast<int>(A.size());

	int i = 0;
	while (i < len)
	{
		if (A[i] > 0 && A[i] <= len && A[i] != i + 1)
		{
			if (A[A[i] - 1] != A[i])
			{
				swap(A[A[i] - 1], A[i]);
				continue;
			}
		}
		i++;
	}

	for (int i = 0; i < len; i++)
	{
		if (A[i] != i + 1) return i + 1;
	}

	return len + 1;
}
#else
int FirstMissingInteger(vector<int> &A)
{
	int n = A.size();
	for (int i = 0; i < n; i++) {
		if (A[i] > 0 && A[i] <= n) {
			int pos = A[i] - 1;
			if (A[pos] != A[i]) {
				swap(A[pos], A[i]);
				i--;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (A[i] != i + 1) return (i + 1);
	}
	return n + 1;
}
#endif
