/*************************************************************************************************
Largest Coprime Divisor

You are given two positive numbers A and B. You need to find the maximum valued integer X such that:

X divides A i.e. A % X = 0
X and B are co-prime i.e. gcd(X, B) = 1
For example,

A = 30
B = 12
We return
X = 5
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

int GCD2(int a, int b)
{
	if (a < b) swap(a, b);
	if (b == 0) return a;
	return GCD2(a%b, b);
}

int CoprimeDivisor(int A, int B) 
{
	vector<int> xlist;
	int x = 1;
	for (int i = 2; i<=A; i++)
	{
		if (A%i == 0) xlist.push_back(i);
	}

	for (auto a : xlist)
	{
		if (GCD2(a, B) == 1)
		{
			x = max(x, a);
		}
	}

	return x;
}