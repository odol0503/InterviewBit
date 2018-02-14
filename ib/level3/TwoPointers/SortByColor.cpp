/*************************************************************************************************
Sort by Color

Given an array with n objects colored red, white or blue,
sort them so that objects of the same color are adjacent, with the colors in the order red,
white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: Using library sort function is not allowed.

Example :
Input : [0 1 2 0 1 2]
Modify array so that it becomes : [0 0 1 1 2 2]
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
#if 0
static void qsort(vector<int> &A, int start, int end)
{
	int low = start+1;
	int high = end;

	while (start < end)
	{
		while (low < high)
		{
			while (A[start] >= A[low] && low < end) low++;
			while (A[start] <= A[high] && high > start) high--;
			if (low < high) swap(A[low], A[high]);
		}
		swap(A[start], A[high]);
		qsort(A, start, high-1);
		qsort(A, high+1, end);
	}
}
#endif
static void qsort(vector<int> &A, int left, int right)
{
	int low = left + 1;
	int high = right;

	if (left < right)
	{
		while (low < high)
		{
			while (A[left] >= A[low] && low < right) low++;
			while (A[left] <= A[high] && left < high) high--;
			if (low < high) swap(A[low], A[high]);
		}
		swap(A[left], A[high]);
		qsort(A, left, high - 1);
		qsort(A, high + 1, right);
	}
}
vector<int> SortColors(vector<int> &A) {
	int len = (int)A.size();
	int cnt0 = 0;
	int cnt1 = 0;
	int cnt2 = 0;

	for (int i = 0; i < len; i++)
	{
		if (A[i] == 0) cnt0++;
		if (A[i] == 1) cnt1++;
		if (A[i] == 2) cnt2++;
	}

	for (int i = 0; i < cnt0; i++) A[i] = 0;
	for (int j = 0; j < cnt1; j++) A[cnt0 + j] = 1;
	for (int k = 0; k < cnt2; k++) A[cnt0 + cnt1 + k] = 2;
	return A;
}
#else
vector<int> SortColors(vector<int> &A) {
	int n = A.size();
	int k = n - 1;
	int i = 0;
	for (; i < n; ++i)
	{
		if (A[i] != 0)
		{
			break;
		}
	}

	int j = i;
	for (; i <= k; ++i)
	{
		if (A[i] == 0)
		{
			swap(A[j++], A[i]);
		}
		else if (A[i] == 2)
		{
			swap(A[i--], A[k--]);
		}
	}

	return A;
}
#endif