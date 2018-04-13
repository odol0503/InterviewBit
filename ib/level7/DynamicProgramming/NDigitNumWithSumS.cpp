/*************************************************************************************************
N digit numbers with digit sum S

Find out the number of N digit numbers, whose digits on being added equals to a given number S.
Note that a valid number starts from digits 1-9 except the number 0 itself. 
i.e. leading zeroes are not allowed.

Since the answer can be large, output answer modulo 1000000007

N = 2, S = 4
Valid numbers are {22, 31, 13, 40}
Hence output 4.
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
#define MOD 1000000007

static int sum(int A, int B, int depth, vector<vector<int>> &dp)
{
	if (A == 0)
	{
		if (B == 0) return 1;
		else return 0;
	}

	if (dp[A - 1][B] != -1)
	{
		return dp[A - 1][B] % MOD;
	}

	int cnt = 0;
	for (int i = 0; i <= 9 && i <= B; i++)
	{
		if (depth == 0 && i == 0) continue;

		cnt = (cnt + sum(A - 1, B - i, depth + 1, dp)) % MOD;
	}

	dp[A - 1][B] = cnt;

	return cnt;
}


int digitNumWithSum(int A, int B) {
	vector<vector<int>> dp(A, vector<int>(B + 1, -1));
	return sum(A, B, 0, dp);
}
#else
int rec(vector<vector<int > > &dp, int id, int sum) {
	if (sum < 0) return 0;
	if (id == 0 && sum == 0) return 1;
	if (id == 0) return 0;

	if (dp[id][sum] != -1) return dp[id][sum];

	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += rec(dp, id - 1, sum - i);
		ans %= 1000000007;
	}
	return dp[id][sum] = ans;
}

int digitNumWithSum(int A, int B) {
	int ans = 0;
	vector<vector<int> > dp;
	dp.resize(A + 1);
	for (int i = 0; i < A + 1; i++) {
		dp[i].resize(B + 1);
		for (int j = 0; j < B + 1; j++)
			dp[i][j] = -1;
	}
	for (int i = 1; i < 10; i++) {
		ans += rec(dp, A - 1, B - i);
		ans %= 1000000007;
	}
	return ans;
}
#endif