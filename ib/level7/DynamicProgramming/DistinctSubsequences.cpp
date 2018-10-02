/*************************************************************************************************
Distinct Subsequences

Given two sequences S, T, count number of unique ways in sequence S, to form a subsequence 
that is identical to the sequence T.

Subsequence : A subsequence of a string is a new string which is formed from the original 
string by deleting some (can be none ) of the characters without disturbing the relative 
positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
Example :

S = "rabbbit"
T = "rabbit"
Return 3. And the formations as follows:

S1= "ra_bbit"
S2= "rab_bit"
S3="rabb_it"
"_" marks the removed character.
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
using namespace std;

#define OWN6

#ifdef OWN
int rec(string &A, string &B, int num, int cur, string &str, vector<vector<int>> &dp)
{
	if (num == 0)
	{
		if (B == str) return 1;
		return 0;
	}

	if (dp[cur][num - 1]) return dp[cur][num - 1];

	int cnt = 0;
	for (int i = cur; i<A.size(); i++)
	{
		if (A.size() - cur + 1 < num) break;
		if (B[str.size()] != A[i]) continue;
		str += A[i];
		cnt += rec(A, B, num - 1, i + 1, str, dp);
		str.pop_back();
	}

	if (cnt) dp[cur][num - 1] = cnt;
	return cnt;
}

int DistinctSubsequences(string A, string B) {
	int num = (int)B.size();
	string str;
	vector<vector<int>> dp(A.size() + 1, vector<int>(num + 1, 0));
	return rec(A, B, num, 0, str, dp);
}
#else
/**
* Solution (DP):
* We keep a m*n matrix and scanning through string S, while
* m = T.length() + 1 and n = S.length() + 1
* and each cell in matrix Path[i][j] means the number of distinct subsequences of
* T.substr(1...i) in S(1...j)
*
* Path[i][j] = Path[i][j-1]            (discard S[j])
*              +     Path[i-1][j-1]    (S[j] == T[i] and we are going to use S[j])
*                 or 0                 (S[j] != T[i] so we could not use S[j])
* while Path[0][j] = 1 and Path[i][0] = 0.
*/
int DistinctSubsequences(string S, string T) {
	int m = T.length();
	int n = S.length();
	if (m > n) return 0;    // impossible for subsequence
	vector<vector<int>> path(m + 1, vector<int>(n + 1, 0));
	for (int k = 0; k <= n; k++) path[0][k] = 1;    // initialization

	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= m; i++) {
			path[i][j] = path[i][j - 1] + (T[i - 1] == S[j - 1] ? path[i - 1][j - 1] : 0);
		}
	}

	return path[m][n];
}
#endif
