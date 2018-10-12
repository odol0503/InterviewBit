/*************************************************************************************************
Min Sum Path in Matrix

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right 
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
Example :

Input :
[  1 3 2
4 3 1
5 6 1
]

Output : 8
1 -> 3 -> 2 -> 1 -> 1
*************************************************************************************************/
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define OWN

#ifdef OWN
int MinSumPathInMatrix(vector<vector<int> > A) {
	int n = (int)A.size();
	if (n == 0) return 0;
	int m = (int)A[0].size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			if (i>0 && j>0) dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]);
			else if (j>0) dp[i][j] = dp[i][j - 1];
			else if (i>0) dp[i][j] = dp[i - 1][j];
			dp[i][j] += A[i][j];
		}
	}

	return dp[n - 1][m - 1];
}
#else
int MinSumPathInMatrix(vector<vector<int> > grid) {
	if (grid.size() == 0) return 0;
	int m = grid.size(), n = grid[0].size();
	int minPath[m + 1][n + 1];
	for (int i = 0; i < m; i++) {
		minPath[i][0] = grid[i][0];
		if (i > 0) minPath[i][0] += minPath[i - 1][0];
		for (int j = 1; j < n; j++) {
			minPath[i][j] = grid[i][j] + minPath[i][j - 1];
			if (i > 0) minPath[i][j] = min(minPath[i][j], grid[i][j] + minPath[i - 1][j]);
		}
	}
	return minPath[m - 1][n - 1];
}
#endif