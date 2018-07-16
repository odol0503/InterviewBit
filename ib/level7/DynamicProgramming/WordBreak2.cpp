/*************************************************************************************************
Word Break II

Given a string s and a dictionary of words dict, add spaces in s to construct a sentence 
where each word is a valid dictionary word.

Return all such possible sentences.

For example, given

s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].
A solution is

[
"cat sand dog",
"cats and dog"
]
Make sure the strings are sorted in your result.
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
static int word(string &A, vector<string> &B, int pos, vector<string> &str, vector<string> &ret, vector<int> &dp)
{
	int found = 0;
	int len = (int)A.size();
	if (len == pos)
	{
		string temp;
		for (int i = 0; i<str.size(); i++)
		{
			if (i>0) temp += ' ';
			temp += str[i];
		}
		ret.push_back(temp);
		return 1;
	}

	if (dp[pos] != -1) return dp[pos];

	for (int i = 0; i<B.size(); i++)
	{
		if (A.compare(pos, B[i].size(), B[i], 0, B[i].size()) == 0)
		{
			str.push_back(B[i]);
			found = word(A, B, pos + B[i].size(), str, ret, dp);
			str.pop_back();
		}
	}

	if (found == 0) dp[pos] = 0;
	return found;
}

vector<string> wordBreak2(string A, vector<string> &B) {
	vector<string> ret;
	vector<string> str;
	vector<int> dp(A.size() + 1, -1);
	sort(B.begin(), B.end());
	for (int i = 1; i<B.size(); i++)
	{
		if (B[i - 1] == B[i]) B.erase(B.begin() + i);
	}

	word(A, B, 0, str, ret, dp);

	return ret;
}
#else
vector<string> wordBreak2(string s, vector<string> &dictV) {
	unordered_set<string> dict(dictV.begin(), dictV.end());
	vector<vector<string> > words(s.length() + 1, vector<string>(0));

	// initialize the valid values
	words[s.length()].push_back("");

	// generate solutions from the end
	for (int i = s.length() - 1; i >= 0; i--) {
		vector<string> values;
		for (int j = i + 1; j <= s.length(); j++) {
			if (dict.find(s.substr(i, j - i)) != dict.end()) {
				for (int k = 0; k < words[j].size(); k++) {
					values.push_back(s.substr(i, j - i) + (words[j][k].empty() ? "" : " ") + words[j][k]);
				}
			}
		}
		words[i] = values;
	}
	return words[0];
}
#endif