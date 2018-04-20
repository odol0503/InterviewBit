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

#define OWN

#ifdef OWN
static int combination(int n, int k)
{
	if (n == 0 || k == 0 || n == k)
	{
		return 1;
	}

	int ans = combination(n - 1, k) + combination(n - 1, k - 1);
	return ans;
}

vector<vector<int>> PascalTriangle(int A)
{
	vector<vector<int>> ret(A);

	for (int i = 0; i < A; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			ret[i].push_back(combination(i, j));
		}
	}

	return ret;
}
#else
vector<vector<int> > PascalTriangle(int numRows) {
	vector<vector<int> > ans;
	if (numRows <= 0) {
		return ans;
	}
	vector<int> tmp;
	tmp.push_back(1);
	ans.push_back(tmp);
	for (int i = 0; i < numRows - 1; i++) {
		vector<int> newRow;
		newRow.push_back(1);
		for (int j = 0; j < ans[i].size() - 1; j++) {
			newRow.push_back(ans[i][j] + ans[i][j + 1]);
		}
		newRow.push_back(1);
		ans.push_back(newRow);
	}
	return ans;
}
#endif
