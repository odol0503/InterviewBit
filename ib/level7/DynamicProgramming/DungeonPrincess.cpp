/*************************************************************************************************
Dungeon Princess

The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon.
The dungeon consists of M x N rooms laid out in a 2D grid. 
Our valiant knight (K) was initially positioned in the top-left room and must fight his way 
through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. 
If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) 
upon entering these rooms; other rooms are either empty (0¡¯s) or contain magic orbs 
that increase the knight¡¯s health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move 
only rightward or downward in each step.

Write a function to determine the knight¡¯s minimum initial health so that he is able 
to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be 
at least 7 if he follows the optimal path

RIGHT-> RIGHT -> DOWN -> DOWN.

  | -2 |  -3 |  3 |
  | -5 | -10 |  1 |
  | 10 |  30 | -5 |
  
Dungeon Princess: Example 1

Input arguments to function:
Your function will get an M*N matrix (2-D array) as input which represents the 2D grid 
as described in the question. Your function should return an integer corresponding 
to the knight¡¯s minimum initial health required.

Note:
The knight¡¯s health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and 
the bottom-right room where the princess is imprisoned.
*************************************************************************************************/
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define OWN

#ifdef OWN
int DungeonPrincess(vector<vector<int> > A) {
	if (A.empty()) return 0;
	int n = (int)A.size();
	int m = (int)A[0].size();
	vector<vector<int>> dp(n, vector<int>(m, 0));

	bool positive = true;
	int prev = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = m - 1; j >= 0; j--)
		{
			if (i<n - 1 && j<m - 1) dp[i][j] = max((dp[i + 1][j] > 0 ? 0 : dp[i + 1][j]), (dp[i][j + 1] > 0 ? 0 : dp[i][j + 1]));
			else if (j<m - 1) dp[i][j] = (dp[i][j + 1] > 0 ? 0 : dp[i][j + 1]);
			else if (i<n - 1) dp[i][j] = (dp[i + 1][j] > 0 ? 0 : dp[i + 1][j]);

			prev = dp[i][j] += A[i][j];
		}
	}

	if (dp[0][0] >= 0) return 1;
	return abs(dp[0][0]) + 1;
}
#else
int DungeonPrincess(vector<vector<int> > dungeon) {
	int M = dungeon.size();
	int N = dungeon[0].size();
	// hp[i][j] represents the min hp needed at position (i, j)
	// Add dummy row and column at bottom and right side
	vector<vector<int> > hp(M + 1, vector<int>(N + 1, INT_MAX));
	hp[M][N - 1] = 1;
	hp[M - 1][N] = 1;
	for (int i = M - 1; i >= 0; i--) {
		for (int j = N - 1; j >= 0; j--) {
			int need = min(hp[i + 1][j], hp[i][j + 1]) - dungeon[i][j];
			hp[i][j] = need <= 0 ? 1 : need;
		}
	}
	return hp[0][0];
		}
#endif