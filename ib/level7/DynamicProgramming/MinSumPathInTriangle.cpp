/*************************************************************************************************
Min Sum Path in Triangle
Given a triangle, find the minimum path sum from top to bottom. 
Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, 
where n is the total number of rows in the triangle.
*************************************************************************************************/
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define OWN

#ifdef OWN
int MinSumPathInTriangle(vector<vector<int> > A) {
	int n = (int)A.size();
	vector<vector<int>> dp;
	for (int i = 1; i <= n; i++)
	{
		dp.push_back(vector<int>(i, 0));
	}

	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (i>0)
			{
				if (j == 0) dp[i][j] = dp[i - 1][j];
				else if (j == i) dp[i][j] = dp[i - 1][j - 1];
				else dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]);
			}

			dp[i][j] += A[i][j];
		}
	}

	return *min_element(dp[n - 1].begin(), dp[n - 1].end());
}
#else
int MinSumPathInTriangle(vector<vector<int> > triangle) {
	int n = triangle.size();
	vector<int> minlen(triangle.back());
	for (int layer = n - 2; layer >= 0; layer--) // For each layer
	{
		for (int i = 0; i <= layer; i++) // Check its every 'node'
		{
			// Find the lesser of its two children, and sum the current value in the triangle with it.
			minlen[i] = min(minlen[i], minlen[i + 1]) + triangle[layer][i];
		}
	}
	return minlen[0];
}
#endif