/*************************************************************************************************
Find Permutation

Given a positive integer n and a string s consisting only of letters D or I, you have to find 
any permutation of first n positive integer that satisfy the given input string.
D means the next number is smaller, while I means the next number is greater.

Notes
Length of given string s will always equal to n - 1
Your solution should run in linear time and space.
Example :
Input 1:
n = 3
s = ID
Return: [1, 3, 2]
*************************************************************************************************/
#include <vector>
#include <cassert>
using namespace std;

#define OWN

#ifdef OWN
vector<int> FindPermutation(const string A, int B)
{
	vector<int> ret;
	int len = static_cast<int>(A.size());
	assert(len == B - 1);
	int max_value = B;
	int min_value = 1;
	for (int i = 0; i < len; i++)
	{
		if (A[i] == 'I')
		{
			ret.push_back(min_value++);
		}
		else if (A[i] == 'D')
		{
			ret.push_back(max_value--);
		}
		else assert(0);
	}

	if (min_value == max_value) ret.push_back(min_value);

	return ret;
}
#else
vector<int> FindPermutation(const string A, int B)
{
	assert(A.length() == (B - 1));
	for (int i = 0; i < B - 1; i++) assert((A[i] == 'I') || (A[i] == 'D'));

	vector<int> ans(B); int start = 1, upto = B;
	for (int i = 0; i < B && (start < upto); i++) {
		if (A[i] == 'D') ans[i] = upto--;
		else ans[i] = start++;
	}
	assert(start == upto);
	ans[B - 1] = start;
	return ans;
}
#endif 