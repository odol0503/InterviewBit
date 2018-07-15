/*************************************************************************************************
Word Break

Given a string s and a dictionary of words dict, determine if s can be segmented 
into a space-separated sequence of one or more dictionary words.

For example, given

s = "myinterviewtrainer",
dict = ["trainer", "my", "interview"].
Return 1 ( corresponding to true ) because "myinterviewtrainer" can be segmented 
as "my interview trainer".

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
int checkWord(string &A, vector<string> &B, int pos, vector<int> &dp)
{
	if (pos == A.size()) return 1;

	if (dp[pos] != -1) return 0;

	for (int i = 0; i<B.size(); i++)
	{
		if (A.compare(pos, B[i].size(), B[i], 0, string::npos) == 0)
		{
			if (checkWord(A, B, pos + B[i].size(), dp)) return 1;
		}
	}

	dp[pos] = 0;
	return 0;
}

int WordBreak(string A, vector<string> &B) {
	vector<int> dp(A.size() + 1, -1);
	return checkWord(A, B, 0, dp);
}
#else
short memoize[100001];

bool wordBreak(int index, string &s, unordered_set<string> &dict) {
	if (index >= s.length()) return true;
	if (memoize[index] != -1) return memoize[index];
	bool result = false;
	// try to construct all substrings. 
	string substring = "";
	for (int i = index; i < s.length() && result == false; i++) {
		substring.push_back(s[i]);
		if (dict.find(substring) != dict.end()) {
			result |= wordBreak(i + 1, s, dict);
		}
	}
	return memoize[index] = result;
}

bool wordBreak(string s, vector<string> &dict) {
	memset(memoize, -1, sizeof(int) * s.length());
	unordered_set<string> dictSet(dict.begin(), dict.end());
	return wordBreak(0, s, dictSet);
}
#endif