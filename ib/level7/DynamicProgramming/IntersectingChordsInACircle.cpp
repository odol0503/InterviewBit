/*************************************************************************************************
Intersecting Chords in a Circle

Given a number N, return number of ways you can draw N chords in a circle with 2*N points 
such that no 2 chords intersect.
Two ways are different if there exists a chord which is present in one way and not in other.

For example,
N=2
If points are numbered 1 to 4 in clockwise direction, then different ways to draw chords are:
{(1-2), (3-4)} and {(1-4), (2-3)}

So, we return 2.
Notes:
1 ¡Â N ¡Â 1000
Return answer modulo 109+7.
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
#define MOD (long long)(1e9+7)

static long long fact(long long A)
{
	long long ret = 1;
	for (int i = 2; i <= A; i++)
	{
		ret = (ret * i) % MOD;
	}

	return ret;
}

long long pow2(long long A, long long radix, long long mod)
{
	if (radix == 0) return 1;

	long long val = 1;
	long long base = A;
	while (radix > 1)
	{
		if (radix & 0x01)
		{
			val = (val * base) % mod;
			radix--;
		}

		radix /= 2;
		base = (base * base) % mod;
	}

	return (val*base) % mod;
}

int IntersectingChordsInACircle(int A) {
	long long denom = (fact(A) * fact(A + 1)) % MOD;
	long long numer = fact(2 * A) % MOD;
	int ans = (int)((numer * pow2(denom, MOD - 2, MOD)) % MOD);
	return (int)ans;
}
#else
#define MOD 1000000007ll
typedef long long LL;
LL dp[1009];
LL rec(int n) {
	if (n == 0)return 1;
	LL &ret = dp[n];
	if (ret != -1)return ret;
	ret = 0;
	for (int i = 0; i<n; i++) {
		ret += (rec(i)*rec(n - i - 1)) % MOD;
		if (ret >= MOD)ret -= MOD;
	}
	return ret;
}

int IntersectingChordsInACircle(int A) {
	memset(dp, -1, sizeof(dp));
	return (int)rec(A);
}
#endif