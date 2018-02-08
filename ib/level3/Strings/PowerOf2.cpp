/*************************************************************************************************
Power of 2

Find if Given number is power of 2 or not.
More specifically, find if given number can be expressed as 2^k where k >= 1.

Input:
number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)
Output:
return 1 if the number is a power of 2 else return 0

Example:
Input : 128
Output : 1
*************************************************************************************************/
#include <vector>
#include <string>
using namespace std;

#define OWN

#ifdef OWN
string Div2(string &A)
{
	int len = (int)A.size();
	int carry = 0;
	string ret;

	for (int i = 0; i < len; i++)
	{
		int val = (A[i] - '0') / 2 + carry;
		if (val || i!=0) ret.push_back(val + '0');
		if ((A[i] - '0') % 2) carry = 5;
		else carry = 0;
	}

	if (carry) return "MOD";

	return ret;
}

int PowerOf2(string A) {
	string temp(A);
	while (temp != "2" && temp != "1")
	{
		temp = Div2(temp);
		if (temp == "MOD") return 0;
	}

	if (temp == "2") return 1;
	return 0;
}

#else
bool Not_one(string N) {
	int sz = N.size();
	if (sz > 1)
		return 1;
	if (N[0] != '1')
		return 1;
	return 0;
}

bool is_Eve(string N) {
	int data = (N[N.size() - 1] - '0') & 1;
	if (data)
		return 0;
	return 1;
}

string Divide(string N, int data) {
	reverse(N.begin(), N.end());
	long long base = 10;
	string temp = "";
	for (int i = (int)N.size() - 1, rem = 0; i >= 0; --i) {
		long long Cur = (N[i] - '0') + rem * base;
		int val = Cur / data;
		rem = Cur % data;
		temp += (val + '0');
	}

	while (temp.size() && !(temp[0] - '0'))
		temp.erase(temp.begin());

	return temp;
}

int PowerOf2(string N) {
	int sz = N.size();
	if (sz == 1) {
		if (N[0] == '2' || N[0] == '4' || N[0] == '8')
			return 1;
		return 0;
	}
	else {
		while (Not_one(N) && is_Eve(N)) {
			N = Divide(N, 2);
			if (N.size() == 1 && N[0] == '1')
				break;
		}
		if (Not_one(N))
			return 0;
		return 1;
	}
}
#endif