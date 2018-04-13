/*************************************************************************************************
N digit numbers with digit sum S

Find out the number of N digit numbers, whose digits on being added equals to a given number S.
Note that a valid number starts from digits 1-9 except the number 0 itself. 
i.e. leading zeroes are not allowed.

Since the answer can be large, output answer modulo 1000000007

N = 2, S = 4
Valid numbers are {22, 31, 13, 40}
Hence output 4.
*************************************************************************************************/
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
#define MOD 1000000007

static void sum(int A, int B, int depth, int &ret)
{
	if (A == 0)
	{
		if (B == 0) ret = (ret + 1) % MOD;
		return;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (depth == 0 && i == 0) continue;
		sum(A - 1, B - i, depth + 1, ret);
	}
}

int digitNumWithSum(int A, int B) {
	int ret = 0;
	sum(A, B, 0, ret);
	return ret;
}
#else

#endif