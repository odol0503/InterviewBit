/*************************************************************************************************
Largest area of rectangle with permutations

Given a binary grid i.e. a 2D grid only consisting of 0¡¯s and 1¡¯s, find the area of 
the largest rectangle inside the grid such that all the cells inside the chosen rectangle 
should have 1 in them. You are allowed to permutate the columns matrix i.e. 
you can arrange each of the column in any order in the final grid. 
Please follow the below example for more clarity.

Lets say we are given a binary grid of 3 * 3 size.
1 0 1
0 1 0
1 0 0

At present we can see that max rectangle satisfying the criteria mentioned in the problem 
is of 1 * 1 = 1 area i.e either of the 4 cells which contain 1 in it. 
Now since we are allowed to permutate the columns of the given matrix, 
we can take column 1 and column 3 and make them neighbours. 
One of the possible configuration of the grid can be:
1 1 0
0 0 1
1 0 0

Now In this grid, first column is column 1, second column is column 3 and third column 
is column 2 from the original given grid. Now, we can see that if we calculate the max 
area rectangle, we get max area as 1 * 2 = 2 which is bigger than the earlier case. 
Hence 2 will be the answer in this case.
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_set>
using namespace std;

#define OWN

#ifdef OWN
static int CalRect(vector<vector<int>> &A)
{
	int row = (int)A.size();
	int col = (int)A[0].size();
	int max_area = 0;

	for (int i = 0; i < row; i++)
	{
		unordered_set<int> S;
		for (int j = 0; j < col; j++)
		{
			if (S.count(A[i][j]) == 0 && A[i][j] > 0)
			{
				int cnt = 0;
				for (int k = 0; k < col; k++) if (A[i][k] >= A[i][j]) cnt++;
				max_area = max(max_area, cnt*A[i][j]);
				S.insert(A[i][j]);
			}
		}
	}

	return max_area;
}

static void MakeForm(vector<vector<int>> &A)
{
	int row = (int)A.size();
	int col = (int)A[0].size();

	for (int j = 0; j < col; j++)
	{
		for (int i = 1; i < row; i++)
		{
			if (A[i - 1][j] > 0 && A[i][j] > 0) A[i][j] = A[i - 1][j] + 1;
		}
	}
}

static void SortMat(vector<vector<int>> &A)
{
	for (int i = 0; i<(int)A.size(); i++)
	{
		sort(A[i].begin(), A[i].end());
	}
}

int LargestAreaOfRectangleWithPermutations(vector<vector<int> > &A) {
	int max_area = 0;
	MakeForm(A);
	SortMat(A);
	return CalRect(A);
}
#else
int LargestAreaOfRectangleWithPermutations(vector<vector<int> > &mat) {
	int R = mat.size();
	int C = mat[0].size();
	vector<vector<int>> hist(R + 1, vector<int>(C + 1));

	// Step 1: Fill the auxiliary array hist[][]
	for (int i = 0; i<C; i++)
	{
		// First row in hist[][] is copy of first row in mat[][]
		hist[0][i] = mat[0][i];

		// Fill remaining rows of hist[][]
		for (int j = 1; j<R; j++)
			hist[j][i] = (mat[j][i] == 0) ? 0 : hist[j - 1][i] + 1;
	}


	// Step 2: Sort rows of hist[][] in non-increasing order
	for (int i = 0; i<R; i++)
	{
		vector<int>count(R + 1, 0);

		// counting occurrence
		for (int j = 0; j<C; j++)
			count[hist[i][j]]++;

		//  Traverse the count array from right side
		int col_no = 0;
		for (int j = R; j >= 0; j--)
		{
			if (count[j] > 0)
			{
				for (int k = 0; k<count[j]; k++)
				{
					hist[i][col_no] = j;
					col_no++;
				}
			}
		}
	}

	// Step 3: Traverse the sorted hist[][] to find maximum area
	int curr_area, max_area = 0;
	for (int i = 0; i<R; i++)
	{
		for (int j = 0; j<C; j++)
		{
			// Since values are in decreasing order,
			// The area ending with cell (i, j) can
			// be obtained by multiplying column number
			// with value of hist[i][j]
			curr_area = (j + 1)*hist[i][j];
			if (curr_area > max_area)
				max_area = curr_area;
		}
	}
	return max_area;
}
#endif