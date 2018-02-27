/*************************************************************************************************
Permutations

Given a collection of numbers, return all possible permutations.

Example:
[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3]
[2,3,1]
[3,1,2]
[3,2,1]
NOTE
No two entries in the permutation sequence should be the same.
For the purpose of this problem, assume that all the numbers in the collection are unique.
Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS.
Example : next_permutations in C++ / itertools.permutations in python.
If you do, we will disqualify your submission retroactively and give you penalty points.
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
int Factorial(int A)
{
	int ans = 1;
	for (int i = 2; i <= A; i++)
		ans *= i;
	return ans;
}

vector<int> NextPermute(vector<int> &A)
{
	int len = (int)A.size();

	for (int i = len - 1; i>0; i--)
	{
		if (A[i - 1] < A[i])
		{
			int j = len - 1;
			while (A[i - 1] >= A[j]) j--;
			swap(A[i - 1], A[j]);
			sort(A.begin() + i, A.end());
			return A;
		}

		if (i == 1) sort(A.begin(), A.end());
	}
	return A;
}

vector<vector<int> > GetAllPermute(vector<int> &A) {
	int len = (int)A.size();
	int num = Factorial(len);
	vector<vector<int>> ret;

	ret.push_back(A);

	for (int i = 0; i<num-1; i++)
	{
		ret.push_back(NextPermute(A));
	}
	return ret;
}
#else
void permute(vector<int> &num, int start, vector<vector<int> > &result) {
	if (start == num.size() - 1) {
		result.push_back(num);
		return;
	}
	for (int i = start; i < num.size(); i++) {
		swap(num[start], num[i]);
		permute(num, start + 1, result);
		swap(num[start], num[i]);
	}
	}

vector<vector<int> > GetAllPermute(vector<int> &num) {
	vector<vector<int> > result;
	if (num.size() == 0)
		return result;
	sort(num.begin(), num.end());
	permute(num, 0, result);
	return result;
}
#endif