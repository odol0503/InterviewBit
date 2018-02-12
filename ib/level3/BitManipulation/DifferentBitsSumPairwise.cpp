/*************************************************************************************************
Different Bits Sum Pairwise

We define f(X, Y) as number of different corresponding bits in binary representation of X and Y.
For example, f(2, 7) = 2, since binary representation of 2 and 7 are 010 and 111, respectively.
The first and the third bit differ, so f(2, 7) = 2.

You are given an array of N positive integers, A1, A2 ,¡¦, AN. Find sum of f(Ai, Aj) 
for all pairs (i, j) such that 1 ¡Â i, j ¡Â N. Return the answer modulo 109+7.

For example,
A=[1, 3, 5]

We return
f(1, 1) + f(1, 3) + f(1, 5) +
f(3, 1) + f(3, 3) + f(3, 5) +
f(5, 1) + f(5, 3) + f(5, 5) =

0 + 1 + 1 +
1 + 0 + 2 +
1 + 2 + 0 = 8
*************************************************************************************************/
#include <vector>
using namespace std;

#define OWN

#ifdef OWN
#define MOD 1000000007

int DifferentBitsSumPairwise(vector<int> &A) 
{
	size_t len = A.size();
	long long ret = 0;

	for (int i = 0; i<32; i++)
	{
		long long cnt0 = 0;
		long long cnt1 = 0;
		for (size_t k = 0; k<len; k++)
		{
			if ((A[k] >> i) & 1) cnt1 = (cnt1 + 1) % MOD;
			else cnt0 = (cnt0 + 1) % MOD;
		}
		ret = (ret + ((2 * ((cnt0 * cnt1) % MOD)) % MOD)) % MOD;
	}

	return (int)ret;
}
#else
typedef long long LL;
#define MOD 1000000007ll

int DifferentBitsSumPairwise(vector<int> &A)
{
	int ans = 0, n = A.size();

	//traverse over all bits
	for (int i = 0; i<31; i++) {
		//count number of elements with ith bit = 0
		LL cnt = 0;
		for (int j = 0; j<n; j++)
			if ((A[j] & (1 << i)))cnt++;

		//add to answer cnt*(n-cnt)*2
		ans += (cnt*((LL)n - cnt) * 2) % MOD;
		if (ans >= MOD)ans -= MOD;
	}

	return ans;
}
#endif