/*************************************************************************************************
Minimize The Absolute Difference

Given three sorted arrays A, B and C of not necessarily same sizes.

Calculate the minimum absolute difference between the maximum and minimum number 
from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |.

Example :

Input:

A : [ 1, 4, 5, 8, 10 ]
B : [ 6, 9, 15 ]
C : [ 2, 3, 6, 6 ]
Output:

1
Explanation: We get the minimum difference for 
a=5, b=6, c=6 as | max(a,b,c) - min(a,b,c) | = |6-5| = 1.
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
int MinimizeAbsoluteDiff(vector<int> &A, vector<int> &B, vector<int> &C) {
	int i = (int)A.size() - 1;
	int j = (int)B.size() - 1;
	int k = (int)C.size() - 1;
	int ret = INT_MAX;

	while (i >= 0 && j >= 0 && k >= 0)
	{
		int max_value = max(A[i], max(B[j], C[k]));
		int min_value = min(A[i], min(B[j], C[k]));
		ret = min(ret, abs(max_value - min_value));
		if (max_value == A[i]) i--;
		else if (max_value == B[j]) j--;
		else if (max_value == C[k]) k--;
	}

	return ret;
}
#else
int MinimizeAbsoluteDiff(vector<int> &A, vector<int> &B, vector<int> &C) {
	int ans = INT_MAX;
	int i = A.size() - 1, j = B.size() - 1, k = C.size() - 1;
	while (i >= 0 && j >= 0 && k >= 0)
	{
		int maxe = max(A[i], max(B[j], C[k]));
		int mine = min(A[i], min(B[j], C[k]));
		ans = min(ans, maxe - mine);
		if (A[i] == maxe) i--;
		else if (B[j] == maxe) j--;
		else if (C[k] == maxe) k--;
	}
	return ans;
}
#endif