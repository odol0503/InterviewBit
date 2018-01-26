/*************************************************************************************************
Maximum Unsorted Subarray

You are given an array (zero indexed) of N non-negative integers, A0, A1 ,¡¦, AN-1.
Find the minimum sub array Al, Al+1 ,¡¦, Ar so if we sort(in ascending order) that sub array, 
then the whole array should get sorted.
If A is already sorted, output -1.

Example :
Input 1:
A = [1, 3, 2, 4, 5]
Return: [1, 2]
Input 2:
A = [1, 2, 3, 4, 5]
Return: [-1]
In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted.
*************************************************************************************************/
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> MaxUnsortedSubarray(vector<int> &A)
{
	int len = static_cast<int>(A.size());
	vector<int> ret;

	int al = INT_MAX;
	int min_value = A[len - 1];
	for (int i = len-2; i >= 0; i--)
	{
		min_value = min(min_value, A[i]);
		if (min_value < A[i]) al = i;
	}

	if (al == INT_MAX) return vector<int>(1, -1);

	int ar = INT_MIN;
	int max_value = A[al];
	for (int i = al+1; i < len; i++)
	{
		max_value = max(max_value, A[i]);
		if (max_value > A[i]) ar = i;
	}

	ret.push_back(al);
	ret.push_back(ar);
	return ret;
}