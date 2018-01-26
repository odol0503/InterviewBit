/*************************************************************************************************
Reverse integer

Reverse digits of an integer.

Example1:
x = 123,
return 321

Example2:
x = -123,
return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer
See Expected Output
*************************************************************************************************/
#include <climits>
int ReverseInt(int A) 
{
	int sign = A < 0 ? -1 : 1;
	A *= sign;
	int rev = 0;
	while (A > 0)
	{
		int mod = A % 10;
		if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && mod > INT_MAX%10)) return 0;
		A /= 10;
		rev = rev * 10 + mod;
	}

	return rev*sign;
}