/*************************************************************************************************
Max Sum Contiguous Subarray

Find the contiguous subarray within an array (containing at least one number)
which has the largest sum.

For example:
Given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

For this problem, return the maximum sum.
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
int MaxSumContiguousSubarray(const vector<int> &A)
{
	int ret = INT_MIN;
	int temp = 0;
	for (auto a : A)
	{
		temp += a;
		ret = max(ret, temp);
		if (temp < 0) temp = 0;
	}

	return ret;
}
#else
int MaxSumContiguousSubarray(const vector<int> &A) {
	int n = A.size();
	int curSum = 0, maxSum = -1000000000;
	for (int i = 0; i < n; i++) {
		curSum += A[i];
		maxSum = max(maxSum, curSum);
		if (curSum < 0) curSum = 0;
	}
	return maxSum;
}
#endif
