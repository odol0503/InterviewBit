/*************************************************************************************************
Nearest Smaller Element
Given an array, find the nearest smaller element G[i] for every element A[i] in the array 
such that the element has an index smaller than i.

More formally,

G[i] for an element A[i] = an element A[j] such that
j is maximum possible AND
j < i AND
A[j] < A[i]
Elements for which no smaller element exist, consider next smaller element as -1.

Example:

Input : A : [4, 5, 2, 10, 8]
Return : [-1, 4, -1, 2, 2]

Example 2:

Input : A : [3, 2, 1]
Return : [-1, -1, -1]
*************************************************************************************************/
#include <stack>
#include <vector>
using namespace std;

#define OWN

#ifdef OWN
vector<int> NearestSmallerElement(vector<int> &A) {
	int len = (int)A.size();
	stack<int> st;
	vector<int> ret(len, -1);
	vector<int> temp;

	for (int i = 0; i < len; i++)
	{
		while (!st.empty())
		{
			if (st.top() < A[i])
			{
				ret[i] = st.top();
				break;
			}
			else st.pop();
		}

		st.push(A[i]);
	}

	return ret;
}
#else
vector<int> NearestSmallerElement(vector<int> &A) {
	vector<int> ans;
	ans.resize(A.size());

	stack<int> st;

	for (int i = 0; i < A.size(); i++) {
		while (!st.empty() && st.top() >= A[i]) st.pop();
		if (st.empty()) {
			ans[i] = -1;
		}
		else {
			ans[i] = st.top();
		}
		st.push(A[i]);
	}
	return ans;
}
#endif