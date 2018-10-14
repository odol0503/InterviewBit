/*************************************************************************************************
Max Rectangle in Binary Matrix

Given a 2D binary matrix filled with 0¡¯s and 1¡¯s, find the largest rectangle containing 
all ones and return its area.

Bonus if you can solve it in O(n^2) or less.

Example :

A : [  1 1 1
       0 1 1
       1 0 0
    ]

Output : 4

As the max area rectangle is created by the 2x2 rectangle created by (0,1), (0,2), (1,1) and (1,2)
*************************************************************************************************/
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define OWN

#ifdef OWN
int MaxRectangleInBinaryMatrix(vector<vector<int> > A) {
	int ret = 0;
	for (int i = 0; i<A.size(); i++)
	{
		for (int j = 0; j<A[0].size(); j++)
		{
			vector<int> dp(A[0].size(), 0);
			for (int l = i; l<A.size(); l++)
			{
				if (A[l][j] == 0) break;
				int sum = 0;
				for (int k = j; k<A[0].size(); k++)
				{
					dp[k] += A[l][k];
					if (dp[k] != (l - i + 1)) break;
					sum += dp[k];
				}

				ret = max(ret, sum);
			}
		}
	}

	return ret;
}
#else
int MaxRectangleInBinaryMatrix(vector<vector<int> > matrix) {
	int rows = matrix.size();
	if (rows == 0) return 0;
	int cols = matrix[0].size();
	if (cols == 0) return 0;
	vector<vector<int>> max_x(rows, vector<int>(cols, 0));  //number of consecutive 1s to the left of matrix[i][j], including itself

	int area = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (matrix[i][j] == 1) {
				if (j == 0) max_x[i][j] = 1;
				else max_x[i][j] = max_x[i][j - 1] + 1;
				int y = 1;
				int x = cols;
				while ((i - y + 1 >= 0) && (matrix[i - y + 1][j] == 1)) {
					x = min(x, max_x[i - y + 1][j]);
					area = max(area, x * y);
					y++;
				}
			}
		}
	}

	return area;
}
#endif