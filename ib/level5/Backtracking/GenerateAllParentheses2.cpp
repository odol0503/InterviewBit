/*************************************************************************************************
Generate all Parentheses 2

Given n pairs of parentheses, write a function to generate all combinations 
of well-formed parentheses of length 2*n.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
Make sure the returned list of strings are sorted.
*************************************************************************************************/
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

#define OWN

#ifdef OWN
static bool IsValid(string A)
{
	int len = (int)A.size();
	stack<char> st;

	for (int i = 0; i < len; i++)
	{
		if (A[i] == '(') st.push('(');
		else
		{
			if (st.empty() || st.top() != '(') return false;
			st.pop();
		}
	}

	if (!st.empty()) return false;
	return true;
}

static string Parenthesis("()");

static void CombParenthesis(int A, int idx,vector<string> &comb)
{
	if (A * 2 == idx)
	{
		if (IsValid(comb.back()) == false) comb.pop_back();
		return;
	}

	string sub;
	if (!comb.empty())
	{
		sub = comb.back();
		comb.pop_back();
	}

	for (int i = 0; i < 2; i++)
	{
		sub += Parenthesis[i];
		comb.push_back(sub);
		CombParenthesis(A, idx + 1, comb);
		sub.pop_back();
	}
}

vector<string> GenerateParenthesis(int A) {
	vector<string> ret;

	CombParenthesis(A, 0, ret);

	return ret;
}
#else
void generateHelper(string &current, int numOpenBrackets, int numClosedBrackets, int n, vector<string> &ans) {
	if (numOpenBrackets == numClosedBrackets && numOpenBrackets == n) {
		ans.push_back(current);
		return;
			}
	if (numOpenBrackets > n || numClosedBrackets > n) {
		// Invalid. 
		return;
	}

	// Now we have 2 options. We can either add '(' to the string or add ')' to the string. 
	// Option 1. Add '(' 
	if (numOpenBrackets < n) {
		current.push_back('(');
		generateHelper(current, numOpenBrackets + 1, numClosedBrackets, n, ans);
		current.pop_back();
	}
	// Option 2. Add ')'
	if (numClosedBrackets < numOpenBrackets) {
		current.push_back(')');
		generateHelper(current, numOpenBrackets, numClosedBrackets + 1, n, ans);
		current.pop_back();
	}
		}

vector<string> GenerateParenthesis(int n) {
	vector<string> ans;
	string current = "";
	int numOpenBrackets = 0, numClosedBrackets = 0;
	generateHelper(current, numOpenBrackets, numClosedBrackets, n, ans);
	return ans;
}
#endif