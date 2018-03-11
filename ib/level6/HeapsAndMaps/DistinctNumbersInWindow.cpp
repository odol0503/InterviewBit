/*************************************************************************************************
Distinct Numbers in Window

You are given an array of N integers, A1, A2 ,¡¦, AN and an integer K. 
Return the of count of distinct numbers in all windows of size K.

Formally, return an array of size N-K+1 where i¡¯th element 
in this array contains number of distinct elements in sequence Ai, Ai+1 ,¡¦, Ai+k-1.

Note:
If K > N, return empty array.
For example,

A=[1, 2, 1, 3, 4, 3] and K = 3

All windows of size K are

[1, 2, 1]
[2, 1, 3]
[1, 3, 4]
[3, 4, 3]

So, we return an array [2, 3, 3, 2].
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>
#include <functional>
#include <iostream>
#include <cassert>
using namespace std;

#define OWN

#ifdef OWN
vector<int> DistinctNumbersInWindow(vector<int> &A, int B) {
	vector<int> ret;
	int len = (int)A.size();
	if (len < B) return ret;
	unordered_map<int, int> window;
	
	for (int i = 0; i<B; i++)
	{
		window[A[i]]++;
	}
	ret.push_back((int)window.size());

	for (int i = 1; i<len - B + 1; i++)
	{
		if (window[A[i - 1]] == 1) window.erase(A[i - 1]);
		else window[A[i - 1]]--;
		window[A[i + B - 1]]++;
		ret.push_back((int)window.size());
	}

	return ret;
}
#else
vector<int> DistinctNumbersInWindow(vector<int> &A, int B) {
	assert(B <= A.size());
	int n = A.size();
	vector<int> ret;
	unordered_map <int, int> m;
	for (int i = 0; i<n; i++) {
		//increase key
		m[A[i]]++;
		if (i - B + 1 >= 0) {

			//decrease key
			ret.push_back(m.size());
			m[A[i - B + 1]]--;

			//remove if count becomes 0
			if (m[A[i - B + 1]] == 0)m.erase(A[i - B + 1]);
		}
	}
	return ret;
}
#endif

