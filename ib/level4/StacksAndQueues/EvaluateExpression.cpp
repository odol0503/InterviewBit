/*************************************************************************************************
Evaluate Expression

Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Examples:

["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*************************************************************************************************/
#include <vector>
#include <stack>
#include <string>
using namespace std;

#define OWN

#ifdef OWN
int EvaluateExpression(vector<string> &A) {
	stack<int> st;
	int len = (int)A.size();
	int ret = 0;

	for (int i = 0; i < len; i++)
	{
		if (A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/")
		{
			int post = st.top();
			st.pop();
			int pre = st.top();
			st.pop();

			if (A[i] == "+") st.push(pre + post);
			else if (A[i] == "-") st.push(pre - post);
			else if (A[i] == "*") st.push(pre * post);
			else if (A[i] == "/") st.push(pre / post);
		}
		else
		{
			st.push(stoi(A[i]));
		}
	}

	return st.top();
}
#else
int EvaluateExpression(vector<string> &tokens) {
	stack<int> st;
	for (int i = 0; i < tokens.size(); ++i) {
		if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
			int v1 = st.top();
			st.pop();
			int v2 = st.top();
			st.pop();
			switch (tokens[i][0]) {
			case '+':
				st.push(v2 + v1);
				break;
			case '-':
				st.push(v2 - v1);
				break;
			case '*':
				st.push(v2 * v1);
				break;
			case '/':
				st.push(v2 / v1);
				break;
			}
		}
		else {
			st.push(atoi(tokens[i].c_str()));
		}
	}
	return st.top();
}
#endif