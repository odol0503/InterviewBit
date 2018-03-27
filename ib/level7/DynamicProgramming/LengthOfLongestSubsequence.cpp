/*************************************************************************************************
Length of Longest Subsequence

Given an array of integers, find the length of longest subsequence 
which is first increasing then decreasing.

**Example: **
For the given array [1 11 2 10 4 5 2 1]
Longest subsequence is [1 2 10 4 2 1]
Return value 6
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
static void GetLen(const vector<int> &A, int idx, vector<int> &arr, vector<vector<int>> &ret, bool isInc)
{
	int i = idx;
	for (; i < (int)A.size()-1; i++)
	{
		for (int j = i + 1; j < (int)A.size(); j++)
		{
			if (isInc && A[i] < A[j])
			{
				arr.push_back(A[i]);
				GetLen(A, j, arr, ret, isInc);
				arr.pop_back();
			}
			else if (!isInc && A[i] > A[j])
			{
				arr.push_back(A[i]);
				GetLen(A, j, arr, ret, isInc);
				arr.pop_back();
			}
		}
	}
	arr.push_back(A[i]);
	ret.push_back(arr);
	arr.pop_back();
}

int LongestSubsequenceLength(const vector<int> &A) {
	vector<int> arr;
	vector<vector<int>> inc;
	vector<vector<int>> dec;

	GetLen(A, 0, arr, inc, true);
	GetLen(A, 0, arr, dec, false);

	return 1;
}
#else

#endif