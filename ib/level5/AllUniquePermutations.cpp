/*************************************************************************************************
All Unique Permutations

Given a collection of numbers that might contain duplicates, 
return all possible unique permutations.

Example :
[1,1,2] have the following unique permutations:

[1,1,2]
[1,2,1]
[2,1,1]
NOTE : No 2 entries in the permutation sequence should be the same.
Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS. 
Example : next_permutations in C++ / itertools.permutations in python.
If you do, we will disqualify your submission retroactively and give you penalty points.
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > AllUniquePermutations(vector<int> &A) {
	int len = (int)A.size();
	vector<vector<int>> ret;
	sort(A.begin(), A.end());
	ret.push_back(A);

	while (1)
	{
		int i = len - 2;
		for (; i >= 0; i--)
		{
			if (A[i] < A[i+1])
			{
				int j = len - 1;
				while (A[i] >= A[j]) j--;
				swap(A[i], A[j]);
				reverse(A.begin() + i + 1, A.end());
				ret.push_back(A);
				break;
			}
		}
		if (i < 0) break;
	}
	return ret;
}