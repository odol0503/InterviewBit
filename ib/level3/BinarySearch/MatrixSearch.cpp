/*************************************************************************************************
Matrix Search

Write an efficient algorithm that searches for a value in an m x n matrix.
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than or equal to the last integer of the previous row.

Example:
Consider the following matrix:
[
[1,   3,  5,  7],
[10, 11, 16, 20],
[23, 30, 34, 50]
]
Given target = 3, return 1 ( 1 corresponds to true )

Return 0 / 1 ( 0 if the element is not present, 1 if the element is present ) for this problem
*************************************************************************************************/
#include <vector>
using namespace std;

#define OWN6

#ifdef OWN
int MatrixSearch(vector<vector<int> > &A, int B) 
{
	int r = (int)A.size();
	int c = (int)A[0].size();
	int left = 0, right = r-1;
	int mid;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (A[mid][c - 1] < B) left = mid + 1;
		else if (A[mid][0] > B) right = mid - 1;
		else
		{
			for (auto a : A[mid])
			{
				if (a == B) return 1;
			}
			return 0;
		}
	}

	return 0;
}
#else
int MatrixSearch(vector<vector<int> > &matrix, int target) {
	int n = (int)matrix.size();
	int m = (int)matrix[0].size();
	int l = 0, r = m * n - 1;
	while (l != r) {
		int mid = (l + r - 1) >> 1;
		if (matrix[mid / m][mid % m] < target)
			l = mid + 1;
		else
			r = mid;
	}
	return (int)matrix[r / m][r % m] == target;
}
#endif