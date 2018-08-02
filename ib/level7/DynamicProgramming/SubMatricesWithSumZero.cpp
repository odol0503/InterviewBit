/*************************************************************************************************
Sub Matrices with sum Zero

Given a 2D matrix, find the number non-empty sub matrices, such that the sum of the elements 
inside the sub matrix is equal to 0. (note: elements might be negative).

Example:
Input
-8  5  7
 3  7 -8
 5 -8  9
Output
2

Explanation
-8
 3
 5

 7 -8
-8  9
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define OWN

#ifdef OWN
int SubMatricesWithSumZero(vector<vector<int>> &A) {
	if (A.size() == 0) return 0;

	int row = (int)A.size();
	int col = (int)A[0].size();
	int cnt = 0;

	for (int l = 0; l<col; l++)
	{
		vector<int> temp(row, 0);
		for (int r = l; r<col; r++)
		{
			int sum = 0;
			unordered_map<int, int> M;
			M[0] = 1;

			for (int i = 0; i<row; i++)
			{
				temp[i] += A[i][r];
				sum += temp[i];

				cnt += M[sum];
				M[sum]++;
			}
		}
	}

	return cnt;
}
#else
int SubMatricesWithSumZero(vector<vector<int>> &A) 
{
	int m = A.size(), n, j, i, ans = 0, k, l;
	if (m != 0)
		n = A[0].size();
	else
		return 0;

	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
		{
			if (i == 0 && j == 0)
			{
				continue;
			}
			if (i == 0)
				A[0][j] += A[0][j - 1];
			else if (j == 0)
				A[i][0] += A[i - 1][0];

			else
				A[i][j] += A[i][j - 1] + A[i - 1][j] - A[i - 1][j - 1];


		}
	}


	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
		{
			for (k = i; k<m; k++)
			{

				for (l = j; l<n; l++)
				{
					int  sub = A[k][l];
					if (i>0)
						sub -= A[i - 1][l];
					if (j>0)
						sub -= A[k][j - 1];
					if (i>0 && j>0)
						sub += A[i - 1][j - 1];


					if (sub == 0)
					{

						ans++;
					}
				}
			}

		}
	}

	return ans;
}
#endif