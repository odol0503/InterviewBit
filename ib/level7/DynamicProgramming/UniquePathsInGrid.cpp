/*************************************************************************************************
Unique Paths in a Grid

Given a grid of size m * n, lets assume you are starting at (1,1) and your goal is to reach (m,n).
At any instance, if you are on (x,y), you can either go to (x, y + 1) or (x + 1, y).

Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Example :
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
[0,0,0],
[0,1,0],
[0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*************************************************************************************************/
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define OWN5

#ifdef OWN
int UniquePathsInGrid(vector<vector<int> > A) {
	int r = (int)A.size();
	int c = (int)A[0].size();
	vector<vector<int>> dp(r, vector<int>(c, 0));

	if (A[0][0] != 1) dp[0][0] = 1;
	for (int i = 0; i<r; i++)
	{
		for (int j = 0; j<c; j++)
		{
			if (A[i][j] == 1) continue;
			if (i>0) dp[i][j] += dp[i - 1][j];
			if (j>0) dp[i][j] += dp[i][j - 1];
		}
	}

	return dp[r - 1][c - 1];
}
#else
int UniquePathsInGrid(vector<vector<int> > obstacleGrid) {
	int m = obstacleGrid.size(), n = obstacleGrid[0].size();
	vector<vector<int>> uniquePaths(m + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			uniquePaths[i][j] = 0;
			if (obstacleGrid[i][j]) continue;
			if (i == 0 && j == 0) uniquePaths[i][j] = 1;
			if (i > 0) uniquePaths[i][j] += uniquePaths[i - 1][j];
			if (j > 0) uniquePaths[i][j] += uniquePaths[i][j - 1];
		}
	}
	return uniquePaths[m - 1][n - 1];
		}
#endif