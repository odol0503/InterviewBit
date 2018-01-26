/*************************************************************************************************
Greatest Common Divisor

Given 2 non negative integers m and n, find gcd(m, n)
GCD of 2 integers m and n is defined as the greatest integer g such that g is a divisor of both m and n.
Both m and n fit in a 32 bit signed integer.

Example
m : 6
n : 9

GCD(m, n) : 3
*************************************************************************************************/
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
int GCD(int A, int B) 
{
	int min_value = min(A, B);
	int diff = abs(A - B);

	if (A == 0) return B;
	if (B == 0) return A;

	while (diff)
	{
		int temp = min(min_value, diff);
		diff = abs(min_value - diff);
		min_value = temp;
	}

	return min_value;
}
#else
int GCD(int m, int n)
{
	if (m < n)
		swap(m, n);

	if (n == 0)
		return m;


	return GCD(m % n, n);
}
#endif
