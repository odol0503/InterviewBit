/*************************************************************************************************
Regular Expression II

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:

int isMatch(const char *s, const char *p)
Some examples:

isMatch("aa","a") ¡æ 0
isMatch("aa","aa") ¡æ 1
isMatch("aaa","aa") ¡æ 0
isMatch("aa", "a*") ¡æ 1
isMatch("aa", ".*") ¡æ 1
isMatch("ab", ".*") ¡æ 1
isMatch("aab", "c*a*b") ¡æ 1
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;

#define OWN

#ifdef OWN
static int rec(const string &A, const string &B, int i, int j, vector<vector<bool>> &dp)
{
	if (i == 0 && (j == 0 || B[j - 1] == '*')) return 1;
	if (i == 0 || j == 0) return 0;

	if (dp[i][j] == false) return 0;

	if (A[i - 1] == B[j - 1] || B[j - 1] == '.')
	{
		if (rec(A, B, i - 1, j - 1, dp)) return 1;
	}

	if (B[j - 1] == '*')
	{
		if (rec(A, B, i, j - 2, dp)) return 1;

		if (A[i - 1] == B[j - 2] || B[j - 2] == '.')
		{
			if (rec(A, B, i - 1, j - 2, dp)) return 1;
			if (rec(A, B, i, j - 2, dp)) return 1;
			if (rec(A, B, i - 1, j, dp)) return 1;
		}
	}

	dp[i][j] = false;

	return 0;
}

int RegularExpression2(const string A, const string B) {
	vector<vector<bool>> dp(A.size() + 1, vector<bool>(B.size() + 1, true));
	return rec(A, B, A.size(), B.size(), dp);
}
#else
map<pair<int, int>, bool> dp;

bool match(const string *s, const string *p, int index1, int index2)
{
	if ((*s).length() == index1)return true;
	if ((*p).length() == index2)return false;
	if (dp.find(make_pair(index1, index2)) != dp.end())return dp[make_pair(index1, index2)];
	bool res = false;
	if (index2<(*p).length() - 1 && (*p)[index2 + 1] == '*')
	{
		if ((*s)[index1] == (*p)[index2] || (*p)[index2] == '.')
		{
			res = (res || match(s, p, index1 + 1, index2));
		}
		res = (res || match(s, p, index1, index2 + 2));
	}
	if ((*p)[index2] == '.')
	{
		res = (res || match(s, p, index1 + 1, index2 + 1));
	}
	if ((*s)[index1] == (*p)[index2] && (index2 == (*p).length() - 1 || ((index2< (*p).length() - 1) && ((*p)[index2 + 1] != '*'))))
	{
		res = (res || match(s, p, index1 + 1, index2 + 1));

	}
	dp[make_pair(index1, index2)] = res;
	return res;
}
int RegularExpression2(const string s, const string p) {
	dp.clear();
	if (match(&s, &p, 0, 0))return 1;
	else return 0;
}
#endif