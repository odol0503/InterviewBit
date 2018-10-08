/*************************************************************************************************
Stringoholics

You are given an array A consisting of strings made up of the letters ¡®a¡¯ and ¡®b¡¯ only.
Each string goes through a number of operations, where:
  1) At time 1, you circularly rotate each string by 1 letter.
  2) At time 2, you circularly rotate the new rotated strings by 2 letters.
  3) At time 3, you circularly rotate the new rotated strings by 3 letters.
  4) At time i, you circularly rotate the new rotated strings by i % length(string) letters.

Eg: String is abaa
  1) At time 1, string is baaa, as 1 letter is circularly rotated to the back
  2) At time 2, string is aaba, as 2 letters of the string baaa is circularly rotated to the back
  3) At time 3, string is aaab, as 3 letters of the string aaba is circularly rotated to the back
  4) At time 4, string is again aaab, as 4 letters of the string aaab is circularly rotated to the back
  5) At time 5, string is aaba, as 1 letters of the string aaab is circularly rotated to the back

After some units of time, a string becomes equal to it¡¯s original self.
Once a string becomes equal to itself, it¡¯s letters start to rotate from the first letter again 
(process resets). So, if a string takes t time to get back to the original, at time t+1 one letter 
will be rotated and the string will be it¡¯s original self at 2t time.
You have to find the minimum time, where maximum number of strings are equal to their original self.
As this time can be very large, give the answer modulo 109+7.

Note: Your solution will run on multiple test cases so do clear global variables after using them.

Input:
A: Array of strings.
Output:

Minimum time, where maximum number of strings are equal to their original self.
Constraints:

1 <= size(A) <= 10^5
1 <= size of each string in A <= 10^5
Each string consists of only characters 'a' and 'b'
Summation of length of all strings <= 10^7
Example:

Input

A: [a,ababa,aba]
Output

4

String 'a' is it's original self at time 1, 2, 3 and 4.
String 'ababa' is it's original self only at time 4. (ababa => babaa => baaba => babaa => ababa)
String 'aba' is it's original self at time 2 and 4. (aba => baa => aba)

Hence, 3 strings are their original self at time 4.
*************************************************************************************************/
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define OWN

#ifdef OWN
#define MOD 1000000007LL

int gcd(int a, int b)
{
	if (a < b) swap(a, b);
	if (b == 0) return a;
	return gcd(a%b, b);
}

string rotate(string &A, int n)
{
	int len = (int)A.size();
	if (n >= len) n %= len;
	if (n == 0) return A;

	string temp = A.substr(n, string::npos);
	temp += A.substr(0, n);
	return temp;
}

static long long pow2(int A, int B, int mod)
{
	long long base = A;
	long long ans = 1;

	if (B == 0) return 1;
	if (B == 1) return A;

	while (B > 1)
	{
		if (B % 2) ans = (ans*base) % MOD;
		base = (base*base) % MOD;
		B /= 2;
	}

	return (ans*base) % MOD;
}

int Stringoholics(vector<string> &A) {
	int num = (int)A.size();
	vector<long long> val;

	for (int i = 0; i<num; i++)
	{
		string temp = A[i];
		int j = 1;
		do
		{
			temp = rotate(temp, j);
			j++;
		} while (A[i] != temp);

		val.push_back(j - 1);
		j = 0;
		temp.clear();
	}

	long long ret = 0;
	vector<long long> temp;

	while (num > 1)
	{
		for (int i = 0; i<num / 2; i++)
		{
			temp.push_back(((val[i] * val[num - i - 1]) % MOD) / gcd(val[i], val[num - i - 1]));
		}

		if (num % 2) temp.push_back(val[num / 2]);

		num = temp.size();
		swap(temp, val);
		temp.clear();
	}

	return val[0];
}
#else

#endif