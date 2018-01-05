/*************************************************************************************************
Prime Sum

Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.
NOTE A solution will always exist. read Goldbach��s conjecture
Example:
Input : 4
Output: 2 + 2 = 4

If there are more than one solutions possible, return the lexicographically smaller solution.
If [a, b] is one solution with a <= b,
and [c,d] is another solution with c <= d, then

[a, b] < [c, d]
If a < c OR a==c AND b < d.
*************************************************************************************************/
#include <vector>
#include <memory>
using namespace std;

vector<int> PrimeSum(int A)
{
	vector<int> ret;
	unique_ptr<bool> p(new bool[A]);
	bool *primes = p.get();
	for (int i = 0; i < A; i++) primes[i] = true;

	for (int i = 2; i*i < A; i++)
	{
		if (primes[i] == false) continue;
		for (int j = i*2; j < A; j+=i)
		{
			if (primes[j] == 1) primes[j] = false;
		}
	}

	for (int i = 2; i < A; i++)
	{
		if (primes[i] && primes[A-i])
		{
			ret.push_back(i);
			ret.push_back(A - i);
			return ret;
		}
	}

	return ret;
}