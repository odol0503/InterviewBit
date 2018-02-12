/*************************************************************************************************
Min XOR value

Given an array of N integers, find the pair of integers in the array which have minimum XOR value. 
Report the minimum XOR value.

Examples :
Input
0 2 5 7
Output
2 (0 XOR 2)
Input
0 4 7 9
Output
3 (4 XOR 7)

Constraints:
2 <= N <= 100 000
0 <= A[i] <= 1 000 000 000
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN

#ifdef OWN
int FindMinXor(vector<int> &A)
{
	int len = (int)A.size();
	int ret = INT_MAX;

	sort(A.begin(), A.end());
	for (int i = 0; i < len - 1; i++)
	{
		ret = min(ret, A[i] ^ A[i+1]);
	}

	return ret;
}
#else
int FindMinXor(vector<int> &A)
{
	sort(numbers.begin(), numbers.end());
	int smallestXor = numbers[0] ^ numbers[1];
	for (int i = 2; i &lt; numbers.size(); i++) {
		smallestXor = min(smallestXor, numbers[i - 1] ^ numbers[i]);
	}
	return smallestXor;
}
#endif