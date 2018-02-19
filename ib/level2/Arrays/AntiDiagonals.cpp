/*************************************************************************************************
Anti Diagonals

Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.
Example:
Input:
1 2 3
4 5 6
7 8 9

Return the following :
[
	[1],
	[2, 4],
	[3, 5, 7],
	[6, 8],
	[9]
]

Input :
1 2
3 4

Return the following  :
[
	[1],
	[2, 3],
	[4]
]
*************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > AntiDiagonal(vector<vector<int> > &A) {
	int n = (int)A.size();
	vector<vector<int>> ans(2 * n - 1);
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			ans[x + y].push_back(A[y][x]);
		}
	}

	return ans;
}
