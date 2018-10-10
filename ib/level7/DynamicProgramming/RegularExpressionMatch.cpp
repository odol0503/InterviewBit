/*************************************************************************************************
Regular Expression Match

Implement wildcard pattern matching with support for '?' and '*'.

'?' : Matches any single character.
'*' : Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

The function prototype should be:

int isMatch(const char *s, const char *p)
Examples :
isMatch("aa","a") ¡æ 0
isMatch("aa","aa") ¡æ 1
isMatch("aaa","aa") ¡æ 0
isMatch("aa", "*") ¡æ 1
isMatch("aa", "a*") ¡æ 1
isMatch("ab", "?*") ¡æ 1
isMatch("aab", "c*a*b") ¡æ 0
Return 1/0 for this problem.
*************************************************************************************************/
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define OWN

#ifdef OWN
int rec(const string &A, const string &B, int i, int j, vector<vector<bool>> &dp)
{
	int ret = 0;

	if (A.size() == i && B.size() == j) return 1;

	if (dp[i][j] == false) return 0;

	if (A.size() == i)
	{
		if (B[j] == '*') return rec(A, B, i, j + 1, dp);
		else return 0;
	}

	if (B.size() == j)
	{
		if (A[i] == '*') return rec(A, B, i + 1, j, dp);
		else return 0;
	}

	if (A[i] == B[j] || A[i] == '?' || B[j] == '?')
	{
		if (rec(A, B, i + 1, j + 1, dp)) return 1;
	}
	else if (A[i] == '*' || B[j] == '*')
	{
		if (rec(A, B, i + 1, j + 1, dp)) return 1;
		if (rec(A, B, i, j + 1, dp)) return 1;
		if (rec(A, B, i + 1, j, dp)) return 1;
	}

	dp[i][j] = false;

	return 0;
}

int RegularExpressionMatch(const string A, const string B) {
	int lenA = (int)A.size();
	int lenB = (int)B.size();
	vector<vector<bool>> dp(A.size() + 1, vector<bool>(B.size() + 1, true));

	return rec(A, B, 0, 0, dp);
}
#else
map<pair<int, int>, int> M;
int suffixLen[50001], len1, len2;

bool helper(const char *s, const char *p, int index1, int index2) {
	// If we are at the end of both pattern and the string, then its obviously a match
	if (s[index1] == 0 && p[index2] == 0) return true;
	// If pattern ends, but the string hasn't, then its not a match
	if (p[index2] == 0) return false;
	// If string ends, then the only permissible character is '*' in the pattern array
	if (s[index1] == 0 && p[index2] != '*') return false;
	// If remaining non * characters in pattern are more than the total chars in s, there can't be match
	if (len1 - index1 < suffixLen[index2]) return false;
	// memoized result
	if (M.find(make_pair(index1, index2)) != M.end()) return M[make_pair(index1, index2)];
	// s has ended. We know next character in p is '*'. Lets check other following chars in p
	if (s[index1] == 0) return M[make_pair(index1, index2)] = helper(s, p, index1, index2 + 1);
	// characters match when pattern is not '*'
	if (s[index1] == p[index2] || p[index2] == '?') return M[make_pair(index1, index2)] = helper(s, p, index1 + 1, index2 + 1);
	// If pattern is '*', then explore both possibilities
	if (p[index2] == '*') return M[make_pair(index1, index2)] = (helper(s, p, index1 + 1, index2) || helper(s, p, index1, index2 + 1));
	return M[make_pair(index1, index2)] = false;
}

int RegularExpressionMatch(const string A, const string B) {
	const char *s = A.c_str();
	const char *p = B.c_str();
	M.clear();
	len1 = strlen(s);
	len2 = strlen(p);
	int cnt = 0;
	for (int i = len2 - 1; i >= 0; i--) {
		if (p[i] != '*') cnt++;
		suffixLen[i] = cnt;
	}
	return helper(s, p, 0, 0);
}
#endif