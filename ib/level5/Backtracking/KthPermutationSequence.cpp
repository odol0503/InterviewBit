/*************************************************************************************************
Kth Permutation SequenceBookmark Suggest Edit
The set [1,2,3,¡¦,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3 ) :

1. "123"
2. "132"
3. "213"
4. "231"
5. "312"
6. "321"
Given n and k, return the kth permutation sequence.

For example, given n = 3, k = 4, ans = "231"

Good questions to ask the interviewer :
What if n is greater than 10. How should multiple digit numbers be represented in string?
In this case, just concatenate the number to the answer.
so if n = 11, k = 1, ans = "1234567891011"
Whats the maximum value of n and k?
In this case, k will be a positive integer thats less than INT_MAX.
*************************************************************************************************/
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define OWN

#ifdef OWN
static void NextPermutation(vector<int> &A)
{
	int len = (int)A.size();
	int i = len - 1;
	for (; i>0; i--)
	{
		if (A[i - 1] < A[i])
		{
			int j = len - 1;
			while (A[i - 1] >= A[j]) j--;
			swap(A[i - 1], A[j]);
			break;
		}
	}
	reverse(A.begin() + i, A.end());
}

string GetPermutation(int A, int B) {
	vector<int> num;
	string ret;

	for (int i = 1; i <= A; i++) num.push_back(i);
	for (int i = 1; i<B; i++) NextPermutation(num);
	for (int i = 0; i<(int)num.size(); i++) ret += to_string(num[i]);
	return ret;
}
#else
int factorial(int n) {
	if (n > 12) {
		// this overflows in int. So, its definitely greater than k
		// which is all we care about. So, we return INT_MAX which
		// is also greater than k.
		return INT_MAX;
	}
	// Can also store these values. But this is just < 12 iteration, so meh!
	int fact = 1;
	for (int i = 2; i <= n; i++) fact *= i;
	return fact;
	}

string getPermutation(int k, vector<int> &candidateSet) {
	int n = candidateSet.size();
	if (n == 0) {
		return "";
	}
	if (k > factorial(n)) return ""; // invalid. Should never reach here.

	int f = factorial(n - 1);
	int pos = k / f;
	k %= f;
	string ch = to_string(candidateSet[pos]);
	// now remove the character ch from candidateSet. 
	candidateSet.erase(candidateSet.begin() + pos);
	return ch + getPermutation(k, candidateSet);
}

string GetPermutation(int n, int k) {
	vector<int> candidateSet;
	for (int i = 1; i <= n; i++) candidateSet.push_back(i);
	return getPermutation(k - 1, candidateSet);
}
#endif