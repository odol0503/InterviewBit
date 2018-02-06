/*************************************************************************************************
Longest Palindromic Substring

Given a string S, find the longest palindromic substring in S.

Substring of string S:
S[i...j] where 0 <= i <= j < len(S)

Palindrome string:
A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.
Incase of conflict, return the substring which occurs first ( with the least starting index ).

Example :
Input : "aaaabaaa"
Output : "aaabaaa"
*************************************************************************************************/
#include <algorithm>
#include <string>
using namespace std;

#define OWN

#ifdef OWN
bool IsParindrome(string &&A)
{
	int len = (int)A.size();
	if (len == 0) return false;
	for (int i = 0; i < len; i++)
	{
		if (A[i] != A[len - i - 1]) return false;
	}
	return true;
}

string LongestPalindrome(string A) {
	int len = (int)A.size();
	int max_len = 0;
	string ret;

	if (len == 0) return "";
	else if (len == 1) return A;

	for (int i = len; i >= 1; i--)
	{
		for (int j = 0; j < i; j++)
		{
			string temp = A.substr(j, i - j);
			if (IsParindrome(move(temp)))
			{
				if (max_len <= i - j)
				{
					ret = temp;
					max_len = i - j;
				}
			}
		}
	}
	return ret;
}
#else
string expandAroundCenter(string s, int c1, int c2) {
	int l = c1, r = c2;
	int n = s.length();
	while (l >= 0 && r <= n - 1 && s[l] == s[r]) {
		l--;
		r++;
	}
	return s.substr(l + 1, r - l - 1);
}

string LongestPalindrome(string s) {
	int n = s.length();
	if (n == 0) return "";
	string longest = s.substr(0, 1);  // a single char itself is a palindrome
	for (int i = 0; i < n - 1; i++) {
		string p1 = expandAroundCenter(s, i, i);
		if (p1.length() > longest.length())
			longest = p1;

		string p2 = expandAroundCenter(s, i, i + 1);
		if (p2.length() > longest.length())
			longest = p2;
	}
	return longest;
}
#endif