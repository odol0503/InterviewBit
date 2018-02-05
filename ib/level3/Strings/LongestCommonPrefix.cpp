/*************************************************************************************************
Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.
Longest common prefix for a pair of strings S1 and S2 is the longest string S which is
the prefix of both S1 and S2.
As an example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".
Given the array of strings, you need to find the longest S which is the prefix of ALL
the strings in the array.

Example:
Given the array as:
[
"abcdefgh",
"aefghijk",
"abcefgh"
]
The answer would be ¡°a¡±.
*************************************************************************************************/
#include <vector>
using namespace std;

#define OWN

#ifdef OWN
string LongestCommonPrefix(vector<string> &A) 
{
	int num = (int)A.size();
	int len = (int)A[0].size();
	bool same_char = true;
	string ret;

	for (int i = 0; i < len; i++)
	{
		for (int j = 1; j < num; j++)
		{
			if (A[j].length() <= i || A[0][i] != A[j][i])
			{
				same_char = false;
				break;
			}
			same_char = true;
		}
		if (same_char == false) break;
		ret.push_back(A[0][i]);
	}

	return ret;
}
#else
string LongestCommonPrefix(vector<string> &A)
{
	if (strs.size() == 0) return "";
	string ans = "";
	for (int i = 0; i < strs[0].length(); i++) {
		// checking if character i qualifies to be in the answer. 
		bool isQualified = true;
		for (int j = 1; j < strs.size(); j++) {
			if (i >= strs[j].length() || strs[j][i] != strs[0][i]) {
				isQualified = false;
				break;
			}
		}
		if (!isQualified) break;
		ans.push_back(strs[0][i]);
	}
	return ans;
}
#endif