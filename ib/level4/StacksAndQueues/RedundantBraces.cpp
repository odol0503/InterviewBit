/*************************************************************************************************
Redundant Braces

Write a program to validate if the input string has redundant braces?
Return 0/1

0 -> NO
1 -> YES
Input will be always a valid expression

and operators allowed are only + , * , - , /

Example:

((a + b)) has redundant braces so answer will be 1
(a + (a + b)) doesn't have have any redundant braces so answer will be 0
*************************************************************************************************/
#include <stack>
using namespace std;

#define OWN5

#ifdef OWN
int RedundantBraces(string A) {
	int len = (int)A.size();
	stack<char> st;
	bool sub = false;

	for (int i = 0; i < len; i++)
	{
		if (A[i] != ')') st.push(A[i]);
		else
		{
			if (st.empty()) return 1;

			while (!st.empty())
			{
				char c = st.top();
				st.pop();
				if (c == '(')
				{
					if (sub)
					{
						sub = false;
						break;
					}
					else return 1;
				}
				else if (c == '+' || c=='-' || c=='*' || c=='/') sub = true;
			}
		}
	}
	return 0;
}
#else
int RedundantBraces(string str)
{
	int N = str.size();
	stack<char> Stk;

	for (int i = 0; i < N; ++i) {
		if (str[i] == ')') {
			int cnt = 0;
			while (Stk.top() != '(') {
				Stk.pop();
				cnt++;
			}
			Stk.pop();
			if (cnt < 2)
				return 1;
		}
		else {
			Stk.push(str[i]);
		}
	}

	bool is = true;
	while (Stk.size()) {
		if (Stk.top() == '(' || Stk.top() == ')') {
			is = false;
			break;
		}
		Stk.pop();
	}

	if (!is)
		return 1;
	return 0;
}
#endif