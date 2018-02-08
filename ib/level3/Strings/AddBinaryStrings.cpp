/*************************************************************************************************
Add Binary Strings

Given two binary strings, return their sum (also a binary string).

Example:
a = "100"
b = "11"
Return a + b = ¡°111¡±.
*************************************************************************************************/
#include <algorithm>
#include <string>
using namespace std;

#define OWN

#ifdef OWN
string AddBinary(string A, string B) 
{
	string ans;
	int carry = 0;
	int lenA = (int)A.size();
	int lenB = (int)B.size();
	
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	int i = 0;
	for (; i < lenA && i < lenB; i++)
	{
		int temp = A[i] - '0' + B[i] - '0' + carry;
		carry = 0;

		if (temp == 0) ans += "0";
		else if (temp == 1) ans += "1";
		else if (temp == 2)
		{
			ans += "0";
			carry = 1;
		}
		else
		{
			ans += "1";
			carry = 1;
		}
	}

	string str;
	if (i < lenA) str.assign(A.begin() + i, A.end());
	else if (i < lenB) str.assign(B.begin() + i, B.end());

	for (size_t j = 0; j < str.size(); j++)
	{
		int temp = str[j] - '0' + carry;
		carry = 0;
		if (temp == 0) ans += "0";
		else if (temp == 1) ans += "1";
		else
		{
			ans += "0";
			carry = 1;
		}
	}

	if (carry == 1) ans += "1";

	reverse(ans.begin(), ans.end());
	return ans;
}
#else
string AddBinary(string a, string b)
{
	string ans = "";
	int ansLen = 0, carry = 0, sum;
	int i = (int)a.length() - 1, j = (int)b.length() - 1;
	while (i >= 0 || j >= 0 || carry) {
		sum = carry;
		if (i >= 0) sum += (a[i] - '0');
		if (j >= 0) sum += (b[j] - '0');
		ans.push_back((char)('0' + sum % 2));
		carry = sum / 2;
		i--;
		j--;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
#endif