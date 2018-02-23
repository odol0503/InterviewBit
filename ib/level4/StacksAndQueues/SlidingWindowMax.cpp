/*************************************************************************************************
Sliding Window Maximum

A long array A[] is given to you. There is a sliding window of size w 
which is moving from the very left of the array to the very right. 
You can only see the w numbers in the window. 
Each time the sliding window moves rightwards by one position. 
You have to find the maximum for each window. 
The following example will give you more clarity.

Example :
The array is [1 3 -1 -3 5 3 6 7], and w is 3.

Window position	Max
[1 3 -1] -3 5 3 6 7	 | 3
1 [3 -1 -3] 5 3 6 7	 | 3
1 3 [-1 -3 5] 3 6 7	 | 5
1 3 -1 [-3 5 3] 6 7	 | 5
1 3 -1 -3 [5 3 6] 7	 | 6
1 3 -1 -3 5 [3 6 7]	 | 7

Input: A long array A[], and a window width w
Output: An array B[], B[i] is the maximum value of from A[i] to A[i+w-1]
Requirement: Find a good optimal way to get B[i]

Note: If w > length of the array, return 1 element with the max of the array.
*************************************************************************************************/
#include <vector>
#include <deque>
#include <utility>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
vector<int> SlidingWindowMax(const vector<int> &A, int B) {
	int len = (int)A.size();
	deque<pair<int, int>> w;
	vector<int> ret;

	if (len <= B)
	{
		int max_val = 0;
		for (int i = 0; i < len; i++) max_val = max(max_val, A[i]);
		ret.push_back(max_val);
		return ret;
	}

	for (int i = 0; i < len; i++)
	{
		while (!w.empty() && w.front().first < i-B+1) w.pop_front();

		while (!w.empty() && w.back().second < A[i]) w.pop_back();

		w.push_back(make_pair(i, A[i]));

		if (i >= B - 1)
		{
			ret.push_back(w.front().second);
		}
	}

	return ret;
}
#else
vector<int> SlidingWindowMax(const vector<int> &A, int w) {
	int n = A.size();
	vector<int> B;
	if (n < w) return B;
	B.resize(n - w + 1);
	deque<int> Q;
	for (int i = 0; i < w; i++) {
		while (!Q.empty() && A[i] >= A[Q.back()])
			Q.pop_back();
		Q.push_back(i);
	}
	for (int i = w; i < n; i++) {
		B[i - w] = A[Q.front()];
		while (!Q.empty() && A[i] >= A[Q.back()])
			Q.pop_back();
		while (!Q.empty() && Q.front() <= i - w)
			Q.pop_front();
		Q.push_back(i);
			}
	B[n - w] = A[Q.front()];
	return B;
		}
#endif