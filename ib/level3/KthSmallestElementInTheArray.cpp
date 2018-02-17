/*************************************************************************************************
Kth Smallest Element in the Array

Find the kth smallest element in an unsorted array of non-negative integers.

Definition of kth smallest element

kth smallest element is the minimum possible n such that there are at least k elements in the array <= n.
In other words, if the array A was sorted, then A[k - 1] ( k is 1 based, while the arrays are 0 based )
NOTE
You are not allowed to modify the array ( The array is read only ).
Try to do it using constant extra space.

Example:
A : [2 1 4 3 2]
k : 3

answer : 2
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
int Partition(vector<int> &a, int left, int right)
{
	int i = left - 1;
	for (int j = left; j<right; j++)
	{
		if (a[j] <= a[right])
		{
			swap(a[++i], a[j]);
		}
	}

	swap(a[++i], a[right]);
	return i;
}

int Kthsmallest(const vector<int> &A, int B) {
	int len = (int)A.size();
	vector<int> C(A);
	int left = 0;
	int right = len - 1;

	while (left < right)
	{
		int p = Partition(C, left, right);

		if (B == p + 1) return C[p];
		else if (B < p + 1) right = p - 1;
		else left = p + 1;
	}

	return C[right];
}
#else

#endif