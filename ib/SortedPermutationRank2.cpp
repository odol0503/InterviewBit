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
#include <cstring>
using namespace std;
#define OWN

#define MOD 1000003L

#ifdef OWN
int Factorial(int a)
{
	int ret = 1;
	for (int i = 2; i <= a; i++) ret = (ret * i) % MOD;
	return ret;
}

int inverse(int a, int b) {
	int r1, r2, q, r, t, t1, t2;
	r1 = a;
	r2 = b;
	t1 = 0; t2 = 1;

	while (r1 != 1)
	{
		q = r2 / r1;
		r = r2 - r1*q;
		t = t1 - t2*q;
		r2 = r1;
		r1 = r;
		t1 = t2;
		t2 = t;
	}
	if (t2 < 0)
		t2 = t2 + b;
	return t2;
}

int FindPermutationRank2(string A) 
{
	int len = static_cast<int>(A.size());
	int rank = 0;
	char temp[256];
	memset(temp, 0, 256);

	for (int i = 0; i < len; i++)
	{
		temp[A[i]]++;
	}

	
	for (int i = 0; i < len; i++)
	{
		int less = 0;
		int dup = 1;
		for (int j = 0; j < 256; j++)
		{
			if (temp[j] > 1)
			{
				dup = (dup * (inverse(Factorial(temp[j]), MOD) % MOD)) % MOD;
			}
		}

		for (int k = i + 1; k < len; k++)
		{
			if (A[k] < A[i]) less++;
		}

		rank = (rank + (((Factorial(len - i - 1) * less) % MOD) * dup) % MOD) % MOD;

		temp[A[i]]--;
	}

	return (int)((rank + 1) % MOD);
}
#else
int Factorial(int a)
{
	int ret = 1;
	for (int i = 2; i <= a; i++) ret = (ret * i) % MOD;
	return ret;
}

int inverse(int a, int b) {
	int r1, r2, q, r, t, t1, t2;
	r1 = a;
	r2 = b;
	t1 = 0; t2 = 1;

	while (r1 != 1)
	{
		q = r2 / r1;
		r = r2 - r1*q;
		t = t1 - t2*q;
		r2 = r1;
		r1 = r;
		t1 = t2;
		t2 = t;
	}
	if (t2 < 0)
		t2 = t2 + b;
	return t2;
}

int FindPermutationRank2(string S) {
	int charCount[256]; // count of characters in S. 
	memset(charCount, 0, sizeof(charCount));
	for (int i = 0; i < S.length(); i++) charCount[S[i]]++;

	long long rank = 0;
	for (int i = 0; i < S.length(); i++) {
		// find number of characters smaller than S[i] still left. 
		int less = 0;
		long long dup = 1;
		for (int ch = 0; ch < S[i]; ch++) {
			less += charCount[ch];
		}

		for (int j = 0; j < 256; j++)
		{
			if (charCount[j] > 1)
			{
				int cnt = charCount[j];
				dup = (dup * (inverse(Factorial(cnt), MOD) % MOD)) % MOD;
			}
		}
		long long fact = Factorial(S.length() - i - 1);
		rank = (rank + (((fact * less) % MOD) * dup) % MOD) % MOD;
		// remove the current character from the set. 
		charCount[S[i]]--;
	}
	return (int)((rank + 1) % MOD);
}
#else
void initializeFactorials(int totalLen, vector<int> &fact) {
	long long int factorial = 1;
	fact.push_back(1); // 0!= 1
	for (int curIndex = 1; curIndex < totalLen; curIndex++) {
		factorial = (factorial * curIndex) % MOD;
		fact.push_back(factorial);
	}
	return;
}

long long int inverseNumber(int num) {
	// Inverse modulo : https://en.wikipedia.org/wiki/Modular_multiplicative_inverse
	// Calculate num ^ MOD-2  % MOD
	long long int ans = 1, base = (long long)num;
	int power = MOD - 2;
	while (power > 0) {
		if (power == 1) {
			return (ans * base) % MOD;
		}
		if (power % 2 == 0) {
			base = (base * base) % MOD;
			power /= 2;
		}
		else {
			ans = (ans * base) % MOD;
			power--;
		}
	}
	return ans;
}

int findRank(string S) {
	// Initializations

	int charCount[256]; // count of characters in S. 
	memset(charCount, 0, sizeof(charCount));
	for (int i = 0; i < S.length(); i++) charCount[S[i]]++;

	vector<int> fact; // fact[i] will contain i! % MOD
	initializeFactorials(S.length() + 1, fact);

	long long int rank = 1;
	for (int i = 0; i < S.length(); i++) {
		// find number of permutations placing character smaller than S[i] at ith position 
		// among characters from i to S.length 
		long long int less = 0;
		int remaining = S.length() - i - 1;
		for (int ch = 0; ch < S[i]; ch++) {
			if (charCount[ch] == 0) continue;
			// Lets try placing ch as the first character in remaining characters
			// and check the number of permutation possible.
			charCount[ch]--;
			long long int numPermutation = fact[remaining];

			for (int c = 0; c < 128; c++) {
				if (charCount[c] <= 1) continue;
				numPermutation = (numPermutation * inverseNumber(fact[charCount[c]])) % MOD;
			}

			charCount[ch]++;
			less = (less + numPermutation) % MOD;
		}

		rank = (rank + less) % MOD;
		// remove the current character from the set. 
		charCount[S[i]]--;
	}
	return rank;
}
#endif