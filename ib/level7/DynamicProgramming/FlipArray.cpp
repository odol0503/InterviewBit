/*************************************************************************************************
Flip Array

Given an array of positive elements, you have to flip the sign of some of its elements 
such that the resultant sum of the elements of array should be minimum non-negative
(as close to zero as possible). Return the minimum no. of elements whose sign needs 
to be flipped such that the resultant sum is minimum non-negative.

Constraints:
1 <= n <= 100
Sum of all the elements will not exceed 10,000.

Example:
A = [15, 10, 6]
ans = 1 (Here, we will flip the sign of 15 and the resultant sum will be 1 )

A = [14, 10, 4]
ans = 1 (Here, we will flip the sign of 14 and the resultant sum will be 0)

Note that flipping the sign of 10 and 4 also gives the resultant sum 0 but flippings 
there are not minimum
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
using namespace std;

#define OWN5

#ifdef OWN
int rec(const vector<int> &A, int cur, int level, int sum, int &ret, vector<vector<vector<pair<int, int>>>> &dp)
{
	if (cur >= A.size() || sum == 0)
	{
		if (sum == 0)
		{
			int a = 0;
		}
		ret = min(ret, level);
		return 0;
	}

	if (dp[cur][level][sum].first != -1)
	{
		ret = dp[cur][level][sum].second;
		return dp[cur][level][sum].first;
	}

	if (sum < A[cur])
	{
		return rec(A, cur + 1, level, sum, ret, dp);
	}

	int ret1 = INT_MAX;
	int ret2 = INT_MAX;
	int val1 = A[cur] + rec(A, cur + 1, level + 1, sum - A[cur], ret1, dp);
	int val2 = rec(A, cur + 1, level, sum, ret2, dp);

	if (val1 == val2) ret = min(ret1, ret2);
	else ret = val1 > val2 ? ret1 : ret2;

	dp[cur][level][sum] = { max(val1, val2), ret };

	return dp[cur][level][sum].first;

	//return max(val1, val2);
}

int FlipArray(const vector<int> &A) {
	int ret = INT_MAX;
	int sum = 0;
	for (int a : A) sum += a;
	sum /= 2;

	vector<vector<vector<pair<int, int>>>> dp(A.size(), vector<vector<pair<int, int>>>(A.size(), vector<pair<int, int>>(sum + 1, { -1, 0 })));

	rec(A, 0, 0, sum, ret, dp);

	return ret;
}
#else
struct node {
	int items;
	int weight;
}dp[105][10005];

int FlipArray(const vector<int>& A) {
	int n = A.size();
	int sum = 0;

	for (int i = 0; i<n; i++) sum += A[i];

	//knapsack algorithm for capacity sum/2
	int temp = sum / 2;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= temp; j++) {
			if (i == 0 || j == 0) dp[i][j] = { 0, 0 };
			else {
				int prev_items = dp[i - 1][j].items;
				int prev_weight = dp[i - 1][j].weight;

				if (j - A[i - 1] >= 0) {
					int curr_weight = dp[i - 1][j - A[i - 1]].weight + A[i - 1];
					int curr_items = dp[i - 1][j - A[i - 1]].items + 1;

					if ((curr_weight>prev_weight) || ((curr_weight == prev_weight) && (curr_items<prev_items))) {
						dp[i][j] = { curr_items, curr_weight };
					}
					else {
						dp[i][j] = dp[i - 1][j];
					}
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
	}


	return dp[n][temp].items;
}
#endif