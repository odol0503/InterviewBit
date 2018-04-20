/*************************************************************************************************
Spiral Order Matrix II

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
Example:
Given n = 3,

You should return the following matrix:

[
	[ 1, 2, 3 ],
	[ 8, 9, 4 ],
	[ 7, 6, 5 ]
]
*************************************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

#define OWN

#ifdef OWN
vector<vector<int>> SpialOrderMatrix(int A)
{
	vector<vector<int>> ans(A, vector<int>(A, 0));

	int len = A * A;
	int x = 0;
	int y = 0;
	int direction = 0;
	int sign = 1;

	for (int i = 0; i < len; i++)
	{
		ans[y][x] = i + 1;

		if (direction == 0)
		{
			x++;
			if (x == A || ans[y][x] != 0)
			{
				direction = 1;
				x--;
				y++;
			}
		}
		else if (direction == 1)
		{
			y++;
			if (y == A || ans[y][x] != 0)
			{
				direction = 2;
				x--;
				y--;
			}
		}
		else if (direction == 2)
		{
			x--;
			if (x < 0 || ans[y][x] != 0)
			{
				direction = 3;
				x++;
				y--;
			}
		}
		else if (direction == 3)
		{
			y--;
			if (y < 0 || ans[y][x] != 0)
			{
				direction = 0;
				x++;
				y++;
			}
		}
	}

	return ans;
}
#else
vector<vector<int> > SpialOrderMatrix(int n) {
	int dir = 0;
	vector< vector<int> > matrix(n, vector<int>(n, 0));
	int i = 0, j = 0, k = 1;
	while (k <= n * n) {
		matrix[i][j] = k++;
		if (dir == 0) {
			j++;
			if (j == n || matrix[i][j] != 0) dir = 1, j--, i++;
		}
		else
			if (dir == 1) {
				i++;
				if (i == n || matrix[i][j] != 0) dir = 2, i--, j--;
			}
			else
				if (dir == 2) {
					j--;
					if (j < 0 || matrix[i][j] != 0) dir = 3, j++, i--;
				}
				else
					if (dir == 3) {
						i--;
						if (i < 0 || matrix[i][j] != 0) dir = 0, i++, j++;
					}
	}
	return matrix;
}
#endif