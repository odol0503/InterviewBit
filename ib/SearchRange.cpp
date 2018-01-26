/*************************************************************************************************
Search for a Range

Given a sorted array of integers, find the starting and ending position of a given target value.
Your algorithm¡¯s runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].

Example:
Given [5, 7, 7, 8, 8, 10]
and target value 8,
return [3, 4].
*************************************************************************************************/
#include <vector>
#include <cmath>
using namespace std;

vector<int> SearchRange(const vector<int> &A, int B)
{
	int start = 0;
	int end = (int)A.size() -1;
	int mid = 0;

	while (start < end)
	{
		mid = (start + end) / 2;
		if (A[mid] == B) break;
		if (A[mid] > B) end = mid;
		else start = mid+1;
	}

	if (A[mid] != B) return vector<int>({ -1, -1 });

	int cnt1 = 0;
	for (int i = mid - 1; i >= 0; i--)
	{
		if (A[i] == A[mid]) cnt1++;
		else break;
	}

	int cnt2 = 0;
	for (int i = mid+1; i < A.size(); i++)
	{
		if (A[i] == A[mid]) cnt2++;
		else break;
	}

	return vector<int>({ mid -cnt1, mid + cnt2 });
}