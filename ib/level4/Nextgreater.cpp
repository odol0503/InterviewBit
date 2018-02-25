/*************************************************************************************************
Next Greater

Given an array, find the next greater element G[i] for every element A[i] in the array. 
The Next greater Element for an element A[i] is the first greater element 
on the right side of A[i] in array.

More formally,
G[i] for an element A[i] = an element A[j] such that
j is minimum possible AND
j > i AND
A[j] > A[i]
Elements for which no greater element exist, consider next greater element as -1.

Example:
Input : A : [4, 5, 2, 10]
Output : [5, 10, 10, -1]

Example 2:
Input : A : [3, 2, 1]
Output : [-1, -1, -1]
*************************************************************************************************/
#include <vector>
#include <stack>
#include <string>
using namespace std;

#define OWN

#ifdef OWN
vector<int> NextGreater(vector<int> &A) {
	int len = (int)A.size();
	stack<int>st;
	vector<int> ret(len, -1);

	for (int i = len - 1; i >= 0; i--)
	{
		while (!st.empty() && st.top() <= A[i])
		{
			st.pop();
		}

		if (!st.empty()) ret[i] = st.top();
		st.push(A[i]);
	}

	return ret;
}
#else

#endif