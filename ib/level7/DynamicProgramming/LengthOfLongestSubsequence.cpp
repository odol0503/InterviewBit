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
int LongestSubsequenceLength(const vector<int> &A) {
	if (A.empty()) return 0;

	vector<int> arr;
	int len = (int)A.size();
	vector<int> dp1(len, 1);
	vector<int> dp2(len, 1);
	int max_len = 0;

	for (int i = 1; i < len; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (A[j] < A[i] && dp1[i] < dp1[j] + 1)
			{
				dp1[i] = dp1[j] + 1;
			}
		}
	}

	for (int i = len - 2; i >= 0; i--)
	{
		for (int j = len - 1; j > i; j--)
		{
			if (A[j] < A[i] && dp2[i] < dp2[j] + 1)
			{
				dp2[i] = dp2[j] + 1;
			}
		}
	}

	for (int i = 0; i < len; i++)
	{
		max_len = max(max_len, dp1[i] + dp2[i]);
	}

	return max_len - 1;
}
#else
int LongestSubsequenceLength(const vector &A) {
	int n = A.size();
	int inc[n];
	int dec[n];
	int ct = 0;

	inc[0] = 1;
	for (int i = 1; i<n; i++)
	{
		inc[i] = 1;
		for (int j = i - 1; j >= 0; j--)
		{
			if (A[i] > A[j] && inc[i] < inc[j] + 1)
				inc[i] = inc[j] + 1;
		}
	}

	dec[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--)
	{
		dec[i] = 1;
		for (int j = i + 1; j<n; j++)
		{
			if (A[i] > A[j] && dec[i] < dec[j] + 1)
				dec[i] = dec[j] + 1;
		}
	}

	int mx = 0;
	for (int i = 0; i<n; i++)
		mx = max(mx, inc[i] + dec[i] - 1);

	return mx;
}
#endif