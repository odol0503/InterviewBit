/*************************************************************************************************
Arrange II

You are given a sequence of black and white horses, and a set of K stables numbered 1 to K. 
You have to accommodate the horses into the stables in such a way that the following 
conditions are satisfied:

You fill the horses into the stables preserving the relative order of horses. 
For instance, you cannot put horse 1 into stable 2 and horse 2 into stable 1. 
You have to preserve the ordering of the horses.
No stable should be empty and no horse should be left unaccommodated.
Take the product (number of white horses * number of black horses) for each stable and take 
the sum of all these products. This value should be the minimum among all possible 
accommodation arrangements

Example:
Input: {WWWB} , K = 2
Output: 0

Explanation:
We have 3 choices {W, WWB}, {WW, WB}, {WWW, B}
for first choice we will get 1*0 + 2*1 = 2.
for second choice we will get 2*0 + 1*1 = 1.
for third choice we will get 3*0 + 0*1 = 0.

Of the 3 choices, the third choice is the best option.

If a solution is not possible, then return -1
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
using namespace std;

#define OWN

#ifdef OWN
int getVal(string &A, int pos, int num)
{
	int w = 0;
	int b = 0;
	for (int i = pos; i<pos + num; i++)
	{
		if (A[i] == 'W') w++;
		else b++;
	}

	return w * b;
}

int rec(string &A, int B, int pos, vector<vector<int>> &dp)
{
	int num = (int)A.size();
	int min_val = INT_MAX;

	if (pos >= num) return min_val;

	if (dp[B - 1][pos] != -1) return dp[B - 1][pos];

	if (B == 1)
	{
		return getVal(A, pos, num - pos);
	}

	for (int i = 1; i <= num - pos; i++)
	{
		int val = rec(A, B - 1, pos + i, dp);
		if (val == INT_MAX) continue;
		min_val = min(min_val, getVal(A, pos, i) + val);
	}

	dp[B - 1][pos] = min_val;

	return min_val;
}

int arrange2(string A, int B) {
	vector<vector<int>> dp(B, vector<int>(A.size(), -1));
	int ret = rec(A, B, 0, dp);
	if (ret == INT_MAX) return -1;
	return ret;
}
#else
vector<vector<int> > dp;

int rec(int start, int stables, string str, int K) {
	int N = str.size();
	if (start == N) {
		if (stables == K)
			return 0;
		return INT_MAX;
	}

	if (stables == K)
		return INT_MAX;

	if (dp[start][stables] != -1)
		return dp[start][stables];

	int W = 0;
	int B = 0;
	int ans = INT_MAX;

	for (int i = start; i < N; ++i) {
		W += str[i] == 'W';
		B += str[i] == 'B';
		if (W * B > ans) break;
		int Temp = rec(i + 1, stables + 1, str, K);
		if (Temp != INT_MAX) {
			ans = min(ans, Temp + (W * B));
		}
	}

	return dp[start][stables] = ans;
	}

int arrange2(string str, int K) {
	int N = str.size();
	dp.clear();
	dp.resize(N, vector<int>(K, -1));

	int ans = rec(0, 0, str, K);
	return ans == INT_MAX ? -1 : ans;
}
#endif