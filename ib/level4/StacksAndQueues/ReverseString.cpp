/*************************************************************************************************
Reverse String

Given a string S, reverse the string using stack.

Example :
Input : "abc"
Return "cba"
*************************************************************************************************/
#include <stack>
using namespace std;

#define OWN

#ifdef OWN
string ReverseString(string A) {
	stack<char> st;
	string ret;

	for (int i = 0; i < (int)A.size(); i++)
	{
		st.push(A[i]);
	}

	while (!st.empty())
	{
		ret += st.top();
		st.pop();
	}

	return ret;
}
#else
string ReverseString(string s) {
	stack<char> st;
	// loop for push
	for (int i = 0; i < s.length(); i++) {
		st.push(s[i]);
	}
	// loop for pop
	for (int i = 0; i < s.length(); i++) {
		s[i] = st.top();
		st.pop();
	}
	return s;
		}
#endif