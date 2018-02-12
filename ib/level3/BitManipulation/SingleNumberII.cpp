/*************************************************************************************************
Single Number II

Given an array of integers, every element appears thrice except for one which occurs once.
Find that element which does not appear thrice.

Note: Your algorithm should have a linear runtime complexity.
Could you implement it without using extra memory?

Example :
Input : [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
Output : 4
*************************************************************************************************/
#include <vector>
using namespace std;

#define OWN

#ifdef OWN
int SingleNumber2(const vector<int> &A) {
	int len = (int)A.size();
	int ret = 0;

	for (int i = 31; i >= 0; i--)
	{
		int cnt0 = 0;
		int cnt1 = 0;
		for (int j = 0; j<len; j++)
		{
			if ((A[j] >> i) & 0x01) cnt1++;
		}

		if (cnt1 % 3) ret |= 0x01 << i;
	}

	return ret;
}
#else
int SingleNumber2(const vector<int> &A) {
	int n = A.size();
	int count[32] = { 0 };
	int result = 0;
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < n; j++) {
			if ((A[j] >> i) & 1) {
				count[i]++;
			}
		}
		result |= ((count[i] % 3) << i);
	}
	return result;
}
#endif