/*************************************************************************************************
Square Root of Integer

Implement int sqrt(int x).
Compute and return the square root of x.
If x is not a perfect square, return floor(sqrt(x))

Example :
Input : 11
Output : 3
DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY
*************************************************************************************************/
#include <cmath>

#define OWN

#ifdef OWN
int SqrtInt(int A) 
{
	if (A < 2) return A;
	long long i = A / 2;
	long long start = 0;
	long long end = A;
	while (i*i > A || A >= (i + 1)*(i + 1))
	{
		if (i == 1) break;

		if (i*i < A)
		{
			start = i;
			i += (long long)((end - i) / 2);
		}
		else if (i*i > A)
		{
			end = i;
			i -= (long long)((i - start) / 2);
		}
	}

	return (int)i;
}
#else
int SqrtInt(int x)
{
	if (x == 0) return 0;
	int start = 1, end = x, ans;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (mid <= x / mid) {
			start = mid + 1;
			ans = mid;
		}
		else {
			end = mid - 1;
		}
	}
	return ans;
}
#endif