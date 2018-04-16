/*************************************************************************************************
Spiral Order Matrix I
Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix 
in spiral order.

Example:
Given the following matrix:
[
	[ 1, 2, 3 ],
	[ 4, 5, 6 ],
	[ 7, 8, 9 ]
]
You should return
[1, 2, 3, 6, 9, 8, 7, 4, 5]
*************************************************************************************************/
#include <vector>
#include <cmath>
using namespace std;

#define OWN

#ifdef OWN
vector<int> SpiralOrderMatrix1(const vector<vector<int> > &A) {
	vector<int> ret;
	vector<vector<int>> B(A.size(), vector<int>(A[0].size(), 0));
	int d = 0;
	int num = (int)(A.size() * A[0].size());
	int row = (int)A.size();
	int col = (int)A[0].size();
	int i = 0, j = 0;

	while (1)
	{
		ret.push_back(A[i][j]);
		if (ret.size() == num) break;
		B[i][j] = 1;

		switch (d)
		{
		case 0:
			if (j == col-1 || B[i][j + 1] == 1)
			{
				d++;
				i++;
				continue;
			}
			j++;
			break;
		case 1:
			if (i == row-1 || B[i + 1][j] == 1)
			{
				d++;
				j--;
				continue;
			}
			i++;
			break;
		case 2:
			if (j == 0 || B[i][j - 1] == 1)
			{
				d++;
				i--;
				continue;
			}
			j--;
			break;
		case 3:
			if (i == 0 || B[i - 1][j] == 1)
			{
				d = 0;
				j++;
				continue;
			}
			i--;
			break;
		}
	}

	return ret;
}
#else
vector<int> SpiralOrderMatrix1(const vector<vector<int> > &matrix) {
	int rows = matrix.size();
	if (rows == 0) return vector<int>();
	int cols = matrix[0].size();
	int row = 0, col = 0, layer = 0;
	vector<int> res;
	res.push_back(matrix[0][0]);
	int dir = 1;
	for (int step = 1; step < rows * cols; step++) {
		switch (dir) { // based on dir, check and change dir, then move on
		case 1: // supposed to go right
			if (col == cols - layer - 1) { // reach right bound
				row++;
				dir = 2;
			}
			else col++;
			break;
		case 2: // supposed to go down
			if (row == rows - layer - 1) { // reach downside bound
				col--;
				dir = 3;
			}
			else row++;
			break;
		case 3: // supposed to go left
			if (col == layer) { // reach left bound
				row--;
				dir = 4;
			}
			else col--;
			break;
		case 4: // supposed to go up
			if (row == layer + 1) { // reach upside bound
				col++;
				dir = 1;
				layer++;
			}
			else row--;
			break;
		}
		res.push_back(matrix[row][col]);
	}
	return res;
	}
#endif