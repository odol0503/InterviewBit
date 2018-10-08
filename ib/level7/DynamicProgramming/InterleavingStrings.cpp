/*************************************************************************************************
Interleaving Strings
Asked in:
Google
Yahoo
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example,
Given:

s1 = "aabcc",
s2 = "dbbca",
When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
using namespace std;

#define OWN

#ifdef OWN
int rec(string &A, string &B, string &C, int i, int j, int k, vector<vector<vector<bool>>> &dp)
{
	if (i == 0 && j == 0 && k == 0) return 1;
	if (i<0 || j<0 || k<0) return 0;

	if (dp[i][j][k] == false) return 0;

	if (A[i - 1] == C[k - 1])
		if (rec(A, B, C, i - 1, j, k - 1, dp)) return 1;

	if (B[j - 1] == C[k - 1])
		if (rec(A, B, C, i, j - 1, k - 1, dp)) return 1;

	dp[i][j][k] = false;

	return 0;
}

int InterleavingStrings(string A, string B, string C) {
	vector<vector<vector<bool>>> dp(A.size() + 1, vector<vector<bool>>(B.size() + 1, vector<bool>(C.size() + 1, true)));
	return rec(A, B, C, A.size(), B.size(), C.size(), dp);
}
#elif OWN2
int InterleavingStrings(string A, string B, string C) {
	map<int, int> M1, M2;

	for (char a : A) M1[a]++;
	for (char b : B) M1[b]++;
	for (char c : C) M2[c]++;

	if (M1 == M2) return 1;
	return 0;
}
#else
string s1, s2, s3;
short memo[101][101][101];

bool isInterleave(int index1, int index2, int index3) {
	if (index1 == s1.length() && index2 == s2.length()) {
		return index3 == s3.length();
	}
	if (index3 >= s3.length()) return false;

	if (memo[index1][index2][index3] != -1) return memo[index1][index2][index3];

	bool answer = false;
	if (index1 < s1.length() && s1[index1] == s3[index3]) answer |= isInterleave(index1 + 1, index2, index3 + 1);
	if (index2 < s2.length() && s2[index2] == s3[index3]) answer |= isInterleave(index1, index2 + 1, index3 + 1);

	return memo[index1][index2][index3] = answer;
}

int InterleavingStrings(string S1, string S2, string S3) {
	s1 = S1;
	s2 = S2;
	s3 = S3;
	memset(memo, -1, sizeof(memo));
	if (S3.length() != S1.length() + S2.length()) return false;
	return isInterleave(0, 0, 0);
}
#endif