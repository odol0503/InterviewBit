/*************************************************************************************************
Rain Water Trapped

Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.

Example :
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

Rain water trapped: Example 1

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
In this case, 6 units of rain water (blue section) are being trapped.
*************************************************************************************************/
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
int RainWaterTrapped(const vector<int> &A) {
	int len = (int)A.size();
	int area = 0;
	int max_height = *max_element(A.begin(), A.end());

	for (int i = 1; i <= max_height; i++)
	{
		int cnt = 0;
		int started = 0;
		for (int j = 0; j < len; j++)
		{
			if (A[j] >= i)
			{
				if (started) area += cnt;
				cnt = 0;
				started = 1;
			}
			else if (started) cnt++;
		}
	}

	return area;
}
#else
int RainWaterTrapped(const vector<int> &A) {
	int result = 0;
	if (A.size() < 3) return 0;
	int i = 0, j = A.size() - 1;
	int maxLeft = A[i], maxRight = A[j];
	while (i < j) {
		if (A[i] < A[j]) {
			maxLeft = max(maxLeft, A[++i]);
			result += maxLeft - A[i];
		}
		else {
			maxRight = max(maxRight, A[--j]);
			result += maxRight - A[j];
		}
	}
	return result;
}
#endif