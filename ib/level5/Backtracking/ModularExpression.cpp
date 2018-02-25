/*************************************************************************************************
Reverse Link List Recursion

Reverse a linked list using recursion.

Example :
Given 1->2->3->4->5->NULL,
return 5->4->3->2->1->NULL.
*************************************************************************************************/
#include <vector>
#include <algorithm>
using namespace std;

#define OWN3

#ifdef OWN
int Mod(int A, int B, int C) {
	if (A == 0) return 0;
	else if (B == 0) return 1 % C;

	long long ans = 1;
	long long base = A;

	while (B)
	{
		if (B & 0x01)
		{
			ans = (ans * base) % C;
			B--;
		}
		else
		{
			base = (base * base) % C;
			B /= 2;
		}
	}

	while (ans < 0) ans += C;

	return (int)ans;
}
#else
int Mod(int x, int n, int p) {
	if (n == 0) return 1 % p;
	long long y = 0;
	if (n % 2 == 0) {
		y = Mod(x, n / 2, p);
		y = (y * y) % p;
	}
	else {
		y = x % p;
		y = (y * Mod(x, n - 1, p)) % p;
	}
	// Incase y is negative. 
	return (int)((y + p) % p);
}
#endif