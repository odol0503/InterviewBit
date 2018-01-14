/*************************************************************************************************
Sorted Permutation Rank

Given a string, find the rank of the string amongst its permutations sorted lexicographically.
Assume that no characters are repeated.

Example :

Input : 'acb'
Output : 2

The order permutations with letters 'a', 'c', and 'b' :
abc
acb
bac
bca
cab
cba
The answer might not fit in an integer, so return your answer % 1000003
*************************************************************************************************/
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

long long Factorial(int a)
{
	long long fact = 1;
	for (long long i = 2; i <= a; i++)
	{
		fact *= i;
		fact %= 1000003L;
	}
	return fact;
}


int FindPermutationRank(string A) 
{
	int len = static_cast<int>(A.size());
	if (len < 2) return 1;
	string f(A);
	sort(f.begin(), f.end());
	long long order = 0;

	for (int i = 0; i < len - 1; i++)
	{
		long long cnt = 0;
		for (int j = i; j < len; j++)
		{
			if (f[j] == A[i])
			{
				break;
			}
			cnt++;
		}
		order += (Factorial(len - i - 1) *cnt) % 1000003;
	}

	return (int)((order + 1) % 1000003);
}