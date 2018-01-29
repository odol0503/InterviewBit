/*************************************************************************************************
Rotated Sorted Array Search

Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ).

You are given a target value to search. If found in the array, return its index, otherwise 
return -1.
You may assume no duplicate exists in the array.

Input : [4 5 6 7 0 1 2] and target = 4
Output : 0

NOTE : Think about the case when there are duplicates. Does your current solution work? 
How does the time complexity change?*
*************************************************************************************************/
#include <vector>
using namespace std;

#define OWN7

#ifdef OWN
int RotatedSortedArraySearch(const vector<int> &A, int B) 
{
	int len = (int)A.size();
	int pivot = A[0];
	int left = 0, right = len - 1;
	int mid = 0;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (pivot > B)
		{
			if (A[mid] > pivot) left = mid + 1;
			else if (A[mid] < pivot)
			{
				if (B < A[mid]) right = mid - 1;
				else if (B > A[mid]) left = mid + 1;
				else return mid;
			}
		}
		else if (pivot < B)
		{
			if (A[mid] > pivot)
			{
				if (B < A[mid]) right = mid - 1;
				else if (B > A[mid]) left = mid + 1;
				else return mid;
			}
			else if (A[mid] < pivot) right = mid - 1;
		}
		else
		{
			return 0;
		}
	}

	return -1;
}
#else
int findMin(const vector<int> &A, int start, int end) {
	if (start > end) return -1;
	if (start == end) {
		return start;
	}
	int mid = (start + end) / 2;
	if (A[mid] < A[end]) {
		return findMin(A, start, mid);
	}
	else if (A[mid] > A[end]) {
		return findMin(A, mid + 1, end);
	}
	else {
		// should not come here 
		int index1 = findMin(A, start, mid);
		int index2 = findMin(A, mid + 1, end);
		if (index1 != -1 && index2 != -1) {
			if (A[index1] < A[index2]) return index1;
			return index2;
		}
		else if (index1 != -1) return index1;
		else return index2;
	}
}

int binarySearch(const vector<int> &A, int start, int end, int target) {
	if (start > end) return -1;
	if (start == end) {
		if (A[start] == target)
			return start;
		return -1;
	}
	int mid = (start + end) / 2;
	if (A[mid] < target) {
		return binarySearch(A, mid + 1, end, target);
	}
	else return binarySearch(A, start, mid, target);
}

int RotatedSortedArraySearch(const vector<int> &A, int target) {
	int n = A.size();
	int index = findMin(A, 0, n - 1);
	int index1 = binarySearch(A, 0, index, target);
	if (index1 != -1) return index1;
	return binarySearch(A, index, n - 1, target);
}
#endif