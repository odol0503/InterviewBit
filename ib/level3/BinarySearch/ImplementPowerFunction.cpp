/*************************************************************************************************
Implement Power Function

Implement pow(x, n) % d.
In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative.
In other words, make sure the answer you return is non negative.

Input : x = 2, n = 3, d = 3
Output : 2

2^3 % 3 = 8 % 3 = 2.
*************************************************************************************************/
#include <vector>
using namespace std;

#define OWN

#ifdef OWN
int Pow(int x, int n, int d) 
{
	long long ans = 1;

	while (n)
	{
		if (n & 0x01)
		{
			ans = (ans * x) % d;
			n--;
		}
		else {
			x = ((long long)x * x)%d;
			n /= 2;
		}
	}
	
	if (ans <= 0)
	{
		while (ans < 0) ans += d;
	}
	return ans % d;
	
}
#else

#endif