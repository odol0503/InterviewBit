/*************************************************************************************************
Palindrome Integer

Determine whether an integer is a palindrome. Do this without extra space.
A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.
Example :
Input : 12121
Output : True

Input : 123
Output : False
*************************************************************************************************/
#include <cmath>

#define OWN7

#ifdef OWN
int IsPalindrome(int A)
{
	if (A < 0) return 0;
	int cnt = 0;
	int temp = A;
	while (temp > 0)
	{
		temp /= 10;
		cnt++;
	}

	for (int i = 0; i < cnt/2; i++)
	{
		int l = (A / static_cast<int>(pow(10,cnt-i-1))) % 10;
		int r = (A / static_cast<int>(pow(10, i))) % 10;
		if (l != r) return 0;
	}

	return 1;
}
#else
int reverse(int x) {
	int rev = 0, digit;
	while (x > 0) {
		digit = x % 10;
		// check for overflow here
		if (rev > (INT_MAX / 10) || (rev == (INT_MAX / 10) && digit > (INT_MAX % 10))) {
			return -1;
		}
		rev = rev * 10 + digit;
		x /= 10;
	}
	return rev;
}

int IsPalindrome(int x) {
	if (x < 0) return false;
	// Lets try reversing x. If reverse overflows, 
	// then the number is not palindromic anyway. 
	return x == reverse(x);
}
#endif