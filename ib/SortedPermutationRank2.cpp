/*************************************************************************************************
Sorted Permutation Rank with Repeats

Given a string, find the rank of the string amongst its permutations sorted lexicographically.
Note that the characters might be repeated. If the characters are repeated, we need to look at 
the rank in unique permutations.
Look at the example for more details.

Example :

Input : 'aba'
Output : 2

The order permutations with letters 'a', 'a', and 'b' :
aab
aba
baa
The answer might not fit in an integer, so return your answer % 1000003

NOTE: 1000003 is a prime number
NOTE: Assume the number of characters in string < 1000003
*************************************************************************************************/
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define MOD 1000003L

long long Factorial(int a)
{
	long long ret = 1;
	for (long long i = 2; i <= a; i++) ret = (ret * i) % MOD;
	return ret;
}

int FindPermutationRank2(string A) 
{
	int len = static_cast<int>(A.size());
	int rank = 0;

	for (int i = 0; i < len; i++)
	{
		int less = 0;
		for (int j = 0; j < len; j++)
		{
			if (A[i] > A[j]) less++;
		}

		rank = rank + (Factorial(len - i - 1)*less) % MOD;
	}

	return (int)(rank + 1) % MOD;
}
