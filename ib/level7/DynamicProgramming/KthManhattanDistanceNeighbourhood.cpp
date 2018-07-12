/*************************************************************************************************
Kth Manhattan Distance Neighbourhood

Given a matrix M of size nxm and an integer K, find the maximum element 
in the K manhattan distance neighbourhood for all elements in nxm matrix.
In other words, for every element M[i][j] find the maximum element M[p][q] 
such that abs(i-p)+abs(j-q) <= K.

Note: Expected time complexity is O(N*N*K)

Constraints:
1 <= n <= 300
1 <= m <= 300
1 <= K <= 300
0 <= M[i][j] <= 1000

Example:

Input:
M  = [[1,2,4],[4,5,8]] , K = 2

Output:
ans = [[5,8,8],[8,8,8]]
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
static void getVal(int A, vector<vector<int>> &B, int cur, vector<vector<int>> &ret)
{
	int n = (int)B.size();
	int m = (int)B[0].size();

	if (cur > A) return;

	if (cur == 0)
	{
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<m; j++)
			{
				ret[i][j] = B[i][j];
			}
		}
	}
	else
	{
		vector<vector<int>> temp(n, vector<int>(m));
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<m; j++)
			{
				temp[i][j] = max((i>0 ? ret[i - 1][j] : INT_MIN),
					max((i<n - 1 ? ret[i + 1][j] : INT_MIN),
						max((j>0 ? ret[i][j - 1] : INT_MIN),
							max((j<m - 1 ? ret[i][j + 1] : INT_MIN),
								ret[i][j]))));
			}
		}
		ret = temp;
	}

	getVal(A, B, cur + 1, ret);
}

vector<vector<int> > KthManhattanDistanceNeighbourhood(int A, vector<vector<int> > &B) 
{
	int n = (int)B.size();
	if (n == 0) return vector<vector<int>>();
	int m = (int)B[0].size();
	vector<vector<int>> ret(n, vector<int>(m, -1));

	getVal(A, B, 0, ret);

	return ret;
}
#else
bool check(int i, int j, int n, int m) {
	//Check if (i,j) are with in matrix dimensions
	if (i >= 0 && j >= 0 && i < n && j < m) return 1;
	return 0;
}

vector<vector<int> > KthManhattanDistanceNeighbourhood(int A, vector<vector<int> > &B) {
	// DP can be optimized to be of N*N size as we need only dp[k-1][n][n] for dp[k][n][n]
	int n = B.size();
	int m = B[0].size();

	vector<vector<vector<int> > > dp(2);
	dp[0] = dp[1] = B;

	int rplus[4] = { 1,0,0,-1 };
	int cplus[4] = { 0,-1,1,0 };

	for (int k = 0; k <= A; k++) {
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				//base case
				if (k == 0) dp[k][i][j] = B[i][j];
				//dp[k][i][j] = max(dp[k-1][i-1][j],dp[k-1][i+1][j],dp[k-1][i][j-1],
				//                                   dp[k-1][i][j+1],dp[k-1][i][j])
				else {
					int ans = dp[(k - 1) % 2][i][j];
					for (int p = 0; p < 4; p++) {
						int temp_i = i + rplus[p];
						int temp_j = j + cplus[p];
						if (check(temp_i, temp_j, n, m)) ans = max(ans, dp[(k - 1) % 2][temp_i][temp_j]);
					}
					dp[k % 2][i][j] = ans;

				}
			}
		}
	}

	return dp[A % 2];
}
#endif