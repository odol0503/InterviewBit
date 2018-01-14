/*************************************************************************************************
Trailing Zeros in Factorial

Given an integer n, return the number of trailing zeroes in n!.
Note: Your solution should be in logarithmic time complexity.

Example :
n = 5
n! = 120
Number of trailing zeros = 1
So, return 1
*************************************************************************************************/
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
int TrailingZeroes(int A)
{
	int cnt2 = 0;
	int cnt5 = 0;

	for (int i = 2; i <= A; i++)
	{
		int temp = i;
		while (temp % 2 == 0)
		{
			cnt2++;
			temp /= 2;
		}

		temp = i;
		while (temp % 5 == 0)
		{
			cnt5++;
			temp /= 5;
		}
	}

	return min(cnt2, cnt5);
}
#else
int TrailingZeroes(int A)
{
	int sum = 0;
	while (n / 5 > 0) {
		sum += (n / 5);
		n /= 5;
		}
	return sum;
}
#endif
