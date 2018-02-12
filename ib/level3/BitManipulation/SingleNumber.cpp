/*************************************************************************************************
Single Number

Given an array of integers, every element appears twice except for one. Find that single one.

Note: Your algorithm should have a linear runtime complexity.
Could you implement it without using extra memory?

Example :
Input : [1 2 2 3 1]
Output : 3
*************************************************************************************************/
#include <vector>
using namespace std;

#define OWN

#ifdef OWN
int SingleNumber(const vector<int> &A) {
	int ret = 0;
	
	for (size_t i = 0; i<A.size(); i++)
	{
		ret ^= A[i];
	}

	return ret;
}
#else
int SingleNumber(const vector<int> &A) {
	int n = A.size();
	int result = 0;
	for (int i = 0; i < n; i++) {
		result ^= A[i];
	}
	return result;
}
#endif