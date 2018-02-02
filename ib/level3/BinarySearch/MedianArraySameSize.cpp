#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN

double GetMedian(vector<int> A)
{
	int len = (int)A.size();

	if (len & 0x01) return (double)A[len / 2];
	else return (double)((A[len / 2] + A[len / 2 - 1]) / 2.0f);
}

double MediaArraySameSize(const vector<int> &A, const vector<int> &B)
{
	if (A.size() != B.size()) return -1;
	int len = (int)A.size();

	if (len == 1) return (A[0] + B[0]) / 2.0f;

	vector<int> C(A);
	vector<int> D(B);

	while (len > 2)
	{
		int odd = len & 0x1;
		double m1 = GetMedian(C);
		double m2 = GetMedian(D);
		len /= 2;

		if (m1 < m2)
		{
			if (odd)
			{
				C.assign(C.begin() + len, C.end());
				D.assign(D.begin(), D.begin() + len+1);
			}
			else
			{
				C.assign(C.begin() + len-1, C.end());
				D.assign(D.begin(), D.begin() + len + 1);
			}
		}
		else
		{
			if (odd)
			{
				C.assign(C.begin(), C.begin() + len+1);
				D.assign(D.begin() + len, D.end());
			}
			else
			{
				C.assign(C.begin(), C.begin() + len + 1);
				D.assign(D.begin() + len-1, D.end());
			}
		}

		len = (int)C.size();
	}

	return (double)((max(C[0], D[0]) + min(C[1], D[1])) / 2.0f);
}
#else
/* Function to get median of a sorted array */
int median(vector<int> arr, int n)
{
	if (n % 2 == 0)
		return (arr[n / 2] + arr[n / 2 - 1]) / 2;
	else
		return arr[n / 2];
}

double MediaArraySameSize(const vector<int> &A, const vector<int> &B)
{
	vector<int> ar1(A);
	vector<int> ar2(B);
	int n = (int)ar1.size();
	/* return -1  for invalid input */
	if (n <= 0)
		return -1;
	if (n == 1)
		return (ar1[0] + ar2[0]) / 2.0f;
	if (n == 2)
		return (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1])) / 2.0f;

	int m1 = median(ar1, n); /* get the median of the first array */
	int m2 = median(ar2, n); /* get the median of the second array */

							 /* If medians are equal then return either m1 or m2 */
	if (m1 == m2)
		return m1;

	/* if m1 < m2 then median must exist in ar1[m1....] and
	ar2[....m2] */
	if (m1 < m2)
	{
		if (n % 2 == 0)
		{
			ar1.assign(ar1.begin() + n / 2 - 1, ar1.end());
			ar2.assign(ar2.begin(), ar2.begin() + n / 2 + 1);
			return MediaArraySameSize(ar1, ar2);
		}
		else
		{
			ar1.assign(ar1.begin() + n / 2, ar1.end());
			ar2.assign(ar2.begin(), ar2.begin() + n / 2 + 1);
			return MediaArraySameSize(ar1, ar2);
		}
	}

	/* if m1 > m2 then median must exist in ar1[....m1] and
	ar2[m2...] */
	if (n % 2 == 0)
	{
		ar1.assign(ar1.begin(), ar1.begin() + n / 2 + 1);
		ar2.assign(ar2.begin() + n / 2 - 1, ar2.end());
		return MediaArraySameSize(ar1, ar2);
	}
	else
	{
		ar1.assign(ar1.begin(), ar1.begin() + n / 2 + 1);
		ar2.assign(ar2.begin() + n / 2, ar2.end());
		return MediaArraySameSize(ar1, ar2);
	}
}
#endif 