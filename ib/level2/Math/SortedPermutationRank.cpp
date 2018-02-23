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
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define OWN

#ifdef OWN
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
		for (int j = 0; j < len; j++)
		{
			if (f[j] == A[i])
			{
				f.erase(j, 1);
				break;
			}
			cnt++;
		}
		order += (Factorial(len - i - 1) * cnt) % 1000003L;
	}

	return (int)((order + 1) % 1000003L);
}
#else
#define MOD 1000003

void initializeFactorials(int totalLen, vector<int> &fact) {
	long long int factorial = 1;
	fact.push_back(1); // 0!= 1
	for (int curIndex = 1; curIndex < totalLen; curIndex++) {
		factorial = (factorial * curIndex) % MOD;
		fact.push_back(factorial);
	}
	return;
}

int FindPermutationRank(string S)
{
	int charCount[256]; // count of characters in S. 
	memset(charCount, 0, sizeof(charCount));
	for (int i = 0; i < S.length(); i++) charCount[S[i]]++;

	vector<int> fact; // fact[i] will contain i! % MOD
	initializeFactorials(S.length() + 1, fact);

	long long int rank = 1;
	for (int i = 0; i < S.length(); i++) {
		// find number of characters smaller than S[i] still left. 
		int less = 0;
		for (int ch = 0; ch < S[i]; ch++) {
			less += charCount[ch];
		}
		rank = (rank + ((long long)fact[S.length() - i - 1] * less)) % MOD;
		// remove the current character from the set. 
		charCount[S[i]]--;
	}
	return rank;
}
#endif