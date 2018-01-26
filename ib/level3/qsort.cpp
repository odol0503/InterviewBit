#include <vector>

using namespace std;

void qsort(vector<int> &A, int left, int right)
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