/*************************************************************************************************
Coin Sum Infinite

You are given a set of coins S. In how many ways can you make sum N 
assuming you have infinite amount of each coin in the set.

Note : Coins in set S will be unique. Expected space complexity of this problem is O(N).

Example :
Input :
S = [1, 2, 3]
N = 4

Return : 4

Explanation : The 4 possible ways are
{1, 1, 1, 1}
{1, 1, 2}
{2, 2}
{1, 3}
Note that the answer can overflow. So, give us the answer % 1000007
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
using namespace std;

#define OWN

#ifdef OWN
#define MOD 1000007LL

int CoinSumInfinite(vector<int> &A, int B) {
	int num = (int)A.size();
	vector<int> dp(B + 1);
	dp[0] = 1;

	for (int i = 0; i<num; i++)
	{
		for (int j = A[i]; j <= B; j++)
		{
			dp[j] = (dp[j] + dp[j - A[i]]) % MOD;
		}
	}

	return dp[B];
}
#else
int CoinSumInfinite(vector<int> &A, int N) {
	/*
	num_ways[i] will be storing the number of solutions for
	sum i. We need N+1 rows as the table is constructed
	in bottom up manner using the base case (N = 0)
	*/
	vector<int> num_ways(N + 1);
	int i, j, m = A.size();

	// Base case (If required sum is 0)
	num_ways[0] = 1;

	// Pick all coins one by one and update the num_ways[] values
	for (i = 0; i < m; i++) {
		for (j = A[i]; j <= N; j++) {
			num_ways[j] += num_ways[j - A[i]];
		}
	}
	return num_ways[N];
}
#endif