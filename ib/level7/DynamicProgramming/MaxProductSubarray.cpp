/*************************************************************************************************
Max Product Subarray

Find the contiguous subarray within an array (containing at least one number) 
which has the largest product.
Return an integer corresponding to the maximum product possible.

Example :
Input : [2, 3, -2, 4]
Return : 6

Possible with [2, 3]
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
int MaxProductSubarray(vector<int> A) {
	if (A.empty()) return 0;
	int num = (int)A.size();
	int ret = A[0];
	int max_val = ret;
	int min_val = ret;

	for (int i = 1; i<num; i++)
	{
		if (A[i] < 0) swap(max_val, min_val);

		max_val = max(A[i], max_val*A[i]);
		min_val = min(A[i], min_val*A[i]);

		ret = max(ret, max_val);
	}

	return ret;
}
#else
int MaxProductSubarray(vector<int> A) 
{
	int n = (int)A.size();
	// store the result that is the max we have found so far
	int r = A[0];

	// imax/imin stores the max/min product of
	// subarray that ends with the current number A[i]
	for (int i = 1, imax = r, imin = r; i < n; i++) {
		// multiplied by a negative makes big number smaller, small number bigger
		// so we redefine the extremums by swapping them
		if (A[i] < 0)
			swap(imax, imin);

		// max/min product for the current number is either the current number itself
		// or the max/min by the previous number times the current one
		imax = max(A[i], imax * A[i]);
		imin = min(A[i], imin * A[i]);

		// the newly computed max value is a candidate for our global result
		r = max(r, imax);
	}
	return r;
}
#endif