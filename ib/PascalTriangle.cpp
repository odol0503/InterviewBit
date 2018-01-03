/*************************************************************************************************
Pascal TriangleBookmark Suggest Edit

Given numRows, generate the first numRows of Pascal¡¯s triangle.

Pascal¡¯s triangle : To generate A[C] in row R, sum up A¡¯[C] and A¡¯[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
	[1],
	[1,1],
	[1,2,1],
	[1,3,3,1],
	[1,4,6,4,1]
]
*************************************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> PascalTriangle(int A)
{
	vector<vector<int>> ans(A);
	for (int i = 1; i <= A; i++) ans[i-1].assign(i, 1);

	if (A > 2)
	{
		for (int i = 2; i < A; i++)
		{
			for (int j = 1; j < i; j++)
			{
				ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
			}
		}
	}

	return ans;
}
