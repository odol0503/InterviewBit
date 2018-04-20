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

#define OWN

#ifdef OWN
int MaxDistance(const vector<int> &A)
{
	int ret = 0;
	vector<pair<int, int>> B;

	for (int i = 0; i<(int)A.size(); i++)
	{
		B.push_back({ A[i], i });
	}
	sort(B.begin(), B.end());

	int max_idx = B[B.size() - 1].second;
	for (int i = (int)B.size() - 2; i >= 0; i--)
	{
		int diff = max_idx - B[i].second;
		if (diff < 0)
		{
			max_idx = B[i].second;
			continue;
		}
		ret = max(ret, diff);
	}

	return ret;
}
#else
int MaxDistance(const vector<int> &num) {
	if (num.size() == 0) return -1;
	if (num.size() == 1) return 0;
	vector<pair<int, int> > toSort;
	for (int i = 0; i < num.size(); i++) {
		toSort.push_back(make_pair(num[i], i));
	}
	sort(toSort.begin(), toSort.end());
	int len = toSort.size();
	int maxIndex = toSort[len - 1].second;
	int ans = 0;
	for (int i = len - 2; i >= 0; i--) {
		ans = max(ans, maxIndex - toSort[i].second);
		maxIndex = max(maxIndex, toSort[i].second);
	}
	return ans;
}
#endif