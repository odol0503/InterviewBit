/*************************************************************************************************
Longest Substring Without Repeat

Given a string,
find the length of the longest substring without repeating characters.

Example:
The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.
*************************************************************************************************/
#include <algorithm>
#include <string>
#include <map>
using namespace std;

#define OWN

#ifdef OWN
int LongestSubstringWithoutRepeating(string A) {
	int len = (int)A.size();
	map<int, int> M;
	int max_len = 0;
	int last_idx = -1;

	if (len == 1) return 1;

	for (int i = 0; i<len; i++)
	{
		if (i>0)
		{
			if (M.count(A[i]))
			{
				last_idx = max(last_idx, M[A[i]]);
			}

			int num = i - last_idx;
			max_len = max(max_len, num);
		}

		M[A[i]] = i;
	}
	return max_len;
}
#else
int LongestSubstringWithoutRepeating(string s) {
	int start = 0, end = 0;
	int longest = 0;

	// Hash which tracks the count of each character in the current window. 
	// We need to make sure that for a solution, none of the 
	// character count / hash value exceeds 1. 
	int hash[260];
	memset(hash, 0, sizeof(hash));

	while (start <= end && end < s.length()) {
		hash[s[end]]++;
		if (hash[s[end]] > 1) {
			// pop stuff out of hash till the count becomes 1.  
			while (start <= end && hash[s[end]] > 1) {
				hash[s[start]]--;
				start++;
			}
		}
		end++;
		longest = max(longest, end - start);
	}
	return longest;
}
#endif