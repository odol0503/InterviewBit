/*************************************************************************************************
Verify Prime

Given a number N, verify if N is prime or not.
Return 1 if N is prime, else return 0.

Example :
Input : 7
Output : True
*************************************************************************************************/
#include <vector>
#include <algorithm>

using namespace std;

#define OWN

#ifdef OWN
int VerifyPrime(int A) {
	int limit = (int)sqrt(A);

	if (A < 2) return 0;
	if (A == 2) return 1;

	for (int i = 2; i <= limit; i++)
	{
		if (A%i == 0) return 0;
	}

	return 1;
}
#else
int VerifyPrime(int n) {
	if (n < 2) return 0;
	int upperLimit = (int)(sqrt(n));
	for (int i = 2; i <= upperLimit; i++) {
		if (i < n && n % i == 0) return 0;
	}
	return 1;
}
#endif