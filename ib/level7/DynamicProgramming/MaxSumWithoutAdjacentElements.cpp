/*************************************************************************************************
Max Sum Without Adjacent Elements

Given a 2 * N Grid of numbers, choose numbers such that the sum of the numbers
is maximum and no two chosen numbers are adjacent horizontally, vertically or 
diagonally, and return it.

Example:
Grid:
1 2 3 4
2 3 4 5
so we will choose
3 and 5 so sum will be 3 + 5 = 8

Note that you can choose more than 2 numbers
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
using namespace std;

#define OWN5

#ifdef OWN
int getSum(vector<vector<int>> &A, int cur, vector<int> &dp)
{
	int row = 2;
	int col = A[0].size();

	if (cur >= col) return 0;

	if (dp[cur]) return dp[cur];

	int max_val = 0;

	for (int i = cur + 2; i<col; i++)
	{
		max_val = max(max_val, getSum(A, i, dp));
	}

	dp[cur] = max_val + max(A[0][cur], A[1][cur]);

	return dp[cur];
}

int MaxSumWithoutAdjacentElements(vector<vector<int> > &A) {
	if (A.empty()) return 0;

	int ret = 0;
	vector<int> dp(A[0].size() + 10, 0);

	for (int i = 0; i<A[0].size(); i++)
	{
		ret = max(ret, getSum(A, i, dp));
	}

	return ret;
}
#else
int MaxSumWithoutAdjacentElements(vector<vector<int> > &V) {
	int N = V[0].size();
	vector<vector<int>> MAXSUM(N + 1, vector<int>(2, 0));

	int ele = max(V[0][0], V[1][0]);
	MAXSUM[0][1] = ele;
	for (int i = 1; i < N; i++) {
		int cur_element = max(V[0][i], V[1][i]);
		MAXSUM[i][0] = max(MAXSUM[i - 1][0], MAXSUM[i - 1][1]);
		MAXSUM[i][1] = cur_element + MAXSUM[i - 1][0];
	}
	return max(MAXSUM[N - 1][0], MAXSUM[N - 1][1]);
}
#endif