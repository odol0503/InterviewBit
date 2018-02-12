/*************************************************************************************************
Divide Integers

Divide two integers without using multiplication, division and mod operator.

Return the floor of the result of the division.
Example:
5 / 2 = 2
Also, consider if there can be overflow cases. For overflow case, return INT_MAX.
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
int DivideIntegers(int A, int B) {
	long long ret = 0;
	long long temp = 0;
	int signA = (A & (1U << 31) ? -1 : 1);
	int signB = (B & (1U << 31) ? -1 : 1);

	if (A == INT_MIN) temp = (long long)INT_MAX + 1;
	else if (signA == -1) temp = A * -1;
	else temp = A;

	if (signB == -1) B *= -1;

	long long pos = (long long)B;
	long long cnt = 0;

	while (temp >= pos)
	{
		pos <<= 1;
		cnt++;
	}

	while (pos)
	{
		if (temp >= pos && cnt >=0)
		{
			temp -= pos;
			ret += 1LL<<cnt;
		}
		pos >>= 1;
		cnt--;
	}

	ret = ret * signA * signB;
	if (ret > INT_MAX) return INT_MAX;

	return (int)ret;
}
#else
int DivideIntegers(int dividend, int divisor) {
	long long n = dividend, m = divisor;
	// determine sign of the quotient
	int sign = n < 0 ^ m < 0 ? -1 : 1;

	// remove sign of operands
	n = abs(n), m = abs(m);

	// q stores the quotient in computation
	long long q = 0;

	// test down from the highest bit
	// accumulate the tentative value for valid bits
	for (long long t = 0, i = 31; i >= 0; i--)
		if (t + (m << i) <= n)
			t += m << i, q |= 1LL << i;

	// assign back the sign
	if (sign < 0) q = -q;

	// check for overflow and return
	return q >= INT_MAX || q < INT_MIN ? INT_MAX : q;
}
#endif