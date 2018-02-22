/*************************************************************************************************
Generate All Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid 
but "(]" and "([)]" are not.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

PROBLEM APPROACH :
Complete solution in hints.
*************************************************************************************************/
#include <vector>
#include <stack>
#include <map>
using namespace std;

#define OWN

#ifdef OWN
int GenerateAllParentheses(string A) 
{
	int len = (int)A.size();
	vector<char> stacks;
	int ret = 0;

	for (int i = 0; i < len; i++)
	{
		if (A[i] == '[' || A[i] == '{' || A[i] == '(')
		{
			stacks.push_back(A[i]);
		}

		if (A[i] == ']' || A[i] == '}' || A[i] == ')')
		{
			if (stacks.empty()) return 0;

			if (A[i] == ']')
			{
				if (stacks.back() != '[') return 0;
			}
			else if (A[i] == '}')
			{
				if (stacks.back() != '{') return 0;
			}
			else if (A[i] == ')')
			{
				if (stacks.back() != '(') return 0;
			}
			stacks.pop_back();
			ret = 1;
		}
	}
	return ret;
}
#else
int GenerateAllParentheses(string s) {
	stack<char> st;
	map<char, char> matchingBracket;
	matchingBracket['{'] = '}';
	matchingBracket['['] = ']';
	matchingBracket['('] = ')';
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			st.push(s[i]);
		}
		else if (st.empty() || matchingBracket[st.top()] != s[i]) {
			return false;
		}
		else {
			st.pop();
		}
	}
	return st.empty();
}
#endif