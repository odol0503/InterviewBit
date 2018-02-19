/*************************************************************************************************
Power Of Two Integers

Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed 
as A^P where P > 1 and A > 0. A and P both should be integers.

Example

Input : 4
Output : True
as 2^2 = 4.
*************************************************************************************************/
#include <cmath>
#include <vector>
using namespace std;

#define OWN

#ifdef OWN
vector<int> GetPrimes(int A)
{
	int sr = static_cast<int>(floor(sqrt(A)));
	vector<int> prime = { 2 };
	for (int i = 3; i <= sr; i++)
	{
		bool isPrime = true;
		for (auto p : prime)
		{
			if (i % p == 0) isPrime = false;
		}

		if (isPrime)
		{
			prime.push_back(i);
		}
	}

	return prime;
}

int IsPower(int A)
{
	if (A == 1) return true;
	vector<int> primes = GetPrimes(A);

	vector<int> cnts;
	for (auto p : primes)
	{
		int cnt = 0;
		while (A%p == 0)
		{
			A /= p;
			cnt++;
		}
		if (cnt > 0)
		{
			cnts.push_back(cnt);
		}
	}

	if (A > 1) cnts.push_back(A);

	for (auto p : primes)
	{
		bool bPower = true;
		for (auto c : cnts)
		{
			if (c%p != 0)
			{
				bPower = false;
				break;
			}
		}
		if (bPower == true)
		{
			return true;
		}
	}

	return false;
}
#else
int IsPower(int x)
{
	if (x <= 1) return true;
	for (int base = 2; base < x && base < INT_MAX / base; base++) {
		int temp = base;
		while (temp <= x && temp < INT_MAX / base) {
			temp *= base;
			if (temp == x) return true;
		}
	}
	return false;
}
#endif