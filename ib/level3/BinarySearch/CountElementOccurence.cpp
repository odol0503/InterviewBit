/*************************************************************************************************
Count Element Occurence

Given a sorted array of integers, find the number of occurrences of a given target value.
Your algorithm¡¯s runtime complexity must be in the order of O(log n).
If the target is not found in the array, return 0

**Example : **
Given [5, 7, 7, 8, 8, 10] and target value 8,
return 2.
*************************************************************************************************/
#include <vector>
using namespace std;

#define OWN

#ifdef OWN
int CountOccurence(const vector<int> &A, int B) 
{
	int left = 0;
	int right = (int)A.size() - 1;
	int mid = 0;

	while (left < right)
	{
		mid = (left + right) / 2;

		if (A[mid] < B) left = mid + 1;
		else right = mid;
	}

	if (A[right] != B) return 0;
	int start = right;

	right = (int)A.size() - 1;
	while (left < right)
	{
		mid = (left + right) / 2 + 1;
		if (A[mid] <= B) left = mid;
		else right = mid - 1;
	}
	return right - start + 1;
}
#else
int CountOccurence(const vector<int> &A, int target) {
	int n = A.size();
	int i = 0, j = n - 1;
	int start = -1, end = -1;

	// FIND FIRST
	while (i < j)
	{
		int mid = (i + j) / 2;
		if (A[mid] < target) i = mid + 1;
		else j = mid;
	}
	if (A[i] != target) return 0; // the element does not exist in the array.

	start = i;

	// FINDLAST
	j = n - 1;  // We don't have to set i to 0 the second time.
	while (i < j)
	{
		int mid = (i + j) / 2 + 1;   // Make mid biased to the right
		if (A[mid] > target) j = mid - 1;
		else i = mid;               // So that this won't make the search range stuck.
	}
	end = j;
	return (end - start + 1);
}
#endif