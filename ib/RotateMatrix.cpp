/*************************************************************************************************
Rotate Matrix

You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
You need to do this in place.
Note that if you end up using an additional array, you will only receive partial score.

Example:
If the array is
[
	[1, 2],
	[3, 4]
]
Then the rotated array becomes:
[
	[3, 1],
	[4, 2]
]
*************************************************************************************************/
#include <vector>
using namespace std;

void RotateMatrix(vector<vector<int> > &A)
{
	int N = static_cast<int>(A.size());
	int temp1 = 0;
	int temp2 = 0;
	for (int i = 0; i < N/2; i++)
	{
		for (int j = i; j < N-i-1; j++)
		{
			temp1 = A[j][N - i - 1];
			A[j][N - i - 1] = A[i][j];
			temp2 = A[N - i - 1][N - j - 1];
			A[N - i - 1][N - j - 1] = temp1;
			temp1 = A[N - j - 1][i];
			A[N - j - 1][i] = temp2;
			A[i][j] = temp1;
		}
	}
}