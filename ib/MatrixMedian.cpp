/*************************************************************************************************
Matrix Median

Given a N cross M matrix in which each row is sorted, find the overall median of the matrix. 
Assume N*M is odd.

For example,
Matrix=
[1, 3, 5]
[2, 6, 9]
[3, 6, 9]
A = [1, 2, 3, 3, 5, 6, 6, 9, 9]

Median is 5. So, we return 5.
Note: No extra memory is allowed.
*************************************************************************************************/
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN

int MatrixMedian(vector<vector<int> > &A) 
{
	int rlen = (int)A.size();
	int clen = (int)A[0].size();
	int num = (rlen * clen)/ 2 + 1 ;

	int start = 0;
	int end = INT_MAX;
	int mid = end / 2;
	int i, j;

	while (end - start > 1)
	{
		int less = 0;
		for (i = 0; i < rlen; i++)
		{
			for (j = 0; j < clen; j++)
			{
				if (A[i][j] < mid) less++;
			}
		}
		
		if (less < num) start = mid;
		else end = mid;
		mid = (start+end)/ 2;
	} 

	return start;
}

#else

#endif