/*************************************************************************************************
Sum of pairwise Hamming Distance

Hamming distance between two non-negative integers is defined as the number of positions at which
the corresponding bits are different.

For example,
HammingDistance(2, 7) = 2, as only the first and the third bit differs in the binary representation 
of 2 (010) and 7 (111).
Given an array of N non-negative integers, find the sum of hamming distances of all pairs of
integers in the array.
Return the answer modulo 1000000007.
Example
Let f(x, y) be the hamming distance defined above.
A=[2, 4, 6]

We return,
f(2, 2) + f(2, 4) + f(2, 6) +
f(4, 2) + f(4, 4) + f(4, 6) +
f(6, 2) + f(6, 4) + f(6, 6) =

0 + 2 + 1
2 + 0 + 1
1 + 1 + 0 = 8
*************************************************************************************************/
#include <vector>
using namespace std;

#define OWN

#ifdef OWN
int HammingDistance(const vector<int> &A)
{
	int len = static_cast<int>(A.size());
	int mod = 1000000007;
	int sum = 0;
	uint32_t bit = 0x1;
	for (int i = 0; i < 31; i++)
	{
		int x = 0, y = 0;
		for (int j = 0; j < len; j++)
		{
			if (A[j] & bit) y++;
			else x++;
		}
		bit <<= 1;
		sum += (2LL * x * y) % mod;
		if (sum > mod) sum %= mod;
	}

	return sum;
}
#else
int HammingDistance(const vector<int> &A)
{
	int inputSize = A.size();
	int mod = 1000000007;
	int sum = 0;
	for (int bitPosition = 0; bitPosition < 31; bitPosition++) {
		int cntBitOne = 0, cntBitZero = 0;
		for (int i = 0; i < inputSize; i++) {
			if (A[i] & (1 << bitPosition)) cntBitOne++;
			else cntBitZero++;
		}
		sum = sum + ((2LL * cntBitOne * cntBitZero) % mod);
		if (sum >= mod) sum = sum - mod;
	}
	return sum;
}
#endif