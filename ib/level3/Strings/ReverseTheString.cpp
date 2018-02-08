/*************************************************************************************************
Reverse the String

Given an input string, reverse the string word by word.

Example:

Given s = "the sky is blue",

return "blue is sky the".

A sequence of non-space characters constitutes a word.
Your reversed string should not contain leading or trailing spaces, even if it is present 
in the input string.
If there are multiple spaces between words, reduce them to a single space in the reversed string.
*************************************************************************************************/
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
string ReverseWords(string &A) {
	int len = (int)A.size();
	char *str = new char[len + 1];
	strcpy(str, A.c_str());
	
	vector<string> list;
	char *temp = strtok(str, " ");
	while (temp)
	{
		list.push_back(string(temp));
		temp = strtok(nullptr, " ");
	}

	delete[] str;
	reverse(list.begin(), list.end());
	
	A.clear();
	for (auto l : list) A = A + l + " ";
	A.pop_back();
	return A;
}
#else
string ReverseWords(string &s) {
	string ans = "";
	string cur = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == ' ') {
			if (cur.length() == 0) {
				continue;
			}
			// found a word 
			reverse(cur.begin(), cur.end());
			if (ans.length() > 0) {
				ans.push_back(' ');
			}
			ans += cur;
			cur = "";
			continue;
		}
		cur.push_back(s[i]);
	}
	if (cur.length() > 0) {
		reverse(cur.begin(), cur.end());
		if (ans.length() > 0) {
			ans.push_back(' ');
		}
		ans += cur;
	}
	s = ans;
	return s;
}
#endif