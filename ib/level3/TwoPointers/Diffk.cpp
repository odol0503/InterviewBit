/*************************************************************************************************
Diffk

Given an array ¡®A¡¯ of sorted integers and another non negative integer k,
find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

Example: Input :
A : [1 3 5]
k : 4
Output : YES as 5 - 1 = 4
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Try doing this in less than linear space complexity.
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
int DiffPossible(vector<int> &A, int B) {
	int len = (int)A.size();
	int left = 0;
	int right = len - 1;
	int mid;

	while (left < right)
	{
		mid = (left + right) / 2;

		if (A[mid] < B) left = mid + 1;
		else right = mid;
	}

	for (int i = right; i < len; i++)
	{
		int target = A[i] - B;
		left = 0;
		right = len - 1;
		while (left < right)
		{
			mid = (left + right) / 2 + 1;

			if (A[mid] <= target) left = mid;
			else right = mid - 1;
		}

		if (i != left && A[left] == target) return 1;
	}

	return 0;
}
#else
int DiffPossible(vector<int> &num, int diff) {
	if (num.size() < 2 || diff < 0) return false;
	int j = 0, len = num.size();
	for (int i = 0; i < len - 1; i++) {
		j = max(j, i + 1);
		while (j < len && num[j] - num[i] < diff) j += 1;
		if (j < len && num[j] - num[i] == diff) return true;
	}
	return false;
}
#endif