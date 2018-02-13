/*************************************************************************************************
3 Sum

Given an array S of n integers, find three integers in S such that the sum is closest 
to a given number, target.
Return the sum of the three integers.

Assume that there will only be one solution

Example:
given array S = {-1 2 1 -4},
and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
int ThreeSumClosest(vector<int> &A, int B) {
	int len = (int)A.size();
	int ret = 0;
	int min_diff = INT_MAX;

	sort(A.begin(), A.end());

	for (int i = 0; i < len - 2; i++)
	{
		int j = i + 1;
		int k = len - 1;

		while (j < k)
		{
			int sum = A[i] + A[j] + A[k];
			int diff = B - sum;

			if (min_diff > abs(diff))
			{
				min_diff = abs(diff);
				ret = sum;
			}

			if (diff > 0) j++;
			else if (diff < 0) k--;
			else return sum;
		}
	}

	return ret;
}
#else
int ThreeSumClosest(vector<int> &num, int target) {
	sort(num.begin(), num.end());
	int bestSum = 1000000000, sum = 0;
	// Fix the smallest number in the three integers
	for (int i = 0; i < num.size() - 2; i++) {
		// Now num[i] is the smallest number in the three integers in the solution
		int ptr1 = i + 1, ptr2 = num.size() - 1;
		while (ptr1 < ptr2) {
			sum = num[i] + num[ptr1] + num[ptr2];
			if (abs(target - sum) < abs(target - bestSum)) {
				bestSum = sum;
			}
			if (sum > target) {
				ptr2--;
			}
			else {
				ptr1++;
			}
		}
	}
	return bestSum;
}
#endif
