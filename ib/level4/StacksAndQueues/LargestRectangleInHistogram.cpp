/*************************************************************************************************
Largest Rectangle In Histogram

Given n non-negative integers representing the histogram¡¯s bar height 
where the width of each bar is 1, find the area of largest rectangle in the histogram.

Largest Rectangle in Histogram: Example 1
Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

Largest Rectangle in Histogram: Example 2
The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*************************************************************************************************/
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
int LargestRectangleArea(vector<int> &A) {
	int len = (int)A.size();
	unordered_set<int> h;
	int max_value = 0;

	for (auto &a : A) h.insert(a);

	for (auto it = h.begin(); it != h.end(); it++)
	{
		int cnt = 0;
		for (int i = 0; i<len; i++)
		{
			if (A[i] >= *it) cnt++;
			else if (cnt > 0)
			{
				max_value = max(max_value, *it*cnt);
				cnt = 0;
			}
			else cnt = 0;
		}
		if (cnt > 0) max_value = max(max_value, *it*cnt);
	}
	return max_value;
}
#else
int LargestRectangleArea(vector<int> &height) {

	int ret = 0;
	height.push_back(0);
	vector<int> index;

	for (int i = 0; i < height.size(); i++)
	{
		while (index.size() > 0 && height[index.back()] >= height[i])
		{
			int h = height[index.back()];
			index.pop_back();

			int sidx = index.size() > 0 ? index.back() : -1;
			if (h * (i - sidx - 1) > ret)
				ret = h * (i - sidx - 1);
		}
		index.push_back(i);
	}

	return ret;
}
#endif