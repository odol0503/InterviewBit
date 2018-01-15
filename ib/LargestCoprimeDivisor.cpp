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
	int X = 0;
	while ((X = GCD2(A, B)) != 1)
	{
		A = A / X;
	}
	return A;
}