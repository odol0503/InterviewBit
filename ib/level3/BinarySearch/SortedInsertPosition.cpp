/*************************************************************************************************
Sorted Insert Position

Given a sorted array and a target value, return the index if the target is found. If not,
return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.
Here are few examples.

[1,3,5,6], 5 ¡æ 2
[1,3,5,6], 2 ¡æ 1
[1,3,5,6], 7 ¡æ 4
[1,3,5,6], 0 ¡æ 0
*************************************************************************************************/
#include <vector>
using namespace std;

#define OWN

#ifdef OWN
int SearchInsert(vector<int> &A, int B) 
{
	int len = (int)A.size();
	int left = 0;
	int right = len - 1;
	int mid = 0;

	while (left < right)
	{
		mid = (left + right) / 2;
		if (A[mid] > B) right = mid - 1;
		else if (A[mid] < B) left = mid + 1;
		else return mid;
	}

	if (A[right] >= B) return right;
	else return right + 1;
}
#else
int SearchInsert(vector<int> &A, int target)
{
	int n = A.size();
	int start = 0, end = n - 1;
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (target == A[mid]) {
			return mid;
		}
		else if (target < A[mid]) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return start;
}
#endif