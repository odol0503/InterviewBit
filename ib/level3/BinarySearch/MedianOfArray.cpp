/*************************************************************************************************
Median of Array

There are two sorted arrays A and B of size m and n respectively.
Find the median of the two sorted arrays 
( The median of the array formed by merging both the arrays ).

The overall run time complexity should be O(log (m+n)).

Sample Input
A : [1 4 5]
B : [2 3]

Sample Output
3
NOTE: IF the number of elements in the merged array is even, then the median
is the average of n / 2 th and n/2 + 1th element.
For example, if the array is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
static double Median(const vector<int> &A)
{
	int len = (int)A.size();

	if (len & 0x01) return A[len / 2];
	else return (A[len / 2 - 1] + A[len / 2]) / 2.0;
}

static double Median3(int a, int b, int c)
{
	return a+b+c-max(max(a, b), c)-min(min(a,b),c);
}

static double Median4(int a, int b, int c, int d)
{
	return ((a + b + c + d) - max(max(max(a, b), c), d) - min(min(min(a, b), c), d)) / 2.0;
}

double findMedianSortedArrays(const vector<int> &a, const vector<int> &b)
{
	vector<int> A(a);
	vector<int> B(b);
	int n = (int)A.size();
	int m = (int)B.size();

	// case1 n == 0 or m == 0
	if (n == 0) {
		if (m == 0) return -1;
		else return Median(B);
	}
	else if (m == 0)
	{
		return Median(A);
	}

	if (n == 1)
	{
		// case2 n==1, m==1
		if (m == 1) return (A[0] + B[0]) / 2.0;

		// case3 n==1, m==odd
		if (m & 0x01)
		{
			return Median4(A[0], B[m / 2 - 1], B[m / 2], B[m / 2 + 1]); // A[0] 1 2 3 | 1 2 A[0] 3 | 1 2 3 A[0]
		}
		// case4 n==1, m==even
		else if (n == 1)
		{
			return Median3(A[0], B[m / 2 - 1], B[m / 2]); // A[0] 1 2 |1 A[0] 2 | 1 2 A[0]
		}
	}

	if (n == 2)
	{
		// case5 n==2, m==2
		if (m == 2)
		{
			return Median4(A[0], A[1], B[0], B[1]); // A[0] A[1] 1 2 | 1 2 A[0] | 1 A[0] A[1] 2 | 1 A[0] 2 A[1]
		}

		// case6 n==2, m==odd
		if (m & 0x01)
		{
			return Median3(max(A[0], B[m / 2 - 1]), B[m / 2], min(A[1], B[m / 2 + 1])); // A[0] A[1] 1 2 3 | A[0] 1 A[1] 2 3 | 1 A[0] 2 A[1] 3 |  1 2 A[0] 3 A[1] | 1 2 3 A[0] A[1]
		}
		// case7 n==2, m==even
		else
		{
			return Median4(max(A[0], B[m / 2 - 2]), B[m / 2 - 1], B[m / 2], min(A[1], B[m / 2 + 1]));
		}
	}

	int idxA = (A.size() & 0x01) ? n / 2 : n / 2 - 1;

	if (Median(A) <= Median(B))
	{
		A.assign(A.begin() + idxA, A.end());
		B.assign(B.begin(), B.begin() + m - idxA);
	}
	else
	{
		A.assign(A.begin(), A.begin() + n / 2 + 1);
		B.assign(B.begin() + idxA, B.end());
	}

	return findMedianSortedArrays(A, B);
}

double MedianArray(const vector<int> &A, const vector<int> &B)
{
	if (A.size() > B.size())
	{
		return findMedianSortedArrays(B, A);
	}
	return findMedianSortedArrays(A, B);
}

#else
double MedianArray(const vector<int> &A, const vector<int> &B)
{
	int m = A.size(), n = B.size();
	if (m > n) return MedianArray(B, A);
	int imin, imax, i, j;
	imin = 0;
	imax = m;
	while (imin <= imax) {
		i = (imin + imax) / 2;
		j = (m + n + 1) / 2 - i;
		if (j > 0 && i < m && B[j - 1] > A[i]) {
			imin = i + 1;
		}
		else if (i > 0 && j < n && A[i - 1] > B[j]) {
			imax = i - 1;
		}
		else {
			// Figure out median now. 
			int median1 = 0, median2 = 0;
			if (i == 0) {
				median1 = B[j - 1];
			}
			else if (j == 0) {
				median1 = A[i - 1];
			}
			else {
				median1 = max(A[i - 1], B[j - 1]);
			}
			if ((m + n) % 2 == 1) {
				return 1.0 * median1;
			}
			if (i == m) {
				median2 = B[j];
			}
			else if (j == n) {
				median2 = A[i];
			}
			else {
				median2 = min(A[i], B[j]);
			}
			return 1.0 * (median1 + median2) / 2.0;
		}
	}
	return -1.0;
}
#endif