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

#define OWN

#ifdef OWN
vector<vector<int> > AntiDiagonal(vector<vector<int> > &A) {
	int len = (int)A.size();
	vector<vector<int>> ret(len * 2 - 1);

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			ret[i + j].push_back(A[i][j]);
		}
	}

	return ret;
}
#else
vector<vector<int> > AntiDiagonal(vector<vector<int> > Vec) {
	int N = Vec.size();
	if (N == 1)
		return Vec;

	vector<pair<int, int> > search_space;
	for (int i = 0; i < N; ++i) {
		search_space.push_back(make_pair(0, i));
	}
	for (int i = 1; i < N; ++i) {
		search_space.push_back(make_pair(i, N - 1));
	}

	vector<vector<int> > Ans;
	for (int i = 0; i < search_space.size(); ++i) {
		vector<int> Temp;
		int x = search_space[i].first;
		int y = search_space[i].second;
		while (x < N && y >= 0) {
			Temp.push_back(Vec[x][y]);
			x += 1;
			y -= 1;
		}
		Ans.push_back(Temp);
	}

	return Ans;
}
#endif