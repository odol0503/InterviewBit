/*************************************************************************************************
Grid Unique Paths

A robot is located at the top-left corner of an A x B grid (marked ¡®Start¡¯ in the diagram below).

Path Sum: Example 1
The robot can only move either down or right at any point in time. The robot is trying to reach 
the bottom-right corner of the grid (marked ¡®Finish¡¯ in the diagram below).
How many possible unique paths are there?
Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.

Example :
Input : A = 2, B = 2
Output : 2

2 possible routes : (0, 0) -> (0, 1) -> (1, 1)
OR  : (0, 0) -> (1, 0) -> (1, 1)
*************************************************************************************************/
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
long long Factorial3(int a)
{
	long long f = 1;
	for (int i = 2; i <= a; i++)
	{
		f *= i;
	}

	return f;
}

int UniquePaths(int A, int B) 
{
	if (A == 1 || B == 1) return 1;
	int t = A + B - 2;
	int n = max(A, B) - 1;

	long long temp = 1;
	for (int i = n+1; i <= t; i++)
	{
		temp *= i;
	}

	return (int)(temp / Factorial3(t-n));
}
#else
int UniquePaths(int A, int B)
{
	// m+n-2 C n-1 = (m+n-2)! / (n-1)! (m-1)! 
	long long ans = 1;
	for (int i = n; i < (m + n - 1); i++) {
		ans *= i;
		ans /= (i - n + 1);
	}
	return (int)ans;
}
#endif