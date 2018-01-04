/*************************************************************************************************
Max Distance

Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].
If there is no solution possible, return -1.
Example :
A : [3 5 4 2]
Output : 2
for the pair (3, 4)
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int MaxDistance(const vector<int> &A)
{
	int len = static_cast<int>(A.size());
	vector<pair<int, int>> it(len);
	for (int i = 0; i < len; i++)
	{
		it[i] = make_pair(A[i], i);
	}

	sort(it.begin(), it.end());

	int max_idx = it[len - 1].second;
	int max_diff = 0;
	int diff = 0;
	for (int i = len - 2; i >= 0; i--)
	{
		diff = max_idx - it[i].second;
		max_diff = max(max_diff, diff);
		max_idx = max(max_idx, it[i].second);
	}

	return max_diff;
}